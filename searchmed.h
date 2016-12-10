#ifndef SEARCHMED_H
#define SEARCHMED_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include "editablesqlmodel4.h"

namespace Ui {
class SearchMed;
}

class SearchMed : public QDialog
{
    Q_OBJECT

public:
    explicit SearchMed(QWidget *parent = 0);
    ~SearchMed();

private slots:
    void on_btnSrch_clicked();

    void on_btnDelete_clicked();

private:
    Ui::SearchMed *ui;
    void initializeModel(QStandardItemModel *model1);
    void createView(QStandardItemModel *model4);
    EditableSqlModel4 *editableModel;
    QString sql;
    int r;
};

#endif // SEARCHMED_H
