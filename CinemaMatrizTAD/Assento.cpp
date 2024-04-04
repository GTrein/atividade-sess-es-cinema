#include "Assento.h"

Assento::Assento() {};


Assento::Assento(string nome, string cpf, bool ocupado, string sprite)
{
	this->nome = nome;
	this->cpf = cpf;
	this->ocupado = ocupado;
	this->sprite = sprite;

}

void Assento::setNome(string nome)
{
	this->nome = nome;
}
void Assento::setCPF(string cpf)
{
	this->cpf = cpf;
}
void Assento::setOcupado(bool ocupado)
{
	this->ocupado = ocupado;
}
void Assento::setSprite(string sprite)
{
	this->sprite = sprite;
}

string Assento::getNome()
{
	return nome;
}
string Assento::getCPF()
{
	return cpf;
}
bool Assento::getOcupado()
{
	return ocupado;
}
string Assento::getSprite()
{
	return sprite;
}