#include "stdafx.h"
#include "game.h"
#include <iostream>
#include <exception>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define BITS_IN_DWORD 32
#define LIFE_SIGN "O"
#define FREE_SIGN "."

using std::cout;

namespace cell_machine
{

    const char* const CellMachineGame::greetingStr = "Greeting string";

    /**
    * Конструктор
    * @param fieldLength - длина игрового поля
    * @param fieldWidth - ширина игрового поля
    */
    CellMachineGame::CellMachineGame(const unsigned int fieldLength, const unsigned int fieldWidth):
    gameFieldLength(defaultGameFieldLength),
        gameFieldWidth(defaultGameFieldWidth),
        fieldSizeInDwords(defaultGameFieldSizeInDwords),
        gameFieldDwords(NULL){


        if(fieldLength < this->maxGameFieldLength && fieldLength > 0)
            this->gameFieldLength = fieldLength;

        if(fieldWidth < this->maxGameFieldWidth && fieldWidth > 0)
            this->gameFieldWidth = fieldWidth;

        this->gameFieldWidth = (fieldWidth < this->maxGameFieldWidth && fieldWidth > 0) ? fieldWidth : this->gameFieldWidth;
        unsigned int oneRowDwordsCount = (this->gameFieldLength % BITS_IN_DWORD) ? (this->gameFieldLength / BITS_IN_DWORD + 1) : (this->gameFieldLength / BITS_IN_DWORD);
        this->fieldSizeInDwords = oneRowDwordsCount * (this->gameFieldWidth);
        try{
            this->gameFieldDwords = new unsigned int[this->fieldSizeInDwords];
        }
        catch (std::exception& e){
            std::cout << "Error allocating memory." << e.what() << std::endl;
        }
    }

    /**
    * Конструктор копирования
    */
    CellMachineGame::CellMachineGame(const CellMachineGame &cmg):
        gameFieldLength(cmg.gameFieldLength),
        gameFieldWidth(cmg.gameFieldWidth),
        fieldSizeInDwords(cmg.fieldSizeInDwords),
        gameFieldDwords(NULL){
        try{
            this->gameFieldDwords = new unsigned int[this->fieldSizeInDwords];
        }
        catch (std::exception& e){
            std::cout << "Error allocating memory." << e.what() << std::endl;
        }
        memcpy(this->gameFieldDwords, cmg.gameFieldDwords, ((this->fieldSizeInDwords)*sizeof(unsigned int)));
    }

    /**
    * Деструктор
    */
    CellMachineGame::~CellMachineGame(){
        delete[] this->gameFieldDwords;
    }

    /**
    * Запуск процесса жизни
    */
    void CellMachineGame::start(){
        this->populateField();
        this->drawFieldConsole();
    }

    /**
    * Заселение игрового поля
    */
    void CellMachineGame::populateField(){
        srand((unsigned int)time(NULL));
        unsigned int *gameCellDword = this->gameFieldDwords;
        for(unsigned int i = 0; i < this->fieldSizeInDwords; i++){
            *gameCellDword =  (rand() & 0xFF) | ((rand() & 0xFF) << 8) | ((rand() & 0xFF) << 16) | ((rand() & 0xFF) << 24);
            gameCellDword++;
        }

    }

    /**
    * Вывод состояния игрового поля
    */
    void CellMachineGame::drawFieldConsole(){
        unsigned int *currentDword = this->gameFieldDwords;
        for(unsigned int row = 0; row < this->gameFieldWidth; row++){
            unsigned int bitNum = 0;
            for(unsigned int col = 0; col < this->gameFieldLength; col++){
                if(bitNum >= BITS_IN_DWORD){
                    bitNum=0;
                    currentDword++;
                }
                (*currentDword  & ( 1 << bitNum))? cout << LIFE_SIGN : cout << FREE_SIGN;
                bitNum++;                
            }
            currentDword++;
            cout << '\n';
        }
    }
}
