#include "jogador.h"

using namespace std;

Jogador::Jogador(int pontos, int num_vidas, int x, int y, int id) :
Personagem(num_vidas, x, y, id), pontos(pontos)
{
    corpo.setSize(sf::Vector2f(50, 50));
    corpo.setFillColor(sf::Color::Green);
    corpo.setPosition(x, y);

    cout << "objeto criado com sucesso....." << endl;
    cout << "o jogador tem " << num_vidas << " vidas" << endl;
    cout << "o jogador tem " << pontos << " pontos" << endl;
}

Jogador::~Jogador()
{
}

void Jogador::desenhar(sf::RenderWindow& janela)
{
    janela.draw(corpo);
}

void Jogador::executar()
{
    cout << "Executando...jogador" << endl;
}

void Jogador::salvar()
{
    cout << "Salvando...jogador" << endl;
}