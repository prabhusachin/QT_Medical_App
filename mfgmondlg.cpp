#include "mfgmondlg.h"
#include "ui_mfgmondlg.h"

MfgMonDlg::MfgMonDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MfgMonDlg)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->btnDelete->setEnabled(false);
    ui->pushButton->setStyleSheet("background-color: rgb(255,237,208)");
    ui->comboBox->addItem("Jan", "1");
    ui->comboBox->addItem("Feb", "2");
    ui->comboBox->addItem("Mar", "3");
    ui->comboBox->addItem("Apr", "4");
    ui->comboBox->addItem("May", "5");
    ui->comboBox->addItem("Jun", "6");
    ui->comboBox->addItem("Jul", "7");
    ui->comboBox->addItem("Aug", "8");
    ui->comboBox->addItem("Sep", "9");
    ui->comboBox->addItem("Oct", "10");
    ui->comboBox->addItem("Nov", "11");
    ui->comboBox->addItem("Dec", "12");
}

MfgMonDlg::~MfgMonDlg()
{
    delete ui;
}

void MfgMonDlg::initializeModel(QStandardItemModel *model1)
{
    QString val = "";
    QString val1 = "";
    QString val2 = "";
    model1->setRowCount(r);
    model1->setColumnCount(9);
    int row = 0;
    val1 = QString::number(m);
    val2 = QString::number(yr);
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
    QSqlQuery query1(db);
    query1.prepare(QString("SELECT * FROM Medicines WHERE mfgdate=:mfgdate"));
    query1.bindValue(":mfgdate", val);
    query1.exec();

    if(query1.size()!=0)
    {

    while (query1.next())
    {
        for(int c=0;c<=8;c++)
        {
        QString sval = query1.value(c).toString();

        QStandardItem* item = new QStandardItem(sval);
        model1->setItem(row, c, item);
        }
        row++;
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

void MfgMonDlg::on_pushButton_clicked()
{
    m = ui->comboBox->itemData(ui->comboBox->currentIndex()).toInt();
    yr = ui->comboBox_2->currentText().toInt();
    r=0;
    QString val = "";
    QString val1 = "";
    QString val2 = "";

    if(m<10)
    {
        val = QString ("0"+val1+QString ("-")+val2);
    }
    else
    {
        val = QString (""+val1+QString ("-")+val2);
    }
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setHostName("localhost");
    db1.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
    db1.setUserName("root");
    db1.setPassword("root");
    bool ok1 = db1.open();
    if (!ok1)
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db1.lastError().text());
      return;
    }
    QSqlQuery query(db1);
    query.prepare(QString("SELECT * FROM Medicines WHERE mfgdate=:mfgdate"));
    query.bindValue(":mfgdate", val);
    query.exec();
    if (query.size()!=0)
    {
        while(query.next())
        {
        r++;
        }
    }

    editableModel = new EditableSqlModel2();
    editableModel->setMYr(m,yr,r);
    initializeModel(editableModel);
    createView(editableModel);
    ui->btnDelete->setEnabled(true);
}

void MfgMonDlg::createView(QStandardItemModel *model4)
{
    ui->tableView->setModel(model4);
}

void MfgMonDlg::on_btnDelete_clicked()
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
        editableModel->removeRows(indexes.last().row(), 1);
        editableModel->submit();
        indexes.removeLast();
    }

    createView(editableModel);
}
