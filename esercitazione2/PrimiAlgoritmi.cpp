#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{	                                                                                                         
	static const int N = 11;
	double darr[N] = { 1.2, 3.4, 2.8,0.3, 0.9, 5.4, 3.8, 0.5, 5.2, 2.7, 3.0  };
	double M=darr[0];
	double m=darr[0];
	double sum=darr[0];
	std::cout <<"Array: {"<< darr[0];
	for (int i=1; i<=10; i++) {
		double valore = darr[i];
		std::cout <<", "<< valore;
		M=std::max(M,valore);
		m=std::min(m,valore);
		sum=sum+valore;
		if (i==10) {
		std::cout <<"}"<< "\n";
			std::cout <<"Massimo: "<< M << "\n";
			std::cout << "minimo: "<< m << "\n";
		}
	}
	double media=sum/N;
	std::cout <<"Media: "<< media << "\n";
	double ScartoQuad= (darr[0]-media)*(darr[0]-media);
	for (int i=1; i<=10; i++) {
		double valore = darr[i];
		ScartoQuad= ScartoQuad+ (valore-media)*(valore-media);	
	}
	double varianza= ScartoQuad/N;
	double DeviazioneStandard = std::sqrt(varianza);
	std::cout <<"Deviazione Standad: "<< DeviazioneStandard << "\n";
	
	return 0;
}