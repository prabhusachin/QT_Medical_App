#ifndef EDITABLESQLMODEL5_H
#define EDITABLESQLMODEL5_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QStandardItemModel>

class EditableSqlModel5 : public QStandardItemModel
{
    Q_OBJECT

public:
    EditableSqlModel5(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    QStandardItemModel* refresh(QStandardItemModel *);
    void setQl(QString s);
    void setMYr(int);

private:
    bool setName(int personId, const QString &Name);
    bool setCompany(int personId, const QString &comp);
    bool setAddress(int personId, const QString &distName);
    bool setMedicine(int personId, const QString &mfgDt);
    bool setPrice(int personId, const double expDt);
    bool setQuantity(int personId, const int prc);
    int r;
    QString sql;

};

#endif // EDITABLESQLMODEL5_H
