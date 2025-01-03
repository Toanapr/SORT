#include "headers/Command.h"
#include "headers/Util.h"

void Command1(const std::string &algorithm, const std::string &given_input, const std::string &output_param)
{
    unsigned long long countComparisons = 0;

    // std::ifstream input(given_input);
    // input >> arrSize;
    // int val;
    // while (input >> val)
    // {
    //     arr.push_back(val);
    // }

    int arrSize;
    std::vector<int> arr;
    readFile(given_input, arr, arrSize);

    auto start = std::chrono::high_resolution_clock::now();
    // algorithmFunctionMap.at(algorithmMap.at(algorithm))(arr, countComparisons);
    algorithmFunctionMap.at(algorithm)(arr, countComparisons);
    auto end = std::chrono::high_resolution_clock::now();

    // std::ofstream outFile;
    // outFile.open("output.txt");
    // outFile << arrSize << '\n';
    // for (int x : arr)
    // {
    //     outFile << x << ' ';
    // }
    // outFile.close();

    writeFile("output.txt", arr);

    std::chrono::duration<double> runTime = (end - start) * 1000.0;

    // std::string algorithmName = algorithmNameMap.at(algorithmMap.at(algorithm));
    std::string algorithmName = algorithmNameMap.at(algorithm);

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algorithmName << '\n';
    std::cout << "Input file: " << given_input << '\n';
    std::cout << "Input size: " << arrSize << '\n';
    std::cout << "---------------------------\n";
    if (output_param == "-time" || output_param == "-both")
        std::cout << std::setprecision(6) << std::fixed << runTime.count() << " ms" << '\n';
    if (output_param == "-comp" || output_param == "-both")
        std::cout << "Comparisons: " << std::to_string(countComparisons) << '\n';
}

void Command2(const std::string &algorithm, const int &input_size,
              const std::string &input_order, const std::string &output_param)
{
    unsigned long long countComparisons = 0;

    // int dataType = dataTypeMap.at(input_order);

    std::vector<int> arr;
    arr.resize(input_size);
    GenerateData(arr, dataTypeMap.at(input_order));

    // write generated data to input.txt
    // std::ofstream outFile;
    // outFile.open("input.txt");
    // outFile << arr.size() << '\n';
    // for (int x : arr)
    // {
    //     outFile << x << ' ';
    // }
    // outFile.close();
    writeFile("input.txt", arr);

    // measure running time and comparisons
    auto start = std::chrono::high_resolution_clock::now();
    // algorithmFunctionMap.at(algorithmMap.at(algorithm))(arr, countComparisons);
    algorithmFunctionMap.at(algorithm)(arr, countComparisons);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime = (end - start) * 1000.0;

    // write sorted data to output.txt
    // outFile.open("output.txt");
    // outFile << arr.size() << '\n';
    // for (int x : arr)
    // {
    //     outFile << x << ' ';
    // }
    // outFile.close();
    writeFile("output.txt", arr);
    // OUTPUT_PARAM outputParam = outputParamMap.at(output_param);

    // std::string algorithmName = algorithmNameMap.at(algorithmMap.at(algorithm));
    std::string algorithmName = algorithmNameMap.at(algorithm);
    std::string dataTypeName = dataTypeNameMap.at(input_order);

    std::cout << "ALGORITHM MODE\n"
              << "Algorithm: " << algorithmName << '\n'
              << "Input size: " << input_size << '\n'
              << "Input order: " << dataTypeName << '\n'
              << "---------------------------\n";

    std::cout << "Running time (if required): ";
    if (output_param == "-time" || output_param == "-both")
    {
        std::cout << std::setprecision(6) << std::fixed << runTime.count() << " ms" << '\n';
    }
    else
    {
        std::cout << " " << '\n';
    }

    std::cout << "Comparisions (if required): ";
    if (output_param == "-comp" || output_param == "-both")
    {
        std::cout << std::to_string(countComparisons) << '\n';
    }
    else
    {
        std::cout << " " << '\n';
    }
}

