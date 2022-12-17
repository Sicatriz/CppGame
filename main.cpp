#include <QApplication>
#include "mainm.h"

/************************************************************/
/*********  C++ taak Elektronica-ICT 2de jaar  **************/
/*******  GITHUB https://github.com/Sicatriz/CppGame  *******/
/****  credits: Indy Penders, Sebbe Gerits, Miguel Nunez ****/
/************************************************************/

  // global object

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    srand(time(NULL));

    MainM* game = new MainM(0); //open and show the game
    game->show();

    return a.exec();
}
