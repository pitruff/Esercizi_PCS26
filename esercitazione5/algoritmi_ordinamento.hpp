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

template<typename T>
void Merge(std::vector<T>& A, int sx, int c, int dx)
{
	int n1=c-sx+1;
	int n2=dx-c;
	
	//costruisco L e R lunghi n1 e n2 anziché n1+1 e n2+1, ora vedremo perché
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	
	for (int i=0; i<n1; i++){
		L[i] = A[sx+i];
	}
	for (int j=0; j<n2; j++){
		R[j]=A[c+1+j];
	}
	
	//siccome vogliamo confrontare sia vettori d numeri che di stringhe, non posso usare comnadi come std::numeric_limits
	// controllerò costantemente gli inidici e li confronterò solo finché avranno elementi, così non ci sarà bisogno del valore infinito per "falsare" la diseguaglianza
	
	int i=0;
	int j=0;
	int k=sx;
	
	while (i<n1 && j<n2){
		if (L[i]<=R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}		
		k++;
	}
	
	//A questo punto uno tra L e R è non ancora vuoto: costruiamo due cicli while per copiare gli elementi rimasti (solo uno verrà eseguito)
	
	while (i<n1){
		A[k]=L[i];
		i++;
		k++;
	}
	
	while (j<n2){
		A[k]=R[j];
		j++;
		k++;
	}
}






template<typename T>
void MergeSort(std::vector<T>& A, int sx, int dx)
{
	if(sx<dx){
			
		int centro=(sx+dx)/2;
		MergeSort(A,sx,centro);
		MergeSort(A,centro+1,dx);
		Merge(A,sx,centro,dx);	
	}
	
}

template<typename T>
int Partition(std::vector<T>& A, int sx, int dx)
{
	T x=A[dx];
	int i=sx-1;
	for (int j=sx; j<=dx-1;  j++){
		if (A[j]<=x){
			i++;
			std::swap(A[i], A[j]);
		}
	}
	if(i!=dx){
		std::swap(A[i+1], A[dx]);
	}
	return(i+1);

}

template<typename T>
void Quicksort(std::vector<T>& A, int sx, int dx)
{
	if(sx<dx){
		int q=Partition(A,sx,dx);
		Quicksort(A,sx,q-1);
		Quicksort(A,q+1,dx);
	
	}
}



//implemento un nuovo insertionsort, che funzioni anche su pezzi di vettori, dall'indice sx all'indice dx
template<typename T>
void NewinsertionSort(std::vector<T>& v, int sx, int dx)
{	
	for(int i=sx+1; i<=dx; i++){
		
		T value = v[i];
		int j=i-1;
		while(j>=sx && v[j]>value){
			v[j+1] = v[j];
			j=j-1;	
		}
		v[j+1]=value;	
	}
	
}

template<typename T>
void BestSort(std::vector<T>& A, int sx, int dx)
{

	if(sx<dx){
		
		if(dx-sx+1<44){ //soglia per cui è meglio usare insertionSort
			NewinsertionSort(A,sx,dx);
		}
		else{
		
			int q=Partition(A,sx,dx);
			BestSort(A,sx,q-1);
			BestSort(A,q+1,dx);	
		}
	}
	
		
	
}