#include <QApplication>
#include "Game.h"

/************************************************************/
/*********  C++ taak Elektronica-ICT 2de jaar  **************/
/*******  GITHUB https://github.com/Sicatriz/CppGame  *******/
/****  credits: Indy Penders, Sebbe Gerits, Miguel Nunez ****/
/************************************************************/

  // global object

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    srand(time(NULL));

    Game* game = new Game(); //open and show the game
    game->show();


    return a.exec();
}
