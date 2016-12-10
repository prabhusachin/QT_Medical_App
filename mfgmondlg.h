#ifndef MFGMONDLG_H
#define MFGMONDLG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include "editablesqlmodel2.h"

namespace Ui {
class MfgMonDlg;
}

class MfgMonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MfgMonDlg(QWidget *parent = 0);
    ~MfgMonDlg();

private slots:
    void on_pushButton_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MfgMonDlg *ui;
    void initializeModel(QStandardItemModel *model1);
    void createView(QStandardItemModel *model4);
    int m;
    int yr;
    int r;
    EditableSqlModel2 *editableModel;
};

#endif // MFGMONDLG_H
