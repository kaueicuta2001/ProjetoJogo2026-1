#include "obstdificil.h"
#include "jogador.h"

ObstDificil::ObstDificil(int id, sf::Vector2f pos, bool danoso, short int danosidade) : Obstaculo(id, pos, danoso), danosidade(danosidade) {}

ObstDificil::~ObstDificil() {}

void ObstDificil::Obstaculizar(Jogador* pJogador)
{
    if (pJogador != nullptr && danoso)
    {
        pJogador->PerderVidas(danosidade);
    }
}

void ObstDificil::Executar() {}

void ObstDificil::Salvar() {}
