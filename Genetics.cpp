//
// Created by diabloget on 6/25/21.
//

#include "Genetics.h"

Genetics::Genetics(std::vector<std::vector<int>> imageVector) {
    this->imageVector = imageVector;
    this->gens = std::vector<std::vector<std::vector<std::vector<int>>>>();
    this->bestGens = std::vector<std::vector<std::vector<int>>>();

    auto rng = std::default_random_engine {};
    this->randomVector = imageVector;
    std::shuffle(std::begin(this->randomVector), std::end(this->randomVector), rng);
    this->global = 0;
    /*
    if(this->randomVector[0] == this->imageVector[0]){
        std::cout << "di si kede como un mamapixas\n";
    }
     */
    this->bestGens.push_back(this->randomVector);
    evolution();
}

void Genetics::generation(std::vector<std::vector<int>> gen){
    std::vector<std::vector<std::vector<int>>> tempGeneration = std::vector<std::vector<std::vector<int>>>();
    std::vector<std::vector<int>> tempGen;
    int cont = 1;



    while(cont<gen.size()){

    /*
     * Random
     */
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(0, 20);
        int rand1 = distr(eng);
        int rand2 = distr(eng);



        tempGen = gen;
        if(rand1 != rand2){
            std::iter_swap(tempGen.begin() + 0, tempGen.begin() + cont);
        } else {
            std::cout << "Mutation\n";
            auto rng = std::default_random_engine {};
            std::shuffle(std::begin(tempGen), std::end(tempGen), rng);


        }

        tempGeneration.push_back(tempGen);
        cont++;

    }

    this->gens.push_back(tempGeneration);
    //Llamar a la funcion fitness y que agregue el mejor vector a una lista de vectores para luego representarlos en la interfaz
}

void Genetics::fitness(std::vector<std::vector<std::vector<int>>> generation){
    int ideal = this->imageVector.size();
    int idealTest = 0;
    int cont = 0;
    std::vector<std::vector<int>> bestGen;
    while(cont < generation.size()){
        int cont2 = 0;
        std::vector<std::vector<int>> currentGen = generation[cont];
        int idealCont = 0;
        while(cont2 < currentGen.size()){
            std::cout << idealTest << " Fitness\n";
            if(currentGen[cont2] == imageVector[cont2]){
                idealCont++;
            }
            if(idealCont>idealTest){
                idealTest = idealCont;
                bestGen = currentGen;
            }
            if(idealCont == idealTest){
                std::vector<std::vector<std::vector<int>>> tempRagnarok = std::vector<std::vector<std::vector<int>>>();
                tempRagnarok.push_back(bestGen);
                tempRagnarok.push_back(currentGen);

                auto rng = std::default_random_engine {};
                std::shuffle(std::begin(tempRagnarok), std::end(tempRagnarok), rng);
                bestGen = tempRagnarok[0];
            }
            if(idealCont == ideal){
                this->result = bestGen;
            }
            cont2++;
        }

        cont++;
    }

    this->bestGens.push_back(bestGen);
    int a = 1;
}

void Genetics::evolution(){
    int cont = 0;
    while(result != this->imageVector){
        if(cont >= 5000){
            result = bestGens[bestGens.size()-1];
            break;
        }

        generation(bestGens[cont]);
        fitness(gens[cont]);
        cont++;
    }
    std::cout << "Evolucion finalizada\n";
    std::cout << "Numero de mejores genes: " << bestGens.size() << "\n";
}

void Genetics::setData(std::string compression, int v, int h, int max){
    this->compression = compression;
    this->v = v;
    this->h = h;
    this->max = max;
}

void Genetics::write(int direction){
    if(direction == 1){
        if(global + 1 < bestGens.size()){
            this->global++;

            std::ofstream myfile;
            myfile.open ("temporal.pgm");
            myfile << compression << "\n";
            myfile << this->h << " " << this->v << "\n";
            myfile << this->max << "\n";
            std::vector<std::vector<int>> tempVector = this->bestGens[global];
            int limit = 0;
            for(int cont1 = 0; cont1 < tempVector.size(); cont1++){
                std::vector<int> tempSquare = tempVector[cont1];
                for(int cont2 = 0; cont2 < tempSquare.size(); cont2++){
                    if(limit == 17){
                        limit = 0;
                        myfile << "\n";
                    }
                    myfile << tempSquare[cont2] << " ";
                    limit++;
                }
            }
            myfile.close();

            //call server

        }
    } else if (direction == 0) {
        if(global > 0){
            this->global--;

            std::ofstream myfile;
            myfile.open ("temporal.pgm");
            myfile << compression << "\n";
            myfile << this->h << " " << this->v << "\n";
            myfile << this->max << "\n";
            std::vector<std::vector<int>> tempVector = this->bestGens[global];
            int limit = 0;
            for(int cont1 = 0; cont1 < tempVector.size(); cont1++){
                std::vector<int> tempSquare = tempVector[cont1];
                for(int cont2 = 0; cont2 < tempSquare.size(); cont2++){
                    if(limit == 17){
                        limit = 0;
                        myfile << "\n";
                    }
                    myfile << tempSquare[cont2] << " ";
                    limit++;
                }
            }
            myfile.close();


            //call server

        }
    } else if (direction == 2) {

        if(global + 11 < bestGens.size()){
            this->global+=10;

            std::ofstream myfile;
            myfile.open ("temporal.pgm");
            myfile << compression << "\n";
            myfile << this->h << " " << this->v << "\n";
            myfile << this->max << "\n";
            std::vector<std::vector<int>> tempVector = this->bestGens[global];
            int limit = 0;
            for(int cont1 = 0; cont1 < tempVector.size(); cont1++){
                std::vector<int> tempSquare = tempVector[cont1];
                for(int cont2 = 0; cont2 < tempSquare.size(); cont2++){
                    if(limit == 17){
                        limit = 0;
                        myfile << "\n";
                    }
                    myfile << tempSquare[cont2] << " ";
                    limit++;
                }
            }
            myfile.close();

            //call server

        }
    } else {
        if(global - 10 > 0){
            this->global-= 10;

            std::ofstream myfile;
            myfile.open ("temporal.pgm");
            myfile << compression << "\n";
            myfile << this->h << " " << this->v << "\n";
            myfile << this->max << "\n";
            std::vector<std::vector<int>> tempVector = this->bestGens[global];
            int limit = 0;
            for(int cont1 = 0; cont1 < tempVector.size(); cont1++){
                std::vector<int> tempSquare = tempVector[cont1];
                for(int cont2 = 0; cont2 < tempSquare.size(); cont2++){
                    if(limit == 17){
                        limit = 0;
                        myfile << "\n";
                    }
                    myfile << tempSquare[cont2] << " ";
                    limit++;
                }
            }
            myfile.close();


            //call server

        }
    }
}
