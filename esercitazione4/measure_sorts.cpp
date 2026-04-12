#include <algorithm>
#include <iostream>
#include <vector>
#include "timecounter.h"
#include "randfiller.h"
#include "algoritmi_ordinamento.hpp"

int main(void){
	
	
	randfiller rf;
	timecounter tc;
	std::vector<int> v;
	
	for (int i=4; i<=8192; i*=2){
		std::cout<<"Dimensione: "<<i<<"\n";
		v.resize(i);
		rf.fill(v, -1000, 1000); 
		
		tc.tic();
		bubbleSort(v);
		std::cout<<"bubbleSort: "<<tc.toc()<<"\n";
		
		rf.fill(v, -1000, 1000); 
		tc.tic();
		selectionSort(v);
		std::cout<<"selectionSort: "<<tc.toc()<<"\n";
		
		rf.fill(v, -1000, 1000); 
		tc.tic();
		insertionSort(v);
		std::cout<<"insertionSort: "<<tc.toc()<<"\n";
		
		rf.fill(v, -1000, 1000); 
		tc.tic();
		std::sort( v.begin(), v.end() );
		std::cout<<"std::sort(): "<<tc.toc()<<"\n"<<"\n";
		
	}
	
	return 0;
	
	
	
	
	
}