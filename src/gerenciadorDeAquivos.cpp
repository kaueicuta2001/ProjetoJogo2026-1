#include "gerenciadordearquivos.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace TheFrog::Gerenciadores;

GerenciadorDeArquivos::GerenciadorDeArquivos()
{
    limiteRegistros = 5;
}

GerenciadorDeArquivos::~GerenciadorDeArquivos() {}

void GerenciadorDeArquivos::SalvarPontuacao(string nome, int pontos, int tempo, int qtdJogadores, int fase)
{
    string nomeArquivo = "ranking_" + to_string(qtdJogadores) + "P_F" + to_string(fase) + ".txt";
    
    try 
    {
        ofstream arquivoSalvar(nomeArquivo, ios::app);
        if (!arquivoSalvar)
            throw runtime_error("Erro ao abrir " + nomeArquivo);
        
        arquivoSalvar << nome << " " << pontos << " " << tempo << endl;
        arquivoSalvar.close();
    } 
    catch (const exception& e) {
        cerr << "Excecao: " << e.what() << endl;
    }
}

struct Registro {
    string nome;
    int pontos;
    int tempo; 
    
    bool operator<(const Registro& outro) const {
        if (pontos != outro.pontos)
            return pontos > outro.pontos;
        return tempo < outro.tempo;
    }
};

vector<string> GerenciadorDeArquivos::LerRanking(int qtdJogadores, int fase) {
    vector<Registro> registros;
    vector<string> rankingFormatado;
    string nomeArquivo = "ranking_" + to_string(qtdJogadores) + "P_F" + to_string(fase) + ".txt";

    try {
        ifstream arquivoLer(nomeArquivo);
        if (!arquivoLer) {
            rankingFormatado.push_back("Nenhum recorde salvo.");
            return rankingFormatado;
        }

        string nome;
        int pontos;
        int tempo;
        
        while (arquivoLer >> nome >> pontos >> tempo) {
            registros.push_back({nome, pontos, tempo});
        }
        arquivoLer.close();

        sort(registros.begin(), registros.end());

        for (size_t i = 0; i < registros.size() && i < 5; ++i) {
            int min = registros[i].tempo / 60;
            int sec = registros[i].tempo % 60;
            string strTempo = (min < 10 ? "0" : "") + to_string(min) + ":" + (sec < 10 ? "0" : "") + to_string(sec);
            
            string formatado = to_string(i + 1) + ". " + registros[i].nome + " | " + to_string(registros[i].pontos) + " pts | " + strTempo;
            rankingFormatado.push_back(formatado);
        }

    } catch (const exception& e) {
        cerr << "Excecao ao ler: " << e.what() << endl;
    }

    if (rankingFormatado.empty()) rankingFormatado.push_back("Ranking vazio.");
    
    return rankingFormatado;
}