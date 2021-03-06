QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agradecimentos.cpp \
    cadastro.cpp \
    editar.cpp \
    main.cpp \
    mainwindow.cpp \
    produtos.cpp \
    relatorio_de_produtos.cpp \
    sobre.cpp

HEADERS += \
    agradecimentos.h \
    cadastro.h \
    editar.h \
    mainwindow.h \
    produtos.h \
    relatorio_de_produtos.h \
    sobre.h

FORMS += \
    agradecimentos.ui \
    cadastro.ui \
    editar.ui \
    mainwindow.ui \
    relatorio_de_produtos.ui \
    sobre.ui

TRANSLATIONS += \
    Teste_Taylor_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Arquivos_de_Recursos.qrc
