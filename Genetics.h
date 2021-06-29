//
// Created by diabloget on 6/25/21.
//

#ifndef GENETICCLIENT_GENETICS_H
#define GENETICCLIENT_GENETICS_H


#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <iostream>
#include <fstream>

class Genetics {
public:
    std::vector<std::vector<int>> imageVector;
    std::vector<std::vector<int>> randomVector;
    std::vector<std::vector<std::vector<std::vector<int>>>> gens;
    std::vector<std::vector<std::vector<int>>> bestGens;
    std::vector<std::vector<int>> result;
    int tol;
    int global;
    Genetics(std::vector<std::vector<int>> imageVector);
    void generation(std::vector<std::vector<int>> gen);
    void fitness(std::vector<std::vector<std::vector<int>>> generation);
    void evolution();
    void write(int direction);
    void setData(std::string compression, int v, int h, int max);

    std::string compression;
    int v;
    int h;
    int max;


};


#endif //GENETICCLIENT_GENETICS_H
