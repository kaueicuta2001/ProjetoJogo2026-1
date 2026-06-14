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
    if (pJogador2) {
        pJogador2->SetNoChao(false);
    }

    list<Obstaculo*>::iterator it_obs = listaObstaculos.begin();
    
    while(it_obs != listaObstaculos.end()) {
        Obstaculo* obs = *it_obs;
        
        if (VerificarColisao(pJogador, obs)) {
            sf::Vector2f posJ1 = pJogador->getPosicao();
            sf::Vector2f tamJ1 = pJogador->getTamanho();
            sf::Vector2f posO = obs->getPosicao();
            sf::Vector2f tamO = obs->getTamanho();
            
            float centroJX = posJ1.x + tamJ1.x / 2.0f;
            float centroJY = posJ1.y + tamJ1.y / 2.0f;
            float centroOX = posO.x + tamO.x / 2.0f;
            float centroOY = posO.y + tamO.y / 2.0f;
            
            float distX = std::abs(centroJX - centroOX);
            float distY = std::abs(centroJY - centroOY);
            
            float minX = (tamJ1.x + tamO.x) / 2.0f;
            float minY = (tamJ1.y + tamO.y) / 2.0f;

            float interX = minX - distX;
            float interY = minY - distY;
            
            if (interX < interY) {
                if (centroJX < centroOX)
                    pJogador->setPosicao(sf::Vector2f(posJ1.x - interX, posJ1.y));
                else
                    pJogador->setPosicao(sf::Vector2f(posJ1.x + interX, posJ1.y));
            } else {
                if (centroJY < centroOY) {
                    pJogador->setPosicao(sf::Vector2f(posJ1.x, posJ1.y - interY));
                    pJogador->SetNoChao(true);
                    obs->Obstaculizar(pJogador);
                } else {
                    pJogador->setPosicao(sf::Vector2f(posJ1.x, posJ1.y + interY));
                }
            }
        }

        if(pJogador2 && VerificarColisao(pJogador2, obs)) {
            sf::Vector2f posJ2 = pJogador2->getPosicao();
            sf::Vector2f tamJ2 = pJogador2->getTamanho();
            sf::Vector2f posO = obs->getPosicao();
            sf::Vector2f tamO = obs->getTamanho();
            
            float centroJ2X = posJ2.x + tamJ2.x / 2.0f;
            float centroJ2Y = posJ2.y + tamJ2.y / 2.0f;
            float centroOX = posO.x + tamO.x / 2.0f;
            float centroOY = posO.y + tamO.y / 2.0f;
            
            float distX = std::abs(centroJ2X - centroOX);
            float distY = std::abs(centroJ2Y - centroOY);
            
            float minX = (tamJ2.x + tamO.x) / 2.0f;
            float minY = (tamJ2.y + tamO.y) / 2.0f;

            float interX = minX - distX;
            float interY = minY - distY;
            
            if (interX < interY) {
                if (centroJ2X < centroOX)
                    pJogador2->setPosicao(sf::Vector2f(posJ2.x - interX, posJ2.y));
                else
                    pJogador2->setPosicao(sf::Vector2f(posJ2.x + interX, posJ2.y));
            } else {
                if (centroJ2Y < centroOY) {
                    pJogador2->setPosicao(sf::Vector2f(posJ2.x, posJ2.y - interY));
                    pJogador2->SetNoChao(true);
                    obs->Obstaculizar(pJogador2);
                } else {
                    pJogador2->setPosicao(sf::Vector2f(posJ2.x, posJ2.y + interY));
                }
            }
        }
        ++it_obs;
    }
    
    if (pJogador && !listaChao.empty()) {
        list<Chao*>::iterator it_chao = listaChao.begin();
        
        while(it_chao != listaChao.end()) {
            Chao* chao = *it_chao;
            
            if (VerificarColisao(pJogador, chao)) {
                sf::Vector2f posJ1 = pJogador->getPosicao();
                sf::Vector2f tamJ1 = pJogador->getTamanho();
                sf::Vector2f posC = chao->getPosicao();
                sf::Vector2f tamC = chao->getTamanho();
                
                float centroJX = posJ1.x + tamJ1.x / 2.0f;
                float centroJY = posJ1.y + tamJ1.y / 2.0f;
                float centroCX = posC.x + tamC.x / 2.0f;
                float centroCY = posC.y + tamC.y / 2.0f;
                
                float distX = std::abs(centroJX - centroCX);
                float distY = std::abs(centroJY - centroCY);
                
                float minX = (tamJ1.x + tamC.x) / 2.0f;
                float minY = (tamJ1.y + tamC.y) / 2.0f;

                float interX = minX - distX;
                float interY = minY - distY;
                
                if (interX < interY) {
                    if (centroJX < centroCX)
                        pJogador->setPosicao(sf::Vector2f(posJ1.x - interX, posJ1.y));
                    else
                        pJogador->setPosicao(sf::Vector2f(posJ1.x + interX, posJ1.y));
                } else {
                    if (centroJY < centroCY) {
                        pJogador->setPosicao(sf::Vector2f(posJ1.x, posJ1.y - interY));
                        pJogador->SetNoChao(true);
                    } else {
                        pJogador->setPosicao(sf::Vector2f(posJ1.x, posJ1.y + interY));
                    }
                }
            }
            
            if(pJogador2 && VerificarColisao(pJogador2, chao)) {
                sf::Vector2f posJ2 = pJogador2->getPosicao();
                sf::Vector2f tamJ2 = pJogador2->getTamanho();
                sf::Vector2f posC = chao->getPosicao();
                sf::Vector2f tamC = chao->getTamanho();
                
                float centroJ2X = posJ2.x + tamJ2.x / 2.0f;
                float centroJ2Y = posJ2.y + tamJ2.y / 2.0f;
                float centroCX = posC.x + tamC.x / 2.0f;
                float centroCY = posC.y + tamC.y / 2.0f;
                
                float distX = std::abs(centroJ2X - centroCX);
                float distY = std::abs(centroJ2Y - centroCY);
                
                float minX = (tamJ2.x + tamC.x) / 2.0f;
                float minY = (tamJ2.y + tamC.y) / 2.0f;

                float interX = minX - distX;
                float interY = minY - distY;
                
                if (interX < interY) {
                    if (centroJ2X < centroCX)
                        pJogador2->setPosicao(sf::Vector2f(posJ2.x - interX, posJ2.y));
                    else
                        pJogador2->setPosicao(sf::Vector2f(posJ2.x + interX, posJ2.y));
                } else {
                    if (centroJ2Y < centroCY) {
                        pJogador2->setPosicao(sf::Vector2f(posJ2.x, posJ2.y - interY));
                        pJogador2->SetNoChao(true);
                    } else {
                        pJogador2->setPosicao(sf::Vector2f(posJ2.x, posJ2.y + interY));
                    }
                }
            }
            ++it_chao;
        }
    }
}

