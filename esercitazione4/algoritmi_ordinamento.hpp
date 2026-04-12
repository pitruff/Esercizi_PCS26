#include <iostream>
#include <vector>
#include <algorithm>



template<typename T>
void bubbleSort(std::vector<T>& v)
{	
	
	bool condizione = true;
	int n=size(v);
	do{
		condizione = true;
		for (int i=1; i<=n-1; i++) {
			T ValoreAttuale=v[i-1];
			T ValoreSuccessivo = v[i];
			if (ValoreAttuale>ValoreSuccessivo) {
				v[i-1] = ValoreSuccessivo;
				v[i]=ValoreAttuale;
				condizione=false;	
			}
		}
	} while (!condizione);
	
}

template<typename T>
void selectionSort(std::vector<T>& v)
{	
	
	int n=size(v);
	for (int i=0; i<=n-2; i++){
		int min_index=i;
		for (int j=i+1; j<=n-1; j++){
			
			if(v[j]<v[min_index]){
				min_index=j;
			}
		}
		if(min_index!=i){
			std::swap(v[i], v[min_index]);
		}
				
	}
	
}

template<typename T>
void insertionSort(std::vector<T>& v)
{	
	
	int n=size(v);
	for(int i=1; i<=n-1; i++){
		
		T value = v[i];
		int j=i-1;
		while(j>=0 && v[j]>value){
			v[j+1] = v[j];
			j=j-1;	
		}
		v[j+1]=value;	
	}
	
}

template<typename T>
bool is_sorted(const std::vector<T>& v)
{	
	int n=size(v);
	if (n<2){
		return true;
	}
	else{
		for (int i=0; i<n-1; i++){

			if (v[i] > v[i+1]){
				return false;
			}
			
		}
		return true;
	}
	
	
}

