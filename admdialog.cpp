#include "admdialog.h"
#include "ui_admdialog.h"

AdmDialog::AdmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdmDialog)
{
    ui->setupUi(this);
    this->setModal(true);
    r4=0;
    ui->btnDelete->setEnabled(false);
    ui->radioButton->setChecked(true);
    ui->edtSimp->setEnabled(true);
    ui->btnSimp->setEnabled(true);
    ui->btnSimp->setEnabled(true);
    ui->edtMed->setEnabled(false);
    ui->edtComp->setEnabled(false);
    ui->edtDist->setEnabled(false);
    ui->edtMfg->setEnabled(false);
    ui->edtExp->setEnabled(false);
    ui->cmbPrc->setEnabled(false);
    ui->btnAdv->setEnabled(false);
    bFlg = false;
    bFlg1 = false;
    bFlg2 = false;
    bFlg3 = false;
    bFlg4 = false;
    bFlg5 = false;
    bFlg6 = false;
    bFlg7 = false;
    bFlg8 = false;
    bFlg9 = false;
    bFlg10 = false;
    bFlg11 = false;
    ui->tableView->hide();
    ui->pushButton->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_2->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_3->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_4->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_5->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_6->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_7->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_8->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_9->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_10->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_11->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_12->setStyleSheet("background-color: rgb(255,237,208)");
    ui->btnSimp->setStyleSheet("background-color: rgb(255,237,208)");
    ui->btnAdv->setStyleSheet("background-color: rgb(255,237,208)");
}

AdmDialog::~AdmDialog()
{
    delete ui;
}

void AdmDialog::on_radioButton_clicked()
{
    ui->edtSimp->setEnabled(true);
    ui->btnSimp->setEnabled(true);
    ui->edtMed->setEnabled(false);
    ui->edtComp->setEnabled(false);
    ui->edtDist->setEnabled(false);
    ui->edtMfg->setEnabled(false);
    ui->edtExp->setEnabled(false);
    ui->cmbPrc->setEnabled(false);
    ui->btnAdv->setEnabled(false);
    ui->tableView->hide();
}

void AdmDialog::on_radioButton_2_clicked()
{
    ui->edtSimp->setEnabled(false);
    ui->btnSimp->setEnabled(false);
    ui->edtMed->setEnabled(true);
    ui->edtComp->setEnabled(true);
    ui->edtDist->setEnabled(true);
    ui->edtMfg->setEnabled(true);
    ui->edtExp->setEnabled(true);
    ui->cmbPrc->setEnabled(true);
    ui->btnAdv->setEnabled(true);
    ui->tableView->hide();
}

void AdmDialog::initializeModel2(QStandardItemModel *model8)
{
    model8->setRowCount(r3);
    model8->setColumnCount(2);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    if (!ok)
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());
      return;
    }
    QSqlQuery query1(db);
    query1.prepare(sql2);
    query1.exec();
    int row = 0;
    if(query1.size()!=0)
    {

    while (query1.next())
    {
        for(int c=0;c<=1;c++)
        {
        QString sval = query1.value(c).toString();

        QStandardItem* item = new QStandardItem(sval);
        model8->setItem(row, c, item);

        }
        row++;
    }

    }
    model8->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model8->setHeaderData(1, Qt::Horizontal, QObject::tr("Category"));
}

void AdmDialog::initializeModel(QStandardItemModel *model1)
{
    model1->setRowCount(r1);
    model1->setColumnCount(9);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    if (!ok)
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());
      return;
    }
    QSqlQuery query1(db);
    query1.prepare(sql1);
    query1.exec();
    int row = 0;
    if(query1.size()!=0)
    {

    while (query1.next())
    {
        for(int c=0;c<=8;c++)
        {
        QString sval = query1.value(c).toString();

        QStandardItem* item = new QStandardItem(sval);
        model1->setItem(row, c, item);

        }
    row++;
    }

    }
    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Companyname"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Distname"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("Mfgdate"));
    model1->setHeaderData(5, Qt::Horizontal, QObject::tr("Expirydate"));
    model1->setHeaderData(6, Qt::Horizontal, QObject::tr("Price"));
    model1->setHeaderData(7, Qt::Horizontal, QObject::tr("Stockqty"));
    model1->setHeaderData(8, Qt::Horizontal, QObject::tr("CategoryId"));

}

