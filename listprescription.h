#ifndef LISTPRESCRIPTION_H
#define LISTPRESCRIPTION_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class ListPrescription;
}

class ListPrescription : public QDialog
{
    Q_OBJECT

public:
    explicit ListPrescription(QWidget *parent = 0);
    ~ListPrescription();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ListPrescription *ui;
};

#endif // LISTPRESCRIPTION_H
