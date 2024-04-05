#include "Sistema.h"
#include <algorithm>
using namespace std;
int sala1Ocupacao;
int sala2Ocupacao;

Sistema::Sistema()
{
	cout << "Sistema rodando\n";
}

void Sistema::InicializarMatriz()
{
	for (int l = 0; l < 10; ++l) {
		for (int c = 0; c < 15; ++c) {
			sala1[l][c] = Assento("", "", false,"(-)");
			sala2[l][c] = Assento("", "", false,"(-)");
		}
	}
}

int Sistema::MenuInicial()
{
	int escolha;
	system("cls");
	cout << "===== Menu =====\n";
	cout << "1 - Reservar assento.\n";
	cout << "2 - Ver sessões.\n";
	cout << "3 - Entrar como administrador.\n";
	cout << "4 - Sair.\n";
	
	cin >> escolha;
	return escolha;
}

void Sistema::Executar()
{
	int escolha;
	do
	{
		escolha = MenuInicial();

		switch (escolha)
		{
		case 1:
			
	
			//reservar assento
			ReservarAssento();
			system("pause");
			break;
		case 2:
			//ver sessoes

			MostrarSalas();
			system("pause");
			break;
		case 3:
			//entrar como administrador
			
			Administrador();
			
			break;
		case 4:
			//encerrar programa
			break;
		default:
			cout << "Escolha inválida.\n";
			break;
		}
	} while (escolha != 4);

}

int Sistema::ImprimirSalas()
{
	int escolha = 0;
	cout << "\nqual sessão você quer ver?(1 ou 2):\n";
	cin >> escolha;
	switch (escolha)
	{
	case 1:
		system("cls");
		cout << "                      Sala 1                      \n" << endl;
		cout << "   1  2  3   4  5  6  7  8  9  10 11 12  13 14 15\n";
		for (int l = 0; l < 10; ++l) {
			cout << static_cast<char>(74 - l) << " ";
			for (int c = 0; c < 15; ++c) {
				cout << sala1[l][c].getSprite();
				if (c == 2 || c == 11)
					cout << " ";

			}
			cout << endl;

		}
		cout << "--______________________________________________--\n";
		cout << "--___________________  TELA  ___________________--\n\n";
		
		
		break;
	case 2:
		system("cls");
		cout << "                      Sala 2                      \n" << endl;
		cout << "   1  2  3   4  5  6  7  8  9  10 11 12  13 14 15\n";
		for (int l = 0; l < 10; ++l) {
			cout << static_cast<char>(74 - l) << " ";
			for (int c = 0; c < 15; ++c) {
				cout << sala2[l][c].getSprite(); 
				if (c == 2 || c == 11)
					cout << " ";

			}
			cout << endl;

		}
		cout << "--______________________________________________--\n";
		cout << "--___________________  TELA  ___________________--\n\n";
		
		
		break;
	default:
		cout << "Essa sessão não existe.\n";
		
		return 0;
		break;
		
	}
	return escolha;
}

void Sistema::MostrarSalas()
{
	ImprimirSalas();

}

