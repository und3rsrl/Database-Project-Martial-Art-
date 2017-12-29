#include "addcategorydialog.h"
#include "ui_addcategorydialog.h"
#include "Category.h"
#include "QMessageBox"

AddCategoryDialog::AddCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCategoryDialog)
{
    ui->setupUi(this);


}

std::unique_ptr<Category> AddCategoryDialog::createCategoryFromInput()
{
    return std::make_unique<Category>(ui->id->text().toInt(), ui->minWeight->text().toInt(), ui->maxWeight->text().toInt(),
                                      ui->minAge->text().toInt(), ui->maxAge->text().toInt());
}

AddCategoryDialog::~AddCategoryDialog()
{
    delete ui;
}

void AddCategoryDialog::accept()
{
    bool validInput = true;

    ui->id->text().toInt(&validInput);
    int minWeight = ui->minWeight->text().toInt(&validInput);
    int maxWeight = ui->maxWeight->text().toInt(&validInput);
    int minAge = ui->minAge->text().toInt(&validInput);
    int maxAge = ui->maxAge->text().toInt(&validInput);

    bool ageError = (minAge > maxAge);
    bool weightError = (minWeight > maxWeight);

    if(!validInput)
    {
            QMessageBox::warning(this, tr("Category add error"), tr("Id, Age, Weight should be numbers"));
    }
    else if (ageError || weightError)
    {
        if(ageError)
        {
            QMessageBox::warning(this, tr("Age error"), tr("Minimum age should be lower or equal to maximum age"));
        }
        if(weightError)
        {
            QMessageBox::warning(this, tr("Weight error"), tr("Minimum weight should be lower or equal to maximum weight"));
        }

    }
    else
    {
            QDialog::accept();
    }
}

void AddCategoryDialog::showEvent(QShowEvent *)
{
    resetFields();
}

void AddCategoryDialog::resetFields()
{
    ui->id->setText("");
    ui->minWeight->setText("");
    ui->maxWeight->setText("");
    ui->minAge->setText("");
    ui->maxAge->setText("");
}
