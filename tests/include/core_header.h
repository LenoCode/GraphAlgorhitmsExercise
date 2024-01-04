//
// Created by leno on 20.12.23..
//

#ifndef CORE_HEADER_H
#define CORE_HEADER_H
#include <gtest/gtest.h>


#define TEST_DESCRIPTION(desc,name)  std::cerr<<"\n" <<"        Test name    "<< name<<"\n" << "\n" <<"[   DESC   ]  = " << desc<< "\n" << std::endl;



// Function to check if multiple arrays are equal
bool areArraysEqual(const int* arrays1, int size1, const int* arrays2,int size2) {
    for(int i = 0; i < size1;++i) {

        bool flag = false;
        for(int j = 0; j < size2;++j) {
            if(arrays1[i] == arrays2[j]) {
                flag = true;
                break;
            }

        }
        if(!flag)return false;
    }
    return true;
}


#endif //CORE_HEADER_H

