#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Untitled_lib1;

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

private:
    Ui::MainWindow* ui;
    Untitled_lib1* lib = nullptr;
};
#endif // MAINWINDOW_H
