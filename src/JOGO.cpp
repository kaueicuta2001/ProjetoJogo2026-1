// JOGO.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Ente
{
    protected:
        int id;
    public:
        Ente(int id) : id(id) {}
        virtual ~Ente() {}
        virtual void executar() = 0;
        //void desenhar() {}
};

class Entidade : public Ente
{
    protected:
        int x;
        int y;
    public:
        Entidade(int x, int y, int id) : Ente(id), x(x), y(y)
        {

        }
        virtual ~Entidade(){}
        virtual void executar() = 0;
        virtual void salvar() = 0;
};

class Personagem : public Entidade
{
    protected:
        int num_vidas;
    public:
        Personagem(int num_vidas, int x, int y, int id) : Entidade(x, y, id), num_vidas(num_vidas)
        {

        }
        ~Personagem(){}
        virtual void executar() = 0;
        virtual void salvar() = 0;
};

class Inimigo : public Personagem
{
    protected:
        int nivel_maldade;
    public:
        Inimigo(int nivel_maldade, int num_vidas, int x, int y, int id) : Personagem(num_vidas, x, y, id), nivel_maldade(nivel_maldade)
        {

        }
        virtual ~Inimigo(){}
        virtual void executar() = 0;
        virtual void salvar() = 0;
};

class BigChief : public Inimigo
{
    private:
        short int forca;
    public:
        BigChief(short int forca, int nivel_maldade, int num_vidas, int x, int y, int id) : Inimigo(nivel_maldade, num_vidas, x, y, id), forca(forca)
        {
        }
        ~BigChief() override{}
};

class InimigoMedio : public Inimigo
{
    private:
        int tamanho;
    public:
        InimigoMedio(int tamanho, int nivel_maldade, int num_vidas, int x, int y, int id) : Inimigo(nivel_maldade, num_vidas, x, y, id), tamanho(tamanho)
        {

        }
        ~InimigoMedio() override{}
        void executar()
        {
            cout << "Executando...Inimigo medio" << endl;
            getchar();
        }
        void salvar()
        {
            cout << "Salvando..." << endl;
            cout << "\n" << endl;
        }
};

class InimigoEasy : public Inimigo
{
private:
    float raio;
public:
    InimigoEasy(float raio, int nivel_maldade, int num_vidas, int x, int y, int id) : Inimigo(nivel_maldade, num_vidas, x, y, id), raio(raio)
    {

    }
    ~InimigoEasy() override{}
    void executar()
    {
        cout << "Executando...Inimigo facil" << endl;
        getchar();
    }
    void salvar()
    {
        cout << "Salvando..." << endl;
        cout << "\n" << endl;

    }
};

class Jogador : public Personagem
{
protected:
    int pontos;
public:
    Jogador(int pontos, int num_vidas, int x, int y, int id) : Personagem(num_vidas, x, y, id), pontos(pontos)
    {
        cout << "objeto criado com sucesso....." << endl;
        cout << "o jogador tem " << num_vidas << " vidas" << endl;
        cout << "As coordenadas do jogador sao de: " << x << " para x, e :" << y << " para y" << endl;
        cout << "O id do objeto jogador eh: " << id << endl;
    }
    ~Jogador() override{}
    void executar()
    {
        cout << "Executando...jogador" << endl;
        getchar();
    }
    void salvar()
    {
        cout << "Salvando...jogador" << endl;
        cout << "\n" << endl;

    }
};

class Obstaculo : public Entidade
{
protected:
    bool danoso;
public:
    Obstaculo(bool danoso, int x, int y, int id) : Entidade(x, y, id), danoso(danoso)
    {

    }
    ~Obstaculo(){}

    virtual void executar() = 0;
    virtual void salvar() = 0;
};

class Plataforma : public Obstaculo
{
private:
    int altura;
public:
    Plataforma(int altura, bool danoso, int x, int y, int id) : Obstaculo(danoso, x, y, id), altura(altura)
    {
        cout << "objeto criado com sucesso....." << endl;
        cout << "A plataforma tem a altura de:" << altura << endl;
        (danoso) ? cout << "A plataforma eh danosa" << endl : cout << "A plataforma nop eh danosa" << endl;
        cout << "As coordenadas da plataforma sao de :" << x << " para x, e :" << y << " para y" << endl;
        cout << "O id do objeto plataforma eh: " << id << endl;
    }
    ~Plataforma() override {}
    void executar()
    {
        cout << "Executando...Plataforma" << endl;
        getchar();
    }
    void salvar()
    {
        cout << "Salvando..." << endl;
        cout << "\n" << endl;

    }
};

