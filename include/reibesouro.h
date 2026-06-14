#pragma once

#include "inimigo.h"

class Projetil;
class GerenciadorDeColisoes;
class ListaEntidades;

class ReiBesouro : public Inimigo
{
    private:
        short int forca;
        float distancia;
        float limiteDir;
        float limiteEsq;
        int direcao;
        bool carapaçaEndurecida;
        int tempoTiro;
        int maxTempoTiro;
        GerenciadorDeColisoes* pGerenciadorColisoes;
        ListaEntidades* pListaEntidades;
        void EndurecerCarapaça();
        void AlterarSpriteMeiaVida();
    public:
        ReiBesouro(int id, sf::Vector2f pos, float dist);
        ~ReiBesouro();
        void Mover();
        void AprimorarMaldade();
        void Executar();
        void Salvar();
        void Danificar(Jogador* jogador);
        void setGerenciadorColisoes(GerenciadorDeColisoes* pGC);
        void setListaEntidades(ListaEntidades* pLE);
        void Atirar();
};