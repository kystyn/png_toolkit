#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include "png_drawer.h"

class main_window : public QMainWindow
{
    Q_OBJECT

public:
    main_window( QApplication &app, QWidget *parent = nullptr );
    void keyPressEvent( QKeyEvent *event ) override;
    ~main_window();

signals:
    void needRedraw( void );

private:
    png_toolkit toolkit;
    std::shared_ptr<png_drawer> drawer;
};

#endif // MAINWINDOW_H
