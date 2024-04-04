#include "Sistema.h"
#include <locale.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "portuguese");
	Sistema meuSistema;
	meuSistema.InicializarMatriz();
	meuSistema.Executar();

	return 0;
}