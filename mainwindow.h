#pragma once

#include <QMainWindow>
#include "canvas.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void saveFile();
    void loadFile();
    void drawLine();
    void drawRect();
    void drawCircle();
    void drawTriangle();
    void chooseColor();
    void undoLastShape();
private:
    Canvas *canvas;
};
