#include "headers/Command.h"
#include "headers/Util.h"

void Command1(const std::string &algorithm, const std::string &given_input, const std::string &output_param)
{
    unsigned long long countComparisons = 0;

    int arrSize;
    std::vector<int> arr;
    readFile(given_input, arr, arrSize);

    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithm)(arr, countComparisons);
    auto end = std::chrono::high_resolution_clock::now();

    writeFile("output.txt", arr);

    std::chrono::duration<double> runTime = (end - start) * 1000.0;

    std::string algorithmName = algorithmNameMap.at(algorithm);

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algorithmName << std::endl;
    std::cout << "Input file: " << given_input << std::endl;
    std::cout << "Input size: " << arrSize << std::endl;
    std::cout << "---------------------------\n";

    std::cout << "Running time (if required): ";
    if (output_param == "-time" || output_param == "-both")
    {
        std::cout << std::setprecision(6) << std::fixed << runTime.count() << " ms" << std::endl;
    }
    else
    {
        std::cout << " " << std::endl;
    }

    std::cout << "Comparisions (if required): ";
    if (output_param == "-comp" || output_param == "-both")
    {
        std::cout << std::to_string(countComparisons) << std::endl;
    }
    else
    {
        std::cout << " " << std::endl;
    }
}

void Command2(const std::string &algorithm, const int &input_size, const std::string &input_order, const std::string &output_param)
{
    unsigned long long countComparisons = 0;

    std::vector<int> arr;
    arr.resize(input_size);
    GenerateData(arr, dataTypeMap.at(input_order));

    writeFile("input.txt", arr);

    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithm)(arr, countComparisons);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime = (end - start) * 1000.0;

    writeFile("output.txt", arr);

    std::string algorithmName = algorithmNameMap.at(algorithm);
    std::string dataTypeName = dataTypeNameMap.at(input_order);

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algorithmName << std::endl;
    std::cout << "Input size: " << input_size << std::endl;
    std::cout << "Input order: " << dataTypeName << std::endl;
    std::cout << "---------------------------\n";

    std::cout << "Running time (if required): ";
    if (output_param == "-time" || output_param == "-both")
    {
        std::cout << std::setprecision(6) << std::fixed << runTime.count() << " ms" << std::endl;
    }
    else
    {
        std::cout << " " << std::endl;
    }

    std::cout << "Comparisions (if required): ";
    if (output_param == "-comp" || output_param == "-both")
    {
        std::cout << std::to_string(countComparisons) << std::endl;
    }
    else
    {
        std::cout << " " << std::endl;
    }
}

void Command3(const std::string &algorithm, const int &input_size, const std::string &output_param)
{
    unsigned long long countComparisons = 0;

    std::vector<int> arr0;
    std::vector<int> arr1;
    std::vector<int> arr2;
    std::vector<int> arr3;

    arr0.resize(input_size);
    arr1.resize(input_size);
    arr2.resize(input_size);
    arr3.resize(input_size);

    GenerateData(arr0, 0);
    GenerateData(arr1, 1);
    GenerateData(arr2, 2);
    GenerateData(arr3, 3);

    std::vector<std::vector<int>> arr;

    arr.push_back(arr0);
    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);

    writeFile("input_1.txt", arr0);
    writeFile("input_2.txt", arr1);
    writeFile("input_3.txt", arr2);
    writeFile("input_4.txt", arr3);

    std::string algorithmName = algorithmNameMap.at(algorithm);

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algorithmName << std::endl;
    std::cout << "Input size: " << input_size << std::endl;

    for (int i = 0; i < 4; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        algorithmFunctionMap.at(algorithm)(arr[i], countComparisons);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> runTime = (end - start) * 1000.0;

        std::string dataTypeName = "";
        if (i == 0)
            dataTypeName = "Random";
        else if (i == 1)
            dataTypeName = "Sorted";
        else if (i == 2)
            dataTypeName = "Reverse";
        else if (i == 3)
            dataTypeName = "Nearly Sorted";

        std::cout << "Input order: " << dataTypeName << std::endl;;
        std::cout << "-------------------------\n";

        std::cout << "Running time (if required): ";
        if (output_param == "-time" || output_param == "-both")
        {
            std::cout << std::setprecision(6) << std::fixed << runTime.count() << " ms" << std::endl;;
        }
        else
        {
            std::cout << " " << std::endl;
        }

        std::cout << "Comparisions (if required): ";
        if (output_param == "-comp" || output_param == "-both")
        {
            std::cout << std::to_string(countComparisons) << std::endl;;
        }
        else
        {
            std::cout << " " << std::endl;
        }

        std::cout << "\n";
    }
}

void Command4(const std::string &algorithm1, const std::string &algorithm2, const std::string &inputFile)
{

    int arrSize;
    std::vector<int> arr;
    readFile(inputFile, arr, arrSize);

    std::vector<int> arr1 = arr;
    std::vector<int> arr2 = arr;

    unsigned long long countComparison1 = 0;
    unsigned long long countComparison2 = 0;

    auto start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithm1)(arr1, countComparison1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime1 = (end - start) * 1000.0;

    start = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithm2)(arr2, countComparison2);
    end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime2 = (end - start) * 1000.0;

    std::string algorithmName1 = algorithmNameMap.at(algorithm1);
    std::string algorithmName2 = algorithmNameMap.at(algorithm2);

    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algorithmName1 << " | " << algorithmName2 << std::endl;;
    std::cout << "Input file: " << inputFile << std::endl;
    std::cout << "Input size: " << arr.size() << std::endl;
    std::cout << "-------------------------\n";
    std::cout << "Running time: " << std::setprecision(6) << std::fixed << runTime1.count() << " ms | " << std::setprecision(6) << std::fixed << runTime2.count() << " ms" << std::endl;;
    std::cout << "Comparisons: " << countComparison1 << " | " << countComparison2 << std::endl;;
}

void Command5(const std::string &algorithm1, const std::string &algorithm2, const int &input_size, const std::string &input_order)
{

    std::vector<int> arr1(input_size);
    std::vector<int> arr2(input_size);

    unsigned long long countComparisons1 = 0;
    unsigned long long countComparisons2 = 0;

    GenerateData(arr1, dataTypeMap.at(input_order));
    arr2 = arr1;

    auto start1 = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithm1)(arr1, countComparisons1);
    auto end1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime1 = (end1 - start1) * 1000.0;

    auto start2 = std::chrono::high_resolution_clock::now();
    algorithmFunctionMap.at(algorithm2)(arr2, countComparisons2);
    auto end2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime2 = (end2 - start2) * 1000.0;

    std::string algorithmName1 = algorithmNameMap.at(algorithm1);
    std::string algorithmName2 = algorithmNameMap.at(algorithm2);

    std::string dataTypeName = dataTypeNameMap.at(input_order);

    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algorithmName1 << " | " << algorithmName2 << std::endl;;
    std::cout << "Input size: " << input_size << std::endl;
    std::cout << "Input order: " << dataTypeName << std::endl;;
    std::cout << "---------------------------\n";
    std::cout << "Running time: " << std::setprecision(6) << std::fixed << runTime1.count() << " ms | " << std::setprecision(6) << std::fixed << runTime2.count() << " ms" << std::endl;;
    std::cout << "Comparisons: " << countComparisons1 << " | " << countComparisons2 << std::endl;;
}