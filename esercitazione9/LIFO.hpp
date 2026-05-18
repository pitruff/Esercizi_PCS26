#include <stack>

template<typename T>
class lifo{
	
	
	std::stack<T> s;
	
	
	
	
public:

	lifo(){
		
	}
	
	
	void put(const T& el){
		
		s.push(el);
	
	}
	
	
	T get(){
		
		T first=s.top();
		s.pop();
		return first;
		
	}
	
	
	bool empty(){
		return s.empty();
	}
	
};