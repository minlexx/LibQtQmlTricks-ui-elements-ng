
#include "QtQmlTricks.h"

#include "QQuickColumnContainer.h"
#include "QQuickContainerAttachedObject.h"
#include "QQuickExtraAnchors.h"
#include "QQuickGridContainer.h"
#include "QQuickRowContainer.h"
#include "QQuickFastObjectListView.h"
#include "QQmlFastObjectListModel.h"
#include "QQmlContainerEnums.h"
#include "QQmlObjectListModel.h"

#include <qqml.h>

void QtQmlTricks::registerComponents (void) {
    qmlRegisterType<QQuickColumnContainer>                    ("QtQmlTricks", 3, 0, "ColumnContainer");
    qmlRegisterType<QQuickGridContainer>                      ("QtQmlTricks", 3, 0, "GridContainer");
    qmlRegisterType<QQuickRowContainer>                       ("QtQmlTricks", 3, 0, "RowContainer");
    qmlRegisterType<QQuickFastObjectListView>                 ("QtQmlTricks", 3, 0, "FastObjectListView");
    qmlRegisterUncreatableType<VerticalDirections>            ("QtQmlTricks", 3, 0, "VerticalDirections",   "Enum-class !");
    qmlRegisterUncreatableType<HorizontalDirections>          ("QtQmlTricks", 3, 0, "HorizontalDirections", "Enum-class !");
    qmlRegisterUncreatableType<FlowDirections>                ("QtQmlTricks", 3, 0, "FlowDirections",       "Enum-class !");
    qmlRegisterUncreatableType<QQuickExtraAnchors>            ("QtQmlTricks", 3, 0, "ExtraAnchors",         "Attached-object class !");
    qmlRegisterUncreatableType<QQuickContainerAttachedObject> ("QtQmlTricks", 3, 0, "Container",            "Attached-object class !");
    qmlRegisterUncreatableType<QQmlObjectListModelBase>       ("QtQmlTricks", 3, 0, "ObjectListModel",      "Abstract base class !");
    qmlRegisterUncreatableType<QQmlFastObjectListModelBase>   ("QtQmlTricks", 3, 0, "FastObjectListModel",  "Abstract base class !");
}
