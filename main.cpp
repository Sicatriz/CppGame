#include <QApplication>
#include "mainm.h"

#include "game.h"

/************************************************************/
/*********  C++ taak Elektronica-ICT 2de jaar  **************/
/*******  GITHUB https://github.com/Sicatriz/CppGame  *******/
/****  credits: Indy Penders, Sebbe Gerits, Miguel Nunez ****/
/************************************************************/

  // global object

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainM* mainm = new MainM(0); //open and show the game
    mainm->show();


    return a.exec();
}
