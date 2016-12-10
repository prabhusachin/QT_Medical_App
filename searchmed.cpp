#include "searchmed.h"
#include "ui_searchmed.h"

SearchMed::SearchMed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchMed)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->btnDelete->setEnabled(false);
    ui->btnSrch->setStyleSheet("background-color: rgb(255,237,208)");
}

SearchMed::~SearchMed()
{
    delete ui;
}

void SearchMed::initializeModel(QStandardItemModel *model1)
{
    model1->setRowCount(r);
    model1->setColumnCount(9);
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
        for(int c=0;c<=8;c++)
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
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Companyname"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Distname"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("Mfgdate"));
    model1->setHeaderData(5, Qt::Horizontal, QObject::tr("Expirydate"));
    model1->setHeaderData(6, Qt::Horizontal, QObject::tr("Price"));
    model1->setHeaderData(7, Qt::Horizontal, QObject::tr("Stockqty"));
    model1->setHeaderData(8, Qt::Horizontal, QObject::tr("CategoryId"));
}

void SearchMed::on_btnSrch_clicked()
{
    QString medcat = ui->edtCat->text();
    QString medname = ui->edtMed->text();
    //QString sql = "";
    if(!medcat.isEmpty() || !medname.isEmpty())
    {
        if(!medcat.isEmpty() )
        {
            if(!medname.isEmpty())
            {
                sql = QString("SELECT * FROM Medicines md, MedCategories mc" +
                QString(" Where md.CategoryId=mc.CID") +
                QString(" And md.Name like '%" + medname + "%'") +
                QString(" And mc.Category like '%" + medcat + "%'"));
            } //cno<>null
            else
            {
                sql = QString("SELECT * FROM Medicines md, MedCategories mc" +
                QString(" Where mc.CID=md.CategoryId") +
                QString(" And mc.Category like '%" + medcat + "%'"));
            } //cno=null
        } //keyword<>null
        else
        {
            if(!medname.isEmpty())
            {
                sql = QString("SELECT * FROM Medicines md, MedCategories mc" +
                QString(" Where md.CategoryId=mc.CID") +
                QString(" And md.Name like '%" +medname + "%'"));
            } //cno<>null
        } // oid<>null
    }
    if(!medcat.isEmpty() || !medname.isEmpty())
    {
        r=0;
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

        editableModel = new EditableSqlModel4();
        initializeModel(editableModel);
        editableModel->setMYr(r);
        editableModel->setQl(sql);
        createView(editableModel);
        ui->btnDelete->setEnabled(true);
    }
    else
    {
        QMessageBox::warning(this,"Search Medicine", "Please enter search criteria");
    }
}

void SearchMed::createView(QStandardItemModel *model4)
{
    ui->tableView->setModel(model4);
}

void SearchMed::on_btnDelete_clicked()
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

        indexes.removeLast();
    }
    editableModel->submit();
    createView(editableModel);
}
