#pragma once 
#include <iostream>
#include <stdexcept>

template<typename T>
class unidirected_edge{
	
	T nodo_partenza;
	T nodo_arrivo;
	double peso; //aggiungo i pesi degli archi
	
public:

	//costruttore user-defined, se non viene specificato il peso assegnato è 1
	unidirected_edge(const T& a, const T& b, double w=1.0){
		if(a<=b){
			nodo_partenza=a;
			nodo_arrivo=b;
		}
		else{
			nodo_partenza=b;
			nodo_arrivo=a;
		}
		peso = w;
		
		
		//non si possono metere pesi negativi, lo facciamo perchè di fatto abbiamo aggiunto i pesi solo per implementare Dijkstra
		if(peso<0.0){
		
			//lancio un eccezione
			throw std::invalid_argument("Il peso di un arco deve essere strettamente positivo");
		}
	}
	//metodi per restituire i nodi

	T from() const {return nodo_partenza;}
	T to() const {return nodo_arrivo;}
	double weight() const {return peso;} //restituisco il peso
	
	
	//implemento <
	bool operator<(const unidirected_edge& other) const{
		
		//prima controllo chi parte dal nodo minore
		if (nodo_partenza<other.from()){
			return true;
		}
		else{
			
			if (other.from()<nodo_partenza){
				return false;
			}
			
			else{ //partono dallo stesso, controllo chi arriva a quello minore
				
				if (nodo_arrivo<other.to()){
						
					return true;
				}
				else{
					return false;
					
				}
	
			}
		}
	}
	
	//implemento ==
	bool operator==(const unidirected_edge& other) const{
		
		if (nodo_partenza==other.from() and nodo_arrivo==other.to()){
			return true;
		}
		else{
			return false;
		}	
	}
	
	
	

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& e){
		
	os<<"L'arco va dal nodo "<<e.from()<<" al nodo "<<e.to()<<" con peso "<<e.weight();
	return os;
}