#ifndef EXPMONDLG_H
#define EXPMONDLG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include "editablesqlmodel.h"

namespace Ui {
class ExpMonDlg;
}

class ExpMonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ExpMonDlg(QWidget *parent = 0);
    ~ExpMonDlg();

private slots:
    void on_pushButton_clicked();

    void on_btnDelete_clicked();

private:
    Ui::ExpMonDlg *ui;
    void initializeModel(QStandardItemModel *model1);
    void createView(QStandardItemModel *model4);
    int m;
    int yr;
    int r;
    EditableSqlModel *editableModel;
};

#endif // EXPMONDLG_H
