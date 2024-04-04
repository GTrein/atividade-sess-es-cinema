#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>
#include <Windows.h>

using namespace std;


class Assento
{
public:
	Assento();
	Assento(string nome, string cpf, bool ocupado, string sprite);
	void setNome(string nome);
	void setCPF(string cpf);
	void setOcupado(bool ocupado);
	void setSprite(string sprite);

	string getNome();
	string getCPF();
	bool getOcupado();
	string getSprite();

private:
	string nome;
	string cpf;
	bool ocupado;
	string sprite;



};

#endif