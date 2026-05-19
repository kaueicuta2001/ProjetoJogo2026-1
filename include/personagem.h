#include "entidade.h"

class Personagem : public Entidade
{
    protected:
        int num_vidas;
    public:
        Personagem(int num_vidas, int x, int y, int id) : Entidade(x, y, id), num_vidas(num_vidas);
        ~Personagem();
        virtual void executar() = 0;
        virtual void salvar() = 0;
};
