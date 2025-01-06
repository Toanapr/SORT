#include <iostream>
#include <fstream>
#include "headers/Algorithm.h"
#include "headers/Command.h"
#include "headers/DataGenerator.h"
#include "headers/Util.h"


int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <algorithm-name>\n";
        std::cerr << "Available algorithms: selection-sort, insertion-sort, bubble-sort, shaker-sort, "
                  << "shell-sort, heap-sort, merge-sort, quick-sort, counting-sort, radix-sort, flash-sort\n";
        return 1;
    }

    std::string algorithm = argv[1];
    if (!isValidAlgorithm(algorithm)) {
        std::cerr << "Invalid algorithm name\n";
        return 1;
    }

    std::vector<int> arr(300000);
    int arrSize;
    // GenerateData(arr, 0);
    // writeFile("input_500k.txt", arr);
    unsigned long long countComparison = 0;
    std::string input_file = "input.txt";

    readFile(input_file, arr, arrSize);

    double time_taken = 0;
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        std::vector<int> arr1(10000);
        arr1 = arr;
        countComparison = 0;
        auto start = std::chrono::high_resolution_clock::now();
        algorithmFunctionMap.at(algorithm)(arr1, countComparison);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> runTime = (end - start) * 1000.0;
        std::cout << "Time taken: " << runTime.count() << " ms" << "\t";
        std::cout << "Comparisons: " << countComparison << std::endl;
        time_taken += runTime.count();
    }

    std::cout << "\nAverage time taken: " << time_taken / n*1.0 << " ms" << std::endl;
    std::cout << "Comparisons: " << countComparison << std::endl;

    return 0;
}

// int main(int argc, char* argv[]) 
// {
//     // if (argc != 2) {
//     //     std::cerr << "Usage: " << argv[0] << " <algorithm-name>\n";
//     //     std::cerr << "Available algorithms: selection-sort, insertion-sort, bubble-sort, shaker-sort, "
//     //               << "shell-sort, heap-sort, merge-sort, quick-sort, counting-sort, radix-sort, flash-sort\n";
//     //     return 1;
//     // }

//     // std::string algorithm = argv[1];
//     // if (!isValidAlgorithm(algorithm)) {
//     //     std::cerr << "Invalid algorithm name\n";
//     //     return 1;
//     // }
//     std::string algorithm[] = {"shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort", "selection-sort", "insertion-sort", "bubble-sort"};

//     int arrSize = 10000;
//     std::vector<int> arr_core(arrSize);

//     // GenerateData(arr, 0);
//     // writeFile("input.txt", arr);

//     unsigned long long countComparison = 0;
//     std::string input_file = "input.txt";

//     readFile(input_file, arr_core, arrSize);

//     double time_taken = 0;
//     for (int j = 0; j < 11; j++)
//     {
//         time_taken = 0;
//         std::vector<int> arr(arrSize);
//         arr = arr_core;
//         for (int i = 0; i < 100; i++)
//         {
//             countComparison = 0;
//             auto start = std::chrono::high_resolution_clock::now();
//             algorithmFunctionMap.at(algorithm[j])(arr, countComparison);
//             auto end = std::chrono::high_resolution_clock::now();
//             std::chrono::duration<double> runTime = (end - start) * 1000.0;
//             // std::cout << i + 1 << ". Time taken: " << runTime.count() << " ms" << std::endl;
//             std::cout << i + 1 << " ";
//             time_taken += runTime.count();
//         }
        
//         std::cout << "\n\nAlgorithm: " << algorithm[j] << std::endl;
//         std::cout << "Average time taken: " << time_taken / 100.0 << " ms" << std::endl;
//         std::cout << "Comparisons: " << countComparison << std::endl;
//     }
//     return 0;
// }
// int main(int argc, char *argv[]) {
//     // Basic argument count check
//     if (argc < 2) {
//         std::cerr << "Usage:\n"
//                   << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]\n"
//                   << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]\n"
//                   << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]\n"
//                   << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]\n"
//                   << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]\n";
//         return 1;
//     }

//     std::string mode = argv[1];

//     // Algorithm mode (-a)
//     if (mode == "-a") {
//         if (argc < 5) {
//             std::cerr << "Invalid number of arguments for algorithm mode\n";
//             return 1;
//         }

//         std::string algorithm = argv[2];
//         if (!isValidAlgorithm(algorithm)) {
//             std::cerr << "Invalid algorithm name\n";
//             return 1;
//         }

//         // Command 1: Given input file
//         if (!isdigit(argv[3][0])) {
//             if (argc != 5) {
//                 std::cerr << "Invalid arguments for Command 1\n";
//                 return 1;
//             }
//             std::string input_file = argv[3];
//             std::string output_param = argv[4];

//             if (!isValidGivenInput(input_file) || !isValidOutputParam(output_param)) {
//                 std::cerr << "Invalid input file or output parameter\n";
//                 return 1;
//             }

//             Command1(algorithm, input_file, output_param);
//             return 0;
//         }
        
//         // Command 2 & 3: Generated data
//         int input_size = std::stoi(argv[3]);
//         if (input_size <= 0) {
//             std::cerr << "Input size must be positive\n";
//             return 1;
//         }

//         // Command 2: With specified order
//         if (argc == 6) {
//             std::string input_order = argv[4];
//             std::string output_param = argv[5];

//             if (!isValidInputOrder(input_order) || !isValidOutputParam(output_param)) {
//                 std::cerr << "Invalid input order or output parameter\n";
//                 return 1;
//             }

//             Command2(algorithm, input_size, input_order, output_param);
//             return 0;
//         }
        
//         // Command 3: Random order
//         if (argc == 5) {
//             std::string output_param = argv[4];
//             if (!isValidOutputParam(output_param)) {
//                 std::cerr << "Invalid output parameter\n";
//                 return 1;
//             }

//             Command3(algorithm, input_size, output_param);
//             return 0;
//         }

//         std::cerr << "Invalid number of arguments\n";
//         return 1;
//     }

//     // Comparison mode (-c)
//     if (mode == "-c") {
//         if (argc < 5) {
//             std::cerr << "Invalid number of arguments for comparison mode\n";
//             return 1;
//         }

//         std::string algorithm1 = argv[2];
//         std::string algorithm2 = argv[3];

//         if (!isValidAlgorithm(algorithm1) || !isValidAlgorithm(algorithm2)) {
//             std::cerr << "Invalid algorithm name(s)\n";
//             return 1;
//         }

//         // Command 4: Compare with given input file
//         if (!isdigit(argv[4][0])) {
//             if (argc != 5) {
//                 std::cerr << "Invalid arguments for Command 4\n";
//                 return 1;
//             }
//             std::string input_file = argv[4];
//             if (!isValidGivenInput(input_file)) {
//                 std::cerr << "Invalid input file\n";
//                 return 1;
//             }

//             Command4(algorithm1, algorithm2, input_file);
//             return 0;
//         }

//         // Command 5: Compare with generated data
//         if (argc != 6) {
//             std::cerr << "Invalid arguments for Command 5\n";
//             return 1;
//         }

//         int input_size = std::stoi(argv[4]);
//         std::string input_order = argv[5];

//         if (input_size <= 0 || !isValidInputOrder(input_order)) {
//             std::cerr << "Invalid input size or order\n";
//             return 1;
//         }

//         Command5(algorithm1, algorithm2, input_size, input_order);
//         return 0;
//     }

//     std::cerr << "Invalid mode. Use -a or -c\n";
//     return 1;
// }