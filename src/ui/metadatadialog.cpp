#include "ui/metadatadialog.h"
#include "ui_metadatadialog.h"

#include "debugtools.h"
#include <QPushButton>

MetadataDialog::MetadataDialog(QWidget *parent) :
    QDialog(parent),
    _ui(new Ui::MetadataDialog)
{
    _ui->setupUi(this);

    QPushButton *button = _ui->buttonBox->button(QDialogButtonBox::Ok);

    if (button != 0) {
        button->setEnabled(false);
    } else {
        debug_err("failed to get ok button");
    }
}

MetadataDialog::~MetadataDialog()
{
    delete _ui;
}

/*** public methods ***/

bool MetadataDialog::isValid() const
{
    return !title().trimmed().isEmpty()
            && !author().trimmed().isEmpty();
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

/*** private slots ***/

void MetadataDialog::on_titleEdit_textChanged()
{
    QPushButton *button = _ui->buttonBox->button(QDialogButtonBox::Ok);

    if (button == 0) {
        debug_err("failed to get ok button");
        return;
    }

    button->setEnabled(isValid());
}

void MetadataDialog::on_authorEdit_textChanged()
{
    QPushButton *button = _ui->buttonBox->button(QDialogButtonBox::Ok);

    if (button == 0) {
        debug_err("failed to get ok button");
        return;
    }

    button->setEnabled(isValid());
}
