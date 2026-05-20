#include "jogo.h"

using namespace std;
using namespace sf;

Jogo::Jogo() :
janela(VideoMode(800, 600), "Projeto Jogo"),
jogador(3, 50, 50, 1, 0),
plataforma(20, false, 1, 2, 60),
obstdificil(50, true, 5, 6, 40),
obstmedio(62.5, false, 6, 8, 50),
inimigoeasy(5.9, 23, 5, 6, 4, 69),
inimigomedio(60, 24, 8, 45, 65, 4647)
{
    Executar();
}

Jogo::~Jogo()
{
    
}
void Jogo::Executar()
{
    plataforma.executar();
    plataforma.salvar();

    obstdificil.executar();
    obstdificil.salvar();

    obstmedio.executar();
    obstmedio.salvar();

    jogador.executar();
    jogador.salvar();

    inimigoeasy.executar();
    inimigoeasy.salvar();

    inimigomedio.executar();
    inimigomedio.salvar();

    while (janela.isOpen())//verifica se a janela está aberta
    {
        sf::Event event;//Event é a classe que representa um evento, como um clique do mouse ou uma tecla pressionada.
        while (janela.pollEvent(event))//verifica se há algum evento durante a execução do jogo
        {
            if (event.type == Event::Closed)//se clicar no x da janela
                janela.close();//fecha a janela
            
            else if(event.type == Event::KeyPressed)//se pressionar uma tecla
            {
                if (event.key.code == Keyboard::Escape)//se a tecla for escape
                    janela.close();//fecha a janela
            }
        }

        janela.clear();

        // Desenhar aqui
        jogador.desenhar(janela);

        janela.display();
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