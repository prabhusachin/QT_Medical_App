#ifndef ADDCAT_H
#define ADDCAT_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class AddCat;
}

class AddCat : public QDialog
{
    Q_OBJECT

public:
    explicit AddCat(QWidget *parent = 0);
    ~AddCat();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddCat *ui;
};

#endif // ADDCAT_H
