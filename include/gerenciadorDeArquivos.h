#pragma once
#include <vector>
#include <string>

class GerenciadorDeArquivos {
private:
    int limiteRegistros;
public:
    GerenciadorDeArquivos();
    ~GerenciadorDeArquivos();

    static void SalvarPontuacao(std::string nome, int pontos, int tempo, int qtdJogadores, int fase);
    static std::vector<std::string> LerRanking(int qtdJogadores, int fase);
};