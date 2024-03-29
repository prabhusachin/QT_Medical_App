#include "register.h"
#include "ui_register.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setModal(true);
    ui->btnReg->setStyleSheet("background-color: rgb(255,237,208)");
    ui->radMale->setChecked(true);
    ui->edtMob->setMaxLength(10);
    ui->edtMob->setValidator( new QIntValidator);
    ui->edtAge->setValidator( new QIntValidator(0, 150));
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::Emptychk(QString prm, QString prm1)
{
    if(prm.isEmpty())
    {
        QMessageBox::warning(this,"Register", "Please enter "+prm1);
        return true;
    }
    else
        return false;
}

void Dialog::on_btnReg_clicked()
{
    QString fname = ui->edtFname->text();
    QString mname = ui->edtMname->text();
    QString lname = ui->edtLname->text();
    QString cemail = ui->edtEmail->text();
    QString gend = "";
    if(ui->radMale->isChecked())
    {
        gend = "Male";
    }
    else if(ui->radFemale->isChecked())
    {
        gend = "Female";
    }
    QString pwd = ui->edtPswd->text();
    QString cpwd = ui->edtCpswd->text();
    QString mob = ui->edtMob->text();
    QString age = ui->edtAge->text();
    QString addr = ui->tedtAddr->toPlainText();
    if(Emptychk(fname, "first name"))
    {
        return;
    }
    else if(Emptychk(mname, "middle name"))
    {
        return;
    }
    else if(Emptychk(lname, "last name"))
    {
        return;
    }
    else if(Emptychk(cemail, "email"))
    {
        return;
    }
    else if(Emptychk(pwd, "password"))
    {
        return;
    }
    else if(Emptychk(cpwd, "confirm password"))
    {
        return;
    }
    else if(pwd != cpwd)
    {
        QMessageBox::warning(this,"Register", "Password & confirm password must be same");
        return;
    }
    else if(Emptychk(mob, "mobile"))
    {
        return;
    }    
    else if(Emptychk(age, "age"))
    {
        return;
    }
    else if(Emptychk(addr, "address"))
    {
        return;
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
    }
    else
    {
        QSqlQuery query(db);
        query.prepare(QString("insert into CustomerReg (stuname,stmname,stlname,stemail,stgender,stpass,stcpass,stmobile,stage,staddress) values(:stuname,:stmname,:stlname,:stemail,:stgender,:stpass,:stcpass,:stmobile,:stage,:staddress)"));
        query.bindValue(":stuname", fname);
        query.bindValue(":stmname", mname);
        query.bindValue(":stlname", lname);
        query.bindValue(":stemail", cemail);
        query.bindValue(":stgender", gend);
        query.bindValue(":stpass", pwd);
        query.bindValue(":stcpass", cpwd);
        query.bindValue(":stmobile", mob);
        query.bindValue(":stage", age);
        query.bindValue(":staddress", addr);
        if(query.exec())
        {
            ui->lblRegStat->setText("Customer has successfully registered");
        }
        else
        {
            ui->lblRegStat->setText("Error registering customer");
        }
    }
}

bool Dialog::validaEmail(QString demail)
{
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);
    return mailREX.exactMatch(demail);
}

