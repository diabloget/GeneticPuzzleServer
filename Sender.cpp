/**
 * @file Sender.cpp
 * @authors Diabloget, Jjvv21
 */
#include "Sender.h"

int opt = 1;
/**
 * @class Sender
 * @brief Instancia del servidor.
 * @details Clase servidor para instanciar los sockets.
 */

/**
 * @brief Constructor de Sender
 * @details Permite construir el objeto Sender para asi llamar a los metodos de los sockets.
 */
Sender::Sender(){
}

/**
 * @brief Envia imagePath al servidor.
 * @param imagePath
 * @return string imagePath
 * @details Envia imagePath de instruccion al servidor y retorna el imagePath respuesta.
 */

void Sender::startSend(std::string imagePath){
    char cstr[imagePath.size() + 1];
    strcpy(cstr, imagePath.c_str());

    //Socket principal
    if ((servidor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (connect(servidor, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("\nConnection Failed \n");
        //send(servidor , cstr , strlen(cstr) , MSG_NOSIGNAL);
        //close(servidor);
        exit(EXIT_FAILURE);
    }
    send(servidor , cstr , strlen(cstr) , 0);
    close(servidor);
}

std::string Sender::startRead(){
    if ((servidor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(servidor, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(servidor, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("%s\n","Waiting" );
    bool end = false;
    int clientConection;
    int addrlen = sizeof(address);
    bzero(buffer,1024);
    do{
        if ((clientConection = accept(servidor, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        int readLen = read(clientConection , buffer, 1024);
        if (readLen > 0){
            printf("%s\n",buffer);
            end = true;
        }
        close(clientConection);
    } while(!end);


    /////////////
    close(servidor);
    std::string x = buffer;
    return x;
}

/**
 * @brief Inicia el servidor
 * @details Envia el mensaje init para asi preparar al socket del servidor para recibir instrucciones.
 */
std::string Sender::initServer(){
    if ((servidor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(servidor, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(servidor, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("%s\n","Waiting" );
    bool end = false;
    int clientConection;
    int addrlen = sizeof(address);
    bzero(buffer,1024);
    do{
        if ((clientConection = accept(servidor, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        int readLen = read(clientConection , buffer, 1024);
        if (readLen > 0){
            printf("%s\n",buffer);
            end = true;
        }
        close(clientConection);
    } while(!end);

    close(servidor);
    std::string x = buffer;
    std::cout << buffer << " Path\n";
    return x;
}