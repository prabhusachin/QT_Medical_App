#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegExp>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btnReg_clicked();

private:
    Ui::Dialog *ui;
    bool Emptychk(QString prm, QString prm1);
    bool validaEmail(QString email);
};

#endif // DIALOG_H
