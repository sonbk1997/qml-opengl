QT += qml quick

HEADERS += fboinsgrenderer.h \
    logorenderer.h
SOURCES += fboinsgrenderer.cpp \
    logorenderer.cpp \
    main.cpp

RESOURCES += fboitem.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/scenegraph/fboitem
INSTALLS += target

OTHER_FILES += \
    main.qml
