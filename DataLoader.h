#ifndef _DATA_LOADER
#define _DATA_LOADER
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>

#include "Pair.h"

class DataLoader
{
  private:

    bool zeroIsFirstIndex;

    typedef int cost_type;
    typedef int company_type;

    //FIELDS
    unsigned vertexes_num, //n
        edges_num,            //m
        companies_num;        //k

    unsigned start_vertex;

    //METHODS
    void initPenalties_arr();
    void initAdj_arr();
    static std::vector<int> extractIntegersFromString(std::string str);

  public:
    //Fields
    unsigned **penalties_arr;
    Pair<cost_type, company_type> **adj_arr;

    //Constructor
    DataLoader(std::string filename, bool zeroIsFirstIndex = true);

    //Methods
    inline const unsigned &getStartVertex() { return start_vertex; }
    inline const unsigned &getVertexesNum() { return vertexes_num; }
    inline const unsigned &getEdgesNum() { return edges_num; }
    inline const unsigned &getCompaniesNum() { return companies_num; }
    inline bool getZeroIsFirstIndex() const { return zeroIsFirstIndex; }
};

#endif