/*
----------------------------------------------------------------------------
A LICENÇA BEER-WARE ou A LICENÇA DA CERVEJA (Revisão 43 em Português Brasil):
<pedrogaya@gmail.com> escreveu este arquivo. Enquanto esta nota estiver na coisa você poderá utilizá-la
como quiser. Caso nos encontremos algum dia e você me reconheça e ache que esta coisa tem algum
valor, você poderá me pagar uma cerveja em retribuição (ou mais de uma), Pedro Gaya.
----------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#define LINHAS 10
#define COLUNAS 10

float calculaProjecao(float matriz[LINHAS][COLUNAS], float resultado[LINHAS][COLUNAS], int ind1a, int ind2a, int nlinhas, int ncolunas){
	float t1,t2,t3;
	t1 = 0;
	t2 = 0;
	for(int i = 0;i < ncolunas;i++){
		t1 += matriz[ind1a][i]*resultado[ind2a][i];
		t2 += resultado[ind2a][i]*resultado[ind2a][i];
	}
	t3 = (t1/t2)*(-1);
	return t3;
}

void limpar(){
	#ifdef _WIN32
	    system("cls");
	#else
	    system ("clear");
	#endif
}

void pause(){
	#ifdef _WIN32
	    system("pause");
	#else
	    system("read -n1 -p ' ' key");
	#endif
}

void logo(){
	limpar();
	cout << "\t  #####                           #####                                      " << endl;
	cout << "\t #     # #####    ##   #    #    #     #  ####  #    # #    # # #####  ##### " << endl;
	cout << "\t #       #    #  #  #  ##  ##    #       #    # #    # ##  ## # #    #   #   " << endl;
	cout << "\t #  #### #    # #    # # ## #     #####  #      ###### # ## # # #    #   #   " << endl;
	cout << "\t #     # #####  ###### #    #          # #      #    # #    # # #    #   #   " << endl;
	cout << "\t #     # #   #  #    # #    #    #     # #    # #    # #    # # #    #   #   " << endl;
	cout << "\t  #####  #    # #    # #    #     #####   ####  #    # #    # # #####    #   " << endl;
	cout << endl << endl;
}

int menu(){
	int user;
	do{
	logo();
	cout << "\n\n\tSeja bem-vindo ao processo de ortogonalizacao de Gram-Schmidt. Escolha a opcao desejada :" << endl;
	cout << "\n\t1- Realizar Ortogonalizacao" << endl;
	cin >> user;
	}while(user != 1 && user != 2);
	return user;
}

int main(){
	float matriz[LINHAS][COLUNAS],resultado[LINHAS][COLUNAS],projecao;
	int user, nlinhas, ncolunas,repetir;
	do{
		user = menu();
		cout << fixed;
		cout << setprecision(2);
		if(user == 1){
			logo();
			cout << "\tEm quantas dimensoes?" << endl;
			cin >> ncolunas;
			cout << "\tQuantos vetores?" << endl;
			cin >> nlinhas;
			for(int r1=0;r1<nlinhas;r1++){
				for(int r2=0;r2<ncolunas;r2++){
					logo();
					cout << "Favor digitar os valores do " << r2+1 << " membro do vetor " << r1+1 << "." << endl;
					cin >> matriz[r1][r2];
				}
			}
			for(int n=0;n<nlinhas;n++){
				for(int z=0;z<ncolunas;z++){
					resultado[n][z] = matriz[n][z];
				}
				for(int x=0;x<n;x++){
					projecao = calculaProjecao(matriz,resultado,n,x,nlinhas,ncolunas);
					for(int k=0;k<ncolunas;k++){
						resultado[n][k] += projecao*resultado[x][k];
					}
				}
			}
		}
		do{
			logo();
			for(int m=0;m<nlinhas;m++){
				cout << "\t< ";
				for(int j=0;j<ncolunas;j++){
					if(j == (ncolunas-1)){
						cout << resultado[m][j];
					}
					else{
						cout << resultado[m][j] << ", ";
					}
				}
				cout << " >" << endl;
			}
			cout << "\n\tVetores ortogonalizados. Deseja retornar ao menu principal?" << endl;
			cout << "\t\t1-Sim" << endl << "\t\t2-Nao" << endl;
			cin >> repetir;
		}while(repetir != 1 && repetir != 2);
	}while(repetir == 1);
	limpar();
	return 0;
}