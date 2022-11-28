#include <QApplication>
#include "Game.h"

/************************************************************/
/*********  C++ taak Elektronica-ICT 2de jaar  **************/
/*******  GITHUB https://github.com/Sicatriz/CppGame  *******/
/****  credits: Indy Penders, Sebbe Gerits, Miguel Nunez ****/
/************************************************************/

Game * game;  // global object

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game(); //open and show the game
    game->show();

    return a.exec();
}
