#include <iostream>
#include <concepts>
#include <algorithm>

template<typename I> requires std::integral<I>
class rational{
	I num_;
	I den_;

public:
	
	//costruttore di default//
	rational()
		: num_(0),den_(1)
	{}
	
	//costruttore user-defined
	rational(const I& n, const I& d)
		: num_(n), den_(d)
		
	{semplifica();} 
		// (1/0) è il nostro +INF	e (-1/0) è il nostro -INF
	   // (0/0) è Nan
	
	//metodi per restituire numeratore e denominatore
	I num() const {return num_;}
	I den() const {return den_;}
	
	
	//OVERLOAD DELLE OPERAZIONI:
	
	//implemento +=
	rational& operator+=(const rational& other) {
		if (den_==0){
			if (num_!=0){ //se il primo è Nan non faccio nulla, è già il risultato 
				if (other.den_==0){
					if (other.num_==0){//primo==Inf, other==Nan
						num_=0;
						den_=0;
					}
					else{//entrambi Inf
						if(num_*other.num_<0){
							num_=0;
							den_=0;
						}
					}
				}// se ho primo=INF e other=numero il risultato è il primo
			}
		}
		else{
			if (other.den_==0){
				if (other.num_==0){//primo=normale, other=Nan
					num_=0;
					den_=0;
				}
				else{//primo=normale, other=Inf
					num_=other.num_;
					den_=other.den_;
				}
		
			}
			else{//entrambi normali
				num_= num_*other.den_ +den_*other.num_;
				den_*=other.den_;
				
				
			}
		}
		semplifica();
		return *this;		
	}
	
	//implemento +
	rational operator+(const rational& other) const{
		rational ret = *this;
		ret +=other;
		return ret;		
	}
	
	//implemento somma con scalare
	rational& operator+=(const I& other){
		return*this += rational<I>(other,1);
	
	}
	rational operator+(const I& other) const{
		rational ret = *this;
		ret +=other;
		return ret;
	
	}
	
	//implemento *=
	rational& operator*=(const rational& other) {
		if (den_==0){
			if (num_!=0){ //se il primo è Nan, abbiamo già il risultato
				if (other.den_==0){
					if (other.num_==0){//primo==Inf, other==Nan
						num_=0;
						den_=0;
					}
					else{//entrambi Inf
						num_*=other.num_;
						//il denominatore rimane zero, moltiplichiamo i numeratori per vedere il segno
					}
				
				}
				else{ //primo=Inf, other=normale
					num_*=other.num_;
					//il denominatore rimane zero, moltiplichiamo i numeratori per vedere il segno
				
				}
			}
		}
		else{
			if (other.den_==0){
				if (other.num_==0){//primo=normale, other=Nan
					num_=0;
					den_=0;
				}
				else{//primo=normale, other=Inf
					num_*=other.num_;
					den_=0;
				}
		
			}
			else{//entrambi normali
				num_*=other.num_;
				den_*=other.den_;
				
				
			}
		}		
		semplifica();
		return *this;
	}
	
	//implemento *
	rational operator*(const rational& other) const{
		rational ret = *this;
		ret *=other;
		return ret;		
	}
	//implemento prodotto per scalare
	rational& operator*=(const I& other){
		return*this *= rational<I>(other,1);
	
	}
	rational operator*(const I& other) const{
		rational ret = *this;
		ret *=other;
		return ret;
	
	}
	
	
	//implemento -=
	rational& operator-=(const rational& other) {
		rational<I> opposto(-other.num(),other.den());
		*this += opposto;
		semplifica();
		return *this;
	}
	//implemento -
	rational operator-(const rational& other) const{
		rational ret = *this;
		ret -=other;
		return ret;		
	}
	//implemento differenza per scalare
	rational& operator-=(const I& other){
		return*this -= rational<I>(other,1);
	
	}
	rational operator-(const I& other) const{
		rational ret = *this;
		ret -=other;
		return ret;
	
	}
	
	//implemento /=
	rational& operator/=(const rational& other) {
		rational<I> inverso(other.den(), other.num());
		*this *= inverso;
		semplifica();
		return *this;
		
	}
	//implemento /
	rational operator/(const rational& other) const{
		rational ret = *this;
		ret /=other;
		return ret;		
	}
	//implemento divisione per scalare
	rational& operator/=(const I& other){
		return*this /= rational<I>(other,1);
	
	}
	rational operator/(const I& other) const{
		rational ret = *this;
		ret /=other;
		return ret;
	
	}


	//semplificazione, algoritmo di euclide
	void semplifica() {
		
		if (den_!=0 and num_!=0) {
			I M = std::max(abs(num_),abs(den_));
			I m = std::min(abs(num_),abs(den_));
			
			while (m!=0){
				I r = M%m; //calcolo il resto
				M=m; //il minimo(divisore) diventa il dividendo
				m=r; //il resto diventa divisore
			}
			num_/=M;
			den_/=M;	
			
		}
		if(den_<0) { //non voglio avere (1/-2) ma (-1/2)
			den_=-den_;
			num_=-num_;
			
		}
		
		else{
			if(den_==0 and num_!=0){
				if(num_>0){
					num_=1;
				}
				else {
					num_=-1;
				}
				//per semplicità mi salvo +inf e - inf come (1/0) e (-1/0)
				//per non portarmi dietro numeri troppo grandi
			}
			if(den_!=0 and num_==0){
				den_=1;
			}//allo stesso modo lo zero me lo salvo come 0 come (0/1)
		}
	}
	
	
	
	
	
	
};

//operatore di stampa
template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
	if (r.den()==0){
		if (r.num()==0){
			os << "Nan";
		}
		else{
			if (r.num()>0){
				os <<"+"<<"Inf";
			}
			else{
				os <<"-"<<"Inf";
			}
		}
	}
	else{
		if (r.num()==0){
			os << 0;
		}
		else{
			os << "("<<r.num()<< "/" << r.den()<<")";
		}
	}
	return os;
}
	



