#include "menu.h"
#include "jogo.h"
#include "gerenciadorgrafico.h"

using namespace std;
using namespace sf;

Menu::Menu(int id, Jogo* jogo) :
Ente(id),
opcaoIndice(0),
opcaoSelecionada(-1),
selecionado(false),
pJog(jogo),
event()
{
    tamanho = static_cast<Vector2f>(pGG->getWindow()->getSize());
    posicao = Vector2f(0.f, 0.f);
    InicializaBG();
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

void Menu::InicializaBotoes()
{    
    if (!fonte.loadFromFile("../assets/Frijole-Regular.ttf"))
    std::cerr << "Erro ao carregar a fonte!" << std::endl;
        
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

void Menu::NavegarOpcao()
{
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
                opcaoIndice = (opcaoIndice - 1 + opcoesMenu.size()) % opcoesMenu.size();
            }
            else if (event.key.code == Keyboard::S || event.key.code == Keyboard::Down){
                opcaoIndice = (opcaoIndice + 1) % opcoesMenu.size();
            }
            else if (event.key.code == Keyboard::Enter)
            {
                opcaoSelecionada = opcaoIndice;
                selecionado = true;
            }

            std::cout << "Opção atual: " << opcaoIndice << std::endl;
        }
    }
}

void Menu::DesenharBotoes()
{
    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        if (i == static_cast<size_t>(opcaoIndice))
            botoesMenu[i].setFillColor(Color::Yellow);
        else    
            botoesMenu[i].setFillColor(Color::White);
    }
    
    for (size_t i = 0; i < botoesMenu.size(); ++i)
    {
        pGG->getWindow()->draw(botoesMenu[i]);
    }
}

bool Menu::getSelecionado() const
{
    return selecionado;
}