#include"GAME.h"


int main() 
{
   srand(static_cast<unsigned>(time(NULL)));
    GAME game;
    game.run();
    return 0;
}
