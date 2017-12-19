#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class MetadataDialog;
}

class MetadataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MetadataDialog(QWidget *parent = 0);
    ~MetadataDialog();

    bool isValid() const;
    void setMetadata(const QString& title, const QString& author);
    QString title() const;
    QString author() const;

private slots:
    void on_titleEdit_textChanged();
    void on_authorEdit_textChanged();

private:
    Ui::MetadataDialog *_ui;
};

#endif // NEWDIALOG_H
