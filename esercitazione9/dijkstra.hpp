#include "unidirected_graph.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <limits>
    
//andando su cppreference ho visto che per usare la struttura di priority_queue, cioò quella utilizzata nello pseudocodice dal Prof. Vicini, c'è bisogno di un comparatore che restituisca true se il secondo argomento viene prima del primo, comparandoli in base alla distanza memorizzata in dist[]. Lo implemento quindi prima dell'algoritmo di Dijkstra    
template <typename T>
struct CompareDist {
	
	//Serve un puntatore alla mappa perche'
	//una struct non puo' "vedere" le variabili locali della funzione dijkstra: gliela passiamo esplicitamente nel costruttore.
	const std::map<T, double>*dist;
	
	CompareDist(const std::map<T, double>* d) :dist(d){}
	
	//restituisce true se 'a' deve venire DOPO 'b' nella coda.
    //Vogliamo estrarre prima il nodo con distanza minore, quindi un nodo va DOPO se ha distanza maggiore.
    bool operator()(const T& a, const T& b) const {
        return dist->at(a) > dist->at(b);
    }
};
	
	
	
	
template<typename T>
unidirected_graph<T> dijkstra(const unidirected_graph<T>& G, T source){


    
    unidirected_graph<T> albero;
    
    //distanza minima nota dalla sorgente a ciascun nodo
    std::map<T, double> dist;
    
    //predecessore di ciascun nodo lungo il cammino minimo
    std::map<T, T> pred;
    
    //nodi gia' "finalizzati": una volta estratti dalla coda, la loro
    //distanza e' definitiva e non li riprocessiamo mai più perchè siamo
	//sicuri che il valore della distanza che ha in questo momento è il 
	//minimo che avrà mai. Serve perchè altrimenti nel ciclodi rilassamento (quando applichiamo //il lemma) potremmo uscire de volte con lo stesso nodo, e se l'abbiamo già finalizzato //sappiamo che possiamo scartarlo
    std::map<T, bool> finalizzato;
    
    //inizializzo tutte le distanze a +infinito tranne la sorgente
    for (const auto& n : G.all_nodes()){
        dist[n] = std::numeric_limits<double>::infinity();
        finalizzato[n] = false;
    }
    dist[source] = 0.0;
    
    
    // Priority queue di soli NODI, ordinata in base a dist[]
   
   

	//ora usiamo la CompareDist implementata sopra per costruire la nostra priority queue
	
    
    std::priority_queue<T, std::vector<T>, CompareDist<T>> pq{CompareDist<T>(&dist)};
    
    pq.push(source);
    
    
    // Ciclo principale

    while (!pq.empty()){
        
        T u = pq.top();
        pq.pop();
        
        //se u era gia' stato finalizzato, vuol dire che era stato
        //aggiunto piu' volte alla coda (vedi sotto) e ora ne stiamo
        //estraendo una copia "vecchia": la scartiamo
        if (finalizzato[u]) continue;
        
        //altrimenti questa e' la prima estrazione di u: lo finalizziamo
        finalizzato[u] = true;
        
        //Qui possiamo applicare il lemma visto a lezione
        for (const auto& vicino : G.neighbours_with_weights(u)){
            
            T w = vicino.first;
            double peso_uw = vicino.second;            
            double nuova_dist = dist[u] + peso_uw;
            
            if (nuova_dist < dist[w]){
                dist[w] = nuova_dist;
                pred[w] = u;
                
                //aggiungo w alla coda. Potrebbe esserci gia' stato
                //aggiunto prima con una distanza maggiore, ma non
                //importa: quando estrarremo la copia "vecchia" il
                //check finalizzato[u] all'inizio del while la scartera'.
                pq.push(w);
            }
        }
    }
    
  
    //Costruzione dell'albero dei cammini minimi
  
    
    for (const auto& coppia : pred){
        T v = coppia.first;
        T p = coppia.second;
		//recupero il peso dell'arco p usando il metodo costruito
        double peso = G.neighbours_with_weights(p)[v];
        albero.add_edge(unidirected_edge<T>(p, v, peso));
    }
    
   
    // Stampa delle distanze calcolate

    std::cout << "Distanze minime dalla sorgente " << source << ":\n";
    for (const auto& coppia : dist){
        std::cout << "  " << coppia.first << ": ";
        if (coppia.second == std::numeric_limits<double>::infinity()){
            std::cout << "non raggiungibile";
        } else {
            std::cout << coppia.second;
        }
        std::cout << "\n";
    }
    
    return albero;
}