#include "adddist.h"
#include "ui_adddist.h"

AddDist::AddDist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDist)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->btnOrder->setStyleSheet("background-color: rgb(255,237,208)");
    ui->edtCno->setMaxLength(16);
    ui->edtCno->setValidator( new QIntValidator(0,9999999999999999));
    ui->edtCmon->setMaxLength(2);
    ui->edtCmon->setValidator( new QIntValidator(0,12));
    ui->edtCexp->setMaxLength(2);
    ui->edtCexp->setValidator( new QIntValidator(0,99));
}

AddDist::~AddDist()
{
    delete ui;
}

bool AddDist::Emptychk(QString prm, QString prm1)
{
    if(prm.isEmpty())
    {
        QMessageBox::warning(this,"Add Distributor", "Please enter "+prm1);
        return true;
    }
    else
        return false;
}


void AddDist::on_btnOrder_clicked()
{
    QString name = ui->edtName->text();
    QString comp = ui->edtComp->text();
    QString addr = ui->edtAddr->text();
    QString med = ui->edtMed->text();
    QString prc = ui->edtPrc->text();
    QString qty = ui->edtQty->text();
    QString amt = ui->edtAmt->text();
    QString cname = ui->edtCname->text();
    QString cno = ui->edtCno->text();
    QString cmon = ui->edtCmon->text();
    QString cexp = ui->edtCexp->text();
    QString expdt = cmon + "-20" + cexp;
    if(Emptychk(name, "distributor name"))
    {
        return;
    }
    else if(Emptychk(comp, "company"))
    {
        return;
    }
    else if(Emptychk(addr, "address"))
    {
        return;
    }
    else if(Emptychk(med, "medicine"))
    {
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
    else if(Emptychk(cname, "name on credit card"))
    {
        return;
    }
    else if(Emptychk(cno, "credit card no"))
    {
        return;
    }
    else if(cno.size() < 16)
    {
        QMessageBox::warning(this,"Add Distributor", "Credit card number must be 16 digit");
        return;
    }
    else if(cexp.isEmpty() || cmon.isEmpty())
    {
        QMessageBox::warning(this,"Add Distributor", "Please enter card expiry date");
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
        query.prepare(QString("insert into DistOrders (ContactName,CompanyName,Address,Medicine,Price,Quantity,Amount,CCName,CCNumber,CCExpiryDate) values(:ContactName,:CompanyName,:Address,:Medicine,:Price,:Quantity,:Amount,:CCName,:CCNumber,:CCExpiryDate)"));
        query.bindValue(":ContactName", name);
        query.bindValue(":CompanyName", comp);
        query.bindValue(":Address", addr);
        query.bindValue(":Medicine", med);
        query.bindValue(":Price", prc);
        query.bindValue(":Quantity", qty);
        query.bindValue(":Amount", amt);
        query.bindValue(":CCName", cname);
        query.bindValue(":CCNumber", cno);
        query.bindValue(":CCExpiryDate", expdt);

        if(query.exec())
        {
            ui->lblStat->setText("Distributor order has been successfully added");
        }
        else
        {
            ui->lblStat->setText("Error adding distributor order");
        }
    }
}

void AddDist::on_edtPrc_textChanged(const QString &arg1)
{
    QString prc = ui->edtPrc->text();
    QString qty = ui->edtQty->text();
    int iprc = 0;
    if(!prc.isEmpty())
        iprc = prc.toInt();
    int iqty = 0;
    if(!qty.isEmpty())
        iqty = qty.toInt();
    int iamt = 0;
    if(iprc != 0 && iqty !=0)
        iamt = iprc * iqty;

    QString amt = QString::number(iamt);
    ui->edtAmt->setText(amt);
}

void AddDist::on_edtQty_textChanged(const QString &arg1)
{
    QString prc = ui->edtPrc->text();
    QString qty = ui->edtQty->text();
    int iprc = 0;
    if(!prc.isEmpty())
        iprc = prc.toInt();
    int iqty = 0;
    if(!qty.isEmpty())
        iqty = qty.toInt();
    int iamt = 0;
    if(iprc != 0 && iqty !=0)
        iamt = iprc * iqty;

    QString amt = QString::number(iamt);
    ui->edtAmt->setText(amt);
}
