#include "addcat.h"
#include "ui_addcat.h"

AddCat::AddCat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCat)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->pushButton->setStyleSheet("background-color: rgb(255,237,208)");
}

AddCat::~AddCat()
{
    delete ui;
}

void AddCat::on_pushButton_clicked()
{
    QString cat = ui->edtCat->text();
    if(cat.isEmpty())
    {
        QMessageBox::warning(this,"Add Medicine Category", "Please enter category");
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
        query.prepare(QString("insert into MedCategories (category) values(:category)"));
        query.bindValue(":category", cat);

        if(query.exec())
        {
            ui->lblStat->setText("Medicine category has been successfully added");
        }
        else
        {
            ui->lblStat->setText("Error adding medicine category");
        }
    }
}
