#pragma once

#include "ente.h"
#include "listaentidades.h"
#include "gerenciadorDeColisoes.h"
#include "chao.h"
#include "plataforma.h"
#include "inimigoeasy.h"

class Fase : public Ente
{
protected:
    Jogador* pJogador;
    ListaEntidades listaEntidades;
    GerenciadorDeColisoes gerenciadorColisoes; 
public:
    Fase(int id, Jogador* jogador);
    virtual ~Fase();
    virtual void CriarInimigosEasy() = 0;
    virtual void CriarPlataformas() = 0;
    virtual void CriarInimigos() = 0;
    virtual void CriarObstaculos() = 0;
    virtual void Executar() = 0;
    virtual void Salvar() = 0;
};