#include <iostream>
#include "razionali.hpp"

int main() {
	
	//inizializziamo dei razionali
	rational<int> r_default;  		//dovrebbe restituire 0/1;
	rational<int> r1(10,20);		//dovrebbe restiruire 1/2;
	rational<int> r2(6,-18);		//dovrebbe restiruire -1/3;
	rational<int> r3(-30,-50);		//dovrebbe restiruire 3/5;
	rational<int> inf(8,0);			//dovrebbe restiruire inf;
	rational<int> n_inf(-7,0);		//dovrebbe restiruire -inf;
	rational<int> nan(0,0);			//dovrebbe restiruire nan;
	
	std::cout<<"INIZIALIZZAZIONI \n";
	std::cout<<"Default:		"<<r_default<<"		[atteso 0]\n";
	std::cout<<"(10,20):		"<<r1<<"		[atteso 1/2]\n";
	std::cout<<"(6,-18):		"<<r2<<"		[atteso -1/3]\n";
	std::cout<<"(-30,-50):		"<<r3<<"		[atteso 3/5]\n";
	std::cout<<"(8,0):			"<<inf<<"		[atteso +Inf]\n";
	std::cout<<"(-7,0):			"<<n_inf<<"		[atteso -Inf]\n";
	std::cout<<"(0,0):			"<<nan<<"		[atteso Nan]\n";
	
	//operazioni
	std::cout<<"\n";
	std::cout<<"OPERAZIONI \n";
	std::cout<<r1<<" + "<<r2<<" =	"<<(r1+r2)<<"		[atteso 1/6]\n";
	std::cout<<r2<<" - "<<r3<<" =	"<<(r2-r3)<<"	[atteso -14/15]\n";
	std::cout<<r3<<" * "<<r1<<" =		"<<(r3*r1)<<"		[atteso 3/10]\n";
	std::cout<<r3<<" / "<<r2<<" = 	"<<(r3/r2)<<"		[atteso -9/5]\n";
	
	//operazioni con scalari
	std::cout<<"\n";
	std::cout<<"OPERAZIONI CON SCALARI \n";
	std::cout<<r1<<" + "<<2<<" =		"<<(r1+2)<<"		[atteso 5/2]\n";
	std::cout<<r2<<" - "<<1<<" =		"<<(r2-1)<<"		[atteso -4/3]\n";
	std::cout<<r3<<" * ("<<(-2)<<") =		"<<(r3*(-2))<<"		[atteso -6/5]\n";
	std::cout<<r2<<" / "<<4<<" = 		"<<(r2/4)<<"		[atteso -1/12]\n";
	//operazioni con inf e nan
	std::cout<<"\n";
	std::cout<<"OPERAZIONI CON INF E NAN\n";	
	std::cout<<r1<<" / 0 =		"<<(r1/r_default)<<"		[atteso +Inf]\n";
	std::cout<<r1<<" + Inf =		"<<(r1+inf)<<"		[atteso +Inf]\n";
	std::cout<<"Inf - Inf =		"<<(inf+n_inf)<<"		[atteso Nan]\n";
	std::cout<<"Inf * "<<r2<<" =		"<<(inf*r2)<<"		[atteso -Inf]\n";
	std::cout<<r_default<<" * "<<inf<<" =		"<<(r_default*inf)<<"		[atteso Nan]\n";
	std::cout<<nan<<" / "<<r3<<" =		"<<(nan/r3)<<"		[atteso Nan]\n";
	
    return 0;
}