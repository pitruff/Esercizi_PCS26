#include "LIFO.hpp"
#include "FIFO.hpp"
#include "unidirected_graph.hpp"
#include <vector>
#include <map>
#include <iostream>

template<typename T, typename Contenitore>
unidirected_graph<T> graph_visit(unidirected_graph<T>& G, T node, Contenitore struttura){
	//struttura sarà o uno stack LIFO o una queue FIFO
	
	//costruisco l'albero della visita che andrò a restiruire in output
	
	unidirected_graph<T> albero_visita;
	
	//reached associa a ogni nodo di tipo T un booleano che dice se l'abbiamo già visitato
	std::map<T, bool> reached;
	
	for (auto i : G.all_nodes()){
			
		reached[i]=false;
	}
	
	struttura.put(node);
	reached[node]=true;
	
	while(!struttura.empty()){
		
		T u=struttura.get();
		
		reached[u] = true;
		
		for(auto w : G.neighbours(u)){
			
			if(!reached[w]){
				
				struttura.put(w);
				reached[w]=true;
				albero_visita.add_edge(unidirected_edge<T>(u,w));
			}
		}	
	}
	return albero_visita;
}	









//qui definisco la versione DFS RICORSIVA

//non usiamo uno stack esplicito o un ciclo while, ogni volta che incontriamo un nodo non ancora visitato richiamiamo la funzione stessa. Costruiamo una funzione ausiliaria che effettua il vero e proprio lavoro della funzione ricorsiva.

template<typename T>
void dfs_visit(const unidirected_graph<T>& G, T u, std::map<T, bool>&reached,unidirected_graph<T>& albero_visita){
    
	// marco il nodo corrente come visitato
    reached[u] = true;

    // scorro tutti i vicini del nodo corrente
    for (auto w : G.neighbours(u)) {

        // se un vicino non è ancora stato raggiunto, allora
        // l'arco (u, w) appartiene all'albero della visita
        if (!reached[w]) {

            albero_visita.add_edge(unidirected_edge<T>(u, w));

			//invece di mettere w in uno stack scendo subito in profondità su w.
			dfs_visit(G, w, reached, albero_visita);
        }
    }
}




//funzione che l'utente chiama: inizializza la mappa reached e l'albero della visita e lancia la prima delle chiamate ricorsive
template<typename T>
unidirected_graph<T> recursive_dfs(unidirected_graph<T>& G, T node){

	//costruisco l'albero della visita che verrà riempito dalle chiamate di dfs_visit
	unidirected_graph<T> albero_visita;
	
	//nessun nodo è ancora stato raggiunto
	std::map<T, bool> reached;

	for (auto n: G.all_nodes()){
		
		reached[n]=false;
		
	}
		
	//lancio la chiamata ricorsiva
	dfs_visit(G, node, reached, albero_visita);
	return albero_visita;

}
















//qui definisco una funzione che, dato un grafo, stamperà a terminale il formato che richiede GraphViz per visualizzarlo

template<typename T>
void print_dot(unidirected_graph<T>& g){
	
	std::cout << "graph G {\n";
	
	//recupero tutti gli archi
	for (auto edge : g.all_edges()){
		//stampo l'arco secono il formato richiesto da Graphviz
		std::cout<<"	"<<edge.from()<<" -- "<<edge.to()<<";\n";
	}
	std::cout<<"}\n";
}