void GerenciadorDeColisoes::TratarColisoesJogsInimigo() 
{
    if (!pJogador || listaInimigos.empty()) return;
    
    list<Inimigo*>::iterator it_inim = listaInimigos.begin();
    
    while(it_inim != listaInimigos.end()) {
        Inimigo* inim = *it_inim;
        
        if (VerificarColisao(pJogador, inim)) {
            
            sf::Vector2f posJ1 = pJogador->getPosicao();
            sf::Vector2f tamJ1 = pJogador->getTamanho();
            sf::Vector2f posI = inim->getPosicao();
            sf::Vector2f tamI = inim->getTamanho();

            float centroJX = posJ1.x + tamJ1.x / 2.0f;
            float centroJY = posJ1.y + tamJ1.y / 2.0f;
            float centroIX = posI.x + tamI.x / 2.0f;
            float centroIY = posI.y + tamI.y / 2.0f;
            
            float distX = std::abs(centroJX - centroIX);
            float distY = std::abs(centroJY - centroIY);
            
            float minX = (tamJ1.x + tamI.x) / 2.0f;
            float minY = (tamJ1.y + tamI.y) / 2.0f;

            float interX = minX - distX;
            float interY = minY - distY;
            
            if (interX < interY) {
                if (centroJX < centroIX){
                    if(!pJogador->getImune()) {
                        inim->Danificar(pJogador);
                        pJogador->IniciarImunidade();
                        pJogador->setPosicao(sf::Vector2f(posJ1.x - interX - 50.f, posJ1.y - 16.f));
                    }
                }
                else{
                    if(!pJogador->getImune()) {
                        inim->Danificar(pJogador);
                        pJogador->IniciarImunidade();
                        pJogador->setPosicao(sf::Vector2f(posJ1.x + interX + 50.f, posJ1.y - 16.f));
                    }
                }
            } else {
                if (centroJY < centroIY) {
                    pJogador->setPosicao(sf::Vector2f(posJ1.x, posJ1.y - interY));
                    pJogador->Pisar(inim);
                } else {
                    if(!pJogador->getImune()) {
                        inim->Danificar(pJogador);
                        pJogador->IniciarImunidade();
                        if(centroJX < centroIX) {
                            pJogador->setPosicao(sf::Vector2f(posJ1.x - interX - 50.f, posJ1.y - 16.f));
                        } else {
                            pJogador->setPosicao(sf::Vector2f(posJ1.x + interX + 50.f, posJ1.y - 16.f));
                        }
                    }
                }
            }
        }

        if (pJogador2 && VerificarColisao(pJogador2, inim)) {
            
            sf::Vector2f posJ2 = pJogador2->getPosicao();
            sf::Vector2f tamJ2 = pJogador2->getTamanho();
            sf::Vector2f posI = inim->getPosicao();
            sf::Vector2f tamI = inim->getTamanho();

            float centroJ2X = posJ2.x + tamJ2.x / 2.0f;
            float centroJ2Y = posJ2.y + tamJ2.y / 2.0f;
            float centroIX = posI.x + tamI.x / 2.0f;
            float centroIY = posI.y + tamI.y / 2.0f;
            
            float distX = std::abs(centroJ2X - centroIX);
            float distY = std::abs(centroJ2Y - centroIY);
            
            float minX = (tamJ2.x + tamI.x) / 2.0f;
            float minY = (tamJ2.y + tamI.y) / 2.0f;

            float interX = minX - distX;
            float interY = minY - distY;
            
            if (interX < interY) {
                if (centroJ2X < centroIX){
                    if(!pJogador2->getImune()) {
                        inim->Danificar(pJogador2);
                        pJogador2->IniciarImunidade();
                        pJogador2->setPosicao(sf::Vector2f(posJ2.x - interX - 50.f, posJ2.y - 16.f));
                    }
                }
                else{
                    if(!pJogador2->getImune()) {
                        inim->Danificar(pJogador2);
                        pJogador2->IniciarImunidade();
                        pJogador2->setPosicao(sf::Vector2f(posJ2.x + interX + 50.f, posJ2.y - 16.f));
                    }
                }
            } else {
                if (centroJ2Y < centroIY) {
                    pJogador2->setPosicao(sf::Vector2f(posJ2.x, posJ2.y - interY));
                    pJogador2->Pisar(inim);
                } else {
                    if(!pJogador2->getImune()) {
                        inim->Danificar(pJogador2);
                        pJogador2->IniciarImunidade();
                        if(centroJ2X < centroIX) {
                            pJogador2->setPosicao(sf::Vector2f(posJ2.x - interX - 50.f, posJ2.y - 16.f));
                        } else {
                            pJogador2->setPosicao(sf::Vector2f(posJ2.x + interX + 50.f, posJ2.y - 16.f));
                        }
                    }
                }
            }
        }
        ++it_inim;
    }
}

