#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <limits>

#include <ctime>

#include "DataLoader.h"
#include "Set.h"

void findShortestRoutesToOtherCities(std::string filename, bool zeroIsFirstVertexIndex)
{
    //Loading data from file
    DataLoader loadedData(filename, zeroIsFirstVertexIndex);

    //Initialization of two empty sets: Q and S
    Set<unsigned> S_set,
        Q_set;

    //At the beginning we add all vertices to Q set
    for (int i = 0; i < loadedData.getVertexesNum(); i++)
        Q_set.add(i);

    const unsigned &start_vertex = loadedData.getStartVertex();
    int *distance_arr = new int[loadedData.getVertexesNum()];
    int *parent_arr = new int[loadedData.getVertexesNum()];

    //Initialization of two arrays: parent_arr and distance_arr
    for (int i = 0; i < loadedData.getVertexesNum(); i++)
    {
        parent_arr[i] = -1;
        distance_arr[i] = std::numeric_limits<unsigned>::max();
    }
    distance_arr[start_vertex] = 0;

    while (!Q_set.isEmpty())
    {
        //Pair which first part is distance value and second is VertexIndex
        Pair<unsigned, int> distanceVertexPair(std::numeric_limits<unsigned>::max(), std::numeric_limits<unsigned>::max());

        //From the set Q we want to choose the vertex with the smallest distance from s
        for (int i = 0; i < Q_set.getSize(); i++) //in Q set there are stored indexes of all not processed vertexes
        {
            unsigned vertexNum = Q_set.get(i);
            if (distanceVertexPair.first >= distance_arr[vertexNum])
                distanceVertexPair = std::move(Pair<unsigned, int>((unsigned)distance_arr[vertexNum], vertexNum));
        }

        //We move found vertex from set Q to set S
        Q_set.remove(distanceVertexPair.second);
        S_set.add(distanceVertexPair.second);

        for (int i = 0; i < loadedData.getVertexesNum(); i++)
        {
            //Helper variables
            auto &neighborIndex = i;
            auto &currentVertexIndex = distanceVertexPair.second;
            auto &currentEdge = loadedData.adj_arr[currentVertexIndex][neighborIndex];

            //If cost between current vertex and probable neihgbour is equal -1, that means the edge does not exist
            if (currentEdge.first == -1)
                continue;

            //Neighbor must be in Q_set
            if (!Q_set.contains(i))
                continue;

            //If we got here, that meanss our probable neighbor is real neighbour

            //At this moment we want to compute penalty cost
            unsigned currentPenalty = 0;

            //If our vertex is start vertex, we skip penalty
            if (parent_arr[currentVertexIndex] != -1)
            {
                int parentOfCurrentVertexIndex = parent_arr[currentVertexIndex];
                int prevEdgeCompanyIndex = loadedData.adj_arr[parentOfCurrentVertexIndex][currentVertexIndex].second;

                int currentEdgeCompanyIndex = loadedData.adj_arr[currentVertexIndex][neighborIndex].second;

                currentPenalty = loadedData.penalties_arr[prevEdgeCompanyIndex][currentEdgeCompanyIndex];
            }

            if (distance_arr[neighborIndex] > distance_arr[currentVertexIndex] + currentEdge.first + currentPenalty)
            {
                distance_arr[neighborIndex] = distance_arr[currentVertexIndex] + currentEdge.first + currentPenalty;
                parent_arr[neighborIndex] = currentVertexIndex;
            }
        }
    }

    //Showing output
    for (int i = 0; i < loadedData.getVertexesNum(); i++)
    {
        //If there is no connection between any vertice and start vertice, standard value of distance is max unsigned value
        //so we want to replace it by -1
        if (distance_arr[i] == std::numeric_limits<unsigned>::max())
            distance_arr[i] = -1;

        std::cout << distance_arr[i] << "\t";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    findShortestRoutesToOtherCities("Res/wejscie.txt", false);

    return 0;
}