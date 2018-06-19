#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
	int tamanhoMatrizAX = 3;
	int tamanhoMatrizAY = 3;
	int tamanhoMatrizBX = 3;
	int tamanhoMatrizBY = 1;
	
	float pa = 0.95;
	float pb = 1;
	float pba = 0.95;
	float alpha = 0.1;
	float beta = 1;
	
	float matrizA[tamanhoMatrizAX][tamanhoMatrizAY] = {{2,3,5},{6,4,1},{9,8,7}};
	float matrizB[tamanhoMatrizBX][tamanhoMatrizBY] = {{4},{5},{8}};
	
	
	float matrizWa[tamanhoMatrizAX][tamanhoMatrizAY*2];
	float matrizWb[tamanhoMatrizBX][tamanhoMatrizBY*2];	
	float matrizWab[tamanhoMatrizBX][tamanhoMatrizAY];
	
	for (int i = 0;i < tamanhoMatrizAX;i++){
		for (int j = 0; j < tamanhoMatrizAY*2;j++){
			matrizWa[i][j] = 1;
		}
	}
	for (int i = 0;i < tamanhoMatrizBX;i++){
		for (int j = 0; j < tamanhoMatrizBY*2;j++){
			matrizWb[i][j] = 1;
		}
	}
	for (int i = 0;i < tamanhoMatrizBX;i++){
		for (int j = 0; j < tamanhoMatrizAY;j++){
			matrizWab[i][j] = 1;
		}
	}
	
	float matrizIA[tamanhoMatrizAX][tamanhoMatrizAY*2];
	float matrizIB[tamanhoMatrizBX][tamanhoMatrizBY*2];
	float somatorio = 0;
	
	for (int i = 0;i < tamanhoMatrizAX;i++){
		for (int j = 0; j < tamanhoMatrizAY;j++){
			somatorio += matrizA[i][j];	
		}
	}	
	cout << "matriz Ia " << endl;
	for (int i = 0;i < tamanhoMatrizAX;i++){
		for (int j = 0; j < tamanhoMatrizAY;j++){
			matrizIA[i][j] = (matrizA[i][j] / somatorio);
			cout << " " << matrizIA[i][j] << " ";
		}
		cout << endl;
	}
	somatorio = 0;	
	for (int i = 0;i < tamanhoMatrizBX;i++){
		for (int j = 0; j < tamanhoMatrizBY;j++){
			somatorio += matrizB[i][j];	
		}
	}	
	cout << "matriz Ib " << endl;
	for (int i = 0;i < tamanhoMatrizBX;i++){
		for (int j = 0; j < tamanhoMatrizBY;j++){
			matrizIB[i][j] = (matrizB[i][j] / somatorio);
			cout << " " << matrizIB[i][j] << " ";
		}
		cout << endl;
	}
	
	float matrizIAc[tamanhoMatrizAX][tamanhoMatrizAY];
	float matrizIBc[tamanhoMatrizBX][tamanhoMatrizBY];
	
	cout << "matriz Iac " << endl;
	for (int i = 0;i < tamanhoMatrizAX;i++){
		for (int j = 0; j < tamanhoMatrizAY;j++){
			matrizIAc[i][j] = (1 - matrizIA[i][j]);
			cout << " " << matrizIAc[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "matriz Ibc " << endl;
	for (int i = 0;i < tamanhoMatrizBX;i++){
		for (int j = 0; j < tamanhoMatrizBY;j++){
			matrizIBc[i][j] = (1 - matrizIB[i][j]);
			cout << " " << matrizIBc[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0;i < tamanhoMatrizAX;i++){
		for (int j = 0; j < tamanhoMatrizAY;j++){
			matrizIA[i][j+tamanhoMatrizAY] = matrizIAc[i][j];
		}
	}
	
	for (int i = 0;i < tamanhoMatrizBX;i++){
		for (int j = 0; j < tamanhoMatrizBY;j++){
			matrizIB[i][j+tamanhoMatrizBY] = matrizIBc[i][j];
		}
	}
	
	cout << "matriz Ia definitivo " << endl;
	for (int i = 0;i < tamanhoMatrizAX;i++){
		for (int j = 0; j < tamanhoMatrizAY*2;j++){
			cout << " " << matrizIA[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "matriz Ib definitivo " << endl;
	for (int i = 0;i < tamanhoMatrizBX;i++){
		for (int j = 0; j < tamanhoMatrizBY*2;j++){
			cout << " " << matrizIB[i][j] << " ";
		}
		cout << endl;
	}
	
	float vetorTa[tamanhoMatrizAX];
	for (int i = 0; i < tamanhoMatrizAX;i++){
		vetorTa[i] = 0;
	}
	
	float vetorTb[tamanhoMatrizBX];
	for (int i = 0; i < tamanhoMatrizBX;i++){
		vetorTb[i] = 0;
	}
	
	/*art a*/
	cout << "calculando T de A " << endl;
	for (int i = 0; i < tamanhoMatrizAX;i++){
		float somatorioLinha = 0;
		float somatorioLinhaW = 0;
		for (int j = 0; j < tamanhoMatrizAY*2;j++){
			somatorioLinha += (pow(matrizIA[i][j], matrizWa[i][j]));
			somatorioLinhaW += matrizWa[i][j]; 
		}
		vetorTa[i] = somatorioLinha / (alpha + somatorioLinhaW);
		cout << "t " << i << " " << vetorTa[i] << endl;
	
	}
	
	/*art b*/	
	cout << "calculando T de B " << endl;
	for (int i = 0; i < tamanhoMatrizBX;i++){
		float somatorioLinha = 0;
		float somatorioLinhaW = 0;
		for (int j = 0; j < tamanhoMatrizBY*2;j++){
			somatorioLinha += (pow(matrizIB[i][j], matrizWb[i][j]));
			somatorioLinhaW += matrizWb[i][j]; 
		}
		vetorTb[i] = somatorioLinha / (alpha + somatorioLinhaW);
		cout << "t " << i << " " << vetorTb[i] << endl;
	}
	
	/*categoria ativa*/
	int categoriaAtivaA = -1;
	int categoriaAtivaB = -1;
	
	float maiorValor = -1;
	for (int i = 0; i < tamanhoMatrizAX;i++){
		if (vetorTa[i] > maiorValor){
			categoriaAtivaA = i;
			maiorValor = vetorTa[i];
		}	
	}
	
	maiorValor = -1;
	for (int i = 0; i < tamanhoMatrizBX;i++){
		if (vetorTb[i] > maiorValor){
			categoriaAtivaB = i;
			maiorValor = vetorTb[i];
		}	
	}
	
	/*Teste de vigilancia*/
	
	float testeVigilanciaA = 0;
	float testeVigilanciaB = 0;
	
	/*match tracking*/
	
	/*atualizacao dos pesos*/
	
	
	
	
	
	system("pause");
	return 0;
}
