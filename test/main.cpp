//
// Created by marmlll on 20.03.2024.
//

#include "emulator.h"

int main(int argc, char* argv[]){
    MEM::Emulator emulator;
    if(argc == 2)
        emulator.start(argv[1]);
    return 0;
}