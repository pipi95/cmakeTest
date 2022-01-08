#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QQmlEngine>
#include <QResource>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QString appPath = QCoreApplication::applicationDirPath();
    // load resources
    QString _qgcResource = appPath + "/untitled_1.dll";
    QString _qgcResource1 = appPath + "/untitled_1_assets.dll";
    bool qgcGroundResourceResult = QResource::registerResource(_qgcResource);
    qDebug().noquote() << _qgcResource << " regist " << (qgcGroundResourceResult ? "success." : "failed.");
    qgcGroundResourceResult = QResource::registerResource(_qgcResource1);
    qDebug().noquote() << _qgcResource1 << " regist " << (qgcGroundResourceResult ? "success." : "failed.");
    MainWindow w;
    auto engine = w.getEngine();
    engine->addImportPath("qrc:/inter");
    engine->addImportPath("qrc:/qml");
    w.show();
    return a.exec();
}
