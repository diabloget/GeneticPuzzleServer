//
// Created by diabloget on 6/23/21.
//

#include "Image.h"

Image::Image(){
    this->imageData = std::vector<int>();
}

void Image::fromFile(std::string path) {
    std::fstream imageFile;
    imageFile.open(path, std::ios::in);
    if (!imageFile) {
        std::cout << "File not found\n";
    }
    else {
        std::cout << "File opened\n";

        std::string data;
        int line = 0;
        int index;


        while(getline(imageFile, data)) {
            index = 0;

            if(line == 0){
                std::string temp = "";
                while(index < data.length()){
                    if(data[index] != ' '){
                        temp = temp + data[index];
                    }
                    this->compression = temp;
                    index++;
                }
            }

            if(line == 1){
                std::string temp = "";
                int cont = 0;
                while(index < data.length()){
                    if(data[index] != ' '){
                        temp += data[index];
                    }
                    if(data[index] == ' '){
                        cont++;
                        temp = "";
                    }
                    if(temp != ""){
                        if(cont == 0){
                            try {
                                this->h = std::stoi(temp);
                            } catch (std::invalid_argument) {

                            }
                        } else {
                            try {
                                this->v = std::stoi(temp);
                            } catch (std::invalid_argument) {

                            }
                        }
                    }
                    //std::cout << this->h << " Horizontal\n" << this->v << " Vertical\n";

                    index++;
                }
            }

            if(line == 2){
                std::string temp = "";
                while(index < data.length()){
                    if(data[index] != ' '){
                        temp = temp + data[index];
                    }
                    try {
                        this->max = std::stoi(temp);
                    } catch (std::invalid_argument) {

                    }

                    index++;
                }
                //std::cout << this-> max << " max\n";
            }

            if(line >= 3){
                std::string temp = "";
                bool isNew = false;
                while(index < data.length()){
                    if(data[index] != ' '){
                        isNew = true;
                        temp += data[index];
                    }
                    if(data[index] == ' '){
                        if(isNew){
                            try {
                                this->imageData.push_back(std::stoi(temp));
                                //std::cout << "se agrego " << temp << " al vector\n";
                                temp = "";
                                isNew = false;
                            } catch (std::invalid_argument) {

                            }
                        }
                    }


                    index++;
                }
            }


            /*
            std::cout << data.length() << "\n";
            std::string hola = data + "\n";
            std::cout << hola;
             */

            line++;
        }

    }
    imageFile.close();
}

void Image::divide(int divideBy){
    if(divideBy > this->imageData.size()){
        std::cout << "The divisor is an invalid argument\n";
    } else if (divideBy <= 0){
        std::cout << "The divisor is an invalid argument\n";
    } else {
        int cont = 0;
        this->idvector = std::vector<std::vector<int>>();

        while(cont < this->imageData.size()){
            int secondCont = 0;
            std::vector<int> tempV = std::vector<int>();
            while(secondCont < divideBy){
                if(cont >= this->imageData.size()){
                    break;
                } else {
                    tempV.push_back(this->imageData[cont]);

                    secondCont++;
                    cont++;
                }
            }
            this->idvector.push_back(tempV);

        }

    }
}

