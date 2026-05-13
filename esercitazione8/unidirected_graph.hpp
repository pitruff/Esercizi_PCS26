#pragma once //per non includere due volte la stessa classe
#include <iostream>
#include <iterator>
#include <set>
#include <map>
#include <vector>
#include "unidirected_edge.hpp"

template<typename T>
class  unidirected_graph{
	
	//Voglio creare tre oggetti per facilitarmi la vita quando implementerò i metodi
	
	//La lista di adiacenza per i nodi
	//uso set e non list per non aggiungere due volte l'arco vicino
	std::map<T, std::set<T>> adiacenze;

	//una mappa di archi a cui associo il loro numero, che sarà la loro posizione nel grafo;
	
	std::map<unidirected_edge<T>, int> arco_id;
	
	
	//un vettore di archi che ordinerò con le operazioni di comparazione implementate in unidirected_edge
	
	std::vector<unidirected_edge<T>> archi;
	
public:
	
	
	//costruttore default
	
	unidirected_graph(){
		
		//non scrivo niente perchè le classi map, set e unidirected_edge hanno già un compilatore di default, quindi ci pensano loro
	}
	
	
	//costruttore copia
	
	unidirected_graph(const unidirected_graph<T>& other){
		
		adiacenze=other.adiacenze;
		arco_id=other.arco_id;
		archi=other.archi;
		
	}
	
	
	//metodo per restituire i vicini
	
	std::set<T> neighbours(T nodo) const{
		
		//Non posso usare "[]" perchè se cerco un nodo che non è nella mappa me lo aggiunge
		
		auto it=adiacenze.find(nodo);
		
		if(it != adiacenze.end()){
			return (*it).second; //restituisco la lista di valori associata al nodo deferenziando l'iteratore
		}
		
		else{
			return std::set<T>();
		}
		
	}
	
	
	//metodo per aggiungere un arco al grafo
	
	void add_edge(const unidirected_edge<T>& new_arco) {
		
		//controllo che non ci sia già il nuovo arco
		if (arco_id.find(new_arco) != arco_id.end()){
			return;
		}
		
		//aggiorno la lista di adiacenza
		adiacenze[new_arco.from()].insert(new_arco.to());
		adiacenze[new_arco.to()].insert(new_arco.from());
		
		//aggiorno il vettore di archi e la mappa
		archi.push_back(new_arco);
		ordina();
		
		
	}
	
	//metodo che restituisce tutti gli archi
	
	
	std::vector<unidirected_edge<T>> all_edges() const{
		return archi;
	}
	
	//metodo che restituisce tutti i nodi
	
	std::vector<T> all_nodes() const{
		
		std::vector<T> v;
		for(const auto& pair : adiacenze){
			v.push_back(pair.first);
		}
		return v;		
		
	}
	
	
	//metodo che, dato un arco, ne restituisce la numerazione all'interno del grafo
	
	
	int edge_number(const unidirected_edge<T>& e) const{
		
		return arco_id.at(e);
		
	}
	
	//metodo che, dato un numero d’arco, restituisce il corrispondente oggetto arco all’interno del grafo
	
	unidirected_edge<T> edge_at(int n) const{
		
		return archi[n];
		
	}
	
	
	//implemento differenza tra grafi
	
	unidirected_graph<T> operator-(const unidirected_graph<T>& other) const{
		
		unidirected_graph new_graph;
		
		//scorro gli archi del mio grafo
		for (const auto& e: archi){
			
			//uso la mappa dell'altro grafo per vedere se l'arco esiste con find()
			if (other.arco_id.find(e) == other.arco_id.end()){
				
				//vuol dire che non l'ho trovato
				//lo aggiungo al nuovo grafo
				new_graph.add_edge(e);
				
			}
		}
		
		return new_graph;
		
	}
	


	//Ho aggiunto la parte sotto perchè pensavo che la numerazione degli archi andasse fatta secondo l'ordine di comparazione stabilito in unidirected_edge. Siccome non toglie niente al resto del programma ma fornisce solo una numerazione ordinata ho pensato di lasciarla
	
	//costruisco delle funzioni che mi aggiustano la mappa degli archi e il vettore dopo un nuovo inserimento
	void ordina_vettore_archi(){
		
		//noto che gli operatori == e < che abbiamo implementato per la classe degli archi sono sufficienti per far funzionare l'algoritmo di selectionSort, quindi uso quello.
		int n=archi.size();
		for (int i=0; i<=n-2; i++){
			int min_index=i;
			for (int j=i+1; j<=n-1; j++){
			
				if(archi[j]<archi[min_index]){
					min_index=j;
				}
			}
			if(min_index!=i){
				std::swap(archi[i], archi[min_index]);
			}
				
		}		
	}
	void ordina_mappa_archi(){
		int n=archi.size();
		for(int i=0; i<n; i++){
			arco_id[archi[i]] = i;
		}
	}
	
	//riassumo tutto in un unica funzione visto che se faccio una faccio anche l'altra
	void ordina(){
		ordina_vettore_archi();
		ordina_mappa_archi();
	}
};