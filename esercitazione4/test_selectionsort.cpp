#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "algoritmi_ordinamento.hpp"
#include "randfiller.h"

int main(void)
{
	randfiller rf;
	for (int i=1; i<=40; i++){ //provo su 40 vettori di interi, 30 float e 30 double
		
		std::vector<int> lunghezza;
		lunghezza.resize(1);
		rf.fill(lunghezza, 0, 100); //così ho deciso casualmente la lunghezza del mio vettore di interi
		
		std::vector<int> vi;
		vi.resize(lunghezza[0]);
		rf.fill(vi, -1000, 1000); //questo è il mio vettore casuale
		
		selectionSort(vi);
		if(!is_sorted(vi)){
			return EXIT_FAILURE;
		}
		
	}
	
	for (int i=1; i<=30; i++){ 
		
		std::vector<int> lunghezza;
		lunghezza.resize(1);
		rf.fill(lunghezza, 0, 100); 
		
		std::vector<float> vf;
		vf.resize(lunghezza[0]);
		rf.fill(vf, -1000.0f, 1000.0f); 
		
		selectionSort(vf);
		if(!is_sorted(vf)){
			return EXIT_FAILURE;
		}
		
	}
	
	for (int i=1; i<=30; i++){ 
		
		std::vector<int> lunghezza;
		lunghezza.resize(1);
		rf.fill(lunghezza, 0, 100); 
		
		std::vector<double> vd;
		vd.resize(lunghezza[0]);
		rf.fill(vd, -1000.0, 1000.0); 
		
		selectionSort(vd);
		if(!is_sorted(vd)){
			return EXIT_FAILURE;
		}
		
	}
	
	//ora vediamo con le stringhe
	std::vector<std::string> lista_stringhe(10);

	lista_stringhe[0]="new york";
	lista_stringhe[1]="genova";
	lista_stringhe[2]="livorno";
	lista_stringhe[3]="cagliari";
	lista_stringhe[4]="bergamo";
	lista_stringhe[5]="madrid";
	lista_stringhe[6]="firenze";
	lista_stringhe[7]="alessandria";
	lista_stringhe[8]="monaco";
	lista_stringhe[9]="domodossola";
	
	selectionSort(lista_stringhe);
	if(!is_sorted(lista_stringhe)){
		return EXIT_FAILURE;
	}
	
	
	return EXIT_SUCCESS;
}