void Command3(const std::string &algorithm, const int &input_size, const std::string &output_param)
{
    unsigned long long countComparisons = 0;

    std::vector<int> arr0;
    arr0.resize(input_size);
    GenerateData(arr0, 0);

    std::vector<int> arr1;
    arr1.resize(input_size);
    GenerateData(arr1, 1);

    std::vector<int> arr2;
    arr2.resize(input_size);
    GenerateData(arr2, 2);

    std::vector<int> arr3;
    arr3.resize(input_size);
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

    // std::ofstream output1("input_1.txt");
    // if (output1.is_open())
    // {
    //     output1 << input_size << '\n';
    //     for (int i = 0; i < input_size; i++)
    //     {
    //         output1 << arr0[i] << ' ';
    //     }
    //     output1.close();
    // }
    // else
    // {
    //     std::cerr << "Unable to open file input_1.txt\n";
    //     exit(1);
    // }

    // std::ofstream output2("input_2.txt");
    // if (output2.is_open())
    // {
    //     output2 << input_size << '\n';
    //     for (int i = 0; i < input_size; i++)
    //     {
    //         output2 << arr1[i] << ' ';
    //     }
    //     output2.close();
    // }
    // else
    // {
    //     std::cerr << "Unable to open file input_2.txt\n";
    //     exit(1);
    // }

    // std::ofstream output3("input_3.txt");
    // if (output3.is_open())
    // {
    //     output3 << input_size << '\n';
    //     for (int i = 0; i < input_size; i++)
    //     {
    //         output3 << arr2[i] << ' ';
    //     }
    //     output3.close();
    // }
    // else
    // {
    //     std::cerr << "Unable to open file input_3.txt\n";
    //     exit(1);
    // }

    // std::ofstream output4("input_4.txt");
    // if (output4.is_open())
    // {
    //     output4 << input_size << '\n';
    //     for (int i = 0; i < input_size; i++)
    //     {
    //         output4 << arr3[i] << ' ';
    //     }
    //     output4.close();
    // }
    // else
    // {
    //     std::cerr << "Unable to open file input_4.txt\n";
    //     exit(1);
    // }

    std::string algorithmName = algorithmNameMap.at(algorithm);

    std::cout << "ALGORITHM MODE\n";
    std::cout << "Algorithm: " << algorithmName << '\n';
    std::cout << "Input size: " << input_size << '\n';

    for (int i = 0; i < 4; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        // algorithmFunctionMap.at(algorithmMap.at(algorithm))(arr[i], countComparisons);
        algorithmFunctionMap.at(algorithm)(arr[i], countComparisons);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> runTime = (end - start) * 1000.0;

        // std::string dataTypeName = dataTypeNameMap.at((DATA_TYPE)i);
        
        std::string dataTypeName = "";
        if (i == 0)
            dataTypeName = "Random";
        else if (i == 1)
            dataTypeName = "Sorted";
        else if (i == 2)
            dataTypeName = "Reverse";
        else if (i == 3)
            dataTypeName = "Nearly Sorted";

        std::cout << "Input order: " << dataTypeName << '\n';
        std::cout << "-------------------------\n";

        std::cout << "Running time (if required): ";
        if (output_param == "-time" || output_param == "-both")
        {
            std::cout << std::setprecision(6) << std::fixed << runTime.count() << " ms" << '\n';
        }
        else
        {
            std::cout << " " << '\n';
        }

        std::cout << "Comparisions (if required): ";
        if (output_param == "-comp" || output_param == "-both")
        {
            std::cout << std::to_string(countComparisons) << '\n';
        }
        else
        {
            std::cout << " " << '\n';
        }

        std::cout << "\n";
    }
}

