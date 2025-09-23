#include <iostream>
#include <string>

int main()  {
int size = 4;
std::string nom_alumnos[size] = {"Liz"," Marlenne"," Angel"," Carlos"};
float U1[size] = {};
float U2[size] = {};

U1[3] = 70;
U2[3] = 70;

std:: cout << "Promedio de Carlos:" << (U1[3] + U2[3]) /2 << std::endl;



return 0;

}
