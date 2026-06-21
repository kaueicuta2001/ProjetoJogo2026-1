#include "gerenciadorDeColisoes.h"
#include <cmath>

using namespace std;
using namespace sf;

GerenciadorDeColisoes::GerenciadorDeColisoes(Jogador* jogador, Jogador* jogador2) :
pJogador(jogador),
pJogador2(jogador2),
listaInimigos(),
listaObstaculos(),
listaChao(),
listaProjeteis(),
totalColisoes(0)
{}

GerenciadorDeColisoes::~GerenciadorDeColisoes()
{
    listaInimigos.clear();
    listaObstaculos.clear();
    listaChao.clear();
    listaProjeteis.clear();
    pJogador = nullptr;
    pJogador2 = nullptr;
}

void GerenciadorDeColisoes::getTotalColisoes() const 
{
    cout << "Total de Colisões: " << totalColisoes << endl;
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

    float intersecaoX = somaMetadesX - distanciaX;
    float intersecaoY = somaMetadesY - distanciaY;

    if(intersecaoX > 0 && intersecaoY > 0) {
        intersecao = Vector2f(intersecaoX, intersecaoY);
    }

    return (intersecaoX > 0 && intersecaoY > 0);
}

void GerenciadorDeColisoes::TratarColisoesPersChao() {

    if(pJogador) {
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
    }
    
    if(pJogador2) {
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
    }

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
        }
    }
}

void GerenciadorDeColisoes::TratarColisoesJogsObstacs() {
    if (pJogador) pJogador->resetVelX();
    if (pJogador2) pJogador2->resetVelX();
    
    for (auto obstaculo : listaObstaculos) {
        if (pJogador && obstaculo && VerificarColisao(pJogador, obstaculo)) {
            sf::Vector2f posJ = pJogador->getPosicao();
            sf::Vector2f tamJ = pJogador->getTamanho();
            sf::Vector2f posO = obstaculo->getPosicao();
            sf::Vector2f tamO = obstaculo->getTamanho();

            if(intersecao.x < intersecao.y) {
                if (posJ.x < posO.x) {
                    pJogador->setPosicao(sf::Vector2f(posO.x - tamJ.x, posJ.y));
                    if(obstaculo->getDanoso()) {
                        obstaculo->Obstaculizar(pJogador);
                    }
                }
                else {
                    pJogador->setPosicao(sf::Vector2f(posO.x + tamO.x, posJ.y));
                    if(obstaculo->getDanoso()) {
                        obstaculo->Obstaculizar(pJogador);
                    }
                }
            } else {
                if (posJ.y < posO.y) {
                    pJogador->SetNoChao(true);
                    pJogador->setPosicao(sf::Vector2f(posJ.x, posO.y - tamJ.y));
                    obstaculo->Obstaculizar(pJogador);
                } else {
                    pJogador->setPosicao(sf::Vector2f(posJ.x, posO.y + tamO.y));
                    if(obstaculo->getDanoso()) {
                        obstaculo->Obstaculizar(pJogador);
                    }
                }
            }   
        }
        if (pJogador2 && obstaculo && VerificarColisao(pJogador2, obstaculo)) {
            sf::Vector2f posJ2 = pJogador2->getPosicao();
            sf::Vector2f tamJ2 = pJogador2->getTamanho();
            sf::Vector2f posO = obstaculo->getPosicao();
            sf::Vector2f tamO = obstaculo->getTamanho();
            
            if(intersecao.x < intersecao.y) {
                if (posJ2.x < posO.x) {
                    pJogador2->setPosicao(sf::Vector2f(posO.x - tamJ2.x, posJ2.y));
                    if(obstaculo->getDanoso()) {
                        obstaculo->Obstaculizar(pJogador2);
                    }
                }
                else {
                    pJogador2->setPosicao(sf::Vector2f(posO.x + tamO.x, posJ2.y));
                    if(obstaculo->getDanoso()) {
                        obstaculo->Obstaculizar(pJogador2);
                    }
                }
            } else {
                if (posJ2.y < posO.y) {
                    pJogador2->SetNoChao(true);
                    pJogador2->setPosicao(sf::Vector2f(posJ2.x, posO.y - tamJ2.y));
                    obstaculo->Obstaculizar(pJogador2);
                } else {
                    pJogador2->setPosicao(sf::Vector2f(posJ2.x, posO.y + tamO.y));
                    if(obstaculo->getDanoso()) {
                        obstaculo->Obstaculizar(pJogador2);
                    }
                }
            }
        }
        
    }
}

