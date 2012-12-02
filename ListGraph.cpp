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
	if(0 <= u < edgeList.size() && 0 <= v < edgeList.size() && u != v && weight > 0)
	{
		edgeList.at(u).push_back(NWPair(v, weight));
		edgeList.at(v).push_back(NWPair(u, weight));
		num_edges++;
	}
}

//from class notes
EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	if(0 <= u < edgeList.size() && 0 <= v < edgeList.size())
	{
		EList::const_iterator it;
		for(it = edgeList.at(u).begin(); it !=edgeList.at(u).end(); it++)
		{
			NWPair tp = *it;
			if(tp.first == v)
				return tp.second;
		}
	}
	return 0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	if(0 <= u < edgeList.size())
		return edgeList.at(u);
}

unsigned ListGraph::degree(NodeID u) const{
	if(0 <= u < edgeList.size())
		return getAdj(u).size();
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}