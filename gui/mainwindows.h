//
// Created by daniel on 10/04/2021.
//

#ifndef OS2021PROJECT_MAINWINDOWS_H
#define OS2021PROJECT_MAINWINDOWS_H

#include <QWidget>
#include <headersFiles/WardRobe.h>


QT_BEGIN_NAMESPACE
namespace Ui { class mainWindows; }
QT_END_NAMESPACE

class mainWindows : public QWidget {
Q_OBJECT

public:
    explicit mainWindows(QWidget *parent = nullptr);

    ~mainWindows() override;

private:
    Family family;
    WardRobe wardrobe;
    Ui::mainWindows *ui;

private slots:
    void createFamilyButton();
    void createWardrobeButton();
    void goShoppingButton();
    void cleanWardrobeButton();
    void putAwayButton();
};





#endif //OS2021PROJECT_MAINWINDOWS_H
