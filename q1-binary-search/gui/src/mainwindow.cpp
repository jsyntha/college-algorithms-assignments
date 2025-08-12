#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString size[] = { "Jon", "Dot", "Eva", "Guy", "Jan", "Tom", "Jim", "Ann", "Kim", "Ron", "Tim", "Kay", "Amy" };
    list.length = sizeof(size) / sizeof(size[0]);

    for (int i = 0; i < list.length - 1; i++) {
        for (int j = 0; j < list.length - i - 1; j++) {
            if (size[j] > size[j + 1]) {
                QString temp = size[j];
                size[j] = size[j + 1];
                size[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < list.length; i++) {
        list.info[i] = size[i];
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{
    QString searchInput = ui->searchInput->text();
    bool found;
    int position;

    BinarySearch(list, searchInput, found, position);

    if (found) {
        ui->resultLabel->setText("Name found: " + searchInput);
        ui->positionLabel->setText("Position: " + QString::number(position));
    } else {
        ui->resultLabel->setText("Name not found");
        ui->positionLabel->clear();
    }
}

void MainWindow::BinarySearch(ListType list, QString& item, bool& found, int& position)
{
    int midPoint;
    int first = 0;
    int last = list.length - 1;
    bool moreToSearch = first <= last;
    found = false;
    int splitCount = 0;

    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        splitCount++;
        qDebug() << "Split Count: " << splitCount;

        if (item < list.info[midPoint])
        {
            last = midPoint - 1;
            moreToSearch = first <= last;
        }
        else if (item > list.info[midPoint])
        {
            first = midPoint + 1;
            moreToSearch = first <= last;
        }
        else
        {
            item = list.info[midPoint];
            found = true;
            position = midPoint;
        }
    }
        ui->splitCountLabel->setText("Split Count: " + QString::number(splitCount));
}