void Sistema::ReservarAssento()
{
	char letra;
	int numero;
	int numeroLetra;
	int sala;
	string nome;
	string cpf;
	sala = ImprimirSalas();

	if (sala == 0) {
		return;
	}
	else if (sala == 1) {
		if (sala1Ocupacao >= 150 && sala2Ocupacao < 150) {
			cout << "A sessão 1 está lotada porém ainda há espaço na sessão 2!\n";
			return;
		}else if (sala1Ocupacao >= 150 && sala2Ocupacao >= 150) {
		cout << "As duas sessões estão lotadas, volte mais tarde.\n";
		return;
		}
		else if (sala == 2) {
			if (sala2Ocupacao >= 150 && sala1Ocupacao < 150) {
				cout << "A sessão 1 está lotada porém ainda há espaço na sessão 2!\n";
				return;
			}
			else if (sala1Ocupacao >= 150 && sala2Ocupacao >= 150) {
				cout << "As duas sessões estão lotadas, volte mais tarde.\n";
				return;
			}
		}
	}
	cout << "Escolha um assento(exemplo A3): ";
	cin >> letra;
	numeroLetra = LetraPraNumero(letra);
	cin >> numero;
	
	if (numero < 1 || numero > 15 || numeroLetra > 9 || numeroLetra < 0)
	{
		cout << "esse assento não existe.\n";
		return;

	}

	if (sala == 1)
	{
	if (sala1[numeroLetra][numero - 1].getOcupado() == true) {
		cout << "esse assento está ocupado.\n";
		return;
	}
		sala1[numeroLetra][numero - 1].setOcupado(true);
		sala1Ocupacao++;
		sala1[numeroLetra][numero - 1].setSprite("(X)");
		cout << "Qual o nome para a reserva?\n";
		cin >> nome;
		sala1[numeroLetra][numero-1].setNome(nome);
		cout << "Qual o CPF para a reserva?\n";
		cin >> cpf;
		sala1[numeroLetra][numero - 1].setCPF(cpf);
	}
	else if (sala == 2) {
	if (sala2[numeroLetra][numero - 1].getOcupado() == true) {
		cout << "esse assento está ocupado.\n";
		return;
	}
		sala2[numeroLetra][numero-1].setOcupado(true);
		sala2Ocupacao++;
		sala2[numeroLetra][numero-1].setSprite("(X)");
		cout << "Qual o nome para a reserva?\n";
		cin >> nome;
		sala2[numeroLetra][numero-1].setNome(nome);
		cout << "Qual o CPF para a reserva?\n";
		cin >> cpf;
		sala2[numeroLetra][numero - 1].setCPF(cpf);
	}
}

int Sistema::LetraPraNumero(char letra)
{
	
	int num = 0;
		
		letra = toupper(letra);
		

		num = static_cast<int>(letra);
		num = 74 - num;
		
		return num;
}

void Sistema::PreencherSala()
	{
	int escolha = 0;
	cout << "\nqual sessão você quer preencher?(uso apenas para testes)\n";
	cin >> escolha;
	switch (escolha)
	{
	case 1:

		for (int l = 0; l < 10; ++l) {
			for (int c = 0; c < 15; ++c) {
				if (sala1[l][c].getOcupado() == false)
					sala1Ocupacao++;
				sala1[l][c] = Assento("Template", "000.000.000-00", true, "(X)");
				

			}
		}
		cout << "Sala preenchida com sucesso!" << endl;
		return;
		break;
	case 2:

		for (int l = 0; l < 10; ++l) {
			for (int c = 0; c < 15; ++c) {
				if (sala2[l][c].getOcupado() == false)
					sala2Ocupacao++;
				sala2[l][c] = Assento("Template", "000.000.000-00", true, "(X)");
				
			}
		}
		cout << "Sala preenchida com sucesso!" << endl;
		return;
		break;
	default:
		cout << "Essa sessão não existe.\n";
		return;
		break;


	}
}

int Sistema::MenuAdministrador()
{
	int escolha;
	system("cls");
	cout << "=== Administrador ===\n";
	cout << "1 - Preencher sala.\n";
	cout << "2 - Informações da reserva.\n";
	cout << "3 - Cancelar reserva.\n";
	cout << "4 - Sair.\n";
	cin >> escolha;
	return escolha;
}

void Sistema::Administrador()
{
	int escolha;
	int numeroLetra;
	int numero;
	char letra = '=';
	int sala;
	do
	{
		escolha = MenuAdministrador();
	switch (escolha)
	{
	case 1:
		PreencherSala();
		system("pause");
		break;
	case 2:
		infoReserva();
		system("pause");
		break;
	case 3:
		cancelarReserva();
		system("pause");
		break;
	case 4:
		//encerrar programa
		break;
	default:
		cout << "Escolha inválida.\n";
		break;
	}
 }while(escolha != 4);
}

