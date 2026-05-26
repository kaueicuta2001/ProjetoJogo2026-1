#include "jogo.h"
#include "ente.h"
#include "jogador.h"
#include "plataforma.h"
#include "inimigoeasy.h"

using namespace std;
using namespace sf;

Jogo::Jogo() :
GG(GerenciadorGrafico::getGerenciadorGrafico())
{
    Ente::setGG(GG);
    Executar();
}

Jogo::~Jogo()
{
    
}

void Jogo::InstanciarEntidades()
{
    Jogador* pJogador = new Jogador(3, Vector2f(100, 100));
    Plataforma* pPlataforma = new Plataforma(2, Vector2f(150, 150), false);
    InimigoEasy* pInimigoEasy = new InimigoEasy(1, Vector2f(200, 200), 50);

    listaEnts.Incluir(pJogador);
    listaEnts.Incluir(pPlataforma);
    listaEnts.Incluir(pInimigoEasy);
}

void Jogo::Executar()
{
    InstanciarEntidades();

    while (GG->VerificaJanelaAberta())//verifica se a janela está aberta
    {
        sf::Event event;//Event é a classe que representa um evento, como um clique do mouse ou uma tecla pressionada.
        while (GG->getWindow()->pollEvent(event))//verifica se há algum evento durante a execução do jogo
        {
            if (event.type == Event::Closed)//se clicar no x da janela
                GG->FecharJanela();//fecha a janela
            
            else if(event.type == Event::KeyPressed)//se pressionar uma tecla
            {
                if (event.key.code == Keyboard::Escape)//se a tecla for escape
                    GG->FecharJanela();//fecha a janela
            }
        }

        GG->LimpaJanela();

        listaEnts.Percorrer();

        GG->Renderizar();
    }
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar:
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln