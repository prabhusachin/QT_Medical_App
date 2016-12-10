#ifndef FROGOTPWD_H
#define FROGOTPWD_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "resetpwd.h"

namespace Ui {
class FrogotPwd;
}

class FrogotPwd : public QDialog
{
    Q_OBJECT

public:
    explicit FrogotPwd(QWidget *parent = 0);
    ~FrogotPwd();

private slots:
    void on_edtGo_clicked();

private:
    Ui::FrogotPwd *ui;
    ResetPwd *respwd;
    bool bFlg;
    //bool validaEmail(QString email);
};

#endif // FROGOTPWD_H
