#include "editablesqlmodel5.h"

EditableSqlModel5::EditableSqlModel5(QObject *parent)
    : QStandardItemModel(parent)
{
}

//! [0]
Qt::ItemFlags EditableSqlModel5::flags(
        const QModelIndex &index) const
{
    Qt::ItemFlags flags = QStandardItemModel::flags(index);
    if (index.column() >= 1 && index.column() <= 6)
        flags |= Qt::ItemIsEditable;
    return flags;
}
//! [0]

//! [1]
bool EditableSqlModel5::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
    if (index.column() < 1 || index.column() > 6)
        return false;

    QModelIndex primaryKeyIndex = QStandardItemModel::index(index.row(), 0);
    int id = data(primaryKeyIndex).toInt();

    clear();

    bool ok;
    if (index.column() == 1) {
        ok = setName(id, value.toString());
    } else if (index.column() == 2) {
        ok = setCompany(id, value.toString());
    }
    else if (index.column() == 3) {
        ok = setAddress(id, value.toString());
    }
    else if (index.column() == 4) {
        ok = setMedicine(id, value.toString());
    }
    else if (index.column() == 5) {
        ok = setPrice(id, (value.toString().toDouble()));
    }
    else if (index.column() == 6) {
        ok = setQuantity(id, (value.toString().toInt()));
    }

    refresh(this);
    return ok;
}
//! [1]

void EditableSqlModel5::setQl(QString s)
{
    sql = s;
    return;
}

void EditableSqlModel5::setMYr(int c)
{
    r = c;
    return;
}

QStandardItemModel* EditableSqlModel5::refresh(QStandardItemModel *model1)
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
      //return;
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

//! [2]
bool EditableSqlModel5::setName(int personId, const QString &Name)
{
    QSqlQuery query;
    query.prepare("update DistOrders set ContactName = ? where id = ?");
    query.addBindValue(Name);
    query.addBindValue(personId);
    return query.exec();
}
//! [2]

bool EditableSqlModel5::setCompany(int personId, const QString &comp)
{
    QSqlQuery query;
    query.prepare("update DistOrders set CompanyName = ? where id = ?");
    query.addBindValue(comp);
    query.addBindValue(personId);
    return query.exec();
}

bool EditableSqlModel5::setAddress(int personId, const QString &distName)
{
    QSqlQuery query;
    query.prepare("update DistOrders set Address = ? where id = ?");
    query.addBindValue(distName);
    query.addBindValue(personId);
    return query.exec();
}

bool EditableSqlModel5::setMedicine(int personId, const QString &mfgDt)
{
    QSqlQuery query;
    query.prepare("update DistOrders set Medicine = ? where id = ?");
    query.addBindValue(mfgDt);
    query.addBindValue(personId);
    return query.exec();
}

bool EditableSqlModel5::setPrice(int personId, const double expDt)
{
    QSqlQuery query;
    query.prepare("update DistOrders set Price = ? where id = ?");
    query.addBindValue(expDt);
    query.addBindValue(personId);
    query.exec();

    QSqlQuery query2;
    query2.prepare("select Quantity from DistOrders where id=?");
    query2.addBindValue(personId);
    query2.exec();
    int iqty = 0;
    if(query2.size()!=0) {
        query2.next();
        iqty = (query2.value(0).toString().toInt());
    }
    double iamt = expDt * (double)iqty;

    QSqlQuery query1;
    query1.prepare("update DistOrders set Amount = ? where id = ?");
    query1.addBindValue(iamt);
    query1.addBindValue(personId);

    return query1.exec();
}

bool EditableSqlModel5::setQuantity(int personId, const int prc)
{
    QSqlQuery query;
    query.prepare("update DistOrders set Quantity = ? where id = ?");
    query.addBindValue(prc);
    query.addBindValue(personId);
    query.exec();

    QSqlQuery query2;
    query2.prepare("select Price from DistOrders where id=?");
    query2.addBindValue(personId);
    query2.exec();
    double iprc = 0;
    if(query2.size()!=0) {
        query2.next();
        iprc = (query2.value(0).toString().toDouble());
    }
    double iamt = iprc * (double)prc;

    QSqlQuery query1;
    query1.prepare("update DistOrders set Amount = ? where id = ?");
    query1.addBindValue(iamt);
    query1.addBindValue(personId);
    return query1.exec();
}
