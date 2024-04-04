#include <iostream>
#include "Assento.h"
#include <vector>
using namespace std;
class Sistema
{
public:


	Sistema();

	void Executar();
	void InicializarMatriz();
	


private:
	int ImprimirSalas();
	int MenuInicial();
	void ReservarAssento();
	void MostrarSalas();
	void PreencherSala();
	void Administrador();
	void cancelarReserva();
	void infoReserva();
	int MenuAdministrador();
	int LetraPraNumero(char letra);
	Assento sala1[10][15];
	Assento sala2[10][15];
};