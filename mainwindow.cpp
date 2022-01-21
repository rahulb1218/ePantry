#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTableView"
QString item;
QString location;
QDate date;
QDate today = QDate::currentDate();
QString todayString = today.toString(Qt::ISODate);
QList<QDate> dates;
QList<QString> entries = {};
bool inserted = false;
QString dateString;
QString previousDate;
QString ISOdateString;
int row = 5;
int index;


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
    row = 4;
    int count = ui->gridLayout->count();
    int columsCount = ui->gridLayout->columnCount();
    int rowsCount = ui->gridLayout->rowCount();

    int i=0;
        for(int j=4; j<rowsCount; j++)
        {
            for(int k=0; k<columsCount && i<count; k++)
            {
                i++;

                //qDebug() << "Removing item at: " << j << "," << k;
                QLayoutItem* item = ui->gridLayout->itemAtPosition(j, k);

                if (!item) continue;

                if (item->widget()) {
                    item->widget()->hide();
                    ui->gridLayout->removeWidget(item->widget());

                } else {
                    item->widget()->hide();
                    ui->gridLayout->removeItem(item);
                    //delete item;
                }
                //qDebug() << "Removed!";
            }
        }

    item = ui->itemBox->text();
    location = ui->locationBox->text();
    date = ui->dateEdit->date();
    ISOdateString = date.toString(Qt::ISODate);
    //qDebug() << ISOdateString;
    //qDebug() << todayString;
    dateString = date.toString();

    //add_button->setText(dateString);
    //add_button->resize(100,100);
    //QLabel *itemLabel = new QLabel();
    //QLabel *locationLabel = new QLabel();
    //QLabel *dateLabel = new QLabel();
    //itemLabel->setText(item);
    //locationLabel->setText(location);
    //dateLabel->setText(dateString);
    int todayYear = (QString(todayString[0]) + QString(todayString[01]) + QString(todayString[2]) + QString(todayString[3])).toInt();
    int todayMonth = (QString(todayString[5]) + QString(todayString[6])).toInt();
    int todayDay = (QString(todayString[8]) + QString(todayString[9])).toInt();

    //dateLabel->setStyleSheet("QLabel {color: white;}");

    for(int i = 0; i < dates.size(); ++i){

        if (date < dates[i]){
            dates.insert(i, date);
            qDebug() << "i is " << i;
            index = i*4;
            inserted = true;
            break;
        }
        }
    if (inserted == false){

        dates.insert(0, date);
        index = 0;
    }
    inserted = false;

    qDebug() << entries.size();
    entries.insert(index, item);
    qDebug() << entries.size();
    entries.insert(index+1, location);
    entries.insert(index+2, dateString);
    entries.insert(index+3, ISOdateString);






    for(int i = 0; i < entries.size(); i = i + 4){
        //qDebug() << "running times: " << entries.size();

        QLabel *itemLabel = new QLabel();
        QLabel *locationLabel = new QLabel();
        QLabel *dateLabel = new QLabel();

        itemLabel->setText(entries[i]);
        locationLabel->setText(entries[i+1]);
        dateLabel->setText(entries[i+2]);

        QString dateText = entries[i+3];

        int year = (QString(dateText[0]) + QString(dateText[1]) + QString(dateText[2]) + QString(dateText[3])).toInt();
        int month = (QString(dateText[5]) + QString(dateText[6])).toInt();
        int day = (QString(dateText[8]) + QString(dateText[9])).toInt();

        if (todayYear > year){

            dateLabel->setStyleSheet("QLabel { background-color : red; color: white;}");
            qDebug() << "expired 1";
        }
        else if (todayYear == year && todayMonth > month){

            dateLabel->setStyleSheet("QLabel { background-color : red; color: white;}");
            qDebug() << "expired 2";
        }
        else if (todayYear == year && todayMonth == month && todayDay > day){

            dateLabel->setStyleSheet("QLabel { background-color : red; color: white;}");
            qDebug() << "expired 3";
        }

        ui->gridLayout->addWidget(itemLabel, row, 0);
        ui->gridLayout->addWidget(locationLabel, row, 1);
        ui->gridLayout->addWidget(dateLabel, row, 2);
        qDebug() << itemLabel->text() << locationLabel->text() << dateLabel->text();
        qDebug() << "adding widget at row: " << row;
        row = row + 1;
    }
    //ui->gridLayout->addWidget(itemLabel, row, 0);
    //ui->gridLayout->addWidget(locationLabel, row, 1);
    //ui->gridLayout->addWidget(dateLabel, row, 2);

    ui->itemBox->setText("");
    ui->locationBox->setText("");


}

MainWindow::~MainWindow()
{
    delete ui;
}

