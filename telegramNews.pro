QT += charts sql
requires(qtConfig(combobox))

HEADERS += \
    mainPage.h \
    newsone.h \
    login.h \
    signUp.h

SOURCES += \
    main.cpp \
    mainPage.cpp \
    newsone.cpp \
    login.cpp \
    signUp.cpp

INSTALLS += target

FORMS += \
    telegramNews.ui \
    newsone.ui \
    login.ui \
    signUp.ui
