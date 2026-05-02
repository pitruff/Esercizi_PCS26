#include <algorithm>
#include <iostream>
#include <vector>
#include "timecounter.h"
#include "randfiller.h"
#include "algoritmi_ordinamento.hpp"

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
		vettoreTempi.resize(7);
		
		for (int j=0; j<=99; j++){
		
			//siccome voglio testare gli algoritmi sugli stessi vettori, ma non posso usare gli stessi stessi prché se no il primo algoritmo che uso li ordinerebbe anche per quelli dopo, ne faccio 6 copie
			//creo quindi un vettore di vettore di vettori. A ogni dimensione associo 100 vettori di 6 vettori identici
			std::vector<std::vector<int>> v;
			v.resize(7);
			std::vector<int> vettore;
			vettore.resize(i);
			rf.fill(vettore, -1000, 1000); 
			for (int k=0; k<=6; k++){
				v[k]=vettore;
			}
			V[j]=v;
		}
		
		//facciamo ordinare a ognuno i 100 vettori di V
		tc.tic();
		for (int j=0; j<=99; j++){
			bubbleSort(V[j][0]);
		}
		double tempo_bS=tc.toc();
		
		vettoreTempi[0]=tempo_bS;
		
		
		
		tc.tic();
		for (int j=0; j<=99; j++){
			selectionSort(V[j][1]);
		}
		double tempo_sS=tc.toc();
		
		vettoreTempi[1]=tempo_sS;
		
		tc.tic();
		for (int j=0; j<=99; j++){
			insertionSort(V[j][2]);
		}
		double tempo_iS=tc.toc();
		
		vettoreTempi[2]=tempo_iS;
		
		tc.tic();
		for (int j=0; j<=99; j++){
			std::sort( V[j][3].begin(), V[j][3].end() );
			
		}
		double tempo_std=tc.toc();
		
		vettoreTempi[3]=tempo_std;
		
		tc.tic();
		for (int j=0; j<=99; j++){
			MergeSort(V[j][4],0,i-1);
		}
		double tempo_mS=tc.toc();
		
		vettoreTempi[4]=tempo_mS;
		
		tc.tic();
		for (int j=0; j<=99; j++){
			Quicksort(V[j][5],0,i-1);
		}
		double tempo_qS=tc.toc();
		
		vettoreTempi[5]=tempo_qS;
		
		//tc.tic();
		//for (int j=0; j<=99; j++){
			//BestSort(V[j][6],0,i-1);
		//}
		//double tempo_bestS=tc.toc();
		
		//vettoreTempi[6]=tempo_bestS;
		
		//vediamo qual è il tempo miliore per questa dimensione
		double tempo_minimo = vettoreTempi[0];
		int indice_minimo=0;
		for(int k=1; k<=5; k++){
			if(vettoreTempi[k]<tempo_minimo) {
				tempo_minimo = vettoreTempi[k];
				indice_minimo=k;
			}
		}
		
		
		std::cout<<"bubbleSort: "<<tempo_bS/100;
		if (indice_minimo==0){
			std::cout<<"		<- The WINNER is bubbleSort!!!";
		}
		std::cout<<"\n";
		
		std::cout<<"selectionSort: "<<tempo_sS/100;
		if (indice_minimo==1){
			std::cout<<"		<- The WINNER is selectionSort!!!";
		}
		std::cout<<"\n";
		std::cout<<"insertionSort: "<<tempo_iS/100;
		if (indice_minimo==2){
			std::cout<<"		<- The WINNER is insertionSort!!!";
		}
		std::cout<<"\n";
		std::cout<<"std::sort(): "<<tempo_std/100;
		if (indice_minimo==3){
			std::cout<<"		<- The WINNER is std::sort()!!!";
		}
		std::cout<<"\n";
		std::cout<<"MergeSort: "<<tempo_mS/100;
		if (indice_minimo==4){
			std::cout<<"		<- The WINNER is MergeSort!!!";
		}
		std::cout<<"\n";
		
		std::cout<<"Quicksort: "<<tempo_qS/100;
		if (indice_minimo==5){
			std::cout<<"		<- The WINNER is Quicksort!!!";
		}
		std::cout<<"\n";
		
		
	}
	
	
	return 0;
	
	
	
	
	
}