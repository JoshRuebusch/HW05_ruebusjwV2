#include "GraphAlgs.h"

#include <algorithm>

using namespace std; 

std::vector<NodeID> shortestTravPath;

double dist;
double shortestDist;
NodeID* arr;

void swap(NodeID* arr, int i, int j){
	NodeID temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void tour(NodeID* arr, int arrLen,Graph* G){
	shortestDist = 10000;
	do{
		dist = 0;
		for(int i = 0; i < arrLen-1; i++)
		{
			dist = dist + G->weight(arr[i],arr[i+1]);
			if (dist > shortestDist)
				break;
		}
		dist = dist + G->weight(arr[0],arr[arrLen-1]);
		if(dist < shortestDist)
		{
			shortestDist = dist;
			shortestTravPath.clear();
			for(int i = 0; i < arrLen; i++)
			{
				
				shortestTravPath.push_back(arr[i]);
			}
		}

	}while(next_permutation(arr, arr+arrLen));
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	std::pair<std::vector<NodeID>, EdgeWeight> alpha;
	alpha.first.resize(G->size());
	arr = new NodeID[G->size()];
	for(int i = 0; i < G->size(); i++)
	{
		arr[i] = i;
	}
	tour(arr,G->size(),G);
	alpha.first = shortestTravPath;
	alpha.second = shortestDist;
	return alpha;
}