void Sistema::infoReserva()
{

	int numeroLetra;
	int numero;
	char letra = '=';
	int sala;
	string nome;
	string cpf;
	sala = ImprimirSalas();
	

	switch (sala)
	{
	case 1:

		cout << "Qual assento?\n";
		cin >> letra;
		numeroLetra = LetraPraNumero(letra);
		cin >> numero;
		if (numero < 1 || numero > 15 || numeroLetra > 9 || numeroLetra < 0)
		{
			cout << "esse assento não existe.\n";
			return;

		}
		else if (sala2[numeroLetra][numero - 1].getOcupado() == false) {
			cout << "esse assento está vazio.\n";
			return;
		}
		nome = sala1[numeroLetra][numero - 1].getNome();
		cpf = sala1[numeroLetra][numero - 1].getCPF();
		cout << "O assento " << letra << numero - 1 << " está reservado para " << nome << " com o cpf: " << cpf << ".\n";
		return;
		break;
	case 2:

		cout << "Qual assento?\n";
		cin >> letra;
		numeroLetra = LetraPraNumero(letra);
		cin >> numero;
		if (numero < 1 || numero > 15 || numeroLetra > 9 || numeroLetra < 0)
		{
			cout << "esse assento não existe.\n";
			return;

		}
		else if (sala2[numeroLetra][numero - 1].getOcupado() == false) {
			cout << "esse assento está vazio.\n";
			return;
		}
		nome = sala2[numeroLetra][numero - 1].getNome();
		cpf = sala2[numeroLetra][numero - 1].getCPF();
		cout << "O assento " << letra << numero - 1 << " está reservado para " << nome << " com o cpf: " << cpf << ".\n";
		return;
		break;
	default:
		cout << "Essa sessão não existe.\n";
		Sleep(1000);
		break;
	}
}

void Sistema::cancelarReserva()
{

	int numeroLetra;
	int numero;
	char letra = '=';
	int sala;
	sala = ImprimirSalas();


	switch (sala)
	{
	case 1:

		cout << "Qual assento?\n";
		cin >> letra;
		numeroLetra = LetraPraNumero(letra);
		cin >> numero;
		if (numero < 1 || numero > 15 || numeroLetra > 9 || numeroLetra < 0)
		{
			cout << "esse assento não existe.\n";
			return;

		}
		else if (sala1[numeroLetra][numero - 1].getOcupado() == false) {
			cout << "esse assento não estava ocupado.\n";
			return;
		}
		sala1[numeroLetra][numero - 1].setOcupado(false);
		sala1Ocupacao--;
		sala1[numeroLetra][numero - 1].setSprite("(-)");
		sala1[numeroLetra][numero - 1].setNome("");
		sala1[numeroLetra][numero - 1].setCPF("");
		cout << "Reserva " << letra << numero << " foi cancelada com sucesso!\n";
		return;
		break;
	case 2:

		cout << "Qual assento?\n";
		cin >> letra;
		numeroLetra = LetraPraNumero(letra);
		cin >> numero;
		if (numero < 1 || numero > 15 || numeroLetra > 9 || numeroLetra < 0)
		{
			cout << "esse assento não existe.\n";
			return;

		}
		else if (sala2[numeroLetra][numero - 1].getOcupado() == false) {
			cout << "esse assento não estava ocupado.\n";
				return;
		}
		sala2[numeroLetra][numero - 1].setOcupado(false);
		sala2Ocupacao--;
		sala2[numeroLetra][numero - 1].setSprite("(-)");
		sala2[numeroLetra][numero - 1].setNome("");
		sala2[numeroLetra][numero - 1].setCPF("");
		cout << "Reserva " << letra << numero  << " foi cancelada com sucesso!\n";
		return;
		break;
	default:
		cout << "Essa sessão não existe.\n";
		
		break;

		

	}
}
