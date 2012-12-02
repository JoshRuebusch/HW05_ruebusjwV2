#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){

	num_edges = 0;

	this->M.resize(num_nodes);

	for(int i = 0; i < num_nodes; i++){
		this->M.resize(num_nodes);
		for(int j = 0; j < num_nodes; j++){
			this->M.at(i).push_back(0);
		}
	}
}

MatrixGraph::~MatrixGraph(){

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	//test preconditions as mentioned in Graph.h
	if(0 <= u < M.size() && 0 <= v < M.size() && u != v && M.at(u).at(v) == 0 && M.at(v).at(u) == 0 && weight > 0)
	{
		num_edges++; //increment
		this->M.at(u).at(v) = this->M.at(v).at(u) = weight; //assign weights
	}
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	//preconditions as mentioned in Graph.h
	if(0 <= u < this->M.size() && 0 <= v < this->M.size())
		return this->M.at(u).at(v);
	else
		return 0; // return 0 if non-existant points
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	if(0 <= u < this->M.size())	//precondition as mentioned in Graph.h
	{
		std::list<NWPair> EList;
		for(int i = 0; i < this->M.at(u).size(); i++)
		{
			NWPair cur(i, this->M.at(u).at(i));
			if(cur.second != 0)				//weight (second) will only be 0 if it has not been assigned. 
				EList.push_back(cur);
		}
		return EList;
	}
}

unsigned MatrixGraph::degree(NodeID u) const{
	if(0 <= u < this->M.size())
	{
		return this->getAdj(u).size();	//when conditions met simply return size of adjacency list
	}
}

unsigned MatrixGraph::size() const{
	return this->M.size();				//just return matrix size
}

unsigned MatrixGraph::numEdges() const{
	return this->num_edges;				//return number of edges 
}