void GerenciadorDeColisoes::TratarColisoesInimigoObstacs() 
{
    if (listaInimigos.empty() || listaObstaculos.empty()) return;
    
    list<Inimigo*>::iterator it_inim = listaInimigos.begin();
    
    while(it_inim != listaInimigos.end()) {
        Inimigo* inim = *it_inim;

        inim->SetNoChao(false);

        list<Obstaculo*>::iterator it_obs = listaObstaculos.begin();
        while(it_obs != listaObstaculos.end()) {
            Obstaculo* obs = *it_obs;
            
            if (VerificarColisao(inim, obs)) {
                sf::Vector2f posI = inim->getPosicao();
                sf::Vector2f tamI = inim->getTamanho();
                sf::Vector2f posO = obs->getPosicao();
                sf::Vector2f tamO = obs->getTamanho();
                            
                float centroIX = posI.x + tamI.x / 2.0f;
                float centroIY = posI.y + tamI.y / 2.0f;
                float centroOX = posO.x + tamO.x / 2.0f;
                float centroOY = posO.y + tamO.y / 2.0f;
                
                float distX = std::abs(centroIX - centroOX);
                float distY = std::abs(centroIY - centroOY);
                
                float minX = (tamI.x + tamO.x) / 2.0f;
                float minY = (tamI.y + tamO.y) / 2.0f;

                float interX = minX - distX;
                float interY = minY - distY;
                
                if (interX < interY) {
                    if (centroIX < centroOX){
                        inim->setPosicao(sf::Vector2f(posI.x - interX, posI.y));
                    }
                    else{
                        inim->setPosicao(sf::Vector2f(posI.x + interX, posI.y));
                    }
                } 
                else {
                    if (centroIY < centroOY) {
                        inim->setPosicao(sf::Vector2f(posI.x, posI.y - interY));
                        inim->SetNoChao(true);
                    } 
                    else {
                        inim->setPosicao(sf::Vector2f(posI.x, posI.y + interY));
                    }
                }
            }
            ++it_obs;
        }
        ++it_inim;
    }
}

void GerenciadorDeColisoes::TratarColisoesJogsProjeteis()
{
    if (listaProjeteis.empty()) return;

    list<Projetil*>::iterator it_proj = listaProjeteis.begin();

    while (it_proj != listaProjeteis.end()) {
        Projetil* proj = *it_proj;

        if (proj->getVivo()) {
            if (pJogador && VerificarColisao(pJogador, proj)) {
                if (!pJogador->getImune()) {
                    proj->Danificar(pJogador);
                    pJogador->IniciarImunidade();
                }
            }

            if (pJogador2 && proj->getVivo() && VerificarColisao(pJogador2, proj)) {
                if (!pJogador2->getImune()) {
                    proj->Danificar(pJogador2);
                    pJogador2->IniciarImunidade();
                }
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

void GerenciadorDeColisoes::Executar() 
{
    TratarColisoesJogsObstacs();
    TratarColisoesInimigoObstacs();
    TratarColisoesJogsInimigo();
    TratarColisoesJogsProjeteis();
    RemoverInimigoInativo();
    RemoverObstaculoInativo();
    RemoverProjetilInativo();
}