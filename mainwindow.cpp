#include <QApplication>
#include <QScreen>
#include <QKeyEvent>
#include "mainwindow.h"

main_window::main_window( QApplication &app, QWidget *parent )
    : QMainWindow(parent), drawer(std::make_shared<png_drawer>())
{
    QScreen *scr = app.screenAt({0, 0});
    resize(scr->size());
    if (!toolkit.load("ex1.png"))
        throw "bad png";
    auto data = toolkit.getPixelData();
    drawer->load(data);
    setCentralWidget(drawer.get());

    QObject::connect(this, &main_window::needRedraw, drawer.get(), QOverload<>::of(&QWidget::update));
}

void main_window::keyPressEvent( QKeyEvent *event )
{
    switch (event->key())
    {
    case Qt::Key::Key_R:
        toolkit.fillHalfRed();
        emit needRedraw();
        break;
    case Qt::Key::Key_S:
        toolkit.save("changed.png");
        break;
    }
}

main_window::~main_window()
{

}
