#include "srchdistributor.h"
#include "ui_srchdistributor.h"

SrchDistributor::SrchDistributor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SrchDistributor)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->btnDelete->setEnabled(false);
    ui->btnSearch->setStyleSheet("background-color: rgb(255,237,208)");
    ui->tableView->hide();
}

SrchDistributor::~SrchDistributor()
{
    delete ui;
}

void SrchDistributor::initializeModel(QStandardItemModel *model1)
{
    model1->setRowCount(r);
    model1->setColumnCount(11);
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
    query1.prepare(sql);
    query1.exec();
    int row = 0;
    if(query1.size()!=0)
    {

    while (query1.next())
    {
        for(int c=0;c<=10;c++)
        {
        QString sval = query1.value(c).toString();

        QStandardItem* item = new QStandardItem(sval);
        model1->setItem(row, c, item);

        }
    row++;
    }

    }
   //model1->setQuery(sql, db);
   model1->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model1->setHeaderData(1, Qt::Horizontal, QObject::tr("ContactName"));
   model1->setHeaderData(2, Qt::Horizontal, QObject::tr("CompanyName"));
   model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Address"));
   model1->setHeaderData(4, Qt::Horizontal, QObject::tr("Medicine"));
   model1->setHeaderData(5, Qt::Horizontal, QObject::tr("Price"));
   model1->setHeaderData(6, Qt::Horizontal, QObject::tr("Quantity"));
   model1->setHeaderData(7, Qt::Horizontal, QObject::tr("Amount"));
   model1->setHeaderData(8, Qt::Horizontal, QObject::tr("CCName"));
   model1->setHeaderData(9, Qt::Horizontal, QObject::tr("CCNumber"));
   model1->setHeaderData(10, Qt::Horizontal, QObject::tr("CCExpiryDate"));
}

void SrchDistributor::on_btnSearch_clicked()
{
    QString oid = ui->edtOid->text();
    QString keyword = ui->edtName->text();
    QString comp = ui->edtComp->text();
    QString med = ui->edtMed->text();
    r=0;
    if(!oid.isEmpty() || !keyword.isEmpty() || !comp.isEmpty() || !med.isEmpty())
    {
        if((!oid.isEmpty()))
        {
            if((!keyword.isEmpty()))
            {
                if((!comp.isEmpty()))
                {
                    if((!med.isEmpty()))
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                            QString(" where ID=" + oid ) +
                            QString(" and ContactName like '%" + keyword + "%'") +
                            QString(" and CompanyName like '%" + comp + "%'") +
                            QString(" and Medicine like '%" + med + "%'"));
                    } //med <> null
                    else
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                        QString(" where ID=" + oid ) +
                        QString(" and ContactName like '%" + keyword + "%'") +
                        QString(" and CompanyName like '%" + comp + "%'"));
                    }	//med = null
                } //comp <> null
                else
                {
                    if((!med.isEmpty()))
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                            QString(" where ID=" + oid ) +
                            QString(" and ContactName like '%" + keyword + "%'") +
                            QString(" and Medicine like '%" + med + "%'"));
                    } //med <> null
                    else
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                        QString(" where ID=" + oid ) +
                        QString(" and ContactName like '%" + keyword + "%'"));
                    }	//med = null
                } //comp = null
            } //keyword <> null
            else
            {
                if((!comp.isEmpty()))
                {
                    if((!med.isEmpty()))
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                            QString(" where ID=" + oid ) +
                            QString(" and CompanyName like '%" + comp + "%'") +
                            QString(" and Medicine like '%" + med + "%'"));
                    } //med <> null
                    else
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                        QString(" where ID=" + oid ) +
                        QString(" and CompanyName like '%" + comp + "%'"));
                    }	//med = null
                } //comp <> null
                else
                {
                    if((!med.isEmpty()))
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                            QString(" where ID=" + oid ) +
                            QString(" and Medicine like '%" + med + "%'"));
                    } //med <> null
                    else
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                        QString(" where ID=" + oid));
                    }	//med = null
                } //comp = null
            } //keyword = null
        } //oid <> null
        else
        {
            if((!keyword.isEmpty()))
            {
                if((!comp.isEmpty()))
                {
                    if((!med.isEmpty()))
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                            QString(" where ContactName like '%" + keyword + "%'") +
                            QString(" and CompanyName like '%" + comp + "%'") +
                            QString(" and Medicine like '%" + med + "%'"));
                    } //med <> null
                    else
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                        QString(" where ContactName like '%" + keyword + "%'") +
                        QString(" and CompanyName like '%" + comp + "%'"));
                    }	//med = null
                } //comp <> null
                else
                {
                    if((!med.isEmpty()))
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                            QString(" where ContactName like '%" + keyword + "%'") +
                            QString(" and Medicine like '%" + med + "%'"));
                    } //med <> null
                    else
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                        QString(" where ContactName like '%" + keyword + "%'"));
                    }	//med = null
                } //comp = null
            } //keyword <> null
            else
            {
                if((!comp.isEmpty()))
                {
                    if((!med.isEmpty()))
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                            QString(" where CompanyName like '%" + comp + "%'") +
                            QString(" and Medicine like '%" + med + "%'"));
                    } //med <> null
                    else
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                        QString(" where CompanyName like '%" + comp + "%'"));
                    }	//med = null
                } //comp <> null
                else
                {
                    if((!med.isEmpty()))
                    {
                        sql = QString("SELECT * FROM DistOrders" +
                            QString(" where Medicine like '%" + med + "%'"));
                    } //med <> null
                } //comp = null
            } //keyword = null
        } //oid = null
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
        query.prepare(sql);
        query.exec();
        while(query.next())
        {
        r++;
        }
        editableModel = new EditableSqlModel5();
        initializeModel(editableModel);
        editableModel->setMYr(r);
        editableModel->setQl(sql);
        createView(editableModel);
        ui->btnDelete->setEnabled(true);
   }
   else
   {
       QMessageBox::warning(this,"Distributor", "Please enter search criterias");
   }
}

void SrchDistributor::createView(QStandardItemModel *model4)
{
    ui->tableView->setModel(model4);
    ui->tableView->show();
}

void SrchDistributor::on_btnDelete_clicked()
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
        query.prepare("delete from DistOrders where id = ?");
        query.addBindValue(id);
        query.exec();
        editableModel->removeRows(indexes.last().row(), 1);

        indexes.removeLast();
    }
    editableModel->submit();
    createView(editableModel);
}
