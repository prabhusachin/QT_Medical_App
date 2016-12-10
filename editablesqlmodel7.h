#ifndef EDITABLESQLMODEL7_H
#define EDITABLESQLMODEL7_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QStandardItemModel>

class EditableSqlModel7 : public QStandardItemModel
{
    Q_OBJECT

public:
    EditableSqlModel7(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    QStandardItemModel* refresh(QStandardItemModel *model1);
    void setQl(QString s);
    void setR2(int c);

private:
    bool setName(int personId, const QString &Name);
    bool setCompany(int personId, const QString &comp);
    bool setDistName(int personId, const QString &distName);
    bool setMfgDt(int personId, const QString &mfgDt);
    bool setExpDt(int personId, const QString &expDt);
    bool setPrc(int personId, const QString &prc);
    bool setStkQty(int personId, const QString &stkQty);
    QString sql;
    int r;
};

#endif // EDITABLESQLMODEL7_H
