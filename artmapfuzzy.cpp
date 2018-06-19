#include <iostream>
#include <stdlib.h>
#include <math.h>

/*ART MAP FUZZY - VERSAO 1.0*/
/*DESENVOLVIDO POR: LUCAS DA SILVA*/
/*E-MAIL: LUCAS21021996@GMAIL.COM*/
/*UNISALESIANO ARACATUBA-SP, JUNHO DE 2018*/

using namespace std;

#define verificaMenorValorVetor(vetor, tamanho, valor) valor = -1; for(int i = 0; i < tamanho; i++){ if (valor < vetor[i]) valor = vetor[i];}

int main(){
	
	/*INICIALIZACAO DE VARIAVEIS, JA PRE-DEFINIDOS, EH POSSIVEL ALTERAR DEPOIS EM TEMPO DE EXECUCAO*/
	int limiteMaximoDimensao = 9; /*ESTE VALOR NAO EH ALTERADO EM REAL-TIME, ELE INDICA O LIMITE DE DIMENSAO DE MATRIZES*/
	int tamanhoMatrizAX = 3;
	int tamanhoMatrizAY = 3;
	int tamanhoMatrizBX = 3;
	int tamanhoMatrizBY = 1;
	
	float pa = 0.95;
	float pb = 1;
	float pba = 0.95;
	float alpha = 0.1;
	float beta = 1;
	int iteracoes = 1;
	
	float matrizInicialA[limiteMaximoDimensao][limiteMaximoDimensao] = {{2,3,5},{6,4,1},{9,8,7}};
	float matrizInicialB[limiteMaximoDimensao][limiteMaximoDimensao] = {{4},{5},{8}};
	
	
	float matrizInicialWa[limiteMaximoDimensao][limiteMaximoDimensao*2];
	float matrizInicialWb[limiteMaximoDimensao][limiteMaximoDimensao*2];	
	float matrizInicialWab[limiteMaximoDimensao][limiteMaximoDimensao];
	
	/*MODO DE RECONHECIMENTO - FICA SALVO NA MEMORIA*/
	int tamanhoMatrizAXReconhecimento = 0;
	int tamanhoMatrizAYReconhecimento = 0;
	int tamanhoMatrizBXReconhecimento = 0;
	int tamanhoMatrizBYReconhecimento = 0;
	
	float matrizReconhecimentoWa[limiteMaximoDimensao][limiteMaximoDimensao*2];
	float matrizReconhecimentoWb[limiteMaximoDimensao][limiteMaximoDimensao*2];	
	float matrizReconhecimentoWab[limiteMaximoDimensao][limiteMaximoDimensao];
	
	
	for (int i = 0;i < limiteMaximoDimensao;i++){
		for (int j = 0; j < limiteMaximoDimensao*2;j++){
			matrizInicialWa[i][j] = 1;
			matrizReconhecimentoWa[i][j] = 1;
		}
	}
	for (int i = 0;i < limiteMaximoDimensao;i++){
		for (int j = 0; j < limiteMaximoDimensao*2;j++){
			matrizInicialWb[i][j] = 1;
			matrizReconhecimentoWb[i][j] = 1;
		}
	}
	for (int i = 0;i < limiteMaximoDimensao;i++){
		for (int j = 0; j < limiteMaximoDimensao;j++){
			matrizInicialWab[i][j] = 1;
			matrizReconhecimentoWab[i][j] = 1;
		}
	}

	float somatorio = 0;
	
	/**/
	/*INICIO DO LOOP DO MENU E AFINS*/
	/**/
	
	int opcao = -1;
	while (opcao != 0){
		system("cls");
		opcao = 1;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// DESENVOLVIMENTO DE REDE NEURAL - ART MAP FUZZY 1.0 ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// AUTOR: LUCAS DA SILVA - R.A.: 203417               ////" << endl;
		cout << "//// ENGENHARIA DA COMPUTACAO - 9TH TERMO               ////" << endl;
		cout << "//// ORIENTACAO: JAMES CLAUTON DA SILVA                 ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// JUNHO, 14 DE 2018 - JUNHO, 16 DE 2018              ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// SELECIONE COM SEU TECLADO UMA DAS OPCOES ABAIXO:   ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// [ 1 ] - REALIZAR ITERACOES / EXECUTAR              ////" << endl;
		cout << "//// [ 2 ] - EDITAR VALORES (ROH, ALPHA E BETA)         ////" << endl;
		cout << "//// [ 3 ] - EDITAR MATRIZES (A E B)                    ////" << endl;
		cout << "//// [ 4 ] - EDITAR MATRIZES (WA, WB E WAB)             ////" << endl;
		cout << "//// [ 5 ] - CONSULTAR VALORES                          ////" << endl;
		cout << "//// [ 6 ] - DEFINIR QUANTIDADE DE ITERACOES            ////" << endl;
		cout << "//// [ 7 ] - FAZER O RECONHECIMENTO                     ////" << endl;
		cout << "//// [ 8 ] - SOBRE O PROJETO                            ////" << endl;
		cout << "//// [ 0 ] - SAIR                                       ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << endl;
		cin >> opcao;
		
		system("cls");
		
		switch (opcao){
			case 8:{
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "A R T     M A P     F U Z Z Y  " << endl;
				cout << "V E R S A O  -  1 . 0" << endl << endl;
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "DESENVOLVIDO POR LUCAS DA SILVA" << endl << endl;
				cout << "E-MAIL : LUCAS21021996@GMAIL.COM" << endl << "PROFESSOR JAMES CLAUTON DA SILVA" << endl;
				cout << "UNISALESIANO ARACATUBA - SP " << endl << " CURSO DE ENGENHARIA DA COMPUTACAO " << endl;
				cout << "DATA: JUNHO, 16 DE 2018 " << endl << endl;
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "PROJETO DESENVOLVIDO PARA AVALIACAO DA MATERIA DE SISTEMAS INTELIGENTES" << endl;
				cout << "CASO OCORRA ALGUM PROBLEMA NA EXECUCAO DO PROJETO, POR FAVOR ENTRAR EM CONTATO NO MEU EMAIL" << endl;
				cout << "MEU GITHUB: www.github.com/LucasMence " << endl << endl;
				cout << "////////////////////////////////////////////////////////////" << endl;
				system("pause");
				break;
			}
			case 7: {
				cout << "////////////////////////////////////////////////////////////" << endl;
				float matrizA[tamanhoMatrizAX][tamanhoMatrizAY];
				float matrizB[tamanhoMatrizBX][tamanhoMatrizBY];
				
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY;j++){
						matrizA[i][j] = matrizInicialA[i][j];
					}
				}
				
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY;j++){
						matrizB[i][j] = matrizInicialB[i][j];
					}
				}
							
				float matrizWa[tamanhoMatrizAX][tamanhoMatrizAY*2];
				float matrizWb[tamanhoMatrizBX][tamanhoMatrizBY*2];	
				float matrizWab[tamanhoMatrizBX][tamanhoMatrizAY];
				
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY*2;j++){
						matrizWa[i][j] = matrizInicialWa[i][j];
					}
				}
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY*2;j++){
						matrizWb[i][j] = matrizInicialWb[i][j];
					}
				}
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizAY*2;j++){
						matrizWab[i][j] = matrizInicialWab[i][j];
					}
				}
				
				float matrizIA[tamanhoMatrizAX][tamanhoMatrizAY*2];
				float matrizIB[tamanhoMatrizBX][tamanhoMatrizBY*2];	
	
				float matrizIAc[tamanhoMatrizAX][tamanhoMatrizAY];
				float matrizIBc[tamanhoMatrizBX][tamanhoMatrizBY];	
				
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
						int menorValorAtual = 0;
						int vetorUso[2] = {matrizIA[i][j],matrizWa[i][j]};
						verificaMenorValorVetor(vetorUso,2,menorValorAtual);
						somatorioLinha +=  menorValorAtual;
					//	somatorioLinha += (pow(matrizIA[i][j], matrizWa[i][j]));
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
					//	somatorioLinha += (pow(matrizIB[i][j], matrizWb[i][j]));
						int menorValorAtual = 0;
						int vetorUso[2] = {matrizIB[i][j],matrizWb[i][j]};
						verificaMenorValorVetor(vetorUso,2,menorValorAtual);
						somatorioLinha +=  menorValorAtual;
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
						cout << " vetorTa " << vetorTa[i] << endl;
						cout << " maiorValor " << maiorValor << endl;
						
						if (vetorTa[i] > (maiorValor+0.001)){
							maiorValor = vetorTa[i];
							categoriaAtivaA = i;
							
							cout << " + " << vetorTa[i] << endl;
							cout << " + " << categoriaAtivaA << endl;
						}
					}	
				}
				cout << "categoria a "<< categoriaAtivaA << endl;
				
				
				maiorValor = -1;
				for (int i = 0; i < tamanhoMatrizBX;i++){
					if (vetorTb[i] > maiorValor){
						categoriaAtivaB = i;
						maiorValor = vetorTb[i];
						cout << " + " << vetorTa[i] << endl;
						cout << " + " << categoriaAtivaA << endl;
					}	
				}
				
				cout << "categoria b "<< categoriaAtivaB << endl;
				
				/*Teste de vigilancia*/
				
				float testeVigilanciaA = 0;
				float testeVigilanciaB = 0;
				
				float valorTesteVigilancia = 0, divisaoTesteVigilancia = 0;
				/*para b*/
				for (int i = 0; i < tamanhoMatrizBY*2; i++){
					valorTesteVigilancia += pow(matrizIB[categoriaAtivaB][i],matrizWb[categoriaAtivaB][i]);
					divisaoTesteVigilancia += matrizIB[categoriaAtivaB][i];
				}
				
				valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
				cout << "teste de vigilancia b " << valorTesteVigilancia << endl;
				if (valorTesteVigilancia >= pb){
					testeVigilanciaB = 1;
				}
				
				int contadorLimite = 1;
				while (testeVigilanciaB == 0 && contadorLimite < tamanhoMatrizBX){
					contadorLimite++;
					vetorTb[categoriaAtivaB] = 0;
					
					maiorValor = -1;
					categoriaAtivaB = -1;
					for (int i = 0; i < tamanhoMatrizBX;i++){
						if (vetorTb[i] > maiorValor){
							categoriaAtivaB = i;
							maiorValor = vetorTb[i];
						}	
					}		
					
					if (categoriaAtivaB >= 0){
						/*para b*/
						for (int i = 0; i < tamanhoMatrizBY; i++){
							valorTesteVigilancia += pow(matrizIB[categoriaAtivaB][i],matrizWb[categoriaAtivaB][i]);
							divisaoTesteVigilancia += matrizIB[categoriaAtivaB][i];
						}
						
						valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
						cout << "teste de vigilancia b " << valorTesteVigilancia << endl;
						if (valorTesteVigilancia >= pb){
							testeVigilanciaB = 1;
						}	
					}
						
				}
				
				if (testeVigilanciaB == 0){
					cout << "houve falha no teste de vigilancia de todas as categorias da matriz B" << endl;
					return 0;
				}
				
				/*para a*/
				for (int i = 0; i < tamanhoMatrizAY*2; i++){
					valorTesteVigilancia += pow(matrizIA[categoriaAtivaA][i],matrizWa[categoriaAtivaA][i]);
					divisaoTesteVigilancia += matrizIA[categoriaAtivaA][i];
				}
				
				valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
				cout << "teste de vigilancia a " << valorTesteVigilancia << endl;
				if (valorTesteVigilancia >= pa){
					testeVigilanciaA = 1;
				}
				
				contadorLimite = 1;
				while (testeVigilanciaA == 0 && contadorLimite < tamanhoMatrizAX){
					contadorLimite++;
					vetorTa[categoriaAtivaA] = 0;
					
					maiorValor = -1;
					categoriaAtivaA = -1;
					for (int i = 0; i < tamanhoMatrizAX*2;i++){
						if (vetorTa[i] > maiorValor){
							categoriaAtivaA = i;
							maiorValor = vetorTa[i];
						}	
					}		
					
					if (categoriaAtivaA >= 0){
						/*para a*/
						for (int i = 0; i < tamanhoMatrizAY*2; i++){
							valorTesteVigilancia += pow(matrizIA[categoriaAtivaA][i],matrizWa[categoriaAtivaA][i]);
							divisaoTesteVigilancia += matrizIA[categoriaAtivaA][i];
						}
						
						valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
						cout << "teste de vigilancia a " << valorTesteVigilancia << endl;
						if (valorTesteVigilancia >= pa){
							testeVigilanciaA = 1;
						}	
					}		
				}
				
				if (testeVigilanciaA == 0){
					cout << "houve falha no teste de vigilancia de todas as categorias da matriz A" << endl;
					return 0;
				}
				
				/*match tracking*/	
				float matrizYA[tamanhoMatrizBX][tamanhoMatrizAY];
				float matrizYB[tamanhoMatrizBX][tamanhoMatrizAY];
				
				for (int i = 0; i < tamanhoMatrizBX; i++){
					for (int j = 0; j < tamanhoMatrizAY; j++){
						matrizYA[i][j] = 0;
						matrizYB[i][j] = 0;
					}
				}
				
				matrizYA[0][categoriaAtivaA] = 1;
				matrizYB[0][categoriaAtivaB] = 1;
				
				float valorMatchTracking = 0, divisaoMatchTracking = 0;
				for (int i = 0; i < tamanhoMatrizAY; i++){
					valorMatchTracking += pow(matrizYA[0][categoriaAtivaA],matrizWab[categoriaAtivaA][i]);
					divisaoMatchTracking += matrizYA[0][categoriaAtivaA];
				}
				
				valorMatchTracking = (valorMatchTracking / divisaoMatchTracking);
				
				/*loop de match tracking - IMPORTANTE*/
				contadorLimite = 1;
				while (testeVigilanciaA == 0 && contadorLimite < (tamanhoMatrizBX*tamanhoMatrizAX)){
					contadorLimite++;
					
					/*determinando o vt e fazendo mais uma vez o teste de vigilancia*/
					for (int x = 0; x < tamanhoMatrizBX; x++){
						for (int y = 0; y < tamanhoMatrizAX; y++){
							/*para A*/	
							/*art a*/
							cout << "calculando T de A " << endl;
							for (int i = 0; i < tamanhoMatrizAX;i++){
								float somatorioLinha = 0;
								float somatorioLinhaW = 0;
								for (int j = 0; j < tamanhoMatrizAY*2;j++){
									//somatorioLinha += (pow(matrizIA[i][j], matrizWa[i][j]));
									int menorValorAtual = 0;
									int vetorUso[2] = {matrizIA[i][j],matrizWa[i][j]};
									verificaMenorValorVetor(vetorUso,2,menorValorAtual);
									somatorioLinha +=  menorValorAtual;
									somatorioLinhaW += matrizWa[i][j]; 
								}
								vetorTa[i] = somatorioLinha / (alpha + somatorioLinhaW);
								cout << "t " << i << " " << vetorTa[i] << endl;
							
							}	
							
							maiorValor = -1;
							for (int i = 0; i < tamanhoMatrizAX;i++){
								if (vetorTa[i] > maiorValor){
									cout << " vetorTa " << vetorTa[i] << endl;
									cout << " maiorValor " << maiorValor << endl;
									
									if (vetorTa[i] > (maiorValor+0.001)){
										maiorValor = vetorTa[i];
										categoriaAtivaA = i;
										
										cout << " + " << vetorTa[i] << endl;
										cout << " + " << categoriaAtivaA << endl;
									}
								}	
							}
							cout << "categoria a "<< categoriaAtivaA << endl;
							
							int contadorLimiteA = 1;
							while (testeVigilanciaA == 0 && contadorLimiteA < tamanhoMatrizAX){
								contadorLimiteA++;
								vetorTa[categoriaAtivaA] = 0;
								
								maiorValor = -1;
								categoriaAtivaA = -1;
								for (int i = 0; i < tamanhoMatrizAX*2;i++){
									if (vetorTa[i] > maiorValor){
										categoriaAtivaA = i;
										maiorValor = vetorTa[i];
									}	
								}		
								
								if (categoriaAtivaA >= 0){
									/*para a*/
									for (int i = 0; i < tamanhoMatrizAY*2; i++){
										valorTesteVigilancia += pow(matrizIA[categoriaAtivaA][i],matrizWa[categoriaAtivaA][i]);
										divisaoTesteVigilancia += matrizIA[categoriaAtivaA][i];
									}
									
									valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
									cout << "teste de vigilancia a " << valorTesteVigilancia << endl;
									if (valorTesteVigilancia >= pa){
										testeVigilanciaA = 1;
									}	
								}		
							}
							
							if (testeVigilanciaA == 0){
								cout << "houve falha no teste de vigilancia de todas as categorias da matriz A" << endl;
								return 0;
							}	
							
							for (int i = 0; i < tamanhoMatrizBX; i++){
								for (int j = 0; j < tamanhoMatrizAY; j++){
										matrizYA[i][j] = 0;
										matrizYB[i][j] = 0;
									}
								}
								
							matrizYA[0][categoriaAtivaA] = 1;
							matrizYB[0][categoriaAtivaB] = 1;
								
							valorMatchTracking = 0, divisaoMatchTracking = 0;
							for (int i = 0; i < tamanhoMatrizAY; i++){
								valorMatchTracking += pow(matrizYA[0][categoriaAtivaA],matrizWab[categoriaAtivaA][i]);
								divisaoMatchTracking += matrizYA[0][categoriaAtivaA];
							}
								
							valorMatchTracking = (valorMatchTracking / divisaoMatchTracking);
							
							if (valorMatchTracking < pba){
								cout << "match tracking invalido " << endl;
								return 0;
							}
						}
						
						/*para B*/
						/*art b*/	
						cout << "calculando T de B " << endl;
						for (int i = 0; i < tamanhoMatrizBX;i++){
							float somatorioLinha = 0;
							float somatorioLinhaW = 0;
							for (int j = 0; j < tamanhoMatrizBY*2;j++){
							//	somatorioLinha += (pow(matrizIB[i][j], matrizWb[i][j]));
								int menorValorAtual = 0;
								int vetorUso[2] = {matrizIB[i][j],matrizWb[i][j]};
								verificaMenorValorVetor(vetorUso,2,menorValorAtual);
								somatorioLinha +=  menorValorAtual;
								somatorioLinhaW += matrizWb[i][j]; 
							}
							vetorTb[i] = somatorioLinha / (alpha + somatorioLinhaW);
							cout << "t " << i << " " << vetorTb[i] << endl;
						}
						
						maiorValor = -1;
						for (int i = 0; i < tamanhoMatrizBX;i++){
							if (vetorTb[i] > maiorValor){
								categoriaAtivaB = i;
								maiorValor = vetorTb[i];
								cout << " + " << vetorTa[i] << endl;
								cout << " + " << categoriaAtivaA << endl;
							}	
						}
						
						cout << "categoria b "<< categoriaAtivaB << endl;
							
						int contadorLimiteB = 1;
						while (testeVigilanciaB == 0 && contadorLimiteB < tamanhoMatrizBX){
							contadorLimiteB++;
							vetorTb[categoriaAtivaB] = 0;
							
							maiorValor = -1;
							categoriaAtivaB = -1;
							for (int i = 0; i < tamanhoMatrizBX;i++){
								if (vetorTb[i] > maiorValor){
									categoriaAtivaB = i;
									maiorValor = vetorTb[i];
								}	
							}		
							
							if (categoriaAtivaB >= 0){
								/*para b*/
								for (int i = 0; i < tamanhoMatrizBY; i++){
									valorTesteVigilancia += pow(matrizIB[categoriaAtivaB][i],matrizWb[categoriaAtivaB][i]);
									divisaoTesteVigilancia += matrizIB[categoriaAtivaB][i];
								}
								
								valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
								cout << "teste de vigilancia b " << valorTesteVigilancia << endl;
								if (valorTesteVigilancia >= pb){
									testeVigilanciaB = 1;
								}	
							}			
						}
						
						if (testeVigilanciaB == 0){
							cout << "houve falha no teste de vigilancia de todas as categorias da matriz B" << endl;
							return 0;
						}
					
					}
				}
				
				/*atualizacao dos pesos*/
				
				float vetorAtualizacaoPesosA1[tamanhoMatrizAY*2];
				float vetorAtualizacaoPesosA2[tamanhoMatrizAY*2];
				
				float vetorAtualizacaoPesosB1[tamanhoMatrizBY*2];
				float vetorAtualizacaoPesosB2[tamanhoMatrizBY*2];
				
				for (int i = 0; i < tamanhoMatrizAY*2; i++){
					vetorAtualizacaoPesosA1[i] =  beta * (pow(matrizIA[categoriaAtivaA][i],matrizWa[categoriaAtivaA][i]));
					vetorAtualizacaoPesosA2[i] =  (1 - beta) * (matrizWa[categoriaAtivaA][i]);		
					vetorAtualizacaoPesosA1[i] += vetorAtualizacaoPesosA2[i]; 
					matrizWa[categoriaAtivaA][i] = vetorAtualizacaoPesosA1[i];
				}
				
				for (int i = 0; i < tamanhoMatrizBY*2; i++){
					vetorAtualizacaoPesosB1[i] =  beta * (pow(matrizIB[categoriaAtivaB][i],matrizWb[categoriaAtivaB][i]));
					vetorAtualizacaoPesosB2[i] =  (1 - beta) * (matrizWb[categoriaAtivaB][i]);		
					vetorAtualizacaoPesosB1[i] += vetorAtualizacaoPesosB2[i]; 
					matrizWb[categoriaAtivaB][i] = vetorAtualizacaoPesosB1[i];
				}
				
				float vetorAtualizacaoPesosAB[tamanhoMatrizAY];
				for (int i = 0; i < tamanhoMatrizAY; i++){
					vetorAtualizacaoPesosAB[i] = 0;
				}
				cout << "categoria a " << categoriaAtivaA << endl; 
				vetorAtualizacaoPesosAB[categoriaAtivaA] = 1;
				
				for (int i = 0; i < tamanhoMatrizAY; i++){
					matrizWab[categoriaAtivaB][i] = vetorAtualizacaoPesosAB[i];
				}
					
				cout << "Impressao de pesos " << endl;
				cout << "Wa " << endl;
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY*2;j++){
						cout << matrizWa[i][j] << " ";
					}
					cout << endl;
				}
				cout << "Wb " << endl;
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY*2;j++){
						cout << matrizWb[i][j] << " ";
					}
					cout << endl;
				}
				cout << "Wab " << endl;
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizAY;j++){
						cout << matrizWab[i][j] << " ";
					}
					cout << endl;
				}
				
				/*COMPARACAO DE VALORES - EH AQUI QUE O SISTEMA FAZ O RECONHECIMENTO*/
				int diferenca = 0;
				for (int i = 0; i < tamanhoMatrizAXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizAYReconhecimento; j++){
						if (matrizReconhecimentoWa[i][j] != matrizWa[i][j])	{
							diferenca = 1;
							break;
						}
					}
				}
				
				for (int i = 0; i < tamanhoMatrizBXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizBYReconhecimento; j++){
						if (matrizReconhecimentoWb[i][j] != matrizWb[i][j])	{
							diferenca = 1;
							break;
						}
					}
				}
				
				for (int i = 0; i < tamanhoMatrizBXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizAYReconhecimento; j++){
						if (matrizReconhecimentoWb[i][j] != matrizWb[i][j])	{
							diferenca = 1;
							break;
						}	
					}
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				if (diferenca == 1){
					cout << "O SISTEMA NAO RECONHECEU AS ENTRADAS COMO UM PADRAO VALIDO ! " << endl;
				} else {
					cout << "AS ENTRADAS FORAM RECONHECIDAS COMO UM PADRAO VALIDO ! " << endl;	
				}	
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "PRESSIONE UMA TECLA PARA VOLTAR AO MENU PRINCIPAL!" << endl;
				system("pause");							
				break;
			}
			case 6: {
				cout << "INSIRA O VALOR DE ITERACOES (ATUAL: "<< iteracoes <<"): ";
				cin >> iteracoes;
				cout << "ITERACAO EDITADA! PRESSIONE UMA TECLA PARA VOLTAR AO MENU PRINCIPAL!" << endl;
				system("pause");	
				break;
			}
			case 5: {
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "MATRIZ A" << endl;
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY;j++){	
						cout << matrizInicialA[i][j] << " ";
					}
					cout << endl;	
				}
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "MATRIZ B" << endl;
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY;j++){	
						cout << matrizInicialB[i][j] << " ";
					}
					cout << endl;	
				}
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "MATRIZ WA" << endl;
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY*2;j++){	
						cout << matrizInicialWa[i][j] << " ";
					}
					cout << endl;	
				}
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "MATRIZ WB" << endl;
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY*2;j++){	
						cout << matrizInicialWb[i][j] << " ";
					}
					cout << endl;	
				}
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "MATRIZ WAB" << endl;
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizBX;j++){	
						cout << matrizInicialWab[i][j] << " ";
					}
					cout << endl;	
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "RECONHECIMENTO: MATRIZ WA" << endl;
				for (int i = 0; i < tamanhoMatrizAXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizAYReconhecimento; j++){
						cout << matrizReconhecimentoWa[i][j] << " ";		
					}
					cout << endl;
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "RECONHECIMENTO: MATRIZ WB" << endl;
				for (int i = 0; i < tamanhoMatrizBXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizBYReconhecimento; j++){
						cout << matrizReconhecimentoWb[i][j] << " ";	
					}
					cout << endl;
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "RECONHECIMENTO: MATRIZ WAB" << endl;
				for (int i = 0; i < tamanhoMatrizAXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizBXReconhecimento; j++){
						cout << matrizReconhecimentoWab[i][j] << " ";	
					}
					cout << endl;
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "PRESSIONE UMA TECLA PARA VOLTAR AO MENU PRINCIPAL!" << endl;
				system("pause");
				break;
			}
			case 4:{				
				cout << "////////////////////////////////////////////////////////////" << endl;
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY*2;j++){
						cout << "INSIRA O VALOR DA MATRIZ WA [ " << i <<" ] [ "<< j <<" ] (ATUAL: "<< matrizInicialWa[i][j] << "): ";
						cin >> matrizInicialWa[i][j];
					}
				}
				
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY*2;j++){
						cout << "INSIRA O VALOR DA MATRIZ WB [ " << i <<" ] [ "<< j <<" ] (ATUAL: "<< matrizInicialWb[i][j] << "): ";
						cin >> matrizInicialWb[i][j];
					}
				}
				
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizAY;j++){
						cout << "INSIRA O VALOR DA MATRIZ WAB [ " << i <<" ] [ "<< j <<" ] (ATUAL: "<< matrizInicialWab[i][j] << "): ";
						cin >> matrizInicialWab[i][j];
					}
				}
				
				cout << "MATRIZES DE PESO EDITADAS! PRESSIONE UMA TECLA PARA VOLTAR AO MENU PRINCIPAL!" << endl;
				system("pause");
				break;
			}
			
			case 3:{
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "INSIRA O NUMERO DE LINHAS DA MATRIZ A (ATUAL: "<< tamanhoMatrizAX <<"): ";
				cin >> tamanhoMatrizAX;
				cout << "INSIRA O NUMERO DE COLUNAS DA MATRIZ A (ATUAL: "<< tamanhoMatrizAY <<"): ";
				cin >> tamanhoMatrizAY;
				cout << "INSIRA O NUMERO DE LINHAS DA MATRIZ B (ATUAL: "<< tamanhoMatrizBX <<"): ";
				cin >> tamanhoMatrizBX;
				cout << "INSIRA O NUMERO DE COLUNAS DA MATRIZ B (ATUAL: " << tamanhoMatrizBY <<"): ";
				cin >> tamanhoMatrizBY;
				
				cout << endl << endl;
				cout << "TAMANHOS DE MATRIZES REDEFINIDOS! PRESSIONE UMA TECLA PARA COMECAR A PREENCHER OS VALORES DAS MATRIZES " << endl;
				system("pause");
				system("cls");
				
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY;j++){
						cout << "INSIRA O VALOR DA MATRIZ A [ " << i <<" ] [ "<< j <<" ] (ATUAL: "<< matrizInicialA[i][j] << "): ";
						cin >> matrizInicialA[i][j];
					}
				}
				
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY;j++){
						cout << "INSIRA O VALOR DA MATRIZ B [ " << i <<" ] [ "<< j <<" ] (ATUAL: "<< matrizInicialB[i][j] << "): ";
						cin >> matrizInicialB[i][j];
					}
				}
				
				cout << "MATRIZES EDITADAS! PRESSIONE UMA TECLA PARA VOLTAR AO MENU PRINCIPAL!" << endl;
				system("pause");
				break;
			}
			
			case 2:{
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "INSIRA O VALOR DE ROH DE A (ATUAL: "<< pa <<"): ";
				cin >> pa;
				cout << "INSIRA O VALOR DE ROH DE B (ATUAL: "<< pb <<"): ";
				cin >> pb;
				cout << "INSIRA O VALOR DE ROH DE BA (ATUAL: "<< pba <<"): ";
				cin >> pba;
				cout << "INSIRA O VALOR DE ALPHA (ATUAL: "<< alpha <<"): ";
				cin >> alpha;
				cout << "INSIRA O VALOR DE BETA (ATUAL: "<< beta <<"): ";
				cin >> beta;
				cout << "VALORES EDITADOS! PRESSIONE UMA TECLA PARA VOLTAR AO MENU PRINCIPAL!" << endl;
				system("pause");
				break;
			}
			
			case 1:{
				cout << "////////////////////////////////////////////////////////////" << endl;
				float matrizA[tamanhoMatrizAX][tamanhoMatrizAY];
				float matrizB[tamanhoMatrizBX][tamanhoMatrizBY];
				
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY;j++){
						matrizA[i][j] = matrizInicialA[i][j];
					}
				}
				
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY;j++){
						matrizB[i][j] = matrizInicialB[i][j];
					}
				}
							
				float matrizWa[tamanhoMatrizAX][tamanhoMatrizAY*2];
				float matrizWb[tamanhoMatrizBX][tamanhoMatrizBY*2];	
				float matrizWab[tamanhoMatrizBX][tamanhoMatrizAY];
				
				for (int i = 0;i < tamanhoMatrizAX;i++){
					for (int j = 0; j < tamanhoMatrizAY*2;j++){
						matrizWa[i][j] = matrizInicialWa[i][j];
					}
				}
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizBY*2;j++){
						matrizWb[i][j] = matrizInicialWb[i][j];
					}
				}
				for (int i = 0;i < tamanhoMatrizBX;i++){
					for (int j = 0; j < tamanhoMatrizAY*2;j++){
						matrizWab[i][j] = matrizInicialWab[i][j];
					}
				}
				
				float matrizIA[tamanhoMatrizAX][tamanhoMatrizAY*2];
				float matrizIB[tamanhoMatrizBX][tamanhoMatrizBY*2];	
	
				float matrizIAc[tamanhoMatrizAX][tamanhoMatrizAY];
				float matrizIBc[tamanhoMatrizBX][tamanhoMatrizBY];	
				
				
				/*LOOP DE ITERACAO*/
				
				for (int contadorIteracao = 0; contadorIteracao < iteracoes; contadorIteracao++){
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
							int menorValorAtual = 0;
							int vetorUso[2] = {matrizIA[i][j],matrizWa[i][j]};
							verificaMenorValorVetor(vetorUso,2,menorValorAtual);
							somatorioLinha +=  menorValorAtual;
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
							int menorValorAtual = 0;
							int vetorUso[2] = {matrizIB[i][j],matrizWb[i][j]};
							verificaMenorValorVetor(vetorUso,2,menorValorAtual);
							somatorioLinha +=  menorValorAtual;
							//somatorioLinha += (pow(matrizIB[i][j], matrizWb[i][j]));
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
							cout << " vetorTa " << vetorTa[i] << endl;
							cout << " maiorValor " << maiorValor << endl;
							
							if (vetorTa[i] > (maiorValor+0.001)){
								maiorValor = vetorTa[i];
								categoriaAtivaA = i;
								
								cout << " + " << vetorTa[i] << endl;
								cout << " + " << categoriaAtivaA << endl;
							}
						}	
					}
					cout << "categoria a "<< categoriaAtivaA << endl;
					
					
					maiorValor = -1;
					for (int i = 0; i < tamanhoMatrizBX;i++){
						if (vetorTb[i] > maiorValor){
							categoriaAtivaB = i;
							maiorValor = vetorTb[i];
							cout << " + " << vetorTa[i] << endl;
							cout << " + " << categoriaAtivaA << endl;
						}	
					}
					
					cout << "categoria b "<< categoriaAtivaB << endl;
					
					/*Teste de vigilancia*/
					
					float testeVigilanciaA = 0;
					float testeVigilanciaB = 0;
					
					float valorTesteVigilancia = 0, divisaoTesteVigilancia = 0;
					/*para b*/
					for (int i = 0; i < tamanhoMatrizBY*2; i++){
						valorTesteVigilancia += pow(matrizIB[categoriaAtivaB][i],matrizWb[categoriaAtivaB][i]);
						divisaoTesteVigilancia += matrizIB[categoriaAtivaB][i];
					}
					
					valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
					cout << "teste de vigilancia b " << valorTesteVigilancia << endl;
					if (valorTesteVigilancia >= pb){
						testeVigilanciaB = 1;
					}
					
					int contadorLimite = 1;
					while (testeVigilanciaB == 0 && contadorLimite < tamanhoMatrizBX){
						contadorLimite++;
						vetorTb[categoriaAtivaB] = 0;
						
						maiorValor = -1;
						categoriaAtivaB = -1;
						for (int i = 0; i < tamanhoMatrizBX;i++){
							if (vetorTb[i] > maiorValor){
								categoriaAtivaB = i;
								maiorValor = vetorTb[i];
							}	
						}		
						
						if (categoriaAtivaB >= 0){
							/*para b*/
							for (int i = 0; i < tamanhoMatrizBY; i++){
								valorTesteVigilancia += pow(matrizIB[categoriaAtivaB][i],matrizWb[categoriaAtivaB][i]);
								divisaoTesteVigilancia += matrizIB[categoriaAtivaB][i];
							}
							
							valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
							cout << "teste de vigilancia b " << valorTesteVigilancia << endl;
							if (valorTesteVigilancia >= pb){
								testeVigilanciaB = 1;
							}	
						}
							
					}
					
					if (testeVigilanciaB == 0){
						cout << "houve falha no teste de vigilancia de todas as categorias da matriz B" << endl;
						return 0;
					}
					
					/*para a*/
					for (int i = 0; i < tamanhoMatrizAY*2; i++){
						valorTesteVigilancia += pow(matrizIA[categoriaAtivaA][i],matrizWa[categoriaAtivaA][i]);
						divisaoTesteVigilancia += matrizIA[categoriaAtivaA][i];
					}
					
					valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
					cout << "teste de vigilancia a " << valorTesteVigilancia << endl;
					if (valorTesteVigilancia >= pa){
						testeVigilanciaA = 1;
					}
					
					contadorLimite = 1;
					while (testeVigilanciaA == 0 && contadorLimite < tamanhoMatrizAX){
						contadorLimite++;
						vetorTa[categoriaAtivaA] = 0;
						
						maiorValor = -1;
						categoriaAtivaA = -1;
						for (int i = 0; i < tamanhoMatrizAX*2;i++){
							if (vetorTa[i] > maiorValor){
								categoriaAtivaA = i;
								maiorValor = vetorTa[i];
							}	
						}		
						
						if (categoriaAtivaA >= 0){
							/*para a*/
							for (int i = 0; i < tamanhoMatrizAY*2; i++){
								valorTesteVigilancia += pow(matrizIA[categoriaAtivaA][i],matrizWa[categoriaAtivaA][i]);
								divisaoTesteVigilancia += matrizIA[categoriaAtivaA][i];
							}
							
							valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
							cout << "teste de vigilancia a " << valorTesteVigilancia << endl;
							if (valorTesteVigilancia >= pa){
								testeVigilanciaA = 1;
							}	
						}		
					}
					
					if (testeVigilanciaA == 0){
						cout << "houve falha no teste de vigilancia de todas as categorias da matriz A" << endl;
						return 0;
					}
					
					/*match tracking*/	
					float matrizYA[tamanhoMatrizBX][tamanhoMatrizAY];
					float matrizYB[tamanhoMatrizBX][tamanhoMatrizAY];
					
					for (int i = 0; i < tamanhoMatrizBX; i++){
						for (int j = 0; j < tamanhoMatrizAY; j++){
							matrizYA[i][j] = 0;
							matrizYB[i][j] = 0;
						}
					}
					
					matrizYA[0][categoriaAtivaA] = 1;
					matrizYB[0][categoriaAtivaB] = 1;
					
					float valorMatchTracking = 0, divisaoMatchTracking = 0;
					for (int i = 0; i < tamanhoMatrizAY; i++){
						valorMatchTracking += pow(matrizYA[0][categoriaAtivaA],matrizWab[categoriaAtivaA][i]);
						divisaoMatchTracking += matrizYA[0][categoriaAtivaA];
					}
					
					valorMatchTracking = (valorMatchTracking / divisaoMatchTracking);
					
					/*loop de match tracking - IMPORTANTE*/
					contadorLimite = 1;
					while (testeVigilanciaA == 0 && contadorLimite < (tamanhoMatrizBX*tamanhoMatrizAX)){
						contadorLimite++;
						
						/*determinando o vt e fazendo mais uma vez o teste de vigilancia*/
						for (int x = 0; x < tamanhoMatrizBX; x++){
							for (int y = 0; y < tamanhoMatrizAX; y++){
								/*para A*/	
								/*art a*/
								cout << "calculando T de A " << endl;
								for (int i = 0; i < tamanhoMatrizAX;i++){
									float somatorioLinha = 0;
									float somatorioLinhaW = 0;
									for (int j = 0; j < tamanhoMatrizAY*2;j++){
										int menorValorAtual = 0;
										int vetorUso[2] = {matrizIA[i][j],matrizWa[i][j]};
										verificaMenorValorVetor(vetorUso,2,menorValorAtual);
										somatorioLinha +=  menorValorAtual;
										//somatorioLinha += (pow(matrizIA[i][j], matrizWa[i][j]));
										somatorioLinhaW += matrizWa[i][j]; 
									}
									vetorTa[i] = somatorioLinha / (alpha + somatorioLinhaW);
									cout << "t " << i << " " << vetorTa[i] << endl;
								
								}	
								
								maiorValor = -1;
								for (int i = 0; i < tamanhoMatrizAX;i++){
									if (vetorTa[i] > maiorValor){
										cout << " vetorTa " << vetorTa[i] << endl;
										cout << " maiorValor " << maiorValor << endl;
										
										if (vetorTa[i] > (maiorValor+0.001)){
											maiorValor = vetorTa[i];
											categoriaAtivaA = i;
											
											cout << " + " << vetorTa[i] << endl;
											cout << " + " << categoriaAtivaA << endl;
										}
									}	
								}
								cout << "categoria a "<< categoriaAtivaA << endl;
								
								int contadorLimiteA = 1;
								while (testeVigilanciaA == 0 && contadorLimiteA < tamanhoMatrizAX){
									contadorLimiteA++;
									vetorTa[categoriaAtivaA] = 0;
									
									maiorValor = -1;
									categoriaAtivaA = -1;
									for (int i = 0; i < tamanhoMatrizAX*2;i++){
										if (vetorTa[i] > maiorValor){
											categoriaAtivaA = i;
											maiorValor = vetorTa[i];
										}	
									}		
									
									if (categoriaAtivaA >= 0){
										/*para a*/
										for (int i = 0; i < tamanhoMatrizAY*2; i++){
											valorTesteVigilancia += pow(matrizIA[categoriaAtivaA][i],matrizWa[categoriaAtivaA][i]);
											divisaoTesteVigilancia += matrizIA[categoriaAtivaA][i];
										}
										
										valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
										cout << "teste de vigilancia a " << valorTesteVigilancia << endl;
										if (valorTesteVigilancia >= pa){
											testeVigilanciaA = 1;
										}	
									}		
								}
								
								if (testeVigilanciaA == 0){
									cout << "houve falha no teste de vigilancia de todas as categorias da matriz A" << endl;
									return 0;
								}	
								
								for (int i = 0; i < tamanhoMatrizBX; i++){
									for (int j = 0; j < tamanhoMatrizAY; j++){
											matrizYA[i][j] = 0;
											matrizYB[i][j] = 0;
										}
									}
									
								matrizYA[0][categoriaAtivaA] = 1;
								matrizYB[0][categoriaAtivaB] = 1;
									
								valorMatchTracking = 0, divisaoMatchTracking = 0;
								for (int i = 0; i < tamanhoMatrizAY; i++){
									valorMatchTracking += pow(matrizYA[0][categoriaAtivaA],matrizWab[categoriaAtivaA][i]);
									divisaoMatchTracking += matrizYA[0][categoriaAtivaA];
								}
									
								valorMatchTracking = (valorMatchTracking / divisaoMatchTracking);
								
								if (valorMatchTracking < pba){
									cout << "match tracking invalido " << endl;
									return 0;
								}
							}
							
							/*para B*/
							/*art b*/	
							cout << "calculando T de B " << endl;
							for (int i = 0; i < tamanhoMatrizBX;i++){
								float somatorioLinha = 0;
								float somatorioLinhaW = 0;
								for (int j = 0; j < tamanhoMatrizBY*2;j++){
									//somatorioLinha += (pow(matrizIB[i][j], matrizWb[i][j]));
									int menorValorAtual = 0;
									int vetorUso[2] = {matrizIB[i][j],matrizWb[i][j]};
									verificaMenorValorVetor(vetorUso,2,menorValorAtual);
									somatorioLinha +=  menorValorAtual;
									somatorioLinhaW += matrizWb[i][j]; 
								}
								vetorTb[i] = somatorioLinha / (alpha + somatorioLinhaW);
								cout << "t " << i << " " << vetorTb[i] << endl;
							}
							
							maiorValor = -1;
							for (int i = 0; i < tamanhoMatrizBX;i++){
								if (vetorTb[i] > maiorValor){
									categoriaAtivaB = i;
									maiorValor = vetorTb[i];
									cout << " + " << vetorTa[i] << endl;
									cout << " + " << categoriaAtivaA << endl;
								}	
							}
							
							cout << "categoria b "<< categoriaAtivaB << endl;
								
							int contadorLimiteB = 1;
							while (testeVigilanciaB == 0 && contadorLimiteB < tamanhoMatrizBX){
								contadorLimiteB++;
								vetorTb[categoriaAtivaB] = 0;
								
								maiorValor = -1;
								categoriaAtivaB = -1;
								for (int i = 0; i < tamanhoMatrizBX;i++){
									if (vetorTb[i] > maiorValor){
										categoriaAtivaB = i;
										maiorValor = vetorTb[i];
									}	
								}		
								
								if (categoriaAtivaB >= 0){
									/*para b*/
									for (int i = 0; i < tamanhoMatrizBY; i++){
										valorTesteVigilancia += pow(matrizIB[categoriaAtivaB][i],matrizWb[categoriaAtivaB][i]);
										divisaoTesteVigilancia += matrizIB[categoriaAtivaB][i];
									}
									
									valorTesteVigilancia = (valorTesteVigilancia / divisaoTesteVigilancia);
									cout << "teste de vigilancia b " << valorTesteVigilancia << endl;
									if (valorTesteVigilancia >= pb){
										testeVigilanciaB = 1;
									}	
								}			
							}
							
							if (testeVigilanciaB == 0){
								cout << "houve falha no teste de vigilancia de todas as categorias da matriz B" << endl;
								return 0;
							}
						
						}
					}
					
					/*atualizacao dos pesos*/
					
					float vetorAtualizacaoPesosA1[tamanhoMatrizAY*2];
					float vetorAtualizacaoPesosA2[tamanhoMatrizAY*2];
					
					float vetorAtualizacaoPesosB1[tamanhoMatrizBY*2];
					float vetorAtualizacaoPesosB2[tamanhoMatrizBY*2];
					
					for (int i = 0; i < tamanhoMatrizAY*2; i++){
						vetorAtualizacaoPesosA1[i] =  beta * (pow(matrizIA[categoriaAtivaA][i],matrizWa[categoriaAtivaA][i]));
						vetorAtualizacaoPesosA2[i] =  (1 - beta) * (matrizWa[categoriaAtivaA][i]);		
						vetorAtualizacaoPesosA1[i] += vetorAtualizacaoPesosA2[i]; 
						matrizWa[categoriaAtivaA][i] = vetorAtualizacaoPesosA1[i];
					}
					
					for (int i = 0; i < tamanhoMatrizBY*2; i++){
						vetorAtualizacaoPesosB1[i] =  beta * (pow(matrizIB[categoriaAtivaB][i],matrizWb[categoriaAtivaB][i]));
						vetorAtualizacaoPesosB2[i] =  (1 - beta) * (matrizWb[categoriaAtivaB][i]);		
						vetorAtualizacaoPesosB1[i] += vetorAtualizacaoPesosB2[i]; 
						matrizWb[categoriaAtivaB][i] = vetorAtualizacaoPesosB1[i];
					}
					
					float vetorAtualizacaoPesosAB[tamanhoMatrizAY];
					for (int i = 0; i < tamanhoMatrizAY; i++){
						vetorAtualizacaoPesosAB[i] = 0;
					}
					cout << "categoria a " << categoriaAtivaA << endl; 
					vetorAtualizacaoPesosAB[categoriaAtivaA] = 1;
					
					for (int i = 0; i < tamanhoMatrizAY; i++){
						matrizWab[categoriaAtivaB][i] = vetorAtualizacaoPesosAB[i];
					}
						
					cout << "Impressao de pesos " << endl;
					cout << "Wa " << endl;
					for (int i = 0;i < tamanhoMatrizAX;i++){
						for (int j = 0; j < tamanhoMatrizAY*2;j++){
							cout << matrizWa[i][j] << " ";
						}
						cout << endl;
					}
					cout << "Wb " << endl;
					for (int i = 0;i < tamanhoMatrizBX;i++){
						for (int j = 0; j < tamanhoMatrizBY*2;j++){
							cout << matrizWb[i][j] << " ";
						}
						cout << endl;
					}
					cout << "Wab " << endl;
					for (int i = 0;i < tamanhoMatrizBX;i++){
						for (int j = 0; j < tamanhoMatrizAY;j++){
							cout << matrizWab[i][j] << " ";
						}
						cout << endl;
					}		
				}	
				/*GUARDA OS NOVOS PESOS GERADOS PARA A MATRIZ DE RECONHECIMENTO PARA QUE NAO FIQUE PERDIDO NA MEMORIA*/
			
				tamanhoMatrizAXReconhecimento = tamanhoMatrizAX;
				tamanhoMatrizAYReconhecimento = tamanhoMatrizAY*2;
				tamanhoMatrizBXReconhecimento = tamanhoMatrizBX;
				tamanhoMatrizBYReconhecimento = tamanhoMatrizBY*2;
				
				for (int i = 0; i < tamanhoMatrizAXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizAYReconhecimento; j++){
						matrizReconhecimentoWa[i][j] = matrizWa[i][j];	
					}
				}
				
				for (int i = 0; i < tamanhoMatrizBXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizBYReconhecimento; j++){
						matrizReconhecimentoWb[i][j] = matrizWb[i][j];	
					}
				}
				
				for (int i = 0; i < tamanhoMatrizAXReconhecimento; i++){
					for (int j = 0; j < tamanhoMatrizBXReconhecimento; j++){
						matrizReconhecimentoWab[i][j] = matrizWab[i][j];	
					}
				}
			}
			
			/*FINALIZANDO TRANSACOES COM ITERACAO*/

			cout << "ITERACAO ENCERRADA" << endl;
			system("pause");			
			break;
		}
	}	
				
	cout << "APLICACAO ENCERRADA! OBRIGADO POR UTILIZAR" << endl;
			
	system("pause");
	return 0;
}
