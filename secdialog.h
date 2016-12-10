#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "mfgyrdlg.h"
#include "expyrdlg.h"
#include "mfgmondlg.h"
#include "expmondlg.h"
#include "listprescription.h"
#include "listcustomers.h"

namespace Ui {
class secDialog;
}

class secDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secDialog(QWidget *parent = 0);
    ~secDialog();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_btnSimp_clicked();

    void on_btnAdv_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();   

private:
    Ui::secDialog *ui;
    MfgYrDlg *mfyrDlg;
    ExpYrDlg *expyrDlg;
    MfgMonDlg *mfgmonDlg;
    ExpMonDlg *expmonDlg;
    ListPrescription *lstpresc;
    ListCustomers *lstcust;
    bool bFlg;
    bool bFlg1;
    bool bFlg2;
    bool bFlg3;
    bool bFlg4;
    bool bFlg5;
    bool bFlg6;
};

#endif // SECDIALOG_H
