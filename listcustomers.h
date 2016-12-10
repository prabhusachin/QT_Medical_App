#ifndef LISTCUSTOMERS_H
#define LISTCUSTOMERS_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class ListCustomers;
}

class ListCustomers : public QDialog
{
    Q_OBJECT

public:
    explicit ListCustomers(QWidget *parent = 0);
    ~ListCustomers();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ListCustomers *ui;
};

#endif // LISTCUSTOMERS_H
