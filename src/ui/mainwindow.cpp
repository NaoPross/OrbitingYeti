#include "debugtools.h"

#include "ui/metadatadialog.h"
#include "ui/statementdialog.h"
#include "ui/mainwindow.h"
#include "ui_mainwindow.h"

#include "diagram/statement.h"

#include <iostream>

#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(samb::Structogram *structogram, QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _structogram(structogram)
{
    _ui->setupUi(this);
    _ui->painter->structogram(&_structogram);

    toolButtonsEnabled((_structogram != nullptr));
}

MainWindow::~MainWindow()
{
    delete _ui;
}

/**** private slots ****/

void MainWindow::on_newButton_clicked()
{
    if (_structogram != nullptr)
        if (!askSaveDialog())
            return;

    delete _structogram;
    _structogram = nullptr;

    MetadataDialog *dialog = new MetadataDialog(this);
    if (dialog->exec() == QDialog::Accepted) {
        _structogram = new samb::Structogram(dialog->title(), dialog->author());
        toolButtonsEnabled(true);
    } else {
        toolButtonsEnabled(false);
    }

    delete dialog;
}

void MainWindow::on_openButton_clicked()
{
    if (_structogram != nullptr)
        if (!askSaveDialog())
            return;

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Load diagram"), "", tr("NS Diagram (*.nsdg);;All Files (*)"));

    if (fileName.isEmpty())
        return;

    debug_err("load dialog is unimplemented");

    // toolButtonsEnabled(true);
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save diagram"), "", tr("NS Diagram (*.nsdg);;All Files (*)"));

    if (fileName.isEmpty())
        return;

    debug_err("saved dialog is unimplemented");

    // toolButtonsEnabled(true);
}

void MainWindow::on_refreshButton_clicked()
{

}

void MainWindow::on_metadataButton_clicked()
{
    if (_structogram == nullptr)
        return;

    MetadataDialog dialog(this);
    dialog.setMetadata(_structogram->title(), _structogram->author());

    if (dialog.exec() == QDialog::Accepted) {
        _structogram->title(dialog.title());
        _structogram->author(dialog.author());
    }
}

void MainWindow::on_newStatementButton_clicked()
{
    if (_structogram == nullptr)
        return;

    StatementDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {

    }
}

/**** private methods ****/

/* @brief open a save dialog
 * @return true if operation completed successfully
 */
bool MainWindow::askSaveDialog()
{
    // TODO: check if it has already been saved once
    auto reply = QMessageBox::question(this,
                                       "Save " + _structogram->title(),
                                       "'" + _structogram->title() + "' is not saved.\nDo you want to save it?",
                                       QMessageBox::Save, QMessageBox::Discard);

    if (reply == QMessageBox::Save) {
        on_saveButton_clicked();

        // TODO: check if file has been ACTUALLY saved
        return true;
    } else {
        return true;
    }

}

/* @brief control ui elements that are relate to _structogram member
 */
void MainWindow::toolButtonsEnabled(bool state)
{
    if (_structogram == nullptr && state == true) {
        debug_err("called enableToolButtons(true) but _structogram is nullptr");
        return;
    }

    // buttons
    _ui->refreshButton->setEnabled(state);
    _ui->metadataButton->setEnabled(state);
    _ui->newStatementButton->setEnabled(state);

    // actions
    _ui->actionSave->setEnabled(state);
    _ui->actionSaveAs->setEnabled(state);
    _ui->actionClose->setEnabled(state);
}
