#-------------------------------------------------
#
# Project created by QtCreator 2016-11-06T16:47:01
#
#-------------------------------------------------

QT       += core gui\
         sql

QTPLUGIN += QMYSQL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    secdialog.cpp \
    register.cpp \
    mfgyrdlg.cpp \
    expyrdlg.cpp \
    mfgmondlg.cpp \
    expmondlg.cpp \
    listprescription.cpp \
    listcustomers.cpp \
    frogotpwd.cpp \
    resetpwd.cpp \
    admdialog.cpp \
    addmedicine.cpp \
    addcat.cpp \
    searchmed.cpp \
    adddist.cpp \
    srchdistributor.cpp \
    editablesqlmodel.cpp \
    eitablesqlmodel1.cpp \
    editablesqlmodel2.cpp \
    editablesqlmodel3.cpp \
    editablesqlmodel4.cpp \
    editablesqlmodel5.cpp \
    editablesqlmodel6.cpp \
    editablesqlmodel7.cpp \
    editablesqlmodel8.cpp

HEADERS  += mainwindow.h \
    secdialog.h \
    register.h \
    mfgyrdlg.h \
    expyrdlg.h \
    mfgmondlg.h \
    expmondlg.h \
    listprescription.h \
    listcustomers.h \
    frogotpwd.h \
    resetpwd.h \
    admdialog.h \
    addmedicine.h \
    addcat.h \
    searchmed.h \
    adddist.h \
    srchdistributor.h \
    editablesqlmodel.h \
    editablesqlmodel1.h \
    editablesqlmodel2.h \
    editablesqlmodel3.h \
    editablesqlmodel4.h \
    editablesqlmodel5.h \
    editablesqlmodel6.h \
    editablesqlmodel7.h \
    editablesqlmodel8.h

FORMS    += mainwindow.ui \
    secdialog.ui \
    register.ui \
    mfgyrdlg.ui \
    expyrdlg.ui \
    mfgmondlg.ui \
    expmondlg.ui \
    listprescription.ui \
    listcustomers.ui \
    frogotpwd.ui \
    resetpwd.ui \
    admdialog.ui \
    addmedicine.ui \
    addcat.ui \
    searchmed.ui \
    adddist.ui \
    srchdistributor.ui
