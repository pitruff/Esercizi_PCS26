#pragma once //per non includere due volte la stessa classe
#include <iostream>


template<typename T>
class unidirected_edge{
	
	T nodo_partenza;
	T nodo_arrivo;
	
public:

	//costruttore user-defined
	unidirected_edge(const T& a, const T& b){
		if(a<=b){
			nodo_partenza=a;
			nodo_arrivo=b;
		}
		else{
			nodo_partenza=b;
			nodo_arrivo=a;
		}
		
	}
	//metodi per restituire i nodi

	T from() const {return nodo_partenza;}
	T to() const {return nodo_arrivo;}
	
	
	
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
		
	os<<"L'arco va dal nodo "<<e.from()<<" al nodo "<<e.to();
	return os;
}