#include <iostream>
#include <vector>
#include <string>
#include <fstream>//permite manejar archivos
#include <sstream>//permite desarmar el archivo

int main() {
    std::vector<std::string> nombres;
    std::vector<std::string> paises;
    std::vector<std::string> disciplinas;//los vectores que se usan
    std::vector<char> generos;
    std::vector<int> medallas;

    std::string rutaArchivo;
    std::cout << "Ingresa el nombre del archivo : ";
    std::cin >> rutaArchivo;

    std::ifstream archivo(rutaArchivo);

    if (!archivo.is_open())//es una verificacion
    {
        std::cout << "Error. No se pudo encontrar el archivo." << std::endl;
        return 1;
    }

    std::string linea;
    std::getline(archivo, linea);
//aqui se ana;iza el archivo y se lee cada linea
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

    archivo.close();//se cierra el archivo
    std::cout << "Se cargaron " << nombres.size() << " atletas" << std::endl;
//Menu
    int opcion;
    do {
        std::cout << "\n--- MENU ---" << std::endl;
        std::cout << "1. Buscar atleta" << std::endl;
        std::cout << "2. Medallas por pais" << std::endl;
        std::cout << "3. Atleta con mas medallas" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string nombreBuscado;
            std::cout << "Nombre del atleta a buscar: ";
            std::cin >> nombreBuscado;

            bool encontrado = false;
            for (int i = 0; i < nombres.size(); ++i) {
                if (nombres[i] == nombreBuscado) {
                    std::cout << " Pais: " << paises[i] << ", Medallas: " << medallas[i] << std::endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << " Atleta no encontrado." << std::endl;
            }
        }
        else if (opcion == 2) {
            std::string paisBuscado;
            std::cout << "Pais a consultar: ";
            std::cin >> paisBuscado;

            int sumaMedallas = 0;
            for (int i = 0; i < paises.size(); ++i) {
                if (paises[i] == paisBuscado) {
                    sumaMedallas = sumaMedallas + medallas[i];
                }
            }
            std::cout << " " << paisBuscado << " tiene un total de " << sumaMedallas << " medallas." << std::endl;
        }
        else if (opcion == 3) {
            int maxMedallas = -1;
            int indiceGanador = -1;

            for (int i = 0; i < medallas.size(); ++i) {
                if (medallas[i] > maxMedallas) {
                    maxMedallas = medallas[i];
                    indiceGanador = i;
                }
            }
            std::cout << " El atleta con mas medallas es " << nombres[indiceGanador] 
                      << " con " << maxMedallas << " medallas." << std::endl;
        }

    } while (opcion != 4);

    std::cout << "Hora de despedirse;(" << std::endl;
    
    return 0;
}
