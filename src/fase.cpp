#include "fase.h"

Fase::Fase(int id, Jogador* jogador) :
Ente(id),
pJogador(jogador),
gerenciadorColisoes(jogador)
{
}

Fase::~Fase()
{
}

