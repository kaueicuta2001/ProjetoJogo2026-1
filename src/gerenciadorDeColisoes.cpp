#include "gerenciadorDeColisoes.h"
#include <cmath>

using namespace std;

GerenciadorDeColisoes::GerenciadorDeColisoes(Jogador* jogador, Jogador* jogador2) :
listaInimigos(),
listaObstaculos(),
listaChao(),
listaProjeteis(),
pJogador(jogador),
pJogador2(jogador2) {}

GerenciadorDeColisoes::~GerenciadorDeColisoes()
{
    listaInimigos.clear();
    listaObstaculos.clear();
    listaChao.clear();
    listaProjeteis.clear();
    pJogador = nullptr;
    pJogador2 = nullptr;
}

void GerenciadorDeColisoes::setJogador(Jogador* jogador) {
    pJogador = jogador;
}

void GerenciadorDeColisoes::setJogador2(Jogador* jogador2) {
    pJogador2 = jogador2;
}

void GerenciadorDeColisoes::IncluirInimigo(Inimigo* inimigo) {
    if (inimigo) {
        listaInimigos.push_back(inimigo);
    }
}

void GerenciadorDeColisoes::IncluirObstaculo(Obstaculo* obstaculo) {
    if (obstaculo) {
        listaObstaculos.push_back(obstaculo);
    }
}

void GerenciadorDeColisoes::IncluirChao(Chao* chao) {
    if (chao) {
        listaChao.push_back(chao);
    }
}

void GerenciadorDeColisoes::IncluirProjetil(Projetil* projetil) {
    if (projetil) {
        listaProjeteis.push_back(projetil);
    }
}

bool GerenciadorDeColisoes::VerificarColisao(Entidade* ent1, Entidade* ent2) {
    sf::Vector2f pos1 = ent1->getPosicao();
    sf::Vector2f tam1 = ent1->getTamanho();
    sf::Vector2f pos2 = ent2->getPosicao();
    sf::Vector2f tam2 = ent2->getTamanho();

    sf::Vector2f centro1(pos1.x + tam1.x / 2.0f, pos1.y + tam1.y / 2.0f);
    sf::Vector2f centro2(pos2.x + tam2.x / 2.0f, pos2.y + tam2.y / 2.0f);

    float distanciaX = abs(centro1.x - centro2.x);
    float distanciaY = abs(centro1.y - centro2.y);

    float somaMetadesX = tam1.x / 2.0f + tam2.x / 2.0f;
    float somaMetadesY = tam1.y / 2.0f + tam2.y / 2.0f;

    if (distanciaX < somaMetadesX && distanciaY < somaMetadesY) {
        return true; 
    }
    return false;
}

