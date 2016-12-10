#include "editablesqlmodel8.h"

EditableSqlModel8::EditableSqlModel8(QObject *parent)
    : QStandardItemModel(parent)
{
}

//! [0]
Qt::ItemFlags EditableSqlModel8::flags(
        const QModelIndex &index) const
{
    Qt::ItemFlags flags = QStandardItemModel::flags(index);
    if (index.column() == 1)
        flags |= Qt::ItemIsEditable;
    return flags;
}
//! [0]

//! [1]
bool EditableSqlModel8::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
    if (index.column() < 1 || index.column() > 1)
        return false;

    QModelIndex primaryKeyIndex = QStandardItemModel::index(index.row(), 0);
    int id = data(primaryKeyIndex).toInt();

    clear();

    bool ok;
    if (index.column() == 1) {
        ok = setCat(id, value.toString());
    }
    refresh(this);
    return ok;
}
//! [1]

void EditableSqlModel8::setQl(QString s)
{
    sql = s;
    return;
}

void EditableSqlModel8::setR3(int c)
{
    r = c;
    return;
}

QStandardItemModel* EditableSqlModel8::refresh(QStandardItemModel *model1)
{
    model1->setRowCount(r);
    model1->setColumnCount(2);
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
        for(int c=0;c<=1;c++)
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
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Category"));

}

//! [2]
bool EditableSqlModel8::setCat(int personId, const QString &Name)
{
    QSqlQuery query;
    query.prepare("update MedCategories set category = ? where cid = ?");
    query.addBindValue(Name);
    query.addBindValue(personId);
    return query.exec();
}





