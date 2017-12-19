#include "ui/metadatadialog.h"
#include "ui_metadatadialog.h"

MetadataDialog::MetadataDialog(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::MetadataDialog)
{
    _ui->setupUi(this);
}

MetadataDialog::~MetadataDialog()
{
    delete _ui;
}

void MetadataDialog::setMetadata(const QString& title, const QString& author)
{
    _ui->titleEdit->setText(title);
    _ui->authorEdit->setText(author);
}


QString MetadataDialog::title() const
{
    return _ui->titleEdit->text();
}

QString MetadataDialog::author() const
{
    return _ui->authorEdit->text();
}
