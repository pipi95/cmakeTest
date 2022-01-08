#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QQmlEngine>

#include "untitled_lib1.h"

#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    menuBar()->addAction("test");
    connect(menuBar()->actions().constFirst(), &QAction::triggered, this, []() {
        qDebug() << "test";
    });
    lib = new Untitled_lib1;
    auto tempLib = lib;
    engine = ui->quickWidget->engine();
    auto quick = ui->quickWidget;
    connect(ui->pushButton, &QPushButton::clicked, this, [tempLib, quick]() {
        tempLib->test();
        quick->setSource(QUrl("qrc:/inter/another.qml"));
    });
    ui->quickWidget->setSource(QUrl("qrc:/qml/test1.qml"));
}

MainWindow::~MainWindow()
{
    delete lib;
    delete ui;
}

QQmlEngine* MainWindow::getEngine() const
{
    return engine;
}
