#include "addmedicine.h"
#include "ui_addmedicine.h"

AddMedicine::AddMedicine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMedicine)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->btnAdd->setStyleSheet("background-color: rgb(255,237,208)");
    ui->edtMfg->setMaxLength(2);
    ui->edtMfg->setValidator( new QIntValidator(0,99));
    ui->edtExp->setMaxLength(2);
    ui->edtExp->setValidator( new QIntValidator(0,99));
    ui->edtMmon->setMaxLength(2);
    ui->edtMmon->setValidator( new QIntValidator(0,12));
    ui->edtEmon->setMaxLength(2);
    ui->edtEmon->setValidator( new QIntValidator(0,12));
    ui->edtPrc->setValidator( new QIntValidator);
    ui->edtQty->setValidator( new QIntValidator);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    if (!ok)
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());
    }
    else
    {
        QSqlQuery query(db);
        query.prepare(QString("select CID,category from MedCategories"));
        query.exec();
        while (query.next())
        {
            ui->cmbCat->addItem(query.value(1).toString(), query.value(0).toString());
        }
    }
}

AddMedicine::~AddMedicine()
{
    delete ui;
}

bool AddMedicine::Emptychk(QString prm, QString prm1)
{
    if(prm.isEmpty())
    {
        QMessageBox::warning(this,"Add Medicine", "Please enter "+prm1);
        return true;
    }
    else
        return false;
}

void AddMedicine::on_btnAdd_clicked()
{
    QString name = ui->edtName->text();
    QString comp = ui->edtComp->text();
    QString dist = ui->edtDist->text();
    QString mfg = ui->edtMfg->text();
    QString exp = ui->edtExp->text();
    QString prc = ui->edtPrc->text();
    QString qty = ui->edtQty->text();
    QString mmon = ui->edtMmon->text();
    QString emon = ui->edtEmon->text();
    int catid = ui->cmbCat->itemData(ui->cmbCat->currentIndex()).toInt();
    QString cid = QString::number(catid);
    QString mfgdt = mmon + "-20" + mfg;
    QString expdt = emon + "-20" + exp;
    if(Emptychk(name, "medicine name"))
    {
        return;
    }
    else if(Emptychk(comp, "company"))
    {
        return;
    }
    else if(Emptychk(dist, "distributor"))
    {
        return;
    }
    else if(Emptychk(comp, "company"))
    {
        return;
    }
    else if(mfg.isEmpty() || mmon.isEmpty())
    {
        QMessageBox::warning(this,"Add Medicine", "Please enter mfg date");
        return;
    }
    else if(exp.isEmpty() || emon.isEmpty())
    {
        QMessageBox::warning(this,"Add Medicine", "Please enter expiry date");
        return;
    }
    else if(Emptychk(prc, "price"))
    {
        return;
    }
    else if(Emptychk(qty, "quantity"))
    {
        return;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    if (!ok)
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());
      return;
    }
    else
    {
        QSqlQuery query(db);
        query.prepare(QString("insert into Medicines (Name,companyname,distname,mfgdate,expirydate,Price,stockqty,CategoryId) values(:Name,:companyname,:distname,:mfgdate,:expirydate,:Price,:stockqty,:CategoryId)"));
        query.bindValue(":Name", name);
        query.bindValue(":companyname", comp);
        query.bindValue(":distname", dist);
        query.bindValue(":mfgdate", mfgdt);
        query.bindValue(":expirydate", expdt);
        query.bindValue(":Price", prc);
        query.bindValue(":stockqty", qty);
        query.bindValue(":CategoryId", cid);

        if(query.exec())
        {
            ui->lblStat->setText("Medicine has been successfully added");
        }
        else
        {
            ui->lblStat->setText("Error adding medicine");
        }
    }


}
