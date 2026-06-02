#pragma once

#include "fase.h"

class Fase1 : public Fase
{
private:
    int maxInimigosEasy;
    int maxPlataformas;
    sf::Texture texturaBG;
    sf::Sprite spriteBG;
    sf::Vector2f tamBG;
public:
    Fase1(int id, Jogador* pJogador);
    ~Fase1();
    void desenharBG();
    void CriarInimigosEasy();
    void CriarChao();
    void CriarPlataformas();
    void CriarInimigos();
    void CriarObstaculos();
    void Executar();
    void Salvar();
};