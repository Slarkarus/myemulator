//
// Created by marmlll on 20.03.2024.
//

#ifndef EMULATOR_PREPROCESSOR_H
#define EMULATOR_PREPROCESSOR_H

#include "my_parser.h"
#include "commands.h"
#include <vector>
#include <string>

// My PrEprocessor
namespace MPE{
    class Preprocessor{
    public:



        std::vector<std::shared_ptr<MCM::Command>> process(std::string path){



            std::vector <std::shared_ptr<MCM::Command>> result;

            std::vector<MPS::Token> tokens = MPS::parse_commands(path);

            for(int i=0; i<tokens.size(); ++i){
                while(MCM::COMMANDS_LIST.find(tokens[i].value) == MCM::COMMANDS_LIST.end()){
                    result.push_back(std::make_shared<MCM::Lab>());
                    result.back()->arg = tokens[i].value;
                    i++;
                }
                switch (MCM::COMMANDS_LIST[tokens[i].value])
                {

                    case 0:
                        result.push_back(std::make_shared<MCM::Begin>());
                        break;
                    case 1:
                        result.push_back(std::make_shared<MCM::End>());
                        break;
                    case 2:
                        result.push_back(std::make_shared<MCM::Push>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 3:
                        result.push_back(std::make_shared<MCM::Pop>());
                        break;
                    case 4:
                        result.push_back(std::make_shared<MCM::Pushr>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 5:
                        result.push_back(std::make_shared<MCM::Popr>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 6:
                        result.push_back(std::make_shared<MCM::Add>());
                        break;
                    case 7:
                        result.push_back(std::make_shared<MCM::Sub>());
                        break;
                    case 8:
                        result.push_back(std::make_shared<MCM::Mul>());
                        break;
                    case 9:
                        result.push_back(std::make_shared<MCM::Div>());
                        break;
                    case 10:
                        result.push_back(std::make_shared<MCM::Out>());
                        break;
                    case 11:
                        result.push_back(std::make_shared<MCM::In>());
                        break;
                    case 12:
                        result.push_back(std::make_shared<MCM::Jmp>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 13:
                        result.push_back(std::make_shared<MCM::Jeq>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 14:
                        result.push_back(std::make_shared<MCM::Jne>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 15:
                        result.push_back(std::make_shared<MCM::Ja>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 16:
                        result.push_back(std::make_shared<MCM::Jae>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 17:
                        result.push_back(std::make_shared<MCM::Jb>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 18:
                        result.push_back(std::make_shared<MCM::Jbe>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 19:
                        result.push_back(std::make_shared<MCM::Call>());
                        result.back()->arg = tokens[i+1].value;
                        i++;
                        break;
                    case 20:
                        result.push_back(std::make_shared<MCM::Ret>());
                        break;
                    default:
                        throw std::invalid_argument("Preprocessor: unknown command");
                }
            }
            return result;
        }
    };
}

#endif //EMULATOR_PREPROCESSOR_H