void Command4(const std::string &algorithm1, const std::string &algorithm2, const std::string &inputFile)
{

    // std::ifstream input(inputFile);
    // std::vector<int> arr;
    // int arrSize;
    // input >> arrSize;
    // int val;
    // while (input >> val)
    // {
    //     arr.push_back(val);
    // }
    int arrSize;
    std::vector<int> arr;
    readFile(inputFile, arr, arrSize);

    std::vector<int> arr1 = arr;
    std::vector<int> arr2 = arr;
    unsigned long long countComparison1 = 0;
    unsigned long long countComparison2 = 0;

    auto start = std::chrono::high_resolution_clock::now();
    // algorithmFunctionMap.at(algorithmMap.at(algorithm1))(arr1, countComparison1);
    algorithmFunctionMap.at(algorithm1)(arr1, countComparison1);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime1 = (end - start) * 1000.0;

    start = std::chrono::high_resolution_clock::now();
    // algorithmFunctionMap.at(algorithmMap.at(algorithm2))(arr2, countComparison2);
    algorithmFunctionMap.at(algorithm2)(arr2, countComparison2);
    end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime2 = (end - start) * 1000.0;

    // std::string algorithmName1 = algorithmNameMap.at(algorithmMap.at(algorithm1));
    // std::string algorithmName2 = algorithmNameMap.at(algorithmMap.at(algorithm2));
    std::string algorithmName1 = algorithmNameMap.at(algorithm1);
    std::string algorithmName2 = algorithmNameMap.at(algorithm2);

    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algorithmName1 << " | " << algorithmName2 << '\n';
    std::cout << "Input file: " << inputFile << '\n';
    std::cout << "Input size: " << arr.size() << '\n';
    std::cout << "-------------------------\n";
    std::cout << "Running time: " << std::setprecision(6) << std::fixed << runTime1.count() << " ms | " << std::setprecision(6) << std::fixed << runTime2.count() << " ms" << '\n';
    std::cout << "Comparisons: " << countComparison1 << " | " << countComparison2 << '\n';
}

void Command5(const std::string &algorithm1, const std::string &algorithm2, const int &input_size, const std::string &input_order)
{
    unsigned long long countComparisons1 = 0, countComparisons2 = 0;

    // DATA_TYPE dataType = dataTypeMap.at(input_order);

    std::vector<int> arr1(input_size);
    std::vector<int> arr2(input_size);
    // GenerateData(arr1, dataType);
    GenerateData(arr1, dataTypeMap.at(input_order));
    arr2 = arr1; //  dữ liệu hai mảng phải giống nhau

    auto start1 = std::chrono::high_resolution_clock::now();
    // algorithmFunctionMap.at(algorithmMap.at(algorithm1))(arr1, countComparisons1);
    algorithmFunctionMap.at(algorithm1)(arr1, countComparisons1);
    auto end1 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime1 = (end1 - start1) * 1000.0;

    auto start2 = std::chrono::high_resolution_clock::now();
    // algorithmFunctionMap.at(algorithmMap.at(algorithm2))(arr2, countComparisons2);
    algorithmFunctionMap.at(algorithm2)(arr2, countComparisons2);
    auto end2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> runTime2 = (end2 - start2) * 1000.0;

    // std::string algorithmName1 = algorithmNameMap.at(algorithmMap.at(algorithm1));
    // std::string algorithmName2 = algorithmNameMap.at(algorithmMap.at(algorithm2));
    std::string algorithmName1 = algorithmNameMap.at(algorithm1);
    std::string algorithmName2 = algorithmNameMap.at(algorithm2);
    // std::string dataTypeName = dataTypeNameMap.at(dataType);
    std::string dataTypeName = dataTypeNameMap.at(input_order);

    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algorithmName1 << " | " << algorithmName2 << '\n';
    std::cout << "Input size: " << input_size << '\n';
    std::cout << "Input order: " << dataTypeName << '\n';
    std::cout << "---------------------------\n";
    std::cout << "Running time: " << std::setprecision(6) << std::fixed << runTime1.count() << " ms | " << std::setprecision(6) << std::fixed << runTime2.count() << " ms" << '\n';
    std::cout << "Comparisons: " << countComparisons1 << " | " << countComparisons2 << '\n';
}