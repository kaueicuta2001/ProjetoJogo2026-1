#include "gerenciadorDeColisoes.h"
#include <cmath>

GerenciadorDeColisoes::GerenciadorDeColisoes() : pListaInimigos(nullptr), pListaObstaculos(nullptr) {}

GerenciadorDeColisoes::~GerenciadorDeColisoes() {}

void GerenciadorDeColisoes::setListas(Lista<Inimigo>* pInimigos, Lista<Obstaculo>* pObstaculos) {
    pListaInimigos = pInimigos;
    pListaObstaculos = pObstaculos;
}

void GerenciadorDeColisoes::VerificarColisoes(Jogador* pJogador) {
    if (!pJogador || (!pListaInimigos && !pListaObstaculos)) return;

    pJogador->SetNoChao(false);

    if (pListaObstaculos) {
        Lista<Obstaculo>::Elemento* it = pListaObstaculos->getPrimeiro();
        while (it != nullptr) {
            Obstaculo* obs = it->getInfo();

            sf::Vector2f posJ = pJogador->getPosicao();
            sf::Vector2f tamJ = pJogador->getTamanho();
            sf::Vector2f posO = obs->getPosicao();
            sf::Vector2f tamO = obs->getTamanho();

            float centroJogX = posJ.x + tamJ.x / 2.0f;
            float centroJogY = posJ.y + tamJ.y / 2.0f;
            float centroObsX = posO.x + tamO.x / 2.0f;
            float centroObsY = posO.y + tamO.y / 2.0f;

            float distX = std::abs(centroJogX - centroObsX);
            float distY = std::abs(centroJogY - centroObsY);

            float minX = (tamJ.x + tamO.x) / 2.0f;
            float minY = (tamJ.y + tamO.y) / 2.0f;

            if (distX < minX && distY < minY) {
                float interX = minX - distX;
                float interY = minY - distY;

                if (interX < interY) {
                    if (centroJogX < centroObsX)
                        pJogador->setPosicao(sf::Vector2f(posJ.x - interX, posJ.y));
                    else
                        pJogador->setPosicao(sf::Vector2f(posJ.x + interX, posJ.y));
                } else {
                    if (centroJogY < centroObsY) {
                        pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y - interY));
                        pJogador->SetNoChao(true);
                    } else {
                        pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y + interY));
                    }
                }
            }
            it = it->getProximo();
        }
    }

    if (pListaInimigos) {
        Lista<Inimigo>::Elemento* it = pListaInimigos->getPrimeiro();
        while (it != nullptr) {
            Inimigo* inimigo = it->getInfo();
            inimigo->SetNoChao(false);

            if (pListaObstaculos) {
                Lista<Obstaculo>::Elemento* it_obs = pListaObstaculos->getPrimeiro();
                while (it_obs != nullptr) {
                    Obstaculo* obs = it_obs->getInfo();

                    sf::Vector2f posI = inimigo->getPosicao();
                    sf::Vector2f tamI = inimigo->getTamanho();
                    sf::Vector2f posO = obs->getPosicao();
                    sf::Vector2f tamO = obs->getTamanho();

                    float centroInimX = posI.x + tamI.x / 2.0f;
                    float centroInimY = posI.y + tamI.y / 2.0f;
                    float centroObsX = posO.x + tamO.x / 2.0f;
                    float centroObsY = posO.y + tamO.y / 2.0f;

                    float distX = std::abs(centroInimX - centroObsX);
                    float distY = std::abs(centroInimY - centroObsY);

                    float minX = (tamI.x + tamO.x) / 2.0f;
                    float minY = (tamI.y + tamO.y) / 2.0f;

                    if (distX < minX && distY < minY) {
                        float interX = minX - distX;
                        float interY = minY - distY;

                        if (interX < interY) {
                            if (centroInimX < centroObsX)
                                inimigo->setPosicao(sf::Vector2f(posI.x - interX, posI.y));
                            else
                                inimigo->setPosicao(sf::Vector2f(posI.x + interX, posI.y));
                        } else {
                            if (centroInimY < centroObsY) {
                                inimigo->setPosicao(sf::Vector2f(posI.x, posI.y - interY));
                                inimigo->SetNoChao(true);
                            } else {
                                inimigo->setPosicao(sf::Vector2f(posI.x, posI.y + interY));
                            }
                        }
                    }
                    it_obs = it_obs->getProximo();
                }
            }

            sf::Vector2f posJ = pJogador->getPosicao();
            sf::Vector2f tamJ = pJogador->getTamanho();
            sf::Vector2f posI = inimigo->getPosicao();
            sf::Vector2f tamI = inimigo->getTamanho();

            float centroJogX = posJ.x + tamJ.x / 2.0f;
            float centroJogY = posJ.y + tamJ.y / 2.0f;
            float centroInimX = posI.x + tamI.x / 2.0f;
            float centroInimY = posI.y + tamI.y / 2.0f;

            float distX = std::abs(centroJogX - centroInimX);
            float distY = std::abs(centroJogY - centroInimY);

            float minX = (tamJ.x + tamI.x) / 2.0f;
            float minY = (tamJ.y + tamI.y) / 2.0f;

            if (distX < minX && distY < minY) {
                float interX = minX - distX;
                float interY = minY - distY;

                if (interX < interY) {
                    if (centroJogX < centroInimX)
                        pJogador->setPosicao(sf::Vector2f(posJ.x - interX, posJ.y));
                    else
                        pJogador->setPosicao(sf::Vector2f(posJ.x + interX, posJ.y));
                } else {
                    if (centroJogY < centroInimY) {
                        pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y - interY));
                        pJogador->SetNoChao(true);
                    } else {
                        pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y + interY));
                    }
                }
            }
            it = it->getProximo();
        }
    }
}
