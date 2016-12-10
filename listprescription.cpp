#include "listprescription.h"
#include "ui_listprescription.h"

ListPrescription::ListPrescription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListPrescription)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->pushButton->setStyleSheet("background-color: rgb(255,237,208)");
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
    QString sql = "SELECT * FROM Prescription";
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(sql, db);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

ListPrescription::~ListPrescription()
{
    delete ui;
}

void ListPrescription::on_pushButton_clicked()
{
    QString pname = ui->edtPname->text();
    QString dname = ui->edtDname->text();
    if(!pname.isEmpty() || !dname.isEmpty())
    {
        QString sql = "";
        if(!pname.isEmpty())
        {
            if(!dname.isEmpty())
            {
                sql = QString("SELECT * FROM Prescription" +
                    QString(" where patientname like '%" + pname + "%'") +
                    QString(" and doctorname like '%" + dname + "%'"));
            } //med <> null
            else
            {
                sql = QString("SELECT * FROM Prescription" +
                QString(" where patientname like '%" + pname + "%'"));
            }	//med = null
        }
        else
        {
            if(!dname.isEmpty())
            {
                sql = QString("SELECT * FROM Prescription" +
                    QString(" where doctorname like '%" + dname + "%'"));
            } //med <> null
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
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(sql, db);
        ui->tableView->setModel(model);
        ui->tableView->show();

    }
    else
    {
        QMessageBox::warning(this,"Prescrition", "Please enter search criterias");
    }
}
