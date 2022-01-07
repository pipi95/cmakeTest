#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QResource>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QString appPath = QCoreApplication::applicationDirPath();
    // load resources
    QString _qgcResource = appPath + "/untitled_1.dll";
    QString _qgcResource1 = appPath + "/untitled_1_assets.dll";
    bool qgcGroundResourceResult = QResource::registerResource(_qgcResource);
    qDebug().noquote() << QString("%1 regist %2.").arg(_qgcResource).arg(qgcGroundResourceResult ? "success" : "failed");
    qgcGroundResourceResult = QResource::registerResource(_qgcResource1);
    qDebug().noquote() << QString("%1 regist %2.").arg(_qgcResource1).arg(qgcGroundResourceResult ? "success" : "failed");
    MainWindow w;
    w.show();
    return a.exec();
}
