TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Correc_Prof/game.cpp \
    Correc_Prof/gridmanagement.cpp \
    main.cpp \
    Nos_fichiers/matrice.cpp \
    Nos_fichiers/jeu.cpp \
    Nos_fichiers/troudever.cpp \
    Nos_fichiers/mur.cpp \
    Nos_fichiers/boost.cpp \
    Nos_fichiers/menutours.cpp \
    Nos_fichiers/doubletour.cpp \
    Nos_fichiers/menuprincipal.cpp \
    Nos_fichiers/deplacement.cpp \
    Nos_fichiers/configuration.cpp \
    Nos_fichiers/didacticiel.cpp \
    Nos_fichiers/modenoncanonique.cpp \

DISTFILES += \
    Nos_fichiers/config.yaml

HEADERS += \
    Correc_Prof/game.h \
    Correc_Prof/gridmanagement.h \
    Correc_Prof/params.h \
    Correc_Prof/type.h \
    Nos_fichiers/matrice.h \
    Nos_fichiers/jeu.h \
    Nos_fichiers/troudever.h \
    Nos_fichiers/mur.h \
    Nos_fichiers/boost.h \
    Nos_fichiers/menutours.h \
    Nos_fichiers/doubletour.h \
    Nos_fichiers/menuprincipal.h \
    Nos_fichiers/deplacement.h \
    Nos_fichiers/configuration.h \
    Nos_fichiers/didacticiel.h \
    Nos_fichiers/modenoncanonique.h \
