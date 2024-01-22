QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dao/admindao.cpp \
    dao/admindaoimpl.cpp \
    dao/cinemadao.cpp \
    dao/cinemadaoimpl.cpp \
    dao/commentdao.cpp \
    dao/commentdaoimpl.cpp \
    dao/filmdao.cpp \
    dao/filmdaoimpl.cpp \
    dao/screendao.cpp \
    dao/screendaoimpl.cpp \
    dao/sessiondao.cpp \
    dao/sessiondaoimpl.cpp \
    dao/ticketdao.cpp \
    dao/ticketdaoimpl.cpp \
    dao/userdao.cpp \
    dao/userdaoimpl.cpp \
    dbutil/dbutil.cpp \
    entity/admin.cpp \
    entity/cinema.cpp \
    entity/comment.cpp \
    entity/film.cpp \
    entity/screen.cpp \
    entity/session.cpp \
    entity/ticket.cpp \
    entity/user.cpp \
    form/commentwidget.cpp \
    form/filmwidget.cpp \
    form/formbuyticket.cpp \
    form/formlogin.cpp \
    form/formselectseat.cpp \
    form/formsessionmanage.cpp \
    form/mainwindowadmin.cpp \
    form/mainwindowuser.cpp \
    form/mybutton.cpp \
    form/seatwidget.cpp \
    main.cpp \
    service/adminservice.cpp \
    service/adminserviceimpl.cpp \
    service/cinemaservice.cpp \
    service/cinemaserviceimpl.cpp \
    service/commentservice.cpp \
    service/commentserviceimpl.cpp \
    service/filmservice.cpp \
    service/filmserviceimpl.cpp \
    service/screenservice.cpp \
    service/screenserviceimpl.cpp \
    service/sessionservice.cpp \
    service/sessionserviceimpl.cpp \
    service/ticketservice.cpp \
    service/ticketserviceimpl.cpp \
    service/userservice.cpp \
    service/userserviceimpl.cpp \

HEADERS += \
    dao/admindao.h \
    dao/admindaoimpl.h \
    dao/cinemadao.h \
    dao/cinemadaoimpl.h \
    dao/commentdao.h \
    dao/commentdaoimpl.h \
    dao/filmdao.h \
    dao/filmdaoimpl.h \
    dao/screendao.h \
    dao/screendaoimpl.h \
    dao/sessiondao.h \
    dao/sessiondaoimpl.h \
    dao/ticketdao.h \
    dao/ticketdaoimpl.h \
    dao/userdao.h \
    dao/userdaoimpl.h \
    dbutil/dbutil.h \
    entity/admin.h \
    entity/cinema.h \
    entity/comment.h \
    entity/film.h \
    entity/screen.h \
    entity/session.h \
    entity/ticket.h \
    entity/user.h \
    form/commentwidget.h \
    form/filmwidget.h \
    form/formbuyticket.h \
    form/formlogin.h \
    form/formselectseat.h \
    form/formsessionmanage.h \
    form/mainwindowadmin.h \
    form/mainwindowuser.h \
    form/mybutton.h \
    form/seatwidget.h \
    service/adminservice.h \
    service/adminserviceimpl.h \
    service/cinemaservice.h \
    service/cinemaserviceimpl.h \
    service/commentservice.h \
    service/commentserviceimpl.h \
    service/filmservice.h \
    service/filmserviceimpl.h \
    service/screenservice.h \
    service/screenserviceimpl.h \
    service/sessionservice.h \
    service/sessionserviceimpl.h \
    service/ticketservice.h \
    service/ticketserviceimpl.h \
    service/userservice.h \
    service/userserviceimpl.h \

FORMS += \
    form/commentwidget.ui \
    form/filmwidget.ui \
    form/formbuyticket.ui \
    form/formlogin.ui \
    form/formselectseat.ui \
    form/formsessionmanage.ui \
    form/mainwindowadmin.ui \
    form/mainwindowuser.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RECOURSE.qrc

