#include "editablesqlmodel2.h"

EditableSqlModel2::EditableSqlModel2(QObject *parent)
    : QStandardItemModel(parent)
{
}

//! [0]
Qt::ItemFlags EditableSqlModel2::flags(
        const QModelIndex &index) const
{
    Qt::ItemFlags flags = QStandardItemModel::flags(index);
    if (index.column() >= 1 && index.column() <= 7)
        flags |= Qt::ItemIsEditable;
    return flags;
}
//! [0]

//! [1]
bool EditableSqlModel2::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
    if (index.column() < 1 || index.column() > 7)
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
        ok = setDistName(id, value.toString());
    }
    else if (index.column() == 4) {
        ok = setMfgDt(id, value.toString());
    }
    else if (index.column() == 5) {
        ok = setExpDt(id, value.toString());
    }
    else if (index.column() == 6) {
        ok = setPrc(id, value.toString());
    }
    else if (index.column() == 7) {
        ok = setStkQty(id, value.toString());
    }
    refresh(this,getM1(),getYr1());
    return ok;
}
//! [1]
void EditableSqlModel2::setMYr(int a,int b,int c)
{
    m1 = a;
    yr1 = b;
    r1 = c;
    return;
}

int EditableSqlModel2::getM1()
{
    return m1;
}

int EditableSqlModel2::getYr1()
{
    return yr1;
}

int EditableSqlModel2::getR1()
{
    return r1;
}



QStandardItemModel* EditableSqlModel2::refresh(QStandardItemModel *model1,int m, int yr)
{
    QString val = "";
    QString val1 = "";
    QString val2 = "";

    model1->setRowCount(getR1());
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

//! [2]
bool EditableSqlModel2::setName(int personId, const QString &Name)
{
    QSqlQuery query;
    query.prepare("update Medicines set Name = ? where id = ?");
    query.addBindValue(Name);
    query.addBindValue(personId);
    return query.exec();
}
//! [2]

bool EditableSqlModel2::setCompany(int personId, const QString &comp)
{
    QSqlQuery query;
    query.prepare("update Medicines set companyname = ? where id = ?");
    query.addBindValue(comp);
    query.addBindValue(personId);
    return query.exec();
}

bool EditableSqlModel2::setDistName(int personId, const QString &distName)
{
    QSqlQuery query;
    query.prepare("update Medicines set distname = ? where id = ?");
    query.addBindValue(distName);
    query.addBindValue(personId);
    return query.exec();
}

bool EditableSqlModel2::setMfgDt(int personId, const QString &mfgDt)
{
    QSqlQuery query;
    query.prepare("update Medicines set mfgdate = ? where id = ?");
    query.addBindValue(mfgDt);
    query.addBindValue(personId);
    return query.exec();
}

bool EditableSqlModel2::setExpDt(int personId, const QString &expDt)
{
    QSqlQuery query;
    query.prepare("update Medicines set expirydate = ? where id = ?");
    query.addBindValue(expDt);
    query.addBindValue(personId);
    return query.exec();
}

bool EditableSqlModel2::setPrc(int personId, const QString &prc)
{
    QSqlQuery query;
    query.prepare("update Medicines set Price = ? where id = ?");
    query.addBindValue(prc);
    query.addBindValue(personId);
    return query.exec();
}

bool EditableSqlModel2::setStkQty(int personId, const QString &stkQty)
{
    QSqlQuery query;
    query.prepare("update Medicines set stockqty = ? where id = ?");
    query.addBindValue(stkQty);
    query.addBindValue(personId);
    return query.exec();
}