void AdmDialog::initializeModel1(QStandardItemModel *model9)
{
    model9->setRowCount(r2);
    model9->setColumnCount(9);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    if (!ok)
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());
      return;
    }
    QSqlQuery query1(db);
    query1.prepare(sql);
    query1.exec();
    int row = 0;
    if(query1.size()!=0)
    {

    while (query1.next())
    {
        for(int c=0;c<=8;c++)
        {
        QString sval = query1.value(c).toString();

        QStandardItem* item = new QStandardItem(sval);
        model9->setItem(row, c, item);

        }
        row++;
    }

    }
    //model9->setQuery(sql, db);
    model9->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model9->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model9->setHeaderData(2, Qt::Horizontal, QObject::tr("Companyname"));
    model9->setHeaderData(3, Qt::Horizontal, QObject::tr("Distname"));
    model9->setHeaderData(4, Qt::Horizontal, QObject::tr("Mfgdate"));
    model9->setHeaderData(5, Qt::Horizontal, QObject::tr("Expirydate"));
    model9->setHeaderData(6, Qt::Horizontal, QObject::tr("Price"));
    model9->setHeaderData(7, Qt::Horizontal, QObject::tr("Stockqty"));
    model9->setHeaderData(8, Qt::Horizontal, QObject::tr("CategoryId"));
}

void AdmDialog::on_btnSimp_clicked()
{
    r4=1;
    QString keywd = ui->edtSimp->text();
    if(keywd.isEmpty())
    {
        QMessageBox::warning(this,"Search", "Please enter keyword");
        return;
    }
    if(!bFlg)
    {
        r1=0;
        QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
        db1.setHostName("localhost");
        db1.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
        db1.setUserName("root");
        db1.setPassword("root");
        bool ok1 = db1.open();
        if (!ok1)
        {
          QMessageBox::critical(0, QObject::tr("Database Error"),
                    db1.lastError().text());
          return;
        }
        sql1 = "SELECT * FROM Medicines WHERE Name LIKE '%"+keywd+"%'";
        QSqlQuery query(db1);
        query.prepare(sql1);
        query.exec();
        r1=query.size();
        editableModel1 = new EditableSqlModel6();
        initializeModel(editableModel1);
        editableModel1->setQl(sql1);
        editableModel1->setMRl(r1);
        createView(editableModel1);
        ui->btnDelete->setEnabled(true);
   }
}

