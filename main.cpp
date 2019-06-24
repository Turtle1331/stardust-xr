#include <QtCore/QUrl>
#include <QtCore/QDebug>

#include <QtGui/QGuiApplication>

#include <QtQml/QQmlApplicationEngine>

#include "core/launcher.h"
#include "core/fileio.h"

#include "core/prefs.h"
#include "core/extensionloader.h"

#include "keyboard/physicalkeyboardadapter.h"
#include "keyboard/waylandkeyboardhandler.h"

int main(int argc, char *argv[])
{
    // ShareOpenGLContexts is needed for using the threaded renderer
    // on Nvidia EGLStreams
    QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts, true);
    QGuiApplication app(argc, argv);


    qmlRegisterType<Launcher>("Launcher", 1, 0, "Launcher");
    qmlRegisterType<FileIO>("FileIO", 1, 0, "FileIO");

    qmlRegisterType<Prefs>("Preferences", 1, 0, "Preferences");
    qmlRegisterType<ExtensionLoader>("ExtensionLoader", 1, 0, "ExtensionLoader");

    qmlRegisterType<PhysicalKeyboardAdapter>("PhysicalKeyboardAdapter", 1, 0, "PhysicalKeyboardAdapter");
    qmlRegisterType<WaylandKeyboardHandler>("WaylandKeyboardHandler", 1, 0, "WaylandKeyboardHandler");


    QQmlApplicationEngine appEngine(QUrl("qrc:/core/main.qml"));

    return app.exec();
}
