#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include "secdialog.h"
#include "register.h"
#include "frogotpwd.h"
#include "admdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_btnRegister_clicked();

    void on_edtFpwd_clicked();

private:
    Ui::MainWindow *ui;
    secDialog *secDialog1;
    AdmDialog *admDialog1;
    Dialog *regDlg;
    FrogotPwd *fPwd;
    bool bFlg;
    bool bFlg1;
    bool bFlg2;    
};

#endif // MAINWINDOW_H
