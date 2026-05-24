#include "bigchief.h"

using namespace std;
using namespace sf;

BigChief::BigChief(int id, Vector2f pos, int num_vidas,  int nivel_maldade, short int poder) :
Inimigo(id, pos, num_vidas, nivel_maldade),
forca(poder)
{
}

BigChief::~BigChief()
{
}

void BigChief::Mover()
{
    // Lógica de movimento do BigChief
}

void BigChief::Executar()
{
    // Lógica de execução do BigChief
}

void BigChief::Salvar()
{
    // Lógica de salvar o estado do BigChief
}