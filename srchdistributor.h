#ifndef SRCHDISTRIBUTOR_H
#define SRCHDISTRIBUTOR_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include "editablesqlmodel5.h"

namespace Ui {
class SrchDistributor;
}

class SrchDistributor : public QDialog
{
    Q_OBJECT

public:
    explicit SrchDistributor(QWidget *parent = 0);
    ~SrchDistributor();

private slots:
    void on_btnSearch_clicked();

    void on_btnDelete_clicked();

private:
    Ui::SrchDistributor *ui;
    void initializeModel(QStandardItemModel *model1);
    void createView(QStandardItemModel *model4);
    EditableSqlModel5 *editableModel;
    QString sql;
    int r;
};

#endif // SRCHDISTRIBUTOR_H