void GerenciadorDeColisoes::TratarColisoesJogsInimgs() {
    for (auto inimigo : listaInimigos) {
        if (inimigo->getVivo()) {
            if (pJogador && VerificarColisao(pJogador, inimigo)) {
                Vector2f posJ = pJogador->getPosicao();
                Vector2f tamJ = pJogador->getTamanho();
                Vector2f posI = inimigo->getPosicao();
                Vector2f tamI = inimigo->getTamanho();

                if (intersecao.x < intersecao.y) {
                    if (posJ.x < posI.x) {
                        if(!pJogador->getImune()){
                            inimigo->Danificar(pJogador);
                            pJogador->IniciarImunidade();
                            pJogador->setPosicao(Vector2f(posI.x - tamJ.x - 10.f, posJ.y - 10.f));
                        }
                    }
                    else {
                        if(!pJogador->getImune()){
                            inimigo->Danificar(pJogador);
                            pJogador->IniciarImunidade();
                            pJogador->setPosicao(Vector2f(posI.x + tamI.x + 10.f, posJ.y - 10.f));
                        }
                    }
                } else {
                    if (posJ.y < posI.y) {
                        pJogador->Pisar(inimigo);
                    } 
                    else {
                        if(!pJogador->getImune()){
                            if(posJ.x < posI.x) {
                                inimigo->Danificar(pJogador);
                                pJogador->IniciarImunidade();
                                pJogador->setPosicao(Vector2f(posI.x - tamJ.x - 10.f, posJ.y - 10.f));
                            }
                            else {
                                inimigo->Danificar(pJogador);
                                pJogador->IniciarImunidade();
                                pJogador->setPosicao(Vector2f(posI.x + tamI.x + 10.f, posJ.y - 10.f));
                            }
                        }
                    }
                }
            }

            if (pJogador2 && VerificarColisao(pJogador2, inimigo)) {
                Vector2f posJ2 = pJogador2->getPosicao();
                Vector2f tamJ2 = pJogador2->getTamanho();
                Vector2f posI = inimigo->getPosicao();
                Vector2f tamI = inimigo->getTamanho();

                if (intersecao.x < intersecao.y) {
                    if(posJ2.x < posI.x) {
                        if(!pJogador2->getImune()){
                            inimigo->Danificar(pJogador2);
                            pJogador2->IniciarImunidade();
                            pJogador2->setPosicao(Vector2f(posI.x - tamJ2.x - 10.f, posJ2.y - 10.f));
                        }
                    }
                    else {
                        if(!pJogador2->getImune()){
                            inimigo->Danificar(pJogador2);
                            pJogador2->IniciarImunidade();
                            pJogador2->setPosicao(Vector2f(posI.x + tamI.x + 10.f, posJ2.y - 10.f));
                        }
                    }
                } else{
                    if(posJ2.y < posI.y) {
                        pJogador2->Pisar(inimigo);
                    }
                    else {
                        if(!pJogador2->getImune()){
                            if(posJ2.x < posI.x) {
                                inimigo->Danificar(pJogador2);
                                pJogador2->IniciarImunidade();
                                pJogador2->setPosicao(Vector2f(posI.x - tamJ2.x - 10.f, posJ2.y - 10.f));
                            }
                        }
                        else {
                            if(!pJogador2->getImune()){
                                inimigo->Danificar(pJogador2);
                                pJogador2->IniciarImunidade();
                                pJogador2->setPosicao(Vector2f(posI.x + tamI.x + 10.f, posJ2.y - 10.f));
                            }
                        }
                    }
                }
            }
        }
    }
}

void GerenciadorDeColisoes::TratarColisoesJogsProjeis() {
    if(pJogador) {
        for (auto projetil : listaProjeteis) {
            if (projetil->getVivo() && VerificarColisao(pJogador, projetil)) {
                if(!pJogador->getImune()) {
                    projetil->Danificar(pJogador);
                    pJogador->IniciarImunidade();
                }
                projetil->Desativar();
            }
        }
    }
    if(pJogador2) {
        for (auto projetil : listaProjeteis) {
            if (projetil->getVivo() && VerificarColisao(pJogador2, projetil)) {
                if(!pJogador2->getImune()) {
                    projetil->Danificar(pJogador2);
                    pJogador2->IniciarImunidade();
                }
                projetil->Desativar();
            }
        }
    }
}

void GerenciadorDeColisoes::TratarColisoesInimgsObstacs(){
    for(auto inimigo : listaInimigos){
        for(auto obstaculo : listaObstaculos){
            if(inimigo && obstaculo && VerificarColisao(inimigo, obstaculo) && obstaculo->getColide() && inimigo->getColideObstaculo()){
                Vector2f posI = inimigo->getPosicao();
                Vector2f tamI = inimigo->getTamanho();
                Vector2f posO = obstaculo->getPosicao();
                Vector2f tamO = obstaculo->getTamanho();

                if(intersecao.x < intersecao.y){
                    if(posI.x < posO.x)
                        inimigo->setPosicao(sf::Vector2f(posO.x - tamI.x, posI.y));
                    else
                        inimigo->setPosicao(sf::Vector2f(posO.x + tamO.x, posI.y));
                }
                else{
                    if(posI.y < posO.y){
                        inimigo->SetNoChao(true);
                        inimigo->setPosicao(sf::Vector2f(posI.x, posO.y - tamI.y));
                    }
                    else
                        inimigo->setPosicao(sf::Vector2f(posI.x, posO.y + tamO.y));
                }
                    
            }
        }
    }
}

void GerenciadorDeColisoes::Executar() {
    TratarColisoesPersChao();
    TratarColisoesJogsObstacs();
    TratarColisoesJogsInimgs();
    TratarColisoesJogsProjeis();
    TratarColisoesInimgsObstacs();

    RemoverInimigoInativo();
    RemoverObstaculoInativo();
    RemoverProjetilInativo();

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
