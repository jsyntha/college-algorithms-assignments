#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(static_cast<unsigned int>(time(0)));
    answer = rand() % 1000 + 1;

    first = 1;
    last = 1000;
    attempts = 0;
    found = false;

    // DEBUG LINE
    ui->debugLabel->setText("DEBUG: Answer is " + QString::number(answer));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitButton_clicked()
{
    if (found || attempts >= 10) {
        QMessageBox::information(this, "Game Over", "Game already finished!");
        return;
    }

    bool ok;
    int guess = ui->guessInput->text().toInt(&ok);

    if (!ok || guess < 1 || guess > 1000) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a number between 1 and 1000.");
        return;
    }

    attempts++;
    ui->attemptsLabel->setText("Attempt: " + QString::number(attempts));

    if (guess < answer) {
        ui->feedbackLabel->setText("Too low, try again!");
        first = guess + 1;
    } else if (guess > answer) {
        ui->feedbackLabel->setText("Too high, try again!");
        last = guess - 1;
    } else {
        ui->feedbackLabel->setText("Correct! You guessed the number!");
        found = true;
    }

    ui->rangeLabel->setText("Range: " + QString::number(first) + " - " + QString::number(last));

    if (!found && attempts >= 10) {
        ui->feedbackLabel->setText("You should be able to do better!");
    }

    if (found) {
        if (attempts < 10) {
            QMessageBox::information(this, "Success", "Either you know the secret or you got lucky!");
        } else {
            QMessageBox::information(this, "Success", "You know the secret!");
        }
    }
}
