#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "diagram/structogram.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(samb::Structogram *structogram = nullptr, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newButton_clicked();
    void on_openButton_clicked();
    void on_saveButton_clicked();

    void on_refreshButton_clicked();
    void on_metadataButton_clicked();
    void on_newStatementButton_clicked();

private:
    Ui::MainWindow *_ui;
    samb::Structogram *_structogram;

    bool askSaveDialog();
    void toolButtonsEnabled(bool state);
};

#endif // MAINWINDOW_H
