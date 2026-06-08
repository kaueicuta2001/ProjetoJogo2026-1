#include <iostream>
#include <time.h>

#include "jogo.h"

int main()
{
    srand(time(nullptr));

    Jogo jogo;
    jogo.Executar();

    return 0;
}
