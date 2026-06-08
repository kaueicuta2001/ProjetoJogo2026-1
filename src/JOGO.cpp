#include "jogo.h"

using namespace sf;

Jogo::Jogo() :
GG(GerenciadorGrafico::getGerenciadorGrafico()),
pJogador(nullptr),
menu(nullptr),
faseAtual(nullptr),
opcaoSelecionada(0)
{
    Ente::setGG(GG);
    pJogador = new Jogador(5, Vector2f(50.f, 50.f));
    menu = new Menu(0);
    faseAtual = new Fase1(1, pJogador);
}

Jogo::~Jogo() {
    if(pJogador)
        delete pJogador;
    if(faseAtual)
        delete faseAtual;
    if(menu)
        delete menu;
}


void Jogo::Executar()
{
    while (GG->VerificaJanelaAberta())
    {
        /*Event event;

        while (GG->getWindow()->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                GG->FecharJanela();
            }
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    GG->FecharJanela();
                }
            }
        }*/

        GG->LimpaJanela();
        std::cout << "Janela limpa" << std::endl;
        
        switch(opcaoSelecionada)
        {
            case 0:
                std::cout << "Executando menu..." << std::endl;
                menu->Executar();
                if(menu->getSelecionado()){
                    opcaoSelecionada = menu->getOpcaoSelecionada();
                    menu->setSelecionado(false);
                }
                break;
            case 1:
                faseAtual->Executar();
                break;
            case 2:
                GG->FecharJanela();
                break;
            default:
                break;
        }
    
        GG->Renderizar();
    }
}