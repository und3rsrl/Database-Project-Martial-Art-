#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QActionGroup>



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
    void onViewTriggered(QAction *action);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<AddItemDialog> mAddItemDialog;
    std::unique_ptr<QActionGroup> mViews;
};

#endif // MAINWINDOW_H
