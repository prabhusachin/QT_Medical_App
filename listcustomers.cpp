#include "listcustomers.h"
#include "ui_listcustomers.h"

ListCustomers::ListCustomers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListCustomers)
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
    QString sql = "SELECT * FROM CustomerReg";
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(sql, db);
    ui->tableView->setModel(model);
    ui->tableView->show();
}

ListCustomers::~ListCustomers()
{
    delete ui;
}

void ListCustomers::on_pushButton_clicked()
{
    QString name = ui->edtName->text();
    if(!name.isEmpty())
    {
        QString sql = QString("SELECT * FROM CustomerReg" +
                    QString(" WHERE stuname LIKE '%"+ name+"%'") +
                    QString(" OR stmname LIKE '%"+ name+"%'") +
                    QString(" OR stlname LIKE '%"+ name+"%'"));
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
        QMessageBox::warning(this,"Prescrition", "Please enter search criteria");
    }
}
