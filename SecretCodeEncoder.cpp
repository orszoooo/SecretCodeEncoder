// SecretCodeEncoder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "Encoder.h"

int main(int argc, char* argv[])
{
    Encoder* enc = new Encoder();
    std::string sentence = "";
    
    if (argc < 2) {
        std::cout << "Please provide sentence to encode: ";
        
        std::getline(std::cin, sentence);
        sentence = enc->Encode(sentence);
    }
    else {
        if (argc == 4) {
            if (std::string(argv[1]) == "-f") {
                auto input_path = std::filesystem::path(argv[2]);
                auto output_path = std::filesystem::path(argv[3]);

                if (std::filesystem::exists(input_path)) {
                    std::ifstream source_file(input_path);
                    std::ofstream end_file(output_path, std::ios::trunc);

                    if (source_file.is_open() && end_file.is_open()) {
                        while (std::getline(source_file, sentence)) { //Encode each line of text file
                            end_file << enc->Encode(sentence);
                            end_file << std::endl;
                        }
                        sentence = "In " + output_path.string();
                    }
                    else {
                        sentence = "Can't open the files!";
                    }

                    source_file.close();
                    end_file.close();
                }
                else {
                    sentence = "File does not exist!";
                }
            }
        }
        else {
            sentence = enc->Encode(argv[1]);
        }  
    }

    std::cout << "Encoded sentence: " << sentence << std::endl;
   
    delete enc;
}
