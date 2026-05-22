#include "jogador.h"

using namespace std;

Jogador::Jogador(int id, sf::Vector2f pos, int num_vidas) :
Personagem(id, pos, num_vidas), pontos(pontos)
{
    vel = sf::Vector2f(1.f, 1.f);
    cor = sf::Color::Green;

    corpo.setSize(sf::Vector2f(50.f, 50.f));
    corpo.setFillColor(cor);
    corpo.setPosition(pos);

    cout << "objeto criado com sucesso....." << endl;
    cout << "o jogador tem " << num_vidas << " vidas" << endl;
    cout << "o jogador tem " << pontos << " pontos" << endl;
}

Jogador::~Jogador()
{
}

void Jogador::Desenhar(sf::RenderWindow& janela)
{
    janela.draw(corpo);
}

void Jogador::Executar()
{
    cout << "Executando...jogador" << endl;
}

void Jogador::Salvar()
{
    cout << "Salvando...jogador" << endl;
}