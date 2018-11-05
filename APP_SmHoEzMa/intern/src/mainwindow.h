#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainview.h"

#include <QApplication>
#include <QMainWindow>
#include <QQmlApplicationEngine>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    CMainView* m_pMainView;
};

#endif // MAINWINDOW_H
