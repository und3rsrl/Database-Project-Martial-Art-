#include "additemdialog.h"
#include "ui_additemdialog.h"
#include <qmessagebox.h>
#include "Player.h"

AddItemDialog::AddItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemDialog)
{
    ui->setupUi(this);
}

std::unique_ptr<Player> AddItemDialog::createPlayerFromInput()
{

    return std::make_unique<Player>(ui->IDInput->text().toInt(),
                                    ui->TeamInput->text(),
                                    ui->ScoreInput->text().toInt(),
                                    ui->AgeInput->text().toInt(),
                                    ui->WeightInput->text().toInt());

}

void AddItemDialog::accept()
{
    bool ok = true;
    ui->IDInput->text().toInt(&ok);
    ui->AgeInput->text().toInt(&ok);
    ui->WeightInput->text().toInt(&ok);
    ui->ScoreInput->text().toInt(&ok);
    if(!ok)
    {
            QMessageBox::warning(this, tr("Player Add Error"), tr("Id, Age, Weight should be numbers"));
    }
    else
    {
            QDialog::accept();
    }
}

void AddItemDialog::showEvent(QShowEvent *)
{
    resetFields();
}

void AddItemDialog::resetFields()
{
    ui->AgeInput->setText("");
    ui->WeightInput->setText("");
    ui->IDInput->setText("");
    ui->ScoreInput->setText("");
    ui->TeamInput->setText("");
}

AddItemDialog::~AddItemDialog()
{
    delete ui;
}
