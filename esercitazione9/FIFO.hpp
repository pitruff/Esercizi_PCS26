#include <queue>
#pragma once

template<typename T>
class fifo{
	
	
	std::queue<T> q;
	
public:

	fifo(){
	}
	
	
	void put(const T& el){
		
		q.push(el);
	
	}
	
	T get(){
		
		T first=q.front();
		q.pop();
		return first;
	}
	
	bool empty(){
		return q.empty();
	}
	
	
	
	
	
	
	
};