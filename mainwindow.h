#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <paletacores.h>
#include <QTimer>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void update();
    void clicado();
private:
    Ui::MainWindow *ui;
    PaletaCores paletaColorida;
    QTimer *relogio;
};

#endif // MAINWINDOW_H