void AdmDialog::on_btnAdv_clicked()
{
    r4=2;
    QString keyword = ui->edtMed->text();
    QString companyname = ui->edtComp->text();
    QString distname = ui->edtDist->text();
    QString expirydate = ui->edtExp->text();
    QString mfgdate = ui->edtMfg->text();
    QString price = ui->cmbPrc->currentText();

    if(keyword.isEmpty() && companyname.isEmpty() &&
            distname.isEmpty() && expirydate.isEmpty() &&
            mfgdate.isEmpty() && price.isEmpty())
    {
        QMessageBox::warning(this,"Search", "Please enter search parameters");
        return;
    }
    if(!keyword.isEmpty())
    {
        if(!companyname.isEmpty())
        {
            if(!distname.isEmpty())
            {
                if(!mfgdate.isEmpty())
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'"));
                        }
                    } //expdate==null
                } //mfgdate <> null
                else
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'"));
                        }
                    } //expdate==null
                } //mfgdt = null
            } //distname <> null
            else
            {
                if(!mfgdate.isEmpty())
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'"));
                        }
                    } //expdate==null
                } //mfgdate <> null
                else
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Companyname LIKE '%" + companyname + "%'"));
                        }
                    } //expdate==null
                } //mfgdt = null
            } //dist=null
        } // company<>null
        else
        {
            if(!distname.isEmpty())
            {
                if(!mfgdate.isEmpty())
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'"));
                        }
                    } //expdate==null
                } //mfgdate <> null
                else
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'"));
                        }
                    } //expdate==null
                } //mfgdt = null
            } //distname <> null
            else
            {
                if(!mfgdate.isEmpty())
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'"));
                        }
                    } //expdate==null
                } //mfgdate <> null
                else
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Name LIKE '%" + keyword + "%'"));
                        }
                    } //expdate==null
                } //mfgdt = null
            } //dist=null
        } //comp=null
    } //name<>null
    else
    {
        if(!companyname.isEmpty())
        {
            if(!distname.isEmpty())
            {
                if(!mfgdate.isEmpty())
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'"));
                        }
                    } //expdate==null
                } //mfgdate <> null
                else
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Distname LIKE '%" + distname + "%'"));
                        }
                    } //expdate==null
                } //mfgdt = null
            } //distname <> null
            else
            {
                if(!mfgdate.isEmpty())
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'"));
                        }
                    } //expdate==null
                } //mfgdate <> null
                else
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Companyname LIKE '%" + companyname + "%'"));
                        }
                    } //expdate==null
                } //mfgdt = null
            } //dist=null
        } // company<>null
        else
        {
            if(!distname.isEmpty())
            {
                if(!mfgdate.isEmpty())
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Distname LIKE '%" + distname + "%'") +
                            QString(" AND Mfgdate LIKE '%" + mfgdate + "%'"));
                        }
                    } //expdate==null
                } //mfgdate <> null
                else
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Distname LIKE '%" + distname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Distname LIKE '%" + distname + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Distname LIKE '%" + distname + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Distname LIKE '%" + distname + "%'"));
                        }
                    } //expdate==null
                } //mfgdt = null
            } //distname <> null
            else
            {
                if(!mfgdate.isEmpty())
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Mfgdate LIKE '%" + mfgdate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Mfgdate LIKE '%" + mfgdate + "%'"));
                        }
                    } //expdate==null
                } //mfgdate <> null
                else
                {
                    if(!expirydate.isEmpty())
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Expirydate LIKE '%" + expirydate + "%'") +
                            QString(" AND Price between " + price));
                        }
                        else
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Expirydate LIKE '%" + expirydate + "%'"));
                        }
                    } //expdt <> null
                    else
                    {
                        if(price != "Select")
                        {
                            sql = QString ("SELECT * FROM Medicines" +
                            QString(" WHERE Price between " + price));
                        }
                    } //expdate==null
                } //mfgdt = null
            } //dist=null
        } //comp=null
    } // name=null
    if(!bFlg)
    {

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("localhost");
        db.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
        db.setUserName("root");
        db.setPassword("root");
        bool ok = db.open();
        if (!ok)
        {
          QMessageBox::critical(0, QObject::tr("Database Error"),
                    db.lastError().text());
        }
        else
        {
            r2=0;
            QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
            db1.setHostName("localhost");
            db1.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
            db1.setUserName("root");
            db1.setPassword("root");
            bool ok1 = db1.open();
            if (!ok1)
            {
              QMessageBox::critical(0, QObject::tr("Database Error"),
                        db1.lastError().text());
              return;
            }
            QSqlQuery query(db1);
            query.prepare(sql);
            query.exec();
            r2=query.size();

            editableModel2 = new EditableSqlModel7();
            initializeModel1(editableModel2);
            editableModel2->setQl(sql);
            editableModel2->setR2(r2);
            createView(editableModel2);
            ui->btnDelete->setEnabled(true);
        }
    }
}

void AdmDialog::on_pushButton_clicked()
{
    if(!bFlg1 || !mfyrDlg->isVisible())
    {
        ui->tableView->hide();
        bFlg1 = true;
        mfyrDlg = new MfgYrDlg();
        mfyrDlg->show();
    }
}

void AdmDialog::on_pushButton_7_clicked()
{
    if(!bFlg2 || !expyrDlg->isVisible())
    {
        ui->tableView->hide();
        bFlg2 = true;
        expyrDlg = new ExpYrDlg();
        expyrDlg->show();
    }
}

void AdmDialog::on_pushButton_3_clicked()
{
    if(!bFlg3 || !mfgmonDlg->isVisible())
    {
        ui->tableView->hide();
        bFlg3 = true;
        mfgmonDlg = new MfgMonDlg();
        mfgmonDlg->show();
    }
}

void AdmDialog::on_pushButton_2_clicked()
{
    if(!bFlg4 || !expmonDlg->isVisible())
    {
        ui->tableView->hide();
        bFlg4 = true;
        expmonDlg = new ExpMonDlg();
        expmonDlg->show();
    }
}

