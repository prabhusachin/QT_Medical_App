#ifndef EDITABLESQLMODEL8_H
#define EDITABLESQLMODEL8_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QStandardItemModel>

class EditableSqlModel8 : public QStandardItemModel
{
    Q_OBJECT

public:
    EditableSqlModel8(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    QStandardItemModel* refresh(QStandardItemModel *model1);
    void setQl(QString s);
    void setR3(int c);

private:
    bool setCat(int personId, const QString &Name);
    QString sql;
    int r;
};

#endif // EDITABLESQLMODEL8_H
