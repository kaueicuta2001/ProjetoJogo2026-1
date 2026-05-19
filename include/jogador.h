#include "personagem.h"

class Jogador : public Personagem
{
    private:
        int pontos;
    public:
        Jogador(int num_vidas, int x, int y, int id, int pontos) : Personagem(num_vidas, x, y, id), pontos(pontos);
        ~Jogador();
        void executar();
        void salvar();
};