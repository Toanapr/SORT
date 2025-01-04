#include "Algorithm.h"
#include "Command.h"
#include "DataGenerator.h"

void readFile(const std::string &inputFile, std::vector<int> &arr, int &arrSize);
void writeFile(const std::string &outputFile, const std::vector<int> &arr);

bool isValidAlgorithm(const std::string &algorithm);
bool isValidInputOrder(const std::string &input_order);
bool isValidGivenInput(const std::string &given_input);
bool isValidOutputParam(const std::string &output_param);