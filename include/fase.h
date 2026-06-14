#pragma once

#include "ente.h"
#include "listaentidades.h"
#include "gerenciadorDeColisoes.h"
#include "chao.h"
#include "plataforma.h"
#include "besouro.h"
#include "vespa.h"

class Fase : public Ente
{
protected:
    int maxBesouros;
    int maxPlataformas;
    Jogador* pJogador;
    Jogador* pJogador2;
    ListaEntidades listaEntidades;
    GerenciadorDeColisoes gerenciadorColisoes; 
    
    void TratarEventos();
    void CriarBesouros();
    void CriarPlataformas();
    void CriarChao();
    virtual void CriarInimigos() = 0;
    virtual void CriarObstaculos() = 0;
    void CriarCenario();
public:
    Fase(int id, Jogador* jogador, Jogador* jogador2 = nullptr);
    virtual ~Fase();
    virtual void Executar() = 0;
};