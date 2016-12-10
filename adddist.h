#ifndef ADDDIST_H
#define ADDDIST_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class AddDist;
}

class AddDist : public QDialog
{
    Q_OBJECT

public:
    explicit AddDist(QWidget *parent = 0);
    ~AddDist();

private slots:
    void on_btnOrder_clicked();

    void on_edtPrc_textChanged(const QString &arg1);

    void on_edtQty_textChanged(const QString &arg1);

private:
    Ui::AddDist *ui;
    bool Emptychk(QString prm, QString prm1);
};

#endif // ADDDIST_H
