#ifndef STATEMENTDIALOG_H
#define STATEMENTDIALOG_H

#include <QDialog>

namespace Ui {
class StatementDialog;
}

class StatementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StatementDialog(QWidget *parent = 0);
    ~StatementDialog();

private:
    Ui::StatementDialog *ui;
};

#endif // STATEMENTDIALOG_H
