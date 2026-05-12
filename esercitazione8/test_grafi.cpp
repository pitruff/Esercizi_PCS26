#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <set>

#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"

int main(void)
{
	
	unidirected_graph g1;
	unidirected_edge e12(1,2);
	unidirected_edge e23(2,3);
	unidirected_edge e34(3,4);
	
	g1.add_edge(e12);
	g1.add_edge(e23);
	g1.add_edge(e34);
	
	
	//testo il costruttore di copia. Giusto per provare qualcosa controllo se hanno lo stesso numero di archi e se l'arco con l'ID 2 è lo stesso
	
	unidirected_graph grafo_copia(g1);
	
	if (grafo_copia.all_edges().size()!=g1.all_edges().size() or grafo_copia.edge_at(2) != g1.edge_at(2)){
		
		return EXIT_FAILURE;
	
	}
	
	
	
	//Ora vediamo se abbiamo costruito bene g1. Ho aggiunto 3 archi
	if (g1.all_edges().size()!=3){
		
		return EXIT_FAILURE;
	
	}
	
	//i nodi dovrebbero essere 1,2,3,4
	if (g1.all_nodes().size()!=4){
		
		return EXIT_FAILURE;
	
	}
	
	//prendo per esempio il set dei vicini di 2, che dovrebbe includere 1 e 3
	std::set<int> vicini2=g1.neighbours(2);
	
	if(vicini2.size()!=2){
		return EXIT_FAILURE;
	}
	
	if(vicini2.count(1)!=1){
		return EXIT_FAILURE;
	}
	
	if(vicini2.count(3)!=1){
		return EXIT_FAILURE;
	}
	
	if(vicini2.count(4)!=0){
		return EXIT_FAILURE;
	}
	
	
	
	//vediamo se funzionano edge_number e edge.at
	
	int id1 = g1.edge_number(e12);
	int id2 = g1.edge_number(e23);
	int id3 = g1.edge_number(e34);
	
	unidirected_edge recuperato1=g1.edge_at(id1);
	unidirected_edge recuperato2=g1.edge_at(id2);
	unidirected_edge recuperato3=g1.edge_at(id3);
	
	if(recuperato1!=e12 or recuperato2!=e23 or recuperato3!=e34){

		return EXIT_FAILURE;
	}

	
	//testiamo la differenza tra grafi
	//costruiamo un secondo grafo che contiene solo l'arco e23
	
	unidirected_graph g2;
	g2.add_edge(e23);
	
	unidirected_graph diff= g1-g2;
	
	//verifichiamo prima la dimensione di diff
	
	if (diff.all_edges().size()!=2){
		return EXIT_FAILURE;
	}
	
	//e poi che non contenga e23
	
	for (const auto& e : diff.all_edges()){
		if(e==e23){
			return EXIT_FAILURE;
		}
	}
	
	
	return EXIT_SUCCESS;
	
	
	
	
}