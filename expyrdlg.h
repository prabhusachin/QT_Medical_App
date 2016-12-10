#ifndef EXPYRDLG_H
#define EXPYRDLG_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include "editablesqlmodel1.h"

namespace Ui {
class ExpYrDlg;
}

class ExpYrDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ExpYrDlg(QWidget *parent = 0);
    ~ExpYrDlg();

private slots:
    void on_pushButton_clicked();

    void on_btnDelete_clicked();

private:
    Ui::ExpYrDlg *ui;
    void initializeModel(QStandardItemModel *model1);
    void createView(QStandardItemModel *model4);
    int catid;
    int yr;
    int r;
    EditableSqlModel1 *editableModel;
};

#endif // EXPYRDLG_H
