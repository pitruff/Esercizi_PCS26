#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	std::cout << "Enter the file name: \n";
	std::string filename;
	std::cin>>filename;
	ifstream ifs(filename);
	if( ifs.fail() ) {
		std::cerr<<"error opening the file\n";
	}
	if ( ifs.is_open()) {
		while( !ifs.eof() ) {
			string location;
			double sommatemp=0;
			ifs >> location;
			if( ifs.fail() ) 
				break;
			for (int i= 1; i<=4; i++ ){
				double newtemp;
				ifs >> newtemp;
				sommatemp = sommatemp + newtemp;
				}
			double mediatemp = sommatemp/4;
			std::cout<<location<< " " <<mediatemp<<"\n";
		}

	}
}