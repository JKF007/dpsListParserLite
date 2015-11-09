#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "toolbox.h"

using std::cout;
using std::cin;
using std::string;
using std::getline;

int main(){

    std::ifstream input_file;
    std::ofstream output_file;

    std::vector<string> tokenized_input;
    std::vector<string> small_arms_list;

    string inputLine;

    input_file.open("small_arms_list.txt");

    while( std::getline(input_file, inputLine) ){

        small_arms_list.push_back(inputLine);

    }

    input_file.close();

    input_file.open("coh2dps.csv");
    output_file.open("coh2dpsedited.csv");

    while( std::getline(input_file, inputLine) ){

        tokenized_input.clear();
        string_tokenizer(inputLine, tokenized_input, ',');

        if(tokenized_input.size() >0){
            string name = tokenized_input.at(0);

            if ( vectorSearch(name , small_arms_list) >=0){
                output_file << name <<",";

                for (int cellNum =4; cellNum <=10; cellNum++){
                    string dpsNumber = tokenized_input.at(cellNum);
                    output_file<<dpsNumber<<",";
                }
                output_file <<"\n";
            }
        }
    }

    input_file.close();
    output_file.close();
    return 1;
};
