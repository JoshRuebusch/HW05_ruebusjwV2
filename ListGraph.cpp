#include "ListGraph.h"

ListGraph::ListGraph(int numNodes){
	num_edges = 0;

	if(numNodes>0){
		for(int i = 0; i < numNodes; i++){
			edgeList.push_back(EList(NULL));
		}
	}
}

ListGraph::~ListGraph(){

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	return 0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	std::list<NWPair> EList;
	return EList;
}

unsigned ListGraph::degree(NodeID u) const{
	return 0;
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}