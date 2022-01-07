#include "mainwindow.h"
#include "./ui_mainwindow.h"

//#include "untitled_lib1/untitled_lib1.h"

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
    connect(ui->pushButton, &QPushButton::clicked, this, [tempLib]() {
        tempLib->test();
    });
    ui->quickWidget->setSource(QUrl("qrc:/qml/qml/test1.qml"));
}

MainWindow::~MainWindow()
{
    delete lib;
    delete ui;
}
