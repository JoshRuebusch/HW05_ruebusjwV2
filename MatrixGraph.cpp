#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){

	num_edges = 0;

	M.resize(num_nodes);

	for(int i = 0; i < num_nodes; i++){
		M.resize(num_nodes);
		for(int j = 0; j < num_nodes; j++){
			M.at(i).push_back(0);
		}
	}
}

MatrixGraph::~MatrixGraph(){

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	//test preconditions as mentioned in Graph.h
	if(0 <= u && u < M.size() && 0 <= v && v < M.size() && u != v && M.at(u).at(v) == 0 && M.at(v).at(u) == 0 && weight < 0)
	{
		num_edges++; //increment
		M.at(u).at(v) = M.at(v).at(u) = weight; //assign weights
	}
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	//preconditions as mentioned in Graph.h
	if(0 <= u < M.size(), 0 <= v < M.size())
		return M.at(u).at(v);
	else
		return 0; // return 0 if non-existant points
}

//stub
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair> EList;
	return EList;
}

//stub
unsigned MatrixGraph::degree(NodeID u) const{
	return 0;
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}

