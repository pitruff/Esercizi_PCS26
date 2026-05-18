#include <iostream>
#include "visite.hpp"
#include "dijkstra.hpp"

int main(){
	
	unidirected_graph<int> G;
	//costruisco albero
	unidirected_edge e1(1,2);
	unidirected_edge e2(1,3);
	unidirected_edge e3(1,4);
	unidirected_edge e4(2,4);
	unidirected_edge e5(3,6);
	unidirected_edge e6(1,6);
	unidirected_edge e7(4,6);
	unidirected_edge e8(2,5);
	unidirected_edge e9(2,7);
	unidirected_edge e10(5,7);
	unidirected_edge e11(4,7);
	unidirected_edge e12(6,7);
	unidirected_edge e13(6,8);
	unidirected_edge e14(7,9);
	unidirected_edge e15(8,9);
	
	G.add_edge(e1);
	G.add_edge(e2);
	G.add_edge(e3);
	G.add_edge(e4);
	G.add_edge(e5);
	G.add_edge(e6);
	G.add_edge(e7);
	G.add_edge(e8);
	G.add_edge(e9);
	G.add_edge(e10);
	G.add_edge(e11);
	G.add_edge(e12);
	G.add_edge(e13);
	G.add_edge(e14);
	G.add_edge(e15);
	
	std::cout << "\nG\n";
	print_dot(G);
	
	fifo<int> coda;
	auto BFS_G =graph_visit(G,1, coda);
	std::cout << "BFS\n";
	print_dot(BFS_G);
	
	lifo<int> pila;
	auto DFS_G =graph_visit(G,1, pila);
	std::cout << "\nDFS\n";
	print_dot(DFS_G);
	
	auto DFS_RECURSIVE=recursive_dfs(G,1);
	std::cout << "\nDFS_recursive\n";
	print_dot(DFS_RECURSIVE);
	
	
	
	std::cout << "\n========== TEST DIJKSTRA ==========\n";

	unidirected_graph<char> H;
	
	unidirected_edge f1('A', 'B', 4.0);
	unidirected_edge f2('A', 'C', 2.0);
	unidirected_edge f3('B', 'C', 1.0);
	unidirected_edge f4('B', 'D', 5.0);
	unidirected_edge f5('C', 'D', 8.0);
	unidirected_edge f6('C', 'E', 10.0);
	unidirected_edge f7('D', 'E', 2.0);
	
    H.add_edge(f1);
    H.add_edge(f2);
    H.add_edge(f3);
    H.add_edge(f4);
    H.add_edge(f5);
    H.add_edge(f6);
    H.add_edge(f7);
    
	std::cout << "\nH\n";
	print_dot(H);

    auto albero = dijkstra(H, 'A');
	print_dot(albero);
	
	
	
	
	return 0;
	
}