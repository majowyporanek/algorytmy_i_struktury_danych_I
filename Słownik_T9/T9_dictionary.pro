QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../Pulpit/algorytmy_i_struktury_danych_2022/slownik_t9/LinkedList.h \
    ../Pulpit/algorytmy_i_struktury_danych_2022/slownik_t9/PrefixTree.h \
    ../Pulpit/algorytmy_i_struktury_danych_2022/slownik_t9/SlownikT9.h \
    LinkedList.h \
    PrefixTree.h \
    SlowniikT9.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../Pulpit/algorytmy_i_struktury_danych_2022/slownik_t9/words.txt \
    slowa.txt \
    words.txt
