#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include <memory>
#include "Player.h"


namespace Ui {
class AddItemDialog;
}

class AddItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(QWidget *parent = 0);

    std::unique_ptr<Player> createPlayerFromInput();

    ~AddItemDialog();

protected:
    void accept() override;
    void showEvent(QShowEvent *);

private slots:


private:
    Ui::AddItemDialog *ui;
    void resetFields();

};

#endif // ADDITEMDIALOG_H
