#include <iostream>
using namespace std;

//Desarrollar un programa que permita registrar 
//las notas de estudiantes de un curso y 
//calcular estadísticas académicas.

float calcularPromedio(float n1,float n2,float n3);

int main() {

    int codigo, opcion;
    char nombre[50];
    float nota1,nota2,nota3,promedio;

    do{
        cout<<"Bienvenido al Sistema de Evaluacion Academica"<<endl;
        cout<<"Presiona enter para continuar...";cin.get();


        cout<<"\n---Sistema de Evaluacion Academica---"<<endl;
        cout<<"1. Registrar estudiantes"<<endl;
        cout<<"2. Mostrar lista de estudiantes"<<endl;
        cout<<"3. Clasificacion de estudiantes"<<endl;
        cout<<"4. Estadisticas academicas"<<endl;
        cout<<"5. Buscar por codigo"<<endl;
        cout<<"6. Buscar por nombre"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        switch (opcion)
        {
            case 1:
                cout<<"---Registro de estudiantes---"<<endl;
                cout<<"Ingrese el codigo de alumno:";cin>>codigo;
                cout<<"Ingrese el nombre del alumno: ";cin>>nombre;
                cout<<"Ingresa la nota 1: ";cin>>nota1;
                cout<<"Ingresa la nota 2: ";cin>>nota2;
                cout<<"Ingresa la nota 3: ";cin>>nota3;
            break;
            case 2:
                cout<<"---Lista de estudiantes---"<<endl;
                cout<<"Codigo | Nombre | Nota 1 | Nota 2 | Nota 3 | Promedio"<<endl;
                cout<<"-------------------------------------------";
                cout<<codigo<<"|"<<nombre<<"|"<<nota1<<"|"<<nota2<<"|"<<nota3<<"|"<<promedio<<endl;    
                break;
            case 3:
                if (promedio >= 18){
                    cout<<"Excelencia"<<endl;
                }else if(promedio >= 11 && promedio < 18){
                    cout<<"Aprobado"<<endl;
                }else{
                    cout<<"Reprobado"<<endl;
                }  
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                cout<<"Saliendo del sistema..."<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
        if (opcion!=0){
            cout<<"Presiona enter para continuar...";cin.get();
        }
    }while(opcion!=0);

    
    promedio = calcularPromedio(nota1,nota2,nota3);
    cout<<"El promedio del alumno es: "<<promedio<<endl;

    
    return 0;
}

float calcularPromedio(float n1, float n2, float n3){
    float promedio = (n1+n2+n3)/3;
    return promedio;
}