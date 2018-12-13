
QT += core gui qml quick

INCLUDEPATH += \
    $$PWD \
    $$PWD/core/macros \
    $$PWD/core/models \
    $$PWD/gui/containers \
    $$PWD/gui/helpers

HEADERS += \
    $$PWD/core/macros/QmlEnumHelpers.h \
    $$PWD/core/macros/QmlPropertyHelpers.h \
    $$PWD/core/models/QQmlFastObjectListModel.h \
    $$PWD/core/models/QQmlObjectListModel.h \
    $$PWD/gui/containers/QQmlContainerEnums.h \
    $$PWD/gui/containers/QQuickAbstractContainerBase.h \
    $$PWD/gui/containers/QQuickColumnContainer.h \
    $$PWD/gui/containers/QQuickContainerAttachedObject.h \
    $$PWD/gui/containers/QQuickFastObjectListView.h \
    $$PWD/gui/containers/QQuickGridContainer.h \
    $$PWD/gui/containers/QQuickRowContainer.h \
    $$PWD/gui/helpers/QQuickExtraAnchors.h \
    $$PWD/QtQmlTricks.h

SOURCES += \
    $$PWD/gui/containers/QQuickAbstractContainerBase.cpp \
    $$PWD/gui/containers/QQuickColumnContainer.cpp \
    $$PWD/gui/containers/QQuickContainerAttachedObject.cpp \
    $$PWD/gui/containers/QQuickFastObjectListView.cpp \
    $$PWD/gui/containers/QQuickGridContainer.cpp \
    $$PWD/gui/containers/QQuickRowContainer.cpp \
    $$PWD/gui/helpers/QQuickExtraAnchors.cpp \
    $$PWD/QtQmlTricks.cpp
