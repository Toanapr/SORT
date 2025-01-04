#include "headers/util.h"

void readFile(const std::string &inputFile, std::vector<int> &arr, int &arrSize)
{
    std::ifstream input(inputFile);
    
    if (!input.is_open())
    {
        std::cerr << "Unable to open file\n";
        return;
    }

    input >> arrSize;
    int val;
    while (input >> val)
    {
        arr.push_back(val);
    }
}

void writeFile(const std::string &outputFile, const std::vector<int> &arr)
{
    std::ofstream output(outputFile);
    if (output.is_open())
    {
        output << arr.size() << '\n';
        for (int x : arr)
        {
            output << x << ' ';
        }
        output.close();
    }
    else
    {
        std::cerr << "Unable to open file\n";
    }
}

bool isValidAlgorithm(const std::string &algorithm)
{
    if (algorithmFunctionMap.find(algorithm) != algorithmFunctionMap.end())
    {
        return true;
    }

    return false;
}

bool isValidInputOrder(const std::string &input_order)
{
    if (input_order == "-rand" || input_order == "-sorted" || input_order == "-rev" || input_order == "-nsorted")
    {
        return true;
    }

    return false;
}

bool isValidGivenInput(const std::string &given_input)
{
    std::ifstream inFile;
    inFile.open(given_input);
    if (inFile.is_open())
    {
        inFile.close();
        return true;
    }
    return false;
}

bool isValidOutputParam(const std::string &output_param)
{
    if (output_param == "-time" || output_param == "-comp" || output_param == "-both")
    {
        return true;
    }

    return false;
}