void AdmDialog::on_pushButton_4_clicked()
{
    r3=0;
    r4=3;
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE");
    db1.setHostName("localhost");
    db1.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
    db1.setUserName("root");
    db1.setPassword("root");
    bool ok1 = db1.open();
    if (!ok1)
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db1.lastError().text());
      return;
    }
    sql2 = "select CID, category from MedCategories";
    QSqlQuery query(db1);
    query.prepare(sql2);
    query.exec();
    r3=query.size();
    editableModel3 = new EditableSqlModel8();
    initializeModel2(editableModel3);
    editableModel3->setQl(sql2);
    editableModel3->setR3(r3);
    createView(editableModel3);
    ui->btnDelete->setEnabled(true);
}

void AdmDialog::on_pushButton_5_clicked()
{
    if(!bFlg5 || !lstpresc->isVisible())
    {
        ui->tableView->hide();
        bFlg5 = true;
        lstpresc = new ListPrescription();
        lstpresc->show();
    }
}

void AdmDialog::on_pushButton_6_clicked()
{
    if(!bFlg6 || !lstcust->isVisible())
    {
        ui->tableView->hide();
        bFlg6 = true;
        lstcust = new ListCustomers();
        lstcust->show();
    }
}


void AdmDialog::on_pushButton_8_clicked()
{
    if(!bFlg7 || !addmed->isVisible())
    {
        ui->tableView->hide();
        bFlg7 = true;
        addmed = new AddMedicine();
        addmed->show();
    }
}

void AdmDialog::on_pushButton_9_clicked()
{
    if(!bFlg8 || !addcat->isVisible())
    {
        ui->tableView->hide();
        bFlg8 = true;
        addcat = new AddCat();
        addcat->show();
    }
}

void AdmDialog::on_pushButton_10_clicked()
{
    if(!bFlg9 || !srchmed->isVisible())
    {
        ui->tableView->hide();
        bFlg9 = true;
        srchmed = new SearchMed();
        srchmed->show();
    }
}

void AdmDialog::on_pushButton_11_clicked()
{
    if(!bFlg10 || !adddist->isVisible())
    {
        ui->tableView->hide();
        bFlg10 = true;
        adddist = new AddDist();
        adddist->show();
    }
}

void AdmDialog::on_pushButton_12_clicked()
{
    if(!bFlg11 || !srchdist->isVisible())
    {
        ui->tableView->hide();
        bFlg11 = true;
        srchdist = new SrchDistributor();
        srchdist->show();
    }
}

void AdmDialog::createView(QStandardItemModel *model4)
{
    ui->tableView->setModel(model4);
    ui->tableView->show();
}

void AdmDialog::on_btnDelete_clicked()
{
    QModelIndexList indexes = ui->tableView->selectionModel()->selectedRows();
    while (!indexes.isEmpty())
    {
        QModelIndex primaryKeyIndex = indexes.last();
        int id = 0;
        if(r4 == 1)
        {
            id = editableModel1->data(primaryKeyIndex).toInt();
        }
        else if(r4 == 2)
        {
            id = editableModel2->data(primaryKeyIndex).toInt();
        }
        else if(r4 == 3)
        {
            id = editableModel3->data(primaryKeyIndex).toInt();
        }
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("localhost");
        db.setDatabaseName("D:\\QT_551\\Test3\\onlmedicine.db");
        db.setUserName("root");
        db.setPassword("root");
        bool ok = db.open();
        if (!ok)
        {
          QMessageBox::critical(0, QObject::tr("Database Error"),
                    db.lastError().text());
          return;
        }
        QString s1 = "";
        if(r4 <= 2)
        {
            s1 = "delete from Medicines where id = ?";
        }
        else if(r4 == 3)
        {
            s1 = "delete from MedCategories where cid = ?";
        }

        QSqlQuery query(db);
        query.prepare(s1);
        query.addBindValue(id);
        query.exec();
        if(r4 == 1)
        {
            editableModel1->removeRows(indexes.last().row(), 1);
        }
        else if(r4 == 2)
        {
            editableModel2->removeRows(indexes.last().row(), 1);
        }
        else if(r4 == 3)
        {
            editableModel3->removeRows(indexes.last().row(), 1);
        }

        indexes.removeLast();
    }
    if(r4 == 1)
    {
        editableModel1->submit();
        createView(editableModel1);
        editableModel1->setMRl(r1);
    }
    else if(r4 == 2)
    {
        editableModel2->submit();
        createView(editableModel2);
        editableModel2->setR2(r2);
    }
    else if(r4 == 3)
    {
        editableModel3->submit();
        createView(editableModel3);
        editableModel3->setR3(r3);
    }
}
