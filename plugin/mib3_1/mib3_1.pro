# include global settings for all DLT Viewer Plugins
include( ../plugin.pri )

# Put intermediate files in the build directory
MOC_DIR     = build/moc
OBJECTS_DIR = build/obj
RCC_DIR     = build/rcc
UI_DIR      = build/ui

# target name
TARGET = $$qtLibraryTarget(mib3_1)

# plugin header files
HEADERS += \
    mib3_1.h \
    form.h

# plugin source files
SOURCES += \
    mib3_1.cpp \
    form.cpp

FORMS += \
    form.ui



