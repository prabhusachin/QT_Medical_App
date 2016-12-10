#include "secdialog.h"
#include "ui_secdialog.h"

secDialog::secDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDialog)
{
    ui->setupUi(this);
    this->setModal(true);
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

    ui->pushButton->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_2->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_3->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_4->setStyleSheet("background-color: rgb(255,237,208)");
    ui->pushButton_7->setStyleSheet("background-color: rgb(255,237,208)");
    ui->btnSimp->setStyleSheet("background-color: rgb(255,237,208)");
    ui->btnAdv->setStyleSheet("background-color: rgb(255,237,208)");
}

secDialog::~secDialog()
{
    delete ui;
}

void secDialog::on_radioButton_clicked()
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

void secDialog::on_radioButton_2_clicked()
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

void secDialog::on_btnSimp_clicked()
{
    QString keywd = ui->edtSimp->text();
    if(keywd.isEmpty())
    {
        QMessageBox::warning(this,"Search", "Please enter keyword");
        return;
    }
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
            QString sql = "SELECT * FROM Medicines WHERE Name LIKE '%"+keywd+"%'";
            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(sql, db);
            ui->tableView->setModel(model);
            ui->tableView->show();
        }
    }
}

void secDialog::on_btnAdv_clicked()
{
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
            QString sql = "";
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
            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(sql, db);
            ui->tableView->setModel(model);
            ui->tableView->show();
        }
    }
}

void secDialog::on_pushButton_clicked()
{
    if(!bFlg1 || !mfyrDlg->isVisible())
    {
        ui->tableView->hide();
        bFlg1 = true;
        mfyrDlg = new MfgYrDlg();
        mfyrDlg->show();
    }
}

void secDialog::on_pushButton_7_clicked()
{
    if(!bFlg2 || !expyrDlg->isVisible())
    {
        ui->tableView->hide();
        bFlg2 = true;
        expyrDlg = new ExpYrDlg();
        expyrDlg->show();
    }
}

void secDialog::on_pushButton_3_clicked()
{
    if(!bFlg3 || !mfgmonDlg->isVisible())
    {
        ui->tableView->hide();
        bFlg3 = true;
        mfgmonDlg = new MfgMonDlg();
        mfgmonDlg->show();
    }
}

void secDialog::on_pushButton_2_clicked()
{
    if(!bFlg4 || !expmonDlg->isVisible())
    {
        ui->tableView->hide();
        bFlg4 = true;
        expmonDlg = new ExpMonDlg();
        expmonDlg->show();
    }
}

void secDialog::on_pushButton_4_clicked()
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
        QString sql = "select category from MedCategories";
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(sql, db);
        ui->tableView->setModel(model);
        ui->tableView->show();
    }
}

