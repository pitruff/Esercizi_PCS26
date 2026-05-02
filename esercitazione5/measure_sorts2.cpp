#include <algorithm>
#include <iostream>
#include <vector>
#include "timecounter.h"
#include "randfiller.h"
#include "algoritmi_ordinamento.hpp"


//faccio la stessa identica cosa di measure_sorts, ma solo per il mio quicksort modificato (bestSort) e std::sort()
int main(void){
	
	
	randfiller rf;
	timecounter tc;
	
	//qui testerò su ogni dimensione
	for (int i=1; i<=100; i++){
		std::cout<<"\n";
		std::cout<<"Dimensione: "<<i<<"\n";
		//costruisco il vettore di 100 vettori di dimensione i 
		std::vector<std::vector<std::vector<int>>> V;
		V.resize(100);
		
		//costruisco un vettore in cui metto il tempo di ordinamnto di ogni algoritmo al variare delle dimensioni, così lo ordinerò e vedrò facilmente ad ogni dimensione qual è il più veloce
		std::vector<double> vettoreTempi;
		vettoreTempi.resize(2);
		
		for (int j=0; j<=99; j++){
		
			//siccome voglio testare gli algoritmi sugli stessi vettori, ma non posso usare gli stessi stessi prché se no il primo algoritmo che uso li ordinerebbe anche per quelli dopo, ne faccio 6 copie
			//creo quindi un vettore di vettore di vettori. A ogni dimensione associo 100 vettori di 6 vettori identici
			std::vector<std::vector<int>> v;
			v.resize(2);
			std::vector<int> vettore;
			vettore.resize(i);
			rf.fill(vettore, -1000, 1000); 
			v[0]=vettore;
			v[1]=vettore;
			V[j]=v;
		}
		
		//facciamo ordinare a ognuno i 100 vettori di V
		
		tc.tic();
		for (int j=0; j<=99; j++){
			std::sort( V[j][0].begin(), V[j][0].end() );
			
		}
		double tempo_std=tc.toc();
		
		vettoreTempi[0]=tempo_std;
		
		
		tc.tic();
		for (int j=0; j<=99; j++){
			BestSort(V[j][1],0,i-1);
		}
		double tempo_bestS=tc.toc();
		
		vettoreTempi[1]=tempo_bestS;
		
		//vediamo qual è il tempo miliore per questa dimensione
		double tempo_minimo = vettoreTempi[0];
		int indice_minimo=0;
		
		if(vettoreTempi[1]<tempo_minimo) {
			tempo_minimo = vettoreTempi[1];
			indice_minimo=1;
		}
		
		
		std::cout<<"\n";
		std::cout<<"std::sort(): "<<tempo_std/100;
		if (indice_minimo==0){
			std::cout<<"		<- The WINNER is std::sort()!!!";
		}
		std::cout<<"\n";
		
		std::cout<<"BestSort: "<<tempo_bestS/100;
		if (indice_minimo==1){
			std::cout<<"		<- The WINNER is BestSort!!!";
		}
		std::cout<<"\n";
		
	}
	
	
	return 0;
	
	
	
	
	
}