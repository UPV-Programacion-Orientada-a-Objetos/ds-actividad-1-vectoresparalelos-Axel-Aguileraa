#include <iostream>
#include <vector>
#include <string>
#include <fstream>//permite trabajar con archivos
#include <sstream>//es util para desarmar el texto 

int main() {
    std::vector<std::string> nombres;
    std::vector<std::string> paises;
    std::vector<std::string> disciplinas;//los vectores
    std::vector<char> generos;
    std::vector<int> medallas;


    std::string rutaArchivo;
    std::cout << "Ingresa el nombre del archivo: ";
    std::cin >> rutaArchivo;

    std::ifstream archivo(rutaArchivo);//intenta abrir el archivo escrito en modo lectura

    if (!archivo.is_open())//es una verificacion
 {
        std::cout << "Error. No se pudo encontrar el archivo." << std::endl;
        return 1;//cierra el programa si no encuentra el archivo
    }


    std::string linea;
    std::getline(archivo, linea);

    

   //este bucle se repite mientras el archivo tenga lineas por leer
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string token;

        std::getline(ss, token, ',');
        nombres.push_back(token);

        std::getline(ss, token, ',');
        paises.push_back(token);

        std::getline(ss, token, ',');
        disciplinas.push_back(token);

        std::getline(ss, token, ',');
        generos.push_back(token[0]);

        std::getline(ss, token, ',');
        medallas.push_back(std::stoi(token));
    }

    archivo.close();
    std::cout << "Se cargaron " << nombres.size() << " atletas" << std::endl;
  
    }
