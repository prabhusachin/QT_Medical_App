#ifndef ADDMEDICINE_H
#define ADDMEDICINE_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class AddMedicine;
}

class AddMedicine : public QDialog
{
    Q_OBJECT

public:
    explicit AddMedicine(QWidget *parent = 0);
    ~AddMedicine();

private slots:
    void on_btnAdd_clicked();

private:
    Ui::AddMedicine *ui;
    bool Emptychk(QString prm, QString prm1);
};

#endif // ADDMEDICINE_H
