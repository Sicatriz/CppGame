#include <QApplication>
#include "Game.h"


Game * game;  // global object

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game(); //open and show the game
    game->show();

    return a.exec();
}
