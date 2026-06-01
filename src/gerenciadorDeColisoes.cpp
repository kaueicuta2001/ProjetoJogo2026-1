#include "GerenciadorDeColisoes.h"
#include <cmath>

using namespace std;

GerenciadorDeColisoes::GerenciadorDeColisoes() : listaInimigos(), listaObstaculos() {}

GerenciadorDeColisoes::~GerenciadorDeColisoes() {}

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

void GerenciadorDeColisoes::VerificarColisoes(Jogador* pJogador) {
    if (!pJogador || (listaInimigos.empty() && listaObstaculos.empty())) return;

    if (!listaObstaculos.empty()) {
        std::list<Obstaculo*>::iterator it = listaObstaculos.begin();
        while (it != listaObstaculos.end()) {
            Obstaculo* obs = *it;

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
                    if (centroJogX < centroObsX){
                        pJogador->setPosicao(sf::Vector2f(posJ.x - interX, posJ.y));
                        cout << "colisao obstaculo esquerda" << endl;
                    }
                    else{
                        pJogador->setPosicao(sf::Vector2f(posJ.x + interX, posJ.y));
                        cout << "colisao obstaculo direita" << endl;
                    }
                } else {
                    if (centroJogY < centroObsY){
                        pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y - interY));
                        cout << "colisao obstaculo cima" << endl;
                    }
                    else{
                        pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y + interY));
                        cout << "colisao obstaculo baixo" << endl;
                    }
                }
            }
            ++it;
        }
    }
    if (!listaInimigos.empty()) {
        std::list<Inimigo*>::iterator it = listaInimigos.begin();
        while (it != listaInimigos.end()) {
            Inimigo* inimigo = *it;

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
                    if (centroJogX < centroInimX){
                        pJogador->setPosicao(sf::Vector2f(posJ.x - interX, posJ.y));
                        cout << "colisao inimigo esquerda" << endl;
                    }
                    else{
                        pJogador->setPosicao(sf::Vector2f(posJ.x + interX, posJ.y));
                        cout << "colisao inimigo direita" << endl;
                    }
                } else {
                    if (centroJogY < centroInimY){
                        pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y - interY));
                        cout << "colisao inimigo cima" << endl;
                    }
                    else{
                        pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y + interY));
                        cout << "colisao inimigo baixo" << endl;
                    }
                }
            }
            ++it;
        }
    }
}

void GerenciadorDeColisoes::RemoverInimigoInativo() {
    std::list<Inimigo*>::iterator it = listaInimigos.begin();
    while (it != listaInimigos.end()) {
        Inimigo* inimigo = *it;
        if (!inimigo->getVivo()) {
            it = listaInimigos.erase(it);
        } else {
            ++it;
        }
    }
}

void GerenciadorDeColisoes::RemoverObstaculoInativo() {
    std::list<Obstaculo*>::iterator it = listaObstaculos.begin();
    while (it != listaObstaculos.end()) {
        Obstaculo* obstaculo = *it;
        if (!obstaculo->getVivo()) {
            it = listaObstaculos.erase(it);
        } else {
            ++it;
        }
    }
}