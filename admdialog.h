#ifndef ADMDIALOG_H
#define ADMDIALOG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStandardItemModel>
#include <QMessageBox>
#include "mfgyrdlg.h"
#include "expyrdlg.h"
#include "mfgmondlg.h"
#include "expmondlg.h"
#include "listprescription.h"
#include "listcustomers.h"
#include "addmedicine.h"
#include "addcat.h"
#include "searchmed.h"
#include "adddist.h"
#include "srchdistributor.h"
#include "editablesqlmodel6.h"
#include "editablesqlmodel7.h"
#include "editablesqlmodel8.h"

namespace Ui {
class AdmDialog;
}

class AdmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdmDialog(QWidget *parent = 0);
    ~AdmDialog();

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

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_btnDelete_clicked();

private:
    Ui::AdmDialog *ui;
    MfgYrDlg *mfyrDlg;
    ExpYrDlg *expyrDlg;
    MfgMonDlg *mfgmonDlg;
    ExpMonDlg *expmonDlg;
    ListPrescription *lstpresc;
    ListCustomers *lstcust;
    AddMedicine *addmed;
    AddCat *addcat;
    SearchMed *srchmed;
    AddDist *adddist;
    SrchDistributor *srchdist;
    void initializeModel(QStandardItemModel *model1);
    void initializeModel1(QStandardItemModel *model9);
    void initializeModel2(QStandardItemModel *model8);
    void createView(QStandardItemModel *model4);
    QString sql;
    QString sql1;
    QString sql2;
    bool bFlg;
    bool bFlg1;
    bool bFlg2;
    bool bFlg3;
    bool bFlg4;
    bool bFlg5;
    bool bFlg6;
    bool bFlg7;
    bool bFlg8;
    bool bFlg9;
    bool bFlg10;
    bool bFlg11;
    int r1;
    int r2;
    int r3;
    int r4;
    EditableSqlModel8 *editableModel3;
    EditableSqlModel7 *editableModel2;
    EditableSqlModel6 *editableModel1;
};

#endif // ADMDIALOG_H
