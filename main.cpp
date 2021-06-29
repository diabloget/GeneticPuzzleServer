#include <iostream>

#include "Image.h"
#include "Genetics.h"
#include "Sender.h"
#include <unistd.h>
#define GetCurrentDir getcwd

int main() {
    char buff[FILENAME_MAX]; //create string buffer to hold path
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    //std::cout << current_working_dir;

    Sender sender = Sender();
    //std::cout << "Hello, World!" << std::endl;
    Image imageReader = Image();
    imageReader.fromFile(sender.initServer());
    //std::cout << imageReader.max;
    int divisor =0;
    try {
        divisor = stoi(sender.initServer());
    } catch (std::invalid_argument){
        std::cout << "Error en la conversion de str a int \n";
    }
    imageReader.divide(divisor);

    std::cout << "Size of divided vector: " << imageReader.idvector[2].size() << "\n";
    Genetics prueba = Genetics(imageReader.idvector);
    prueba.setData(imageReader.compression, imageReader.v, imageReader.h, imageReader.max);

    while(true){
        prueba.write(stoi(sender.startRead()));
        sender.startSend(current_working_dir + "/Testing/temporal.pgm");
    }
    //prueba.write(1);
    std::cout << "Size of besty vector: " << prueba.bestGens.size() << "\n";


    return 0;
}
