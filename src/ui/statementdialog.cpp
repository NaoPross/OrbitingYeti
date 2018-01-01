#include "include/ui/statementdialog.h"
#include "ui_statementdialog.h"

StatementDialog::StatementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatementDialog)
{
    ui->setupUi(this);
}

StatementDialog::~StatementDialog()
{
    delete ui;
}
