#ifndef MFGYRDLG_H
#define MFGYRDLG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include "editablesqlmodel3.h"

namespace Ui {
class MfgYrDlg;
}

class MfgYrDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MfgYrDlg(QWidget *parent = 0);
    ~MfgYrDlg();

private slots:
    void on_pushButton_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MfgYrDlg *ui;
    void initializeModel(QStandardItemModel *model1);
    void createView(QStandardItemModel *model4);
    EditableSqlModel3 *editableModel;
    int catid;
    int yr;
    int r;
};

#endif // MFGYRDLG_H
