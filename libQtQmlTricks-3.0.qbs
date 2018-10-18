import qbs;

Product {
    name: "lib_qt_qml_tricks_ng";
    type: "staticlibrary";
    cpp.cxxLanguageVersion: "c++11";
    cpp.includePaths: [
        ".",
        "core",
        "core/macros",
        "core/models",
        "gui",
        "gui/containers",
        "gui/helpers",
    ]

    Export {
        cpp.cxxLanguageVersion: "c++11";
        cpp.includePaths: [
            ".",
            "./core",
            "./core/macros",
            "./core/models",
            "./gui",
            "./gui/containers",
            "./gui/helpers",
        ]

        Depends {
            name: "Qt";
            submodules: ["core", "gui", "qml", "quick", "svg"];
        }
        Depends {
            name: "cpp";
        }
    }
    Depends {
        name: "Qt";
        submodules: ["core", "gui", "qml", "quick", "svg"];
    }
    Depends {
        name: "cpp";
    }
    Group {
        name: "C++";
        files: [
            "QtQmlTricks.cpp",
            "QtQmlTricks.h",
            "core/macros/QmlEnumHelpers.h",
            "core/macros/QmlPropertyHelpers.h",
            "core/models/QQmlObjectListModel.h",
            "gui/containers/QQmlContainerEnums.h",
            "gui/containers/QQuickAbstractContainerBase.cpp",
            "gui/containers/QQuickAbstractContainerBase.h",
            "gui/containers/QQuickColumnContainer.cpp",
            "gui/containers/QQuickColumnContainer.h",
            "gui/containers/QQuickContainerAttachedObject.cpp",
            "gui/containers/QQuickContainerAttachedObject.h",
            "gui/containers/QQuickGridContainer.cpp",
            "gui/containers/QQuickGridContainer.h",
            "gui/containers/QQuickRowContainer.cpp",
            "gui/containers/QQuickRowContainer.h",
            "gui/helpers/QQuickExtraAnchors.cpp",
            "gui/helpers/QQuickExtraAnchors.h",
        ]
    }
    Group {
        name: "Markdown";
        files: [
            "LICENSE.md",
            "README.md",
        ]
    }
}
