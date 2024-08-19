#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include "warmitemwidget.h"
#include <QObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //дефолтный адрес сервера
    ui->lineEditServerAddress->setText("http://www.ru");

    //заполнить список виджетами
    auto item_house_room_1_item = new QListWidgetItem();
    auto item_house_room_2_item = new QListWidgetItem();
    auto item_house_room_3_item = new QListWidgetItem();
    auto item_house_room_4_item = new QListWidgetItem();

    auto item_house_room_1_widget = new WarmItemWidget(this);
    item_house_room_1_widget->setLocationName("Веранда");
    item_house_room_1_widget->setLocation("Большой дом - веранда");
    item_house_room_1_widget->setDescription("2 штуки на веранде");
    item_house_room_1_widget->setPower("800 ватт");

    auto item_house_room_2_widget = new WarmItemWidget(this);
    item_house_room_2_widget->setLocationName("Спальня");
    item_house_room_2_widget->setLocation("Большой дом - спальня");
    item_house_room_2_widget->setDescription("2 штуки в спальне");
    item_house_room_2_widget->setPower("800 ватт");

    auto item_house_room_3_widget = new WarmItemWidget(this);
    item_house_room_3_widget->setLocationName("Гостиная");
    item_house_room_3_widget->setLocation("Большой дом - гостиная");
    item_house_room_3_widget->setDescription("2 штуки в гостиной");
    item_house_room_3_widget->setPower("800 ватт");

    auto item_house_room_4_widget = new WarmItemWidget(this);
    item_house_room_4_widget->setLocationName("Кухня");
    item_house_room_4_widget->setLocation("Кухня");
    item_house_room_4_widget->setDescription("3 штуки на кухне");
    item_house_room_4_widget->setPower("1200 ватт");


    item_house_room_1_item->setSizeHint(item_house_room_1_widget->sizeHint());
    ui->listWidget->addItem(item_house_room_1_item);
    ui->listWidget->setItemWidget(item_house_room_1_item, item_house_room_1_widget);

    item_house_room_2_item->setSizeHint(item_house_room_2_widget->sizeHint());
    ui->listWidget->addItem(item_house_room_2_item);
    ui->listWidget->setItemWidget(item_house_room_2_item, item_house_room_2_widget);

    item_house_room_3_item->setSizeHint(item_house_room_3_widget->sizeHint());
    ui->listWidget->addItem(item_house_room_3_item);
    ui->listWidget->setItemWidget(item_house_room_3_item, item_house_room_3_widget);

    item_house_room_4_item->setSizeHint(item_house_room_4_widget->sizeHint());
    ui->listWidget->addItem(item_house_room_4_item);
    ui->listWidget->setItemWidget(item_house_room_4_item, item_house_room_4_widget);

    //коннекты
    QObject::connect(ui->actionExit, &QAction::triggered, []() {
        qApp->quit();
    });

    QObject::connect(ui->pushButtonServerConnect, &QPushButton::pressed, [&]() {
        if(!this->isConnected) {
            ui->labelConnectionStatus->setText("Подключено");
            ui->labelConnectionStatus->setStyleSheet("color: green");
            ui->pushButtonServerConnect->setText("Отключить");
            this->isConnected = true;
        }
        else {
            ui->labelConnectionStatus->setText("Отключено");
            ui->labelConnectionStatus->setStyleSheet("color: red");
            ui->pushButtonServerConnect->setText("Подключить");
            this->isConnected = false;
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

