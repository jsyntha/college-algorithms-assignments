#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct ListType {
    QString info[100];
    int length = 1;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    ListType list;

    void BinarySearch(ListType list, QString& item, bool& found, int& position);
};
#endif // MAINWINDOW_H
