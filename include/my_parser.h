//
// Created by marmlll on 20.03.2024.
//

#ifndef MY_PROJECT_PARSER_H
#define MY_PROJECT_PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>

// My ParSer
namespace MPS
{
    enum class TokenType {
        INTEGER_VALUE,
        COMMAND_NAME,
        LABEL_NAME,
        REGISTER_NAME
    };

    struct Token {
        std::string value;
        TokenType type;
    };

    class Parser{
    private:
        std::string &input_;
        long long offset_;
        std::string last_word;
        std::vector<Token> tokens_;

        std::smatch last_match_;

        std::map<TokenType, std::regex> token_regex_ = {
                {TokenType::INTEGER_VALUE, std::regex("[-+]?[0-9]+")},
                {TokenType::LABEL_NAME, std::regex("[a-z]+:")},
                {TokenType::COMMAND_NAME, std::regex("[a-zA-Z_]+")},
                {TokenType::REGISTER_NAME, std::regex("\\$[A-Z]+")}
        };



    public:
        Parser(std::string &input) : input_(input), offset_(0) {};
        std::vector <Token> getTokens(){
            return tokens_;
        }
        void skip_spaces(){
            while(!eof() && input_[offset_] == ' '){
                offset_++;
            }
        }
        void capture_word(){
            last_word = "";
            while(!eof() &&input_[offset_] != ' ' && input_[offset_]!='\n' ){
                last_word += input_[offset_];
                offset_++;
            }

        }
        bool check_word(TokenType type){
            std::regex_search(last_word.cbegin(), last_word.cend(), last_match_, token_regex_.at(type));
            if (!last_match_.empty()) {
                tokens_.push_back({last_word, type});
                return true;
            }
            return false;
        }
        void skip_newlines(){
            while(!eof() && input_[offset_] == '\n'){
                offset_++;
            }
        }

        bool eof(){
            return offset_ >= input_.size();
        }
    };

    std::vector <Token> parse_commands(std::string &input){
        Parser pars(input);
        while(!pars.eof())
        {
            pars.skip_spaces();
            pars.capture_word();
            if(pars.check_word(TokenType::COMMAND_NAME)){
                pars.skip_spaces();
            }
            else if(pars.check_word(TokenType::LABEL_NAME)){
                pars.skip_spaces();
            }
            else{
                throw std::invalid_argument("Parser: bad input string");
            }

            pars.capture_word();
            if(pars.check_word(TokenType::INTEGER_VALUE)){
                pars.skip_spaces();
            }
            else if(pars.check_word(TokenType::REGISTER_NAME)){
                pars.skip_spaces();
            }
            pars.skip_newlines();
        }

        return pars.getTokens();
    }
}




#endif //MY_PROJECT_PARSER_H
