#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Gml.h"
#include <QMainWindow>

struct ui;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ImportGml_Slot();

private:
    void NewGmlPage(const QString &gmlText);

private:
    struct ui *m_ui;
    Gml *m_gml;
};

#endif // MAINWINDOW_H
