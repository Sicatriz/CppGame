#include <QApplication>
#include "mainm.h"

/************************************************************/
/*********  C++ taak Elektronica-ICT 2de jaar  **************/
/*******  GITHUB https://github.com/Sicatriz/CppGame  *******/
/****  credits: Indy Penders, Sebbe Gerits, Miguel Nunez ****/
/************************************************************/

using namespace insemi;


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    srand(time(NULL));

    // show start menu
    MainM* game = new MainM(0);
    game->show();

    return a.exec();
}
