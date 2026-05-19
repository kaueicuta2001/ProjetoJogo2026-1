#include "Jogo.h"

using namespace std;

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
    }
    void salvar()
    {
        cout << "Salvando..." << endl;
        cout << "\n" << endl;
    }
};



// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar:
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln