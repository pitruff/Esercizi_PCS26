#include <iostream>

int main()
{	                                                                                                         
	static const int N = 11;
	double darr[N] = { 1.2, 3.4, 2.8,0.3, 0.9, 5.4, 3.8, 0.5, 5.2, 2.7, 3.0 };
	std::cout <<"Array: {"<< darr[0];
	for (int i=1; i<=10; i++) {
		std::cout <<", "<< darr[i];
		if (i==10) {
		std::cout <<"}"<< "\n";
		}
	}
	
	bool condizione = true;
	do{
		condizione = true;
		for (int i=1; i<=10; i++) {
			double ValoreAttuale=darr[i-1];
			double ValoreSuccessivo = darr[i];
			if (ValoreAttuale>ValoreSuccessivo) {
				darr[i-1] = ValoreSuccessivo;
				darr[i]=ValoreAttuale;
				condizione=false;	
			}
		}
	} while (!condizione);
	
	std::cout <<"Array ordinato: {"<< darr[0];
	for (int i=1; i<=10; i++) {
		std::cout <<", "<< darr[i];
		if (i==10) {
		std::cout <<"}"<< "\n";
		}
	}
	
	
	return 0;
}