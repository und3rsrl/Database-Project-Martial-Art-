#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>



namespace Ui {
class MainWindow;

}

class AddItemDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

private slots:
    void onAddPlayer();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AddItemDialog> mAddItemDialog;
};

#endif // MAINWINDOW_H
