#pragma once

#include "Algorithm.h"
#include "DataGenerator.h"
#include <chrono>

void Command1(const std::string &algorithm, const std::string &given_input, const std::string &output_param);
void Command2(const std::string &algorithm, const int &input_size, const std::string &input_order, const std::string &output_param);
void Command3(const std::string &algorithm, const int &input_size, const std::string &output_param);
void Command4(const std::string &algorithm1, const std::string &algorithm2, const std::string &inputFile);
void Command5(const std::string &algorithm1, const std::string &algorithm2, const int &input_size, const std::string &input_order);
