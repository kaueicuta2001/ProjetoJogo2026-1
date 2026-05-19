#include "bigchief.h"

BigChief::BigChief(short int forca, int nivel_maldade, int num_vidas, int x, int y, int id) : Inimigo(nivel_maldade, num_vidas, x, y, id), forca(forca)
{
}

BigChief::~BigChief()
{
}