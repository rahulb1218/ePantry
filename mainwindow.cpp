#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableView"
QString item;
QString location;
QDate date;
QDate today = QDate::currentDate();
QString todayString = today.toString(Qt::ISODate);
QList<QDate> dates;
bool inserted = false;
QString dateString;
QString previousDate;
QString ISOdateString;
int row = 5;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    add_button = new QPushButton("Add", this);
    //add_button->setGeometry(QRect(QPoint(100,100), QSize(200,50)));
    ui->gridLayout->addWidget(add_button, 2, 3);
    dates.append(QDate(3000, 01, 01));
    connect(add_button, &QPushButton::released, this, &MainWindow::handleButton);

    QLabel *itemLabel1 = new QLabel();
    QLabel *locationLabel1 = new QLabel();
    QLabel *dateLabel1 = new QLabel();
    itemLabel1->setText("yeehaw betch");
    locationLabel1->setText("neeneer neener");
    dateLabel1->setText("oh yesssssss");
    ui->gridLayout->addWidget(itemLabel1, 4, 0);
    ui->gridLayout->addWidget(locationLabel1, 4, 1);
    ui->gridLayout->addWidget(dateLabel1, 4, 2);
}

void MainWindow::handleButton()
{
    item = ui->itemBox->text();
    location = ui->locationBox->text();
    date = ui->dateEdit->date();
    ISOdateString = date.toString(Qt::ISODate);
    //qDebug() << ISOdateString;
    //qDebug() << todayString;
    dateString = date.toString();

    //add_button->setText(dateString);
    //add_button->resize(100,100);
    QLabel *itemLabel = new QLabel();
    QLabel *locationLabel = new QLabel();
    QLabel *dateLabel = new QLabel();
    itemLabel->setText(item);
    locationLabel->setText(location);
    dateLabel->setText(dateString);
    int todayYear = (QString(todayString[0]) + QString(todayString[01]) + QString(todayString[2]) + QString(todayString[3])).toInt();
    int todayMonth = (QString(todayString[5]) + QString(todayString[6])).toInt();
    int todayDay = (QString(todayString[8]) + QString(todayString[9])).toInt();
    int year = (QString(ISOdateString[0]) + QString(ISOdateString[1]) + QString(ISOdateString[2]) + QString(ISOdateString[3])).toInt();
    int month = (QString(ISOdateString[5]) + QString(ISOdateString[6])).toInt();
    int day = (QString(ISOdateString[8]) + QString(ISOdateString[9])).toInt();
    dateLabel->setStyleSheet("QLabel {color: white;}");

    for(int i = 0; i < dates.size(); ++i){

        if (date < dates[i]){
            dates.insert(i, date);

            inserted = true;
            break;
        }
        }
    if (inserted == false){

        dates.insert(0, date);
    }
    inserted = false;


    if (todayYear > year){

        dateLabel->setStyleSheet("QLabel { background-color : red; color: white;}");
    }
    else if (todayYear == year && todayMonth > month){

        dateLabel->setStyleSheet("QLabel { background-color : red; color: white;}");
    }
    else if (todayYear == year && todayMonth == month && todayDay > day){

        dateLabel->setStyleSheet("QLabel { background-color : red; color: white;}");
    }





    qDebug() << row;
    ui->gridLayout->addWidget(itemLabel, row, 0);
    ui->gridLayout->addWidget(locationLabel, row, 1);
    ui->gridLayout->addWidget(dateLabel, row, 2);

    ui->itemBox->setText("");
    ui->locationBox->setText("");

    row = row + 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