class ObstDificil : public Obstaculo
{
private:
    short int danosidade;
public:
    ObstDificil(short int danosidade, bool danoso, int x, int y, int id) : Obstaculo(danoso, x, y, id), danosidade(danosidade)
    {
        cout << "objeto criado com sucesso....." << endl;
        cout << "A taxa de danosidade é de :" << danosidade << endl;
        (danoso) ? cout << "O obstaculodificil eh danosa" << endl : cout << "O obstaculodificil nop eh danosa" << endl;
        cout << "As coordenadas do obstaculodificil sao de :" << x << " para x, e :" << y << " para y" << endl;
        cout << "O id do objeto obstaculodificil eh: " << id << endl;
    }
    ~ObstDificil() override{}
    void executar()
    {
        cout << "Executando...Obstaculo Dificil" << endl;
        getchar();
    }
    void salvar()
    {
        cout << "Salvando..." << endl;
        cout << "\n" << endl;

    }

};

class ObstMedio : public Obstaculo
{
private:
    float largura;

public:
    ObstMedio(float largura, bool danoso, int x, int y, int id) : Obstaculo(danoso, x, y, id), largura(largura)
    {
        cout << "objeto criado com sucesso....." << endl;
        cout << "A lagura do obstMedio eh de :" << largura << endl;
        (danoso) ? cout << "O obstaculo eh danosa" << endl : cout << "O obstaculomedio nop eh danosa" << endl;
        cout << "As coordenadas do obstaculomedio sao de :" << x << " para x, e :" << y << " para y" << endl;
        cout << "O id do objeto obstaculomedio eh: " << id << endl;
    }
    ~ObstMedio() override{}
    void executar()
    {
        cout << "Executando...Obstaculo medio" << endl;
        getchar();
    }
    void salvar()
    {
        cout << "Salvando..." << endl;
        cout << "\n" << endl;
    }
};

int main()
{
    Plataforma plat(20, false, 1, 2, 60);
    plat.executar();
    plat.salvar();

    ObstDificil hard(50, true, 5, 6, 40);
    hard.executar();
    hard.salvar();

    ObstMedio medium(62.5, false, 6, 8, 50);
    medium.executar();
    medium.salvar();

    Jogador jgd(35, 10, 8, 9, 47);
    jgd.executar();
    jgd.salvar();

    InimigoEasy easy(5.9, 23, 5, 6, 4, 69);
    easy.executar();
    easy.salvar();

    InimigoMedio mediumini(60, 24, 8, 45, 65, 4647);
    mediumini.executar();
    mediumini.salvar();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Projeto Jogo");//RenderWindow é a classe que representa a janela do jogo, e é nela que tudo será desenhado.
    //O primeiro parâmetro é o tamanho da janela, e o segundo é o título da janela.

    sf::RectangleShape jogador(sf::Vector2f(50,50));//RectangleShape é a classe que representa um retângulo.
    jogador.setFillColor(sf::Color::Green);//setFillColor é a função que define a cor do retângulo, e sf::Color é a classe que representa uma cor.
    jogador.setPosition(50, 50);//setPosition é a função que define a posição do retângulo, e os parâmetros são as coordenadas x e y.

    while (window.isOpen())//verifica se a janela está aberta
    {
        sf::Event event;//Event é a classe que representa um evento, como um clique do mouse ou uma tecla pressionada.
        while (window.pollEvent(event))//verifica se há algum evento durante a execução do jogo
        {
            if (event.type == sf::Event::Closed)//se clicar no x da janela
                window.close();//fecha a janela
            
            else if(event.type == sf::Event::KeyPressed)//se pressionar uma tecla
            {
                if (event.key.code == sf::Keyboard::Escape)//se a tecla for escape
                    window.close();//fecha a janela
            }
        }

        window.clear();

        // Desenhar aqui
        window.draw(jogador);//draw é a função que desenha o retângulo na janela, e o parâmetro é o objeto que queremos desenhar.

        window.display();
    }

    return 0;
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