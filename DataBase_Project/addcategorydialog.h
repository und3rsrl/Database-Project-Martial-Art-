#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H

#include <QDialog>
#include <memory>

namespace Ui {
class AddCategoryDialog;
}

class Category;

class AddCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCategoryDialog(QWidget *parent = 0);

    std::unique_ptr<Category> createCategoryFromInput();

    ~AddCategoryDialog();

protected:
    void accept() override;
    void showEvent(QShowEvent *);

private:
    Ui::AddCategoryDialog *ui;
    void resetFields();
};

#endif // ADDCATEGORYDIALOG_H
