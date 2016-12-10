#include "frogotpwd.h"
#include "ui_frogotpwd.h"

FrogotPwd::FrogotPwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrogotPwd)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->edtGo->setStyleSheet("background-color: rgb(255,237,208)");
    bFlg = false;
}

FrogotPwd::~FrogotPwd()
{
    delete ui;
}

void FrogotPwd::on_edtGo_clicked()
{
    QString em = ui->edtEmail->text();
    if(!em.isEmpty())
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
          return;
        }
        QSqlQuery query(db);
        query.prepare(QString("select stemail from CustomerReg where stemail = :stemail"));
        query.bindValue(":stemail", em);
        query.exec();
        if (query.size()!=0)
        {
            if(!bFlg || !respwd->isVisible())
            {
                bFlg = true;
                respwd = new ResetPwd(NULL,em);
                respwd->show();
            }
        }
        else
        {
            QMessageBox::warning(this,"Forgot Pwd", "Email does not exist!");
        }
    }
    else
    {
        QMessageBox::warning(this,"Forgot Pwd", "Please enter email");
    }
}
