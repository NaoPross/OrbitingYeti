#include "ui/mainwindow.h"
#include "ui_mainwindow.h"

#include "ui/metadatadialog.h"

#include <iostream>

MainWindow::MainWindow(samb::Structogram *structogram, QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _structogram(structogram)
{
    _ui->setupUi(this);
    initData();
}

MainWindow::~MainWindow()
{
    delete _ui;
}

/**** private slots ****/

void MainWindow::on_newButton_clicked()
{
    if (_structogram != nullptr)
    {
        // TODO: implement save dialog
        std::cout << "TODO: implement save dialog" << std::endl;

        delete _structogram;
        _structogram = nullptr;
    }

    MetadataDialog *dialog = new MetadataDialog(this);
    if (dialog->exec() == QDialog::Accepted)
    {
        _structogram = new samb::Structogram(dialog->title(), dialog->author());
    }

    delete dialog;
}

void MainWindow::on_metadataButton_clicked()
{
    if (_structogram == nullptr) { return; }

    MetadataDialog *dialog = new MetadataDialog(this);
    dialog->setMetadata(_structogram->title(), _structogram->author());

    if (dialog->exec() == QDialog::Accepted)
    {
        _structogram->title(dialog->title());
        _structogram->author(dialog->author());
    }
}

/**** private methods ****/

void MainWindow::initData()
{
    if (_structogram == nullptr)
    {
        _structogram = new samb::Structogram("", "");
    }
}
