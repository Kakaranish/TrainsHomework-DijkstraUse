#include "DataLoader.h"

/*


        PRIVATE METHODS


*/
void DataLoader::initPenalties_arr()
{
    penalties_arr = new unsigned *[companies_num];
    for (int i = 0; i < companies_num; i++)
    {
        penalties_arr[i] = new unsigned[companies_num];
        for (int j = 0; j < companies_num; j++)
            penalties_arr[i][j] = 0;
    }
}

void DataLoader::initAdj_arr()
{
    adj_arr = new Pair<cost_type, company_type> *[vertexes_num];
    for (int i = 0; i < vertexes_num; i++)
    {
        adj_arr[i] = new Pair<cost_type, company_type>[vertexes_num];
        for (int j = 0; j < vertexes_num; j++)
            adj_arr[i][j] = std::move(Pair<cost_type, company_type>(-1, -1));
    }
}

std::vector<int> DataLoader::extractIntegersFromString(std::string str)
{
    std::vector<int> result;
    std::size_t currOff = 0;

    while (currOff < str.size())
    {
        if (std::isdigit(str.at(currOff)))
        {
            int num = std::stoi(str.substr(currOff));
            result.push_back(num);

            currOff += std::to_string(num).size();
            continue;
        }

        ++currOff;
    }
    return result;
}
/*


            PUBLIC METHODS


*/
DataLoader::DataLoader(std::string filename, bool zeroIsFirstIndex)
{
    std::ifstream file_handle;
    file_handle.open(filename.c_str(), std::ios::in);

    if (!file_handle.is_open())
        throw std::runtime_error("Unable to open given file: " + filename);

    std::string curr_line;

    //Loading first line
    std::getline(file_handle, curr_line);
    auto vec_of_extracted_int_nums = extractIntegersFromString(curr_line);
    if (vec_of_extracted_int_nums.size() != 4)
        throw std::runtime_error("Incorrect format of file!");

    vertexes_num = vec_of_extracted_int_nums[0];
    edges_num = vec_of_extracted_int_nums[1];
    companies_num = vec_of_extracted_int_nums[2];
    start_vertex = vec_of_extracted_int_nums[3];
    if(!zeroIsFirstIndex)
        --start_vertex;


    //Loading penalties
    initPenalties_arr();
    for (int i = 0; i < companies_num; i++)
    {
        std::getline(file_handle, curr_line);
        vec_of_extracted_int_nums = extractIntegersFromString(curr_line);
        if (vec_of_extracted_int_nums.size() != companies_num)
            throw std::runtime_error("Incorrect format of file!");
        for (int j = 0; j < companies_num; j++)
            penalties_arr[i][j] = vec_of_extracted_int_nums[j];
    }


    //Loading adjacency matrix
    initAdj_arr();
    for (int i = 0; i < edges_num; i++)
    {
        std::getline(file_handle, curr_line);
        vec_of_extracted_int_nums = extractIntegersFromString(curr_line);

        if(!zeroIsFirstIndex)
        {
            --vec_of_extracted_int_nums[0]; 
            --vec_of_extracted_int_nums[1];
            --vec_of_extracted_int_nums[3];
        }


        if (vec_of_extracted_int_nums.size() != 4)
            throw std::runtime_error("Incorrect format of file");

        adj_arr[vec_of_extracted_int_nums[0]][vec_of_extracted_int_nums[1]].first = vec_of_extracted_int_nums[2];
        adj_arr[vec_of_extracted_int_nums[0]][vec_of_extracted_int_nums[1]].second = vec_of_extracted_int_nums[3];
        
        adj_arr[vec_of_extracted_int_nums[1]][vec_of_extracted_int_nums[0]].first = vec_of_extracted_int_nums[2];
        adj_arr[vec_of_extracted_int_nums[1]][vec_of_extracted_int_nums[0]].second = vec_of_extracted_int_nums[3];
    }
}