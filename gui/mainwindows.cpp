//
// Created by daniel on 10/04/2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindows.h" resolved

#include <headersFiles/Family.h>
#include "mainwindows.h"
#include "ui_mainWindows.h"


mainWindows::mainWindows(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainWindows) {

    ui->setupUi(this);


    connect(ui->createFamily, SIGNAL(clicked()), this, SLOT(createFamilyButton()));
    connect(ui->createWardrobe, SIGNAL(clicked()), this, SLOT(createWardrobeButton()));
    connect(ui->sendFamilyShopping, SIGNAL(clicked()), this, SLOT(goShoppingButton()));
    connect(ui->cleatthewardrobe, SIGNAL(clicked()), this, SLOT(cleanWardrobeButton()));
    connect(ui->putAwayCloth, SIGNAL(clicked()), this, SLOT(putAwayButton()));

}

mainWindows::~mainWindows() {
    delete ui;
}


void mainWindows::createFamilyButton(){
    Family genfamily(ui->memberAmount->value());
    this->family = genfamily;
    ui->history->addItem("Family generated");

}

void mainWindows::createWardrobeButton(){
    WardRobe genWardRobe;
    this->wardrobe = genWardRobe;
    ui->history->addItem("Wardrobe generated");
}

void mainWindows::goShoppingButton(){
    family.goShopping(ui->clothAmount->value());
    ui->history->addItem("The family went shopping");
}

void mainWindows::cleanWardrobeButton(){
    wardrobe.cleanWardrobe();
    ui->history->addItem("The wardrobe was cleaned");
}

void mainWindows::putAwayButton(){
    wardrobe.addFamBagsToWardrobe(this->family);
    ui->history->addItem("The family has put away the cloths");
}