void GerenciadorDeColisoes::Executar() {
    RemoverInimigoInativo();
    RemoverObstaculoInativo();
    RemoverProjetilInativo();

    for (auto inimigo : listaInimigos) {
        if (inimigo->getVivo()) {
            inimigo->SetNoChao(false);

            for (auto chao : listaChao) {
                if (chao->getVivo() && VerificarColisao(inimigo, chao)) {
                    sf::Vector2f posIni = inimigo->getPosicao();
                    sf::Vector2f tamIni = inimigo->getTamanho();
                    sf::Vector2f posChao = chao->getPosicao();

                    if (posIni.y < posChao.y) {
                        inimigo->SetNoChao(true);
                        inimigo->setPosicao(sf::Vector2f(posIni.x, posChao.y - tamIni.y));
                    }
                }
            }

            for (auto obstaculo : listaObstaculos) {
                if (obstaculo->getVivo() && VerificarColisao(inimigo, obstaculo)) {
                    sf::Vector2f posIni = inimigo->getPosicao();
                    sf::Vector2f tamIni = inimigo->getTamanho();
                    sf::Vector2f posObs = obstaculo->getPosicao();

                    if (posIni.y < posObs.y) {
                        inimigo->SetNoChao(true);
                        inimigo->setPosicao(sf::Vector2f(posIni.x, posObs.y - tamIni.y));
                    }
                }
            }
        }
    }

    if (pJogador && pJogador->getVivo()) {
        pJogador->SetNoChao(false);

        for (auto chao : listaChao) {
            if (chao->getVivo() && VerificarColisao(pJogador, chao)) {
                sf::Vector2f posJog = pJogador->getPosicao();
                sf::Vector2f tamJog = pJogador->getTamanho();
                sf::Vector2f posChao = chao->getPosicao();

                if (posJog.y < posChao.y) {
                    pJogador->SetNoChao(true);
                    pJogador->setPosicao(sf::Vector2f(posJog.x, posChao.y - tamJog.y));
                }
            }
        }

        for (auto obstaculo : listaObstaculos) {
            if (obstaculo->getVivo() && VerificarColisao(pJogador, obstaculo)) {
                sf::Vector2f posJog = pJogador->getPosicao();
                sf::Vector2f tamJog = pJogador->getTamanho();
                sf::Vector2f posObs = obstaculo->getPosicao();

                if (posJog.y < posObs.y) {
                    pJogador->SetNoChao(true);
                    pJogador->setPosicao(sf::Vector2f(posJog.x, posObs.y - tamJog.y));
                }
                obstaculo->Obstaculizar(pJogador);
            }
        }

        for (auto inimigo : listaInimigos) {
            if (inimigo->getVivo() && VerificarColisao(pJogador, inimigo)) {
                sf::Vector2f posJog = pJogador->getPosicao();
                sf::Vector2f tamJog = pJogador->getTamanho();
                sf::Vector2f posIni = inimigo->getPosicao();

                if (posJog.y + tamJog.y <= posIni.y + 20.0f) {
                    pJogador->Pisar(inimigo);
                } else if (!pJogador->getImune()) {
                    pJogador->PerderVidas(inimigo->getDano());
                    pJogador->IniciarImunidade();
                }
            }
        }
    }

    // 
    if (pJogador2 && pJogador2->getVivo()) {
        pJogador2->SetNoChao(false);

        for (auto chao : listaChao) {
            if (chao->getVivo() && VerificarColisao(pJogador2, chao)) {
                sf::Vector2f posJog = pJogador2->getPosicao();
                sf::Vector2f tamJog = pJogador2->getTamanho();
                sf::Vector2f posChao = chao->getPosicao();

                if (posJog.y < posChao.y) {
                    pJogador2->SetNoChao(true);
                    pJogador2->setPosicao(sf::Vector2f(posJog.x, posChao.y - tamJog.y));
                }
            }
        }

        for (auto obstaculo : listaObstaculos) {
            if (obstaculo->getVivo() && VerificarColisao(pJogador2, obstaculo)) {
                sf::Vector2f posJog = pJogador2->getPosicao();
                sf::Vector2f tamJog = pJogador2->getTamanho();
                sf::Vector2f posObs = obstaculo->getPosicao();

                if (posJog.y < posObs.y) {
                    pJogador2->SetNoChao(true);
                    pJogador2->setPosicao(sf::Vector2f(posJog.x, posObs.y - tamJog.y));
                }
                obstaculo->Obstaculizar(pJogador2);
            }
        }

        for (auto inimigo : listaInimigos) {
            if (inimigo->getVivo() && VerificarColisao(pJogador2, inimigo)) {
                sf::Vector2f posJog = pJogador2->getPosicao();
                sf::Vector2f tamJog = pJogador2->getTamanho();
                sf::Vector2f posIni = inimigo->getPosicao();

                if (posJog.y + tamJog.y <= posIni.y + 20.0f) {
                    pJogador2->Pisar(inimigo);
                } else if (!pJogador2->getImune()) {
                    pJogador2->PerderVidas(inimigo->getDano());
                    pJogador2->IniciarImunidade();
                }
            }
        }
    }

    auto it_proj = listaProjeteis.begin();
    while (it_proj != listaProjeteis.end()) {
        Projetil* proj = *it_proj;
        
        if (proj->getVivo()) {
            if (pJogador && pJogador->getVivo() && VerificarColisao(pJogador, proj)) {
                if (!pJogador->getImune()) {
                    proj->Danificar(pJogador);
                    pJogador->IniciarImunidade();
                }
                proj->Desativar();
            }

            if (pJogador2 && pJogador2->getVivo() && VerificarColisao(pJogador2, proj)) {
                if (!pJogador2->getImune()) {
                    proj->Danificar(pJogador2);
                    pJogador2->IniciarImunidade();
                }
                proj->Desativar();
            }
        }
        ++it_proj;
    }
}

void GerenciadorDeColisoes::RemoverInimigoInativo() 
{
    for (auto it = listaInimigos.begin(); it != listaInimigos.end();) {
        if (!(*it)->getVivo()) {
            it = listaInimigos.erase(it);
        }
        else {
            ++it;
        }
    }
}
    
void GerenciadorDeColisoes::RemoverObstaculoInativo() 
{
    for (auto it = listaObstaculos.begin(); it != listaObstaculos.end();) {
        if (!(*it)->getVivo()) {
            it = listaObstaculos.erase(it);
        }
        else {
            ++it;
        }
    }
}

void GerenciadorDeColisoes::RemoverProjetilInativo()
{
    for (auto it = listaProjeteis.begin(); it != listaProjeteis.end();) {
        if (!(*it)->getVivo()) {
            it = listaProjeteis.erase(it);
        }
        else {
            ++it;
        }
    }
}