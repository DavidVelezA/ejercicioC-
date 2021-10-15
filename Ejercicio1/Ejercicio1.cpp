// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>


using namespace std;
// cedula unica
bool verifica(string ced) {
    ifstream leer("archivo.txt", ios::in);
    double nota1, nota2;
    string cedula, nombre;
    leer >> nombre;
    while (!leer.eof())
    {
        leer >> cedula;
        leer >> nota1;
        leer >> nota2;
        if (cedula == ced)
        {
            leer.close();
            return false;
        }
        leer >> nombre;

    }
    leer.close();
    return true;

}


// registrar estudiante

void registrar(ofstream &es) {
    double nota1, nota2;
    string cedula, nombre;

    es.open("archivo.txt", ios::out | ios::app);
    cin.ignore();
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nombre);
    cout << "Ingrese la cedula del estudiante: ";
    cin >> cedula;

    // id unico
    if (verifica(cedula))
    {
    cout << "Ingrese la primer nota: ";
    cin >> nota1;
    cout << "Ingrese la segunda nota: ";
    cin >> nota2;
  
    // guardar en archivo
    es << nombre << " " << cedula << " " << nota1 << " " << nota2 << "\n";
    es.close();
    system("cls");
    cout << "REGISTRO GUARDADO!\n";
        
    }
    else
    {
        es.close();
        system("cls");
        cout << "CEDULA LA EXISTE!\n";

    }


}

// modificar estudiante

void modificar(ifstream &Lec) {
   string cedula, nombre, cedula_aux, nombre_aux;
    double nota1, nota2, nota1_aux, nota2_aux;

    Lec.open("archivo.txt", ios::in);
    ofstream aux("auxiliar.txt", ios::out);

    if (Lec.is_open()) {    
        cout << "Ingrese la cedula del estudiante: ";
        cin >> cedula_aux;
        Lec >> nombre;
        while (!Lec.eof())
        {
            Lec >> cedula;
            Lec >> nota1;
            Lec >> nota2;         

            if (cedula == cedula_aux)
            {

                cin.ignore();
                cout << "Ingrese el nombre modificado: ";
                getline(cin, nombre_aux);
                cout << "Ingrese la primer nota modificada: ";
                cin >> nota1_aux;
                cout << "Ingrese la segunda nota modificada: ";
                cin >> nota2_aux;
                aux << nombre_aux << " " << cedula_aux << " " << nota1_aux << " " << nota2_aux << "\n";
            }
            else {
               aux << nombre << " " << cedula << " " << nota1 << " " << nota2 << "\n";

            }
            Lec >> nombre;
         
          
        }
        Lec.close();
        aux.close();
        system("cls");
        cout << "REGISTRO MODIFICADO!\n";

    }
    else 
        cout << "Error"<< endl;
    remove("archivo.txt");
    rename("auxiliar.txt", "archivo.txt");
    
    
     
}


// eliminar estudiante
void eliminar(ifstream& Lec) {
    string cedula, nombre, cedula_aux, nombre_aux;
    double nota1, nota2, nota1_aux, nota2_aux;

    Lec.open("archivo.txt", ios::in);
    ofstream aux("auxiliar.txt", ios::out);

    if (Lec.is_open()) {
        cout << "Ingrese la cedula del estudiante: ";
        cin >> cedula_aux;
        Lec >> nombre;
        while (!Lec.eof())
        {
            Lec >> cedula;
            Lec >> nota1;
            Lec >> nota2;

            if (cedula == cedula_aux)
            {
                cout << "REGISTRO ELIMINADO!\n";

               
            }
            else {
                aux << nombre << " " << cedula << " " << nota1 << " " << nota2 << "\n";

            }
            Lec >> nombre;


        }
        Lec.close();
        aux.close();
        system("cls");
        cout << "REGISTRO ELIMINADO!\n";

    }
    else
        cout << "Error" << endl;
    remove("archivo.txt");
    rename("auxiliar.txt", "archivo.txt");
    


}





int main()
{
    ofstream Esc;
    ifstream Lec;

    int opcion;

    do
    {
        cout << "--------------Seleccione una opcion--------------\n";
        cout << "1. Registrar estudiante \n";
        cout << "2. Modificar estudiante \n";
        cout << "3. Eliminar  estudiante \n";
        cout << "4. Salir \n";

        cin >> opcion;

        switch (opcion)
        {

        case 1:
            registrar(Esc);         
        break;

        // caso para modificar
        case 2:
            modificar(Lec);
        break;

        // caso para eliminar 
        case 3:
            eliminar(Lec);
        break;



        default:
            break;
        }

       


    } while (opcion!=4);



  

}

