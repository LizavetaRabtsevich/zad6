#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), canvas(new Canvas(this))
{
    setCentralWidget(canvas);

    QMenu *fileMenu = menuBar()->addMenu("Файл");
    QAction *saveAct = fileMenu->addAction("Сохранить");
    QAction *loadAct = fileMenu->addAction("Загрузить");
    QMenu *colorMenu = menuBar()->addMenu("Цвет");
    QAction *colorAct = colorMenu->addAction("Выбрать цвет");
    QAction *undoAct = fileMenu->addAction("Отменить последний");
    QMenu *drawMenu = menuBar()->addMenu("Рисовать");
    QAction *lineAct = drawMenu->addAction("Линия");
    QAction *rectAct = drawMenu->addAction("Прямоугольник");
    QAction *circleAct = drawMenu->addAction("Круг");
    QAction *triangleAct = drawMenu->addAction("Треугольник");

    connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);
    connect(loadAct, &QAction::triggered, this, &MainWindow::loadFile);
    connect(lineAct, &QAction::triggered, this, &MainWindow::drawLine);
    connect(rectAct, &QAction::triggered, this, &MainWindow::drawRect);
    connect(circleAct, &QAction::triggered, this, &MainWindow::drawCircle);
    connect(triangleAct, &QAction::triggered, this, &MainWindow::drawTriangle);
    connect(undoAct, &QAction::triggered, this, &MainWindow::undoLastShape);
    connect(colorAct, &QAction::triggered, this, &MainWindow::chooseColor);
}

void MainWindow::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "*.vec");
    if (!fileName.isEmpty()) {
        canvas->saveToFile(fileName);
    }
}

void MainWindow::loadFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "*.vec");
    if (!fileName.isEmpty()) {
        canvas->loadFromFile(fileName);
    }
}

void MainWindow::drawLine() {
    canvas->setMode(Canvas::DrawLine);
}

void MainWindow::drawRect() {
    canvas->setMode(Canvas::DrawRect);
}

void MainWindow::drawCircle() {
    canvas->setMode(Canvas::DrawCircle);
}

void MainWindow::drawTriangle() {
    canvas->setMode(Canvas::DrawTriangle);
}

void MainWindow::chooseColor() {
    QColor color = QColorDialog::getColor(Qt::black, this, "Выберите цвет");
    if (color.isValid()) {
        canvas->setCurrentColor(color);
    }
}

void MainWindow::undoLastShape() {
    canvas->undoLastShape();
}


