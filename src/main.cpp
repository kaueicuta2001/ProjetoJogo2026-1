#include <iostream>
#include <time.h>

#include "jogo.h"

using namespace TheFrog;

int main()
{
    srand(time(nullptr));

    Jogo jogo;
    jogo.Executar();

    return 0;
}
