mac:DEFINES += USE_FILE32API

# Uncomment this to disable encryption support
# DEFINES += NOUNCRYPT

include(3rdparty/zlib.pri)

HEADERS += \
    $$PWD/qzipfile.h \
    $$PWD/qzipfileentry.h

SOURCES += \
    $$PWD/qzipfile.cpp \
    $$PWD/qzipfileentry.cpp 
