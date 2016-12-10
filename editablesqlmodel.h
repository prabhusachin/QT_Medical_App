#ifndef EDITABLESQLMODEL_H
#define EDITABLESQLMODEL_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>

class EditableSqlModel : public QStandardItemModel
{
    Q_OBJECT

public:
    EditableSqlModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    QStandardItemModel* refresh(QStandardItemModel* ,int,int);
    void setMYr(int,int,int);
    int getM1();
    int getYr1();
    int getR1();

private:
    bool setName(int personId, const QString &Name);
    bool setCompany(int personId, const QString &comp);
    bool setDistName(int personId, const QString &distName);
    bool setMfgDt(int personId, const QString &mfgDt);
    bool setExpDt(int personId, const QString &expDt);
    bool setPrc(int personId, const QString &prc);
    bool setStkQty(int personId, const QString &stkQty);
    int m1;
    int yr1;
    int r1;
    EditableSqlModel *editableModel;
};

#endif // EDITABLESQLMODEL_H
