#include "expyrdlg.h"
#include "ui_expyrdlg.h"

ExpYrDlg::ExpYrDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExpYrDlg)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->btnDelete->setEnabled(true);
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
    else
    {
        QSqlQuery query(db);
        query.prepare(QString("select CID,category from MedCategories"));
        query.exec();
        while (query.next())
        {
            ui->comboBox->addItem(query.value(1).toString(), query.value(0).toString());
        }
    }
}

ExpYrDlg::~ExpYrDlg()
{
    delete ui;
}

void ExpYrDlg::initializeModel(QStandardItemModel *model1)
{
    model1->setRowCount(r);
    model1->setColumnCount(9);
    QString cid = QString::number(catid);
    int row = 0;
    for(int m=1;m<=12;m++)
    {
        QString val = "";
        QString val1 = QString::number(m);
        QString val2 = QString::number(yr);
        if(m<10)
        {
            val = QString ("0"+val1+QString ("-")+val2);
        }
        else
        {
            val = QString (""+val1+QString ("-")+val2);
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
        QSqlQuery query(db);
        query.prepare(QString("SELECT * FROM Medicines WHERE CategoryId=:CategoryId and Expirydate=:Expirydate"));
        query.bindValue(":CategoryId", cid);
        query.bindValue(":Expirydate", val);
        query.exec();

        if(query.size()!=0)
        {

        while (query.next())
        {
            for(int c=0;c<=8;c++)
            {
            QString sval = query.value(c).toString();

            QStandardItem* item = new QStandardItem(sval);
            model1->setItem(row, c, item);
            }
            row++;
        }        
        }
    }
    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Companyname"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Distname"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("Mfgdate"));
    model1->setHeaderData(5, Qt::Horizontal, QObject::tr("Expirydate"));
    model1->setHeaderData(6, Qt::Horizontal, QObject::tr("Price"));
    model1->setHeaderData(7, Qt::Horizontal, QObject::tr("Stockqty"));
    model1->setHeaderData(8, Qt::Horizontal, QObject::tr("CategoryId"));
}

void ExpYrDlg::on_pushButton_clicked()
{
    catid = ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt();
    yr = ui->comboBox_2->currentText().toInt();

     r=0;
     for(int m=1;m<=12;m++)
     {
         QString val = "";
         QString val1 = QString::number(m);
         QString val2 = QString::number(yr);
         if(m<10)
         {
             val = QString ("0"+val1+QString ("-")+val2);
         }
         else
         {
             val = QString (""+val1+QString ("-")+val2);
         }
        //QMessageBox::warning(this,"Search", val);
         QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
         db1.setHostName("localhost");
         db1.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
         db1.setUserName("root");
         db1.setPassword("root");
         bool ok = db1.open();
         if (!ok)
         {
           QMessageBox::critical(0, QObject::tr("Database Error"),
                     db1.lastError().text());
           return;
         }
         QSqlQuery query(db1);
         query.prepare(QString("SELECT * FROM Medicines WHERE CategoryId=:CategoryId and Expirydate=:Expirydate"));
         query.bindValue(":CategoryId", catid);
         query.bindValue(":Expirydate", val);
         query.exec();
         if (query.size()!=0)
         {
             while(query.next())
             {
             r++;
             }
         }
     }
     editableModel = new EditableSqlModel1();
     editableModel->setMYr(catid,yr,r);
     initializeModel(editableModel);
     createView(editableModel);
     ui->btnDelete->setEnabled(true);
}

void ExpYrDlg::createView(QStandardItemModel *model4)
{
    ui->tableView->setModel(model4);
}


void ExpYrDlg::on_btnDelete_clicked()
{
    QModelIndexList indexes = ui->tableView->selectionModel()->selectedRows();
    while (!indexes.isEmpty())
    {
        QModelIndex primaryKeyIndex = indexes.last();
        int id = editableModel->data(primaryKeyIndex).toInt();
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
        QSqlQuery query(db);
        query.prepare("delete from Medicines where id = ?");
        query.addBindValue(id);
        query.exec();
        //editableModel->beginRemoveRows(primaryKeyIndex, indexes.last().row(), indexes.last().row()+1);
        editableModel->removeRows(indexes.last().row(), 1);
        //editableModel->endRemoveRows();
        editableModel->submit();
        indexes.removeLast();
    }

    createView(editableModel);
}
