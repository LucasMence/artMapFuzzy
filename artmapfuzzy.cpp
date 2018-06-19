#include <iostream>
#include <stdlib.h>
#include <math.h>

/*ART MAP FUZZY - V 1.0*/
/*AUTHOR: LUCAS DA SILVA*/
/*E-MAIL: MENCETHEDEVELOPER@GMAIL.COM*/
/*UNISALESIANO ARACATUBA-SP, JUNE OF 2018*/

using namespace std;

#define verifyTheLowerValueArray(array, size, value) value = -1; for(int i = 0; i < size; i++){ if (value < array[i]) value = array[i];}

int main(){
	
	/*VALUES INITIALIZATION*/
	int limitMaxDimension = 9; /*THIS VALUE CANNOT BE EDITED IN REAL TIME*/
	int sizeMatrixAX = 3;
	int sizeMatrixAY = 3;
	int sizeMatrixBX = 3;
	int sizeMatrixBY = 1;
	
	float pa = 0.95;
	float pb = 1;
	float pba = 0.95;
	float alpha = 0.1;
	float beta = 1;
	int iteractions = 1;
	
	float matrixInitialA[limitMaxDimension][limitMaxDimension] = {{2,3,5},{6,4,1},{9,8,7}};
	float matrixInitialB[limitMaxDimension][limitMaxDimension] = {{4},{5},{8}};
	
	
	float matrixInitialWa[limitMaxDimension][limitMaxDimension*2];
	float matrixInitialWb[limitMaxDimension][limitMaxDimension*2];	
	float matrixInitialWab[limitMaxDimension][limitMaxDimension];
	
	/*RECOGNTION MODE - THIS VALUES ARE SAVED ON THE SYSTEM*/
	int sizeMatrixAXRecogntion = 0;
	int sizeMatrixAYRecogntion = 0;
	int sizeMatrixBXRecogntion = 0;
	int sizeMatrixBYRecogntion = 0;
	
	float matrixRecogntionWa[limitMaxDimension][limitMaxDimension*2];
	float matrixRecogntionWb[limitMaxDimension][limitMaxDimension*2];	
	float matrixRecogntionWab[limitMaxDimension][limitMaxDimension];
	
	
	for (int i = 0;i < limitMaxDimension;i++){
		for (int j = 0; j < limitMaxDimension*2;j++){
			matrixInitialWa[i][j] = 1;
			matrixRecogntionWa[i][j] = 1;
		}
	}
	for (int i = 0;i < limitMaxDimension;i++){
		for (int j = 0; j < limitMaxDimension*2;j++){
			matrixInitialWb[i][j] = 1;
			matrixRecogntionWb[i][j] = 1;
		}
	}
	for (int i = 0;i < limitMaxDimension;i++){
		for (int j = 0; j < limitMaxDimension;j++){
			matrixInitialWab[i][j] = 1;
			matrixRecogntionWab[i][j] = 1;
		}
	}

	float sum = 0;
	
	/**/
	/*MAIN MENU LOOP*/
	/**/
	
	int option = -1;
	while (option != 0){
		system("cls");
		option = 1;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// NEURAL NETWORK DEVELOPMENT     - ART MAP FUZZY 1.0 ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// AUTHOR: LUCAS DA SILVA - R.A.: 203417              ////" << endl;
		cout << "//// COMPUTER ENGINEERING - 9TH SEMESTER                ////" << endl;
		cout << "//// ADVISOR: MR. JAMES CLAUTON DA SILVA                ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// JUNE, 19 OF 2018                                   ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// CHOOSE WITH YOUR KEYBOARD A OPTION BELOW:          ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << "//// [ 1 ] - EXECUTE / DO ITERACTIONS                   ////" << endl;
		cout << "//// [ 2 ] - EDIT VALUES (ROH, ALPHA E BETA)            ////" << endl;
		cout << "//// [ 3 ] - EDIT MATRIX (A AND B)                      ////" << endl;
		cout << "//// [ 4 ] - EDIT MATRIX (WA, WB AND WAB)               ////" << endl;
		cout << "//// [ 5 ] - CHECK VALUES                               ////" << endl;
		cout << "//// [ 6 ] - EDIT THE VALUE OF ITERACTIONS              ////" << endl;
		cout << "//// [ 7 ] - RECOGNITION MODE                           ////" << endl;
		cout << "//// [ 8 ] - ABOUT THE PROJECT                          ////" << endl;
		cout << "//// [ 0 ] - EXIT                                       ////" << endl;
		cout << "////////////////////////////////////////////////////////////" << endl;
		cout << endl;
		cin >> option;
		
		system("cls");
		
		switch (option){
			case 8:{
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "A R T     M A P     F U Z Z Y  " << endl;
				cout << "V E R S I O N  -  1 . 0" << endl << endl;
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "DEVELOPED BY LUCAS DA SILVA" << endl << endl;
				cout << "E-MAIL : MENCETHEDEVELOPER@GMAIL.COM" << endl << "ADVISOR: MR JAMES CLAUTON DA SILVA" << endl;
				cout << "UNISALESIANO ARACATUBA - SP " << endl << " COURSE OF COMPUTER ENGINEERING - 9TH SEMESTER " << endl;
				cout << "DATE: JUNE, 19 OF 2018 " << endl << endl;
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "PROJECT DEVELOPED FOR THE DISCIPLINE OF 'SISTEMAS INTELIGENTES' - ARTIFICIAL INTELIGENCE " << endl;
				cout << "IF YOU SEE SOME PROBLEM ON THE PROJECT, PLEASE SEND ME A E-MAIL" << endl;
				cout << "MY GITHUB: www.github.com/LucasMence " << endl << endl;
				cout << "////////////////////////////////////////////////////////////" << endl;
				system("pause");
				break;
			}
			case 7: {
				cout << "////////////////////////////////////////////////////////////" << endl;
				float matrixA[sizeMatrixAX][sizeMatrixAY];
				float matrixB[sizeMatrixBX][sizeMatrixBY];
				
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						matrixA[i][j] = matrixInitialA[i][j];
					}
				}
				
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY;j++){
						matrixB[i][j] = matrixInitialB[i][j];
					}
				}
							
				float matrixWa[sizeMatrixAX][sizeMatrixAY*2];
				float matrixWb[sizeMatrixBX][sizeMatrixBY*2];	
				float matrixWab[sizeMatrixBX][sizeMatrixAY];
				
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY*2;j++){
						matrixWa[i][j] = matrixInitialWa[i][j];
					}
				}
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY*2;j++){
						matrixWb[i][j] = matrixInitialWb[i][j];
					}
				}
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixAY*2;j++){
						matrixWab[i][j] = matrixInitialWab[i][j];
					}
				}
				
				float matrixIA[sizeMatrixAX][sizeMatrixAY*2];
				float matrixIB[sizeMatrixBX][sizeMatrixBY*2];	
	
				float matrixIAc[sizeMatrixAX][sizeMatrixAY];
				float matrixIBc[sizeMatrixBX][sizeMatrixBY];	
				
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						sum += matrixA[i][j];	
					}
				}	
				cout << "matrix Ia " << endl;
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						matrixIA[i][j] = (matrixA[i][j] / sum);
						cout << " " << matrixIA[i][j] << " ";
					}
					cout << endl;
				}
				sum = 0;	
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY;j++){
						sum += matrixB[i][j];	
					}
				}	
				cout << "matrix Ib " << endl;
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY;j++){
						matrixIB[i][j] = (matrixB[i][j] / sum);
						cout << " " << matrixIB[i][j] << " ";
					}
					cout << endl;
				}
				
				
				
				cout << "matrix Iac " << endl;
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						matrixIAc[i][j] = (1 - matrixIA[i][j]);
						cout << " " << matrixIAc[i][j] << " ";
					}
					cout << endl;
				}
				
				cout << "matrix Ibc " << endl;
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY;j++){
						matrixIBc[i][j] = (1 - matrixIB[i][j]);
						cout << " " << matrixIBc[i][j] << " ";
					}
					cout << endl;
				}
				
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						matrixIA[i][j+sizeMatrixAY] = matrixIAc[i][j];
					}
				}
				
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY;j++){
						matrixIB[i][j+sizeMatrixBY] = matrixIBc[i][j];
					}
				}
				
				cout << "matrix Ia definitive " << endl;
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY*2;j++){
						cout << " " << matrixIA[i][j] << " ";
					}
					cout << endl;
				}
				
				cout << "matrix Ib definitive " << endl;
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY*2;j++){
						cout << " " << matrixIB[i][j] << " ";
					}
					cout << endl;
				}
				
				float arrayTa[sizeMatrixAX];
				for (int i = 0; i < sizeMatrixAX;i++){
					arrayTa[i] = 0;
				}
				
				float arrayTb[sizeMatrixBX];
				for (int i = 0; i < sizeMatrixBX;i++){
					arrayTb[i] = 0;
				}
				
				/*art a*/
				cout << "calculating T of A " << endl;
				for (int i = 0; i < sizeMatrixAX;i++){
					float lineSum = 0;
					float lineSumW = 0;
					for (int j = 0; j < sizeMatrixAY*2;j++){
						int lowerCurrentValue = 0;
						int arrayLowerValue[2] = {matrixIA[i][j],matrixWa[i][j]};
						verifyTheLowerValueArray(arrayLowerValue,2,lowerCurrentValue);
						lineSum +=  lowerCurrentValue;
						lineSumW += matrixWa[i][j]; 
					}
					arrayTa[i] = lineSum / (alpha + lineSumW);
					cout << "t " << i << " " << arrayTa[i] << endl;
				
				}
				
				/*art b*/	
				cout << "calculating T of B " << endl;
				for (int i = 0; i < sizeMatrixBX;i++){
					float lineSum = 0;
					float lineSumW = 0;
					for (int j = 0; j < sizeMatrixBY*2;j++){
						int lowerCurrentValue = 0;
						int arrayLowerValue[2] = {matrixIB[i][j],matrixWb[i][j]};
						verifyTheLowerValueArray(arrayLowerValue,2,lowerCurrentValue);
						lineSum +=  lowerCurrentValue;
						lineSumW += matrixWb[i][j]; 
					}
					arrayTb[i] = lineSum / (alpha + lineSumW);
					cout << "t " << i << " " << arrayTb[i] << endl;
				}
				
				/*category Active*/
				int categoryActiveA = -1;
				int categoryActiveB = -1;
				
				float biggestValue = -1;
				for (int i = 0; i < sizeMatrixAX;i++){
					if (arrayTa[i] > biggestValue){
						cout << " arrayTa " << arrayTa[i] << endl;
						cout << " biggestValue " << biggestValue << endl;
						
						if (arrayTa[i] > (biggestValue+0.001)){
							biggestValue = arrayTa[i];
							categoryActiveA = i;
							
							cout << " + " << arrayTa[i] << endl;
							cout << " + " << categoryActiveA << endl;
						}
					}	
				}
				cout << "category a "<< categoryActiveA << endl;
				
				
				biggestValue = -1;
				for (int i = 0; i < sizeMatrixBX;i++){
					if (arrayTb[i] > biggestValue){
						categoryActiveB = i;
						biggestValue = arrayTb[i];
						cout << " + " << arrayTa[i] << endl;
						cout << " + " << categoryActiveA << endl;
					}	
				}
				
				cout << "category b "<< categoryActiveB << endl;
				
				/*Sentry test*/
				
				float testSentryA = 0;
				float testSentryB = 0;
				
				float valuetestSentry = 0, divtestSentry = 0;
				/*for the b*/
				for (int i = 0; i < sizeMatrixBY*2; i++){
					valuetestSentry += pow(matrixIB[categoryActiveB][i],matrixWb[categoryActiveB][i]);
					divtestSentry += matrixIB[categoryActiveB][i];
				}
				
				valuetestSentry = (valuetestSentry / divtestSentry);
				cout << "test of Sentry b " << valuetestSentry << endl;
				if (valuetestSentry >= pb){
					testSentryB = 1;
				}
				
				int limitCount = 1;
				while (testSentryB == 0 && limitCount < sizeMatrixBX){
					limitCount++;
					arrayTb[categoryActiveB] = 0;
					
					biggestValue = -1;
					categoryActiveB = -1;
					for (int i = 0; i < sizeMatrixBX;i++){
						if (arrayTb[i] > biggestValue){
							categoryActiveB = i;
							biggestValue = arrayTb[i];
						}	
					}		
					
					if (categoryActiveB >= 0){
						/*for the b*/
						for (int i = 0; i < sizeMatrixBY; i++){
							valuetestSentry += pow(matrixIB[categoryActiveB][i],matrixWb[categoryActiveB][i]);
							divtestSentry += matrixIB[categoryActiveB][i];
						}
						
						valuetestSentry = (valuetestSentry / divtestSentry);
						cout << "test of Sentry b " << valuetestSentry << endl;
						if (valuetestSentry >= pb){
							testSentryB = 1;
						}	
					}
						
				}
				
				if (testSentryB == 0){
					cout << "sentry tests failed on the matrix:  B" << endl;
					return 0;
				}
				
				/*for the a*/
				for (int i = 0; i < sizeMatrixAY*2; i++){
					valuetestSentry += pow(matrixIA[categoryActiveA][i],matrixWa[categoryActiveA][i]);
					divtestSentry += matrixIA[categoryActiveA][i];
				}
				
				valuetestSentry = (valuetestSentry / divtestSentry);
				cout << "test of Sentry a " << valuetestSentry << endl;
				if (valuetestSentry >= pa){
					testSentryA = 1;
				}
				
				limitCount = 1;
				while (testSentryA == 0 && limitCount < sizeMatrixAX){
					limitCount++;
					arrayTa[categoryActiveA] = 0;
					
					biggestValue = -1;
					categoryActiveA = -1;
					for (int i = 0; i < sizeMatrixAX*2;i++){
						if (arrayTa[i] > biggestValue){
							categoryActiveA = i;
							biggestValue = arrayTa[i];
						}	
					}		
					
					if (categoryActiveA >= 0){
						/*for the a*/
						for (int i = 0; i < sizeMatrixAY*2; i++){
							valuetestSentry += pow(matrixIA[categoryActiveA][i],matrixWa[categoryActiveA][i]);
							divtestSentry += matrixIA[categoryActiveA][i];
						}
						
						valuetestSentry = (valuetestSentry / divtestSentry);
						cout << "test of Sentry a " << valuetestSentry << endl;
						if (valuetestSentry >= pa){
							testSentryA = 1;
						}	
					}		
				}
				
				if (testSentryA == 0){
					cout << "sentry tests failed on the matrix:  A" << endl;
					return 0;
				}
				
				/*match tracking*/	
				float matrixYA[sizeMatrixBX][sizeMatrixAY];
				float matrixYB[sizeMatrixBX][sizeMatrixAY];
				
				for (int i = 0; i < sizeMatrixBX; i++){
					for (int j = 0; j < sizeMatrixAY; j++){
						matrixYA[i][j] = 0;
						matrixYB[i][j] = 0;
					}
				}
				
				matrixYA[0][categoryActiveA] = 1;
				matrixYB[0][categoryActiveB] = 1;
				
				float valueMatchTracking = 0, divMatchTracking = 0;
				for (int i = 0; i < sizeMatrixAY; i++){
					valueMatchTracking += pow(matrixYA[0][categoryActiveA],matrixWab[categoryActiveA][i]);
					divMatchTracking += matrixYA[0][categoryActiveA];
				}
				
				valueMatchTracking = (valueMatchTracking / divMatchTracking);
				
				/*loop of match tracking - IMPORTANT*/
				limitCount = 1;
				while (testSentryA == 0 && limitCount < (sizeMatrixBX*sizeMatrixAX)){
					limitCount++;
					
					/*verify if VT needs to make once again the test of Sentry*/
					for (int x = 0; x < sizeMatrixBX; x++){
						for (int y = 0; y < sizeMatrixAX; y++){
							/*for the A*/	
							/*art a*/
							cout << "calculating T of A " << endl;
							for (int i = 0; i < sizeMatrixAX;i++){
								float lineSum = 0;
								float lineSumW = 0;
								for (int j = 0; j < sizeMatrixAY*2;j++){
									int lowerCurrentValue = 0;
									int arrayLowerValue[2] = {matrixIA[i][j],matrixWa[i][j]};
									verifyTheLowerValueArray(arrayLowerValue,2,lowerCurrentValue);
									lineSum +=  lowerCurrentValue;
									lineSumW += matrixWa[i][j]; 
								}
								arrayTa[i] = lineSum / (alpha + lineSumW);
								cout << "t " << i << " " << arrayTa[i] << endl;
							
							}	
							
							biggestValue = -1;
							for (int i = 0; i < sizeMatrixAX;i++){
								if (arrayTa[i] > biggestValue){
									cout << " arrayTa " << arrayTa[i] << endl;
									cout << " biggestValue " << biggestValue << endl;
									
									if (arrayTa[i] > (biggestValue+0.001)){
										biggestValue = arrayTa[i];
										categoryActiveA = i;
										
										cout << " + " << arrayTa[i] << endl;
										cout << " + " << categoryActiveA << endl;
									}
								}	
							}
							cout << "category a "<< categoryActiveA << endl;
							
							int limitCountA = 1;
							while (testSentryA == 0 && limitCountA < sizeMatrixAX){
								limitCountA++;
								arrayTa[categoryActiveA] = 0;
								
								biggestValue = -1;
								categoryActiveA = -1;
								for (int i = 0; i < sizeMatrixAX*2;i++){
									if (arrayTa[i] > biggestValue){
										categoryActiveA = i;
										biggestValue = arrayTa[i];
									}	
								}		
								
								if (categoryActiveA >= 0){
									/*for the a*/
									for (int i = 0; i < sizeMatrixAY*2; i++){
										valuetestSentry += pow(matrixIA[categoryActiveA][i],matrixWa[categoryActiveA][i]);
										divtestSentry += matrixIA[categoryActiveA][i];
									}
									
									valuetestSentry = (valuetestSentry / divtestSentry);
									cout << "test of Sentry a " << valuetestSentry << endl;
									if (valuetestSentry >= pa){
										testSentryA = 1;
									}	
								}		
							}
							
							if (testSentryA == 0){
								cout << "sentry tests failed on the matrix:  A" << endl;
								return 0;
							}	
							
							for (int i = 0; i < sizeMatrixBX; i++){
								for (int j = 0; j < sizeMatrixAY; j++){
										matrixYA[i][j] = 0;
										matrixYB[i][j] = 0;
									}
								}
								
							matrixYA[0][categoryActiveA] = 1;
							matrixYB[0][categoryActiveB] = 1;
								
							valueMatchTracking = 0, divMatchTracking = 0;
							for (int i = 0; i < sizeMatrixAY; i++){
								valueMatchTracking += pow(matrixYA[0][categoryActiveA],matrixWab[categoryActiveA][i]);
								divMatchTracking += matrixYA[0][categoryActiveA];
							}
								
							valueMatchTracking = (valueMatchTracking / divMatchTracking);
							
							if (valueMatchTracking < pba){
								cout << "match tracking invalido " << endl;
								return 0;
							}
						}
						
						/*for the B*/
						/*art b*/	
						cout << "calculating T of B " << endl;
						for (int i = 0; i < sizeMatrixBX;i++){
							float lineSum = 0;
							float lineSumW = 0;
							for (int j = 0; j < sizeMatrixBY*2;j++){
								int lowerCurrentValue = 0;
								int arrayLowerValue[2] = {matrixIB[i][j],matrixWb[i][j]};
								verifyTheLowerValueArray(arrayLowerValue,2,lowerCurrentValue);
								lineSum +=  lowerCurrentValue;
								lineSumW += matrixWb[i][j]; 
							}
							arrayTb[i] = lineSum / (alpha + lineSumW);
							cout << "t " << i << " " << arrayTb[i] << endl;
						}
						
						biggestValue = -1;
						for (int i = 0; i < sizeMatrixBX;i++){
							if (arrayTb[i] > biggestValue){
								categoryActiveB = i;
								biggestValue = arrayTb[i];
								cout << " + " << arrayTa[i] << endl;
								cout << " + " << categoryActiveA << endl;
							}	
						}
						
						cout << "category b "<< categoryActiveB << endl;
							
						int limitCountB = 1;
						while (testSentryB == 0 && limitCountB < sizeMatrixBX){
							limitCountB++;
							arrayTb[categoryActiveB] = 0;
							
							biggestValue = -1;
							categoryActiveB = -1;
							for (int i = 0; i < sizeMatrixBX;i++){
								if (arrayTb[i] > biggestValue){
									categoryActiveB = i;
									biggestValue = arrayTb[i];
								}	
							}		
							
							if (categoryActiveB >= 0){
								/*for the b*/
								for (int i = 0; i < sizeMatrixBY; i++){
									valuetestSentry += pow(matrixIB[categoryActiveB][i],matrixWb[categoryActiveB][i]);
									divtestSentry += matrixIB[categoryActiveB][i];
								}
								
								valuetestSentry = (valuetestSentry / divtestSentry);
								cout << "test of Sentry b " << valuetestSentry << endl;
								if (valuetestSentry >= pb){
									testSentryB = 1;
								}	
							}			
						}
						
						if (testSentryB == 0){
							cout << "sentry tests failed on the matrix:  B" << endl;
							return 0;
						}
					
					}
				}
				
				/*weight update*/
				
				float arrayweightUpdateA1[sizeMatrixAY*2];
				float arrayweightUpdateA2[sizeMatrixAY*2];
				
				float arrayweightUpdateB1[sizeMatrixBY*2];
				float arrayweightUpdateB2[sizeMatrixBY*2];
				
				for (int i = 0; i < sizeMatrixAY*2; i++){
					arrayweightUpdateA1[i] =  beta * (pow(matrixIA[categoryActiveA][i],matrixWa[categoryActiveA][i]));
					arrayweightUpdateA2[i] =  (1 - beta) * (matrixWa[categoryActiveA][i]);		
					arrayweightUpdateA1[i] += arrayweightUpdateA2[i]; 
					matrixWa[categoryActiveA][i] = arrayweightUpdateA1[i];
				}
				
				for (int i = 0; i < sizeMatrixBY*2; i++){
					arrayweightUpdateB1[i] =  beta * (pow(matrixIB[categoryActiveB][i],matrixWb[categoryActiveB][i]));
					arrayweightUpdateB2[i] =  (1 - beta) * (matrixWb[categoryActiveB][i]);		
					arrayweightUpdateB1[i] += arrayweightUpdateB2[i]; 
					matrixWb[categoryActiveB][i] = arrayweightUpdateB1[i];
				}
				
				float arrayweightUpdateAB[sizeMatrixAY];
				for (int i = 0; i < sizeMatrixAY; i++){
					arrayweightUpdateAB[i] = 0;
				}
				cout << "category a " << categoryActiveA << endl; 
				arrayweightUpdateAB[categoryActiveA] = 1;
				
				for (int i = 0; i < sizeMatrixAY; i++){
					matrixWab[categoryActiveB][i] = arrayweightUpdateAB[i];
				}
					
				cout << "PRINTING THE WEIGHTS " << endl;
				cout << "Wa " << endl;
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY*2;j++){
						cout << matrixWa[i][j] << " ";
					}
					cout << endl;
				}
				cout << "Wb " << endl;
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY*2;j++){
						cout << matrixWb[i][j] << " ";
					}
					cout << endl;
				}
				cout << "Wab " << endl;
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						cout << matrixWab[i][j] << " ";
					}
					cout << endl;
				}
				
				/*recogntion mode*/
				int diference = 0;
				for (int i = 0; i < sizeMatrixAXRecogntion; i++){
					for (int j = 0; j < sizeMatrixAYRecogntion; j++){
						if (matrixRecogntionWa[i][j] != matrixWa[i][j])	{
							diference = 1;
							break;
						}
					}
				}
				
				for (int i = 0; i < sizeMatrixBXRecogntion; i++){
					for (int j = 0; j < sizeMatrixBYRecogntion; j++){
						if (matrixRecogntionWb[i][j] != matrixWb[i][j])	{
							diference = 1;
							break;
						}
					}
				}
				
				for (int i = 0; i < sizeMatrixBXRecogntion; i++){
					for (int j = 0; j < sizeMatrixAYRecogntion; j++){
						if (matrixRecogntionWb[i][j] != matrixWb[i][j])	{
							diference = 1;
							break;
						}	
					}
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				if (diference == 1){
					cout << "THAT IS A VALID STANDARD ! " << endl;
				} else {
					cout << "THAT STANDARD IS NOT A VALID FOR MATCHING ! " << endl;	
				}	
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "PRESS A KEY FOR BACK TO MAIN MENU!" << endl;
				system("pause");							
				break;
			}
			case 6: {
				cout << "INSERT THE VALUE OF THE iteractions (CURRENT: "<< iteractions <<"): ";
				cin >> iteractions;
				cout << "ITERACTION VALUE SAVED! PRESS A KEY FOR BACK TO MAIN MENU!" << endl;
				system("pause");	
				break;
			}
			case 5: {
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "matrix A" << endl;
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){	
						cout << matrixInitialA[i][j] << " ";
					}
					cout << endl;	
				}
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "matrix B" << endl;
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY;j++){	
						cout << matrixInitialB[i][j] << " ";
					}
					cout << endl;	
				}
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "matrix WA" << endl;
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY*2;j++){	
						cout << matrixInitialWa[i][j] << " ";
					}
					cout << endl;	
				}
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "matrix WB" << endl;
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY*2;j++){	
						cout << matrixInitialWb[i][j] << " ";
					}
					cout << endl;	
				}
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "matrix WAB" << endl;
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixBX;j++){	
						cout << matrixInitialWab[i][j] << " ";
					}
					cout << endl;	
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "Recogntion: matrix WA" << endl;
				for (int i = 0; i < sizeMatrixAXRecogntion; i++){
					for (int j = 0; j < sizeMatrixAYRecogntion; j++){
						cout << matrixRecogntionWa[i][j] << " ";		
					}
					cout << endl;
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "Recogntion: matrix WB" << endl;
				for (int i = 0; i < sizeMatrixBXRecogntion; i++){
					for (int j = 0; j < sizeMatrixBYRecogntion; j++){
						cout << matrixRecogntionWb[i][j] << " ";	
					}
					cout << endl;
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "Recogntion: matrix WAB" << endl;
				for (int i = 0; i < sizeMatrixAXRecogntion; i++){
					for (int j = 0; j < sizeMatrixBXRecogntion; j++){
						cout << matrixRecogntionWab[i][j] << " ";	
					}
					cout << endl;
				}
				
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "PRESS A KEY FOR BACK TO MAIN MENU!" << endl;
				system("pause");
				break;
			}
			case 4:{				
				cout << "////////////////////////////////////////////////////////////" << endl;
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY*2;j++){
						cout << "INSERT THE VALUE OF THE MATRIX WA [ " << i <<" ] [ "<< j <<" ] (CURRENT: "<< matrixInitialWa[i][j] << "): ";
						cin >> matrixInitialWa[i][j];
					}
				}
				
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY*2;j++){
						cout << "INSERT THE VALUE OF THE MATRIX WB [ " << i <<" ] [ "<< j <<" ] (CURRENT: "<< matrixInitialWb[i][j] << "): ";
						cin >> matrixInitialWb[i][j];
					}
				}
				
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						cout << "INSERT THE VALUE OF THE MATRIX WAB [ " << i <<" ] [ "<< j <<" ] (CURRENT: "<< matrixInitialWab[i][j] << "): ";
						cin >> matrixInitialWab[i][j];
					}
				}
				
				cout << "WEIGHT MATRIX VALUES SAVED! PRESS A KEY FOR BACK TO MAIN MENU!" << endl;
				system("pause");
				break;
			}
			
			case 3:{
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "INSERT THE TOTAL OF LINES OF THE MATRIX A (CURRENT: "<< sizeMatrixAX <<"): ";
				cin >> sizeMatrixAX;
				cout << "INSERT THE TOTAL OF COLUMNS OF THE MATRIX A (CURRENT: "<< sizeMatrixAY <<"): ";
				cin >> sizeMatrixAY;
				cout << "INSERT THE TOTAL OF LINES OF THE MATRIX B (CURRENT: "<< sizeMatrixBX <<"): ";
				cin >> sizeMatrixBX;
				cout << "INSERT THE TOTAL OF COLUMNS OF THE MATRIX B (CURRENT: " << sizeMatrixBY <<"): ";
				cin >> sizeMatrixBY;
				
				cout << endl << endl;
				cout << "WEIGHT OF THE MATRIX SAVED! PRESS A KEY TO BEGIN EDIT THE VALUE OF THE MATRIX " << endl;
				system("pause");
				system("cls");
				
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						cout << "INSERT THE VALUE OF THE MATRIX A [ " << i <<" ] [ "<< j <<" ] (CURRENT: "<< matrixInitialA[i][j] << "): ";
						cin >> matrixInitialA[i][j];
					}
				}
				
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY;j++){
						cout << "INSERT THE VALUE OF THE MATRIX B [ " << i <<" ] [ "<< j <<" ] (CURRENT: "<< matrixInitialB[i][j] << "): ";
						cin >> matrixInitialB[i][j];
					}
				}
				
				cout << "MATRIX VALUES SAVED! PRESS A KEY FOR BACK TO MAIN MENU!" << endl;
				system("pause");
				break;
			}
			
			case 2:{
				cout << "////////////////////////////////////////////////////////////" << endl;
				cout << "INSERT THE VALUE OF THE ROH of A (CURRENT: "<< pa <<"): ";
				cin >> pa;
				cout << "INSERT THE VALUE OF THE ROH of B (CURRENT: "<< pb <<"): ";
				cin >> pb;
				cout << "INSERT THE VALUE OF THE ROH of BA (CURRENT: "<< pba <<"): ";
				cin >> pba;
				cout << "INSERT THE VALUE OF THE ALPHA (CURRENT: "<< alpha <<"): ";
				cin >> alpha;
				cout << "INSERT THE VALUE OF THE BETA (CURRENT: "<< beta <<"): ";
				cin >> beta;
				cout << "VALUES SAVED! PRESS A KEY FOR BACK TO MAIN MENU!" << endl;
				system("pause");
				break;
			}
			
			case 1:{
				cout << "////////////////////////////////////////////////////////////" << endl;
				float matrixA[sizeMatrixAX][sizeMatrixAY];
				float matrixB[sizeMatrixBX][sizeMatrixBY];
				
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY;j++){
						matrixA[i][j] = matrixInitialA[i][j];
					}
				}
				
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY;j++){
						matrixB[i][j] = matrixInitialB[i][j];
					}
				}
							
				float matrixWa[sizeMatrixAX][sizeMatrixAY*2];
				float matrixWb[sizeMatrixBX][sizeMatrixBY*2];	
				float matrixWab[sizeMatrixBX][sizeMatrixAY];
				
				for (int i = 0;i < sizeMatrixAX;i++){
					for (int j = 0; j < sizeMatrixAY*2;j++){
						matrixWa[i][j] = matrixInitialWa[i][j];
					}
				}
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixBY*2;j++){
						matrixWb[i][j] = matrixInitialWb[i][j];
					}
				}
				for (int i = 0;i < sizeMatrixBX;i++){
					for (int j = 0; j < sizeMatrixAY*2;j++){
						matrixWab[i][j] = matrixInitialWab[i][j];
					}
				}
				
				float matrixIA[sizeMatrixAX][sizeMatrixAY*2];
				float matrixIB[sizeMatrixBX][sizeMatrixBY*2];	
	
				float matrixIAc[sizeMatrixAX][sizeMatrixAY];
				float matrixIBc[sizeMatrixBX][sizeMatrixBY];	
				
				
				/*LOOP of ITERACTION*/
				
				for (int iteractionCounter = 0; iteractionCounter < iteractions; iteractionCounter++){
					for (int i = 0;i < sizeMatrixAX;i++){
						for (int j = 0; j < sizeMatrixAY;j++){
							sum += matrixA[i][j];	
						}
					}	
					cout << "matrix Ia " << endl;
					for (int i = 0;i < sizeMatrixAX;i++){
						for (int j = 0; j < sizeMatrixAY;j++){
							matrixIA[i][j] = (matrixA[i][j] / sum);
							cout << " " << matrixIA[i][j] << " ";
						}
						cout << endl;
					}
					sum = 0;	
					for (int i = 0;i < sizeMatrixBX;i++){
						for (int j = 0; j < sizeMatrixBY;j++){
							sum += matrixB[i][j];	
						}
					}	
					cout << "matrix Ib " << endl;
					for (int i = 0;i < sizeMatrixBX;i++){
						for (int j = 0; j < sizeMatrixBY;j++){
							matrixIB[i][j] = (matrixB[i][j] / sum);
							cout << " " << matrixIB[i][j] << " ";
						}
						cout << endl;
					}
					
					
					
					cout << "matrix Iac " << endl;
					for (int i = 0;i < sizeMatrixAX;i++){
						for (int j = 0; j < sizeMatrixAY;j++){
							matrixIAc[i][j] = (1 - matrixIA[i][j]);
							cout << " " << matrixIAc[i][j] << " ";
						}
						cout << endl;
					}
					
					cout << "matrix Ibc " << endl;
					for (int i = 0;i < sizeMatrixBX;i++){
						for (int j = 0; j < sizeMatrixBY;j++){
							matrixIBc[i][j] = (1 - matrixIB[i][j]);
							cout << " " << matrixIBc[i][j] << " ";
						}
						cout << endl;
					}
					
					for (int i = 0;i < sizeMatrixAX;i++){
						for (int j = 0; j < sizeMatrixAY;j++){
							matrixIA[i][j+sizeMatrixAY] = matrixIAc[i][j];
						}
					}
					
					for (int i = 0;i < sizeMatrixBX;i++){
						for (int j = 0; j < sizeMatrixBY;j++){
							matrixIB[i][j+sizeMatrixBY] = matrixIBc[i][j];
						}
					}
					
					cout << "matrix Ia definitive " << endl;
					for (int i = 0;i < sizeMatrixAX;i++){
						for (int j = 0; j < sizeMatrixAY*2;j++){
							cout << " " << matrixIA[i][j] << " ";
						}
						cout << endl;
					}
					
					cout << "matrix Ib definitive " << endl;
					for (int i = 0;i < sizeMatrixBX;i++){
						for (int j = 0; j < sizeMatrixBY*2;j++){
							cout << " " << matrixIB[i][j] << " ";
						}
						cout << endl;
					}
					
					float arrayTa[sizeMatrixAX];
					for (int i = 0; i < sizeMatrixAX;i++){
						arrayTa[i] = 0;
					}
					
					float arrayTb[sizeMatrixBX];
					for (int i = 0; i < sizeMatrixBX;i++){
						arrayTb[i] = 0;
					}
					
					/*art a*/
					cout << "calculating T of A " << endl;
					for (int i = 0; i < sizeMatrixAX;i++){
						float lineSum = 0;
						float lineSumW = 0;
						for (int j = 0; j < sizeMatrixAY*2;j++){
							int lowerCurrentValue = 0;
							int arrayLowerValue[2] = {matrixIA[i][j],matrixWa[i][j]};
							verifyTheLowerValueArray(arrayLowerValue,2,lowerCurrentValue);
							lineSum +=  lowerCurrentValue;
							lineSumW += matrixWa[i][j]; 
						}
						arrayTa[i] = lineSum / (alpha + lineSumW);
						cout << "t " << i << " " << arrayTa[i] << endl;
					
					}
					
					/*art b*/	
					cout << "calculating T of B " << endl;
					for (int i = 0; i < sizeMatrixBX;i++){
						float lineSum = 0;
						float lineSumW = 0;
						for (int j = 0; j < sizeMatrixBY*2;j++){
							int lowerCurrentValue = 0;
							int arrayLowerValue[2] = {matrixIB[i][j],matrixWb[i][j]};
							verifyTheLowerValueArray(arrayLowerValue,2,lowerCurrentValue);
							lineSum +=  lowerCurrentValue;
							lineSumW += matrixWb[i][j]; 
						}
						arrayTb[i] = lineSum / (alpha + lineSumW);
						cout << "t " << i << " " << arrayTb[i] << endl;
					}
					
					/*category Active*/
					int categoryActiveA = -1;
					int categoryActiveB = -1;
					
					float biggestValue = -1;
					for (int i = 0; i < sizeMatrixAX;i++){
						if (arrayTa[i] > biggestValue){
							cout << " arrayTa " << arrayTa[i] << endl;
							cout << " biggestValue " << biggestValue << endl;
							
							if (arrayTa[i] > (biggestValue+0.001)){
								biggestValue = arrayTa[i];
								categoryActiveA = i;
								
								cout << " + " << arrayTa[i] << endl;
								cout << " + " << categoryActiveA << endl;
							}
						}	
					}
					cout << "category a "<< categoryActiveA << endl;
					
					
					biggestValue = -1;
					for (int i = 0; i < sizeMatrixBX;i++){
						if (arrayTb[i] > biggestValue){
							categoryActiveB = i;
							biggestValue = arrayTb[i];
							cout << " + " << arrayTa[i] << endl;
							cout << " + " << categoryActiveA << endl;
						}	
					}
					
					cout << "category b "<< categoryActiveB << endl;
					
					/*test of Sentry*/
					
					float testSentryA = 0;
					float testSentryB = 0;
					
					float valuetestSentry = 0, divtestSentry = 0;
					/*for the b*/
					for (int i = 0; i < sizeMatrixBY*2; i++){
						valuetestSentry += pow(matrixIB[categoryActiveB][i],matrixWb[categoryActiveB][i]);
						divtestSentry += matrixIB[categoryActiveB][i];
					}
					
					valuetestSentry = (valuetestSentry / divtestSentry);
					cout << "test of Sentry b " << valuetestSentry << endl;
					if (valuetestSentry >= pb){
						testSentryB = 1;
					}
					
					int limitCount = 1;
					while (testSentryB == 0 && limitCount < sizeMatrixBX){
						limitCount++;
						arrayTb[categoryActiveB] = 0;
						
						biggestValue = -1;
						categoryActiveB = -1;
						for (int i = 0; i < sizeMatrixBX;i++){
							if (arrayTb[i] > biggestValue){
								categoryActiveB = i;
								biggestValue = arrayTb[i];
							}	
						}		
						
						if (categoryActiveB >= 0){
							/*for the b*/
							for (int i = 0; i < sizeMatrixBY; i++){
								valuetestSentry += pow(matrixIB[categoryActiveB][i],matrixWb[categoryActiveB][i]);
								divtestSentry += matrixIB[categoryActiveB][i];
							}
							
							valuetestSentry = (valuetestSentry / divtestSentry);
							cout << "test of Sentry b " << valuetestSentry << endl;
							if (valuetestSentry >= pb){
								testSentryB = 1;
							}	
						}
							
					}
					
					if (testSentryB == 0){
						cout << "sentry tests failed on the matrix:  B" << endl;
						return 0;
					}
					
					/*for the a*/
					for (int i = 0; i < sizeMatrixAY*2; i++){
						valuetestSentry += pow(matrixIA[categoryActiveA][i],matrixWa[categoryActiveA][i]);
						divtestSentry += matrixIA[categoryActiveA][i];
					}
					
					valuetestSentry = (valuetestSentry / divtestSentry);
					cout << "test of Sentry a " << valuetestSentry << endl;
					if (valuetestSentry >= pa){
						testSentryA = 1;
					}
					
					limitCount = 1;
					while (testSentryA == 0 && limitCount < sizeMatrixAX){
						limitCount++;
						arrayTa[categoryActiveA] = 0;
						
						biggestValue = -1;
						categoryActiveA = -1;
						for (int i = 0; i < sizeMatrixAX*2;i++){
							if (arrayTa[i] > biggestValue){
								categoryActiveA = i;
								biggestValue = arrayTa[i];
							}	
						}		
						
						if (categoryActiveA >= 0){
							/*for the a*/
							for (int i = 0; i < sizeMatrixAY*2; i++){
								valuetestSentry += pow(matrixIA[categoryActiveA][i],matrixWa[categoryActiveA][i]);
								divtestSentry += matrixIA[categoryActiveA][i];
							}
							
							valuetestSentry = (valuetestSentry / divtestSentry);
							cout << "test of Sentry a " << valuetestSentry << endl;
							if (valuetestSentry >= pa){
								testSentryA = 1;
							}	
						}		
					}
					
					if (testSentryA == 0){
						cout << "sentry tests failed on the matrix:  A" << endl;
						return 0;
					}
					
					/*match tracking*/	
					float matrixYA[sizeMatrixBX][sizeMatrixAY];
					float matrixYB[sizeMatrixBX][sizeMatrixAY];
					
					for (int i = 0; i < sizeMatrixBX; i++){
						for (int j = 0; j < sizeMatrixAY; j++){
							matrixYA[i][j] = 0;
							matrixYB[i][j] = 0;
						}
					}
					
					matrixYA[0][categoryActiveA] = 1;
					matrixYB[0][categoryActiveB] = 1;
					
					float valueMatchTracking = 0, divMatchTracking = 0;
					for (int i = 0; i < sizeMatrixAY; i++){
						valueMatchTracking += pow(matrixYA[0][categoryActiveA],matrixWab[categoryActiveA][i]);
						divMatchTracking += matrixYA[0][categoryActiveA];
					}
					
					valueMatchTracking = (valueMatchTracking / divMatchTracking);
					
					/*loop of match tracking - IMPORTANTE*/
					limitCount = 1;
					while (testSentryA == 0 && limitCount < (sizeMatrixBX*sizeMatrixAX)){
						limitCount++;
						
						/*verify if VT needs to make once again the test of Sentry*/
						for (int x = 0; x < sizeMatrixBX; x++){
							for (int y = 0; y < sizeMatrixAX; y++){
								/*for the A*/	
								/*art a*/
								cout << "calculating T of A " << endl;
								for (int i = 0; i < sizeMatrixAX;i++){
									float lineSum = 0;
									float lineSumW = 0;
									for (int j = 0; j < sizeMatrixAY*2;j++){
										int lowerCurrentValue = 0;
										int arrayLowerValue[2] = {matrixIA[i][j],matrixWa[i][j]};
										verifyTheLowerValueArray(arrayLowerValue,2,lowerCurrentValue);
										lineSum +=  lowerCurrentValue;
										lineSumW += matrixWa[i][j]; 
									}
									arrayTa[i] = lineSum / (alpha + lineSumW);
									cout << "t " << i << " " << arrayTa[i] << endl;
								
								}	
								
								biggestValue = -1;
								for (int i = 0; i < sizeMatrixAX;i++){
									if (arrayTa[i] > biggestValue){
										cout << " arrayTa " << arrayTa[i] << endl;
										cout << " biggestValue " << biggestValue << endl;
										
										if (arrayTa[i] > (biggestValue+0.001)){
											biggestValue = arrayTa[i];
											categoryActiveA = i;
											
											cout << " + " << arrayTa[i] << endl;
											cout << " + " << categoryActiveA << endl;
										}
									}	
								}
								cout << "category a "<< categoryActiveA << endl;
								
								int limitCountA = 1;
								while (testSentryA == 0 && limitCountA < sizeMatrixAX){
									limitCountA++;
									arrayTa[categoryActiveA] = 0;
									
									biggestValue = -1;
									categoryActiveA = -1;
									for (int i = 0; i < sizeMatrixAX*2;i++){
										if (arrayTa[i] > biggestValue){
											categoryActiveA = i;
											biggestValue = arrayTa[i];
										}	
									}		
									
									if (categoryActiveA >= 0){
										/*for the a*/
										for (int i = 0; i < sizeMatrixAY*2; i++){
											valuetestSentry += pow(matrixIA[categoryActiveA][i],matrixWa[categoryActiveA][i]);
											divtestSentry += matrixIA[categoryActiveA][i];
										}
										
										valuetestSentry = (valuetestSentry / divtestSentry);
										cout << "test of Sentry a " << valuetestSentry << endl;
										if (valuetestSentry >= pa){
											testSentryA = 1;
										}	
									}		
								}
								
								if (testSentryA == 0){
									cout << "sentry tests failed on the matrix:  A" << endl;
									return 0;
								}	
								
								for (int i = 0; i < sizeMatrixBX; i++){
									for (int j = 0; j < sizeMatrixAY; j++){
											matrixYA[i][j] = 0;
											matrixYB[i][j] = 0;
										}
									}
									
								matrixYA[0][categoryActiveA] = 1;
								matrixYB[0][categoryActiveB] = 1;
									
								valueMatchTracking = 0, divMatchTracking = 0;
								for (int i = 0; i < sizeMatrixAY; i++){
									valueMatchTracking += pow(matrixYA[0][categoryActiveA],matrixWab[categoryActiveA][i]);
									divMatchTracking += matrixYA[0][categoryActiveA];
								}
									
								valueMatchTracking = (valueMatchTracking / divMatchTracking);
								
								if (valueMatchTracking < pba){
									cout << "match tracking invalido " << endl;
									return 0;
								}
							}
							
							/*for the B*/
							/*art b*/	
							cout << "calculating T of B " << endl;
							for (int i = 0; i < sizeMatrixBX;i++){
								float lineSum = 0;
								float lineSumW = 0;
								for (int j = 0; j < sizeMatrixBY*2;j++){
									int lowerCurrentValue = 0;
									int arrayLowerValue[2] = {matrixIB[i][j],matrixWb[i][j]};
									verifyTheLowerValueArray(arrayLowerValue,2,lowerCurrentValue);
									lineSum +=  lowerCurrentValue;
									lineSumW += matrixWb[i][j]; 
								}
								arrayTb[i] = lineSum / (alpha + lineSumW);
								cout << "t " << i << " " << arrayTb[i] << endl;
							}
							
							biggestValue = -1;
							for (int i = 0; i < sizeMatrixBX;i++){
								if (arrayTb[i] > biggestValue){
									categoryActiveB = i;
									biggestValue = arrayTb[i];
									cout << " + " << arrayTa[i] << endl;
									cout << " + " << categoryActiveA << endl;
								}	
							}
							
							cout << "category b "<< categoryActiveB << endl;
								
							int limitCountB = 1;
							while (testSentryB == 0 && limitCountB < sizeMatrixBX){
								limitCountB++;
								arrayTb[categoryActiveB] = 0;
								
								biggestValue = -1;
								categoryActiveB = -1;
								for (int i = 0; i < sizeMatrixBX;i++){
									if (arrayTb[i] > biggestValue){
										categoryActiveB = i;
										biggestValue = arrayTb[i];
									}	
								}		
								
								if (categoryActiveB >= 0){
									/*for the b*/
									for (int i = 0; i < sizeMatrixBY; i++){
										valuetestSentry += pow(matrixIB[categoryActiveB][i],matrixWb[categoryActiveB][i]);
										divtestSentry += matrixIB[categoryActiveB][i];
									}
									
									valuetestSentry = (valuetestSentry / divtestSentry);
									cout << "test of Sentry b " << valuetestSentry << endl;
									if (valuetestSentry >= pb){
										testSentryB = 1;
									}	
								}			
							}
							
							if (testSentryB == 0){
								cout << "sentry tests failed on the matrix:  B" << endl;
								return 0;
							}
						
						}
					}
					
					/*weight update*/
					
					float arrayweightUpdateA1[sizeMatrixAY*2];
					float arrayweightUpdateA2[sizeMatrixAY*2];
					
					float arrayweightUpdateB1[sizeMatrixBY*2];
					float arrayweightUpdateB2[sizeMatrixBY*2];
					
					for (int i = 0; i < sizeMatrixAY*2; i++){
						arrayweightUpdateA1[i] =  beta * (pow(matrixIA[categoryActiveA][i],matrixWa[categoryActiveA][i]));
						arrayweightUpdateA2[i] =  (1 - beta) * (matrixWa[categoryActiveA][i]);		
						arrayweightUpdateA1[i] += arrayweightUpdateA2[i]; 
						matrixWa[categoryActiveA][i] = arrayweightUpdateA1[i];
					}
					
					for (int i = 0; i < sizeMatrixBY*2; i++){
						arrayweightUpdateB1[i] =  beta * (pow(matrixIB[categoryActiveB][i],matrixWb[categoryActiveB][i]));
						arrayweightUpdateB2[i] =  (1 - beta) * (matrixWb[categoryActiveB][i]);		
						arrayweightUpdateB1[i] += arrayweightUpdateB2[i]; 
						matrixWb[categoryActiveB][i] = arrayweightUpdateB1[i];
					}
					
					float arrayweightUpdateAB[sizeMatrixAY];
					for (int i = 0; i < sizeMatrixAY; i++){
						arrayweightUpdateAB[i] = 0;
					}
					cout << "category a " << categoryActiveA << endl; 
					arrayweightUpdateAB[categoryActiveA] = 1;
					
					for (int i = 0; i < sizeMatrixAY; i++){
						matrixWab[categoryActiveB][i] = arrayweightUpdateAB[i];
					}
						
					cout << "PRINTING THE WEIGHTS " << endl;
					cout << "Wa " << endl;
					for (int i = 0;i < sizeMatrixAX;i++){
						for (int j = 0; j < sizeMatrixAY*2;j++){
							cout << matrixWa[i][j] << " ";
						}
						cout << endl;
					}
					cout << "Wb " << endl;
					for (int i = 0;i < sizeMatrixBX;i++){
						for (int j = 0; j < sizeMatrixBY*2;j++){
							cout << matrixWb[i][j] << " ";
						}
						cout << endl;
					}
					cout << "Wab " << endl;
					for (int i = 0;i < sizeMatrixBX;i++){
						for (int j = 0; j < sizeMatrixAY;j++){
							cout << matrixWab[i][j] << " ";
						}
						cout << endl;
					}		
				}	
				/*SAVE THE NEW WEIGHT VALUES TO MAKE THE RECOGNTION LATER*/
			
				sizeMatrixAXRecogntion = sizeMatrixAX;
				sizeMatrixAYRecogntion = sizeMatrixAY*2;
				sizeMatrixBXRecogntion = sizeMatrixBX;
				sizeMatrixBYRecogntion = sizeMatrixBY*2;
				
				for (int i = 0; i < sizeMatrixAXRecogntion; i++){
					for (int j = 0; j < sizeMatrixAYRecogntion; j++){
						matrixRecogntionWa[i][j] = matrixWa[i][j];	
					}
				}
				
				for (int i = 0; i < sizeMatrixBXRecogntion; i++){
					for (int j = 0; j < sizeMatrixBYRecogntion; j++){
						matrixRecogntionWb[i][j] = matrixWb[i][j];	
					}
				}
				
				for (int i = 0; i < sizeMatrixAXRecogntion; i++){
					for (int j = 0; j < sizeMatrixBXRecogntion; j++){
						matrixRecogntionWab[i][j] = matrixWab[i][j];	
					}
				}
			}
			
			/*FINISHING THE ITERACTIONS*/

			cout << "ITERACTION FINISHED" << endl;
			system("pause");			
			break;
		}
	}	
				
	cout << "SYSTEM FINISHED! THANKS FOR USING!" << endl;
			
	system("pause");
	return 0;
}
