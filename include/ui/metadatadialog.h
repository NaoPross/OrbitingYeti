#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

namespace Ui {
class MetadataDialog;
}

class MetadataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MetadataDialog(QWidget *parent = 0);
    ~MetadataDialog();

    void setMetadata(const QString& title, const QString& author);
    QString title() const;
    QString author() const;

private:
    Ui::MetadataDialog *_ui;
};

#endif // NEWDIALOG_H
