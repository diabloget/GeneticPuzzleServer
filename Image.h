//
// Created by diabloget on 6/23/21.
//

#ifndef GENETICCLIENT_IMAGE_H
#define GENETICCLIENT_IMAGE_H
#include <iostream>
#include <fstream>
#include <vector>

class Image {

public:
    std::string compression;
    int v;
    int h;
    int max;
    std::vector<int> imageData;
    std::vector<std::vector<int>> idvector;
    Image();


    void fromFile(std::string path);

    void divide(int divideBy);

};


#endif //GENETICCLIENT_IMAGE_H
