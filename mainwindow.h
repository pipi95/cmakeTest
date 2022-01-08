#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Untitled_lib1;
class QQmlEngine;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    QQmlEngine* getEngine() const;

private:
    Ui::MainWindow* ui;
    Untitled_lib1* lib = nullptr;
    QQmlEngine* engine = nullptr;
};
#endif // MAINWINDOW_H
