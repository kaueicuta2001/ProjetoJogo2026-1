#include "gerenciadorDeColisoes.h"
#include <cmath>

using namespace std;

GerenciadorDeColisoes::GerenciadorDeColisoes(Jogador* jogador) :
listaInimigos(),
listaObstaculos(), 
pJogador(jogador) {}

GerenciadorDeColisoes::~GerenciadorDeColisoes()
{
    pJogador = nullptr;
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

bool GerenciadorDeColisoes::VerificarColisao(Entidade* pe1, Entidade* pe2) const {
    if (!pe1 || !pe2) return false;
    
    sf::Vector2f pos1 = pe1->getPosicao();
    sf::Vector2f tam1 = pe1->getTamanho();
    sf::Vector2f pos2 = pe2->getPosicao();
    sf::Vector2f tam2 = pe2->getTamanho();
    
    float centro1X = pos1.x + tam1.x / 2.0f;
    float centro1Y = pos1.y + tam1.y / 2.0f;
    float centro2X = pos2.x + tam2.x / 2.0f;
    float centro2Y = pos2.y + tam2.y / 2.0f;
    
    float distX = std::abs(centro1X - centro2X);
    float distY = std::abs(centro1Y - centro2Y);
    
    float minX = (tam1.x + tam2.x) / 2.0f;
    float minY = (tam1.y + tam2.y) / 2.0f;
    
    return (distX < minX && distY < minY);
}


void GerenciadorDeColisoes::TratarColisoesJogsObstacs() {
    if (!pJogador || listaObstaculos.empty()) return;

    pJogador->SetNoChao(false);
    
    list<Obstaculo*>::iterator it_obs = listaObstaculos.begin();
    
    while(it_obs != listaObstaculos.end()) {
        Obstaculo* obs = *it_obs;
        
        if (VerificarColisao(pJogador, obs)) {
            sf::Vector2f posJ = pJogador->getPosicao();
            sf::Vector2f tamJ = pJogador->getTamanho();
            sf::Vector2f posO = obs->getPosicao();
            sf::Vector2f tamO = obs->getTamanho();
            
            float interX = ((tamJ.x + tamO.x) / 2.0f) - std::abs((posJ.x + tamJ.x/2.f) - (posO.x + tamO.x/2.f));
            float interY = ((tamJ.y + tamO.y) / 2.0f) - std::abs((posJ.y + tamJ.y/2.f) - (posO.y + tamO.y/2.f));
            
            if (interX < interY) {
                if ((posJ.x + tamJ.x/2.f) < (posO.x + tamO.x/2.f))
                pJogador->setPosicao(sf::Vector2f(posJ.x - interX, posJ.y));
                else
                pJogador->setPosicao(sf::Vector2f(posJ.x + interX, posJ.y));
            } else {
                if ((posJ.y + tamJ.y/2.f) < (posO.y + tamO.y/2.f)) {
                    pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y - interY));
                    pJogador->SetNoChao(true);
                } else {
                    pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y + interY));
                }
            }
        }
        ++it_obs;
    }
}

void GerenciadorDeColisoes::TratarColisoesJogsInimigo() {
    if (!pJogador || listaInimigos.empty()) return;
    
    list<Inimigo*>::iterator it_inim = listaInimigos.begin();
    
    while(it_inim != listaInimigos.end()) {
        Inimigo* inim = *it_inim;
        
        if (VerificarColisao(pJogador, inim)) {
            
            sf::Vector2f posJ = pJogador->getPosicao();
            sf::Vector2f tamJ = pJogador->getTamanho();
            sf::Vector2f posO = inim->getPosicao();
            sf::Vector2f tamO = inim->getTamanho();
            
            float interX = ((tamJ.x + tamO.x) / 2.0f) - std::abs((posJ.x + tamJ.x/2.f) - (posO.x + tamO.x/2.f));
            float interY = ((tamJ.y + tamO.y) / 2.0f) - std::abs((posJ.y + tamJ.y/2.f) - (posO.y + tamO.y/2.f));
            
            if (interX < interY) {
                if ((posJ.x + tamJ.x/2.f) < (posO.x + tamO.x/2.f))
                pJogador->setPosicao(sf::Vector2f(posJ.x - interX, posJ.y));
                else
                pJogador->setPosicao(sf::Vector2f(posJ.x + interX, posJ.y));
            } else {
                if ((posJ.y + tamJ.y/2.f) < (posO.y + tamO.y/2.f)) {
                    pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y - interY));
                    pJogador->SetNoChao(true);
                } else {
                    pJogador->setPosicao(sf::Vector2f(posJ.x, posJ.y + interY));
                }
            }
        }
        ++it_inim;
    }
}

void GerenciadorDeColisoes::TratarColisoesInimigoObstacs() {
    if (listaInimigos.empty() || listaObstaculos.empty()) return;
    
    list<Inimigo*>::iterator it_inim = listaInimigos.begin();
    
    while(it_inim != listaInimigos.end()) {
        Inimigo* inim = *it_inim;

        inim->SetNoChao(false);

        list<Obstaculo*>::iterator it_obs = listaObstaculos.begin();
        while(it_obs != listaObstaculos.end()) {
            Obstaculo* obs = *it_obs;
            
            if (VerificarColisao(inim, obs)) {
                sf::Vector2f posJ = inim->getPosicao();
                sf::Vector2f tamJ = inim->getTamanho();
                sf::Vector2f posO = obs->getPosicao();
                sf::Vector2f tamO = obs->getTamanho();
                
                float interX = ((tamJ.x + tamO.x) / 2.0f) - std::abs((posJ.x + tamJ.x/2.f) - (posO.x + tamO.x/2.f));
                float interY = ((tamJ.y + tamO.y) / 2.0f) - std::abs((posJ.y + tamJ.y/2.f) - (posO.y + tamO.y/2.f));
                
                if (interX < interY) {
                    if ((posJ.x + tamJ.x/2.f) < (posO.x + tamO.x/2.f))
                    inim->setPosicao(sf::Vector2f(posJ.x - interX, posJ.y));
                    else
                    inim->setPosicao(sf::Vector2f(posJ.x + interX, posJ.y));
                } 
                else {
                    if ((posJ.y + tamJ.y/2.f) < (posO.y + tamO.y/2.f)) {
                        inim->setPosicao(sf::Vector2f(posJ.x, posJ.y - interY));
                        inim->SetNoChao(true);
                    } 
                    else {
                        inim->setPosicao(sf::Vector2f(posJ.x, posJ.y + interY));
                    }
                }
            }
            ++it_obs;
        }
        ++it_inim;
    }
}

void GerenciadorDeColisoes::RemoverInimigoInativo() {
    for (auto it = listaInimigos.begin(); it != listaInimigos.end();) {
        if (!(*it)->getVivo()) {
            it = listaInimigos.erase(it);
        }
        else {
            ++it;
        }
    }
}
    
void GerenciadorDeColisoes::RemoverObstaculoInativo() {
    for (auto it = listaObstaculos.begin(); it != listaObstaculos.end();) {
        if (!(*it)->getVivo()) {
            it = listaObstaculos.erase(it);
        }
        else {
            ++it;
        }
    }
}

void GerenciadorDeColisoes::Executar() {
    TratarColisoesJogsObstacs();
    TratarColisoesInimigoObstacs();
    TratarColisoesJogsInimigo();
    RemoverInimigoInativo();
    RemoverObstaculoInativo();
}