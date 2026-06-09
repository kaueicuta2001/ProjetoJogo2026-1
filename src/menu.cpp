#include "menu.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

Menu::Menu(int id) :
Ente(id),
opcao(0),
opcaoSelecionada(-1),
selecionado(false)
{
    tamanho = static_cast<Vector2f>(pGG->getWindow()->getSize());
    posicao = Vector2f(0.f, 0.f);
    opcoesMenu.push_back("Iniciar Jogo");
    opcoesMenu.push_back("Sair");
    InicializaBG();
    InicializaTextos();
}

Menu::~Menu()
{
}

void Menu::InicializaBG()
{
    if (!textura.loadFromFile("../assets/menuBG.png"))
        cerr << "Erro ao carregar a textura de fundo!" << endl;
    sprite.setTexture(textura);
    sprite.setPosition(posicao);
    sprite.setScale(
        tamanho.x / textura.getSize().x,
        tamanho.y / textura.getSize().y
    );
}

void Menu::InicializaTextos()
{    
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
        std::cerr << "Erro ao carregar a fonte!" << std::endl;

    titulo.setFont(fonte);
    titulo.setString("Menu Principal");
    titulo.setCharacterSize(40);
    titulo.setFillColor(sf::Color::White);
    titulo.setPosition(425.f, 175.f);

    for (size_t i = 0; i < opcoesMenu.size(); ++i)
    {
        Text textoLocal;
        textoLocal.setFont(fonte);
        textoLocal.setString(opcoesMenu[i]);
        textoLocal.setCharacterSize(24);
        textoLocal.setFillColor(sf::Color::White);
        textoLocal.setPosition(525.f, 375.f + i * 40.f);
        botoesMenu.push_back(textoLocal);
    }
}

void Menu::TratarEventos()
{
    Event event;

    while (pGG->getWindow()->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            pGG->getWindow()->close();
        }

        if (event.type == Event::KeyPressed)
        {
            if(event.key.code == Keyboard::Escape)
            {
                pGG->getWindow()->close();
            }
            if (event.key.code == Keyboard::W || event.key.code == Keyboard::Up){
                opcao = (opcao - 1 + opcoesMenu.size()) % opcoesMenu.size();
                std::cout << "W pressionado" << std::endl;
            }
            else if (event.key.code == Keyboard::S || event.key.code == Keyboard::Down){
                opcao = (opcao + 1) % opcoesMenu.size();
                std::cout << "S pressionado" << std::endl;
            }
            else if (event.key.code == Keyboard::Enter)
            {
                opcaoSelecionada = opcao + 1; // 1 para iniciar, 2 para sair
                selecionado = true;
                std::cout << "Enter pressionado, opção selecionada: " << opcaoSelecionada << std::endl;
            }

            std::cout << "Opção atual: " << opcao << std::endl;
        }

        // Atualiza as cores imediatamente quando o evento acontece
        for (size_t i = 0; i < botoesMenu.size(); ++i)
        {
            if (i == static_cast<size_t>(opcao))
                botoesMenu[i].setFillColor(Color::Yellow);
            else
                botoesMenu[i].setFillColor(Color::White);
        }
    }
}

bool Menu::getSelecionado() const
{
    return selecionado;
}

void Menu::setSelecionado(bool sel)
{
    selecionado = sel;
}

int Menu::getOpcaoSelecionada() const
{
    return opcaoSelecionada;
}

void Menu::Executar()
{
    Desenhar(); 

    pGG->getWindow()->draw(titulo);

    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        pGG->getWindow()->draw(botoesMenu[i]);
    }

    TratarEventos();
}