   int cantidadEstudiantes = 0;
    int opcion;

    cout<<"Bienvenido al Sistema de Evaluacion Academica"<<endl;

    do{
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
            case 1:{
                if(cantidadEstudiantes < MAX_ESTUDIANTES){
                    cout<<"\n---Registro de estudiantes---"<<endl;
                    cout<<"Ingrese el codigo de alumno (solo numeros):";
                    cin>>codigos[cantidadEstudiantes];
                    cout<<"Ingrese el nombre del alumno: ";
                    cin.ignore();
                    getline(cin, nombres[cantidadEstudiantes]);

                    cout<<"Ingresa la nota 1: ";
                    cin>>notas1[cantidadEstudiantes];
                    cout<<"Ingresa la nota 2: ";
                    cin>>notas2[cantidadEstudiantes];
                    cout<<"Ingresa la nota 3: ";
                    cin>>notas3[cantidadEstudiantes];

                    promedios[cantidadEstudiantes] = calcularPromedio(
                        notas1[cantidadEstudiantes],
                        notas2[cantidadEstudiantes],
                        notas3[cantidadEstudiantes]
                        );

                    cout<<"\n Estudiante registrado con exito. Promedio: "<<promedios[cantidadEstudiantes]<<endl;
                    cantidadEstudiantes++;

                }else{
                    cout<<"\n Limite maximo de registros alcanzados.["<<MAX_ESTUDIANTES<<"]"<<endl;
                }
                break;
            }

            case 2:{
                cout<<"---Lista de estudiantes---"<<endl;
                if(cantidadEstudiantes==0){
                    cout<<"No hay estudiantes registrados."<<endl;
                }else{
                    cout<<"Codigo | Nombre | Nota 1 | Nota 2 | Nota 3 | Promedio"<<endl;
                    cout<<"-------------------------------------------"<<endl;
                    for(int i =0; i < cantidadEstudiantes;i++){
                        cout<<codigos[i]<<" | "<<nombres[i]<<" | "
                        <<notas1[i]<<" | "<<notas2[i]<<" | "
                        <<notas3[i]<<" | "<<promedios[i]<<endl;
                    }    
                }
                break;
            }
            case 3:{
                cout<<"\n--- Clasificacion de estudiantes ---"<<endl;
                if(cantidadEstudiantes == 0){
                    cout<<"No hay estudiantes registrados."<<endl;
                }else{
                    for(int i = 0; i < cantidadEstudiantes; i++){
                        cout<<nombres[i]<<" - Promedio: "<<promedios[i]<<" | Clasificacion: ";
                        
                        if (promedios[i] >= 18){
                            cout<<"Excelencia"<<endl;
                        }else if(promedios[i] >= 11){
                            cout<<"Aprobado"<<endl;
                        }else{
                            cout<<"Reprobado"<<endl;
                        }
                    }
                }  
                break;
            }
            case 4:{
                cout<<"\n--- Estadisticas academicas ---"<<endl;
                if(cantidadEstudiantes == 0){
                    cout<<"No hay estudiantes registrados."<<endl;
                }else{
                    float sumaPromedios = 0;
                    float maxNota = promedios[0];
                    float minNota = promedios[0];
                    int aprobados = 0, desaprobados = 0;

                    for(int i = 0; i < cantidadEstudiantes; i++){
                        sumaPromedios = sumaPromedios + promedios[i];
                        
                        if(promedios[i] >= 11){
                            aprobados++;
                        }else{
                            desaprobados++;
                        }
                    }

                    for(int i = 1; i < cantidadEstudiantes; i++){
                        float notas[3] = {notas1[i], notas2[i], notas3[i]};
                        
                        for (int j = 0; j < 3; j++) {
                            if (notas[j] > maxNota) {
                                maxNota = notas[j];
                            }
                            if (notas[j] < minNota) {
                                minNota = notas[j];
                            }
                        }
                    }

                    float promedioGeneral = sumaPromedios/ cantidadEstudiantes;

                    cout<<"Promedio general del curso: "<<promedioGeneral<<endl;
                    cout<<"Nota mas alta: "<<maxNota<<endl;
                    cout<<"Nota mas baja: "<<minNota<<endl;
                    cout<<"Cantidad de aprobados: "<<aprobados<<endl;
                    cout<<"Cantidad de desaprobados: "<<desaprobados<<endl;
                }
                break;
            }
            case 5:{
                cout<<"\n--- Buscar por codigo ---"<<endl;
                if(cantidadEstudiantes == 0){
                    cout<<"No hay estudiantes registrados."<<endl;
                    break;
                }else{
                    int buscarCodigo;
                    cout<<"Ingrese el codigo a buscar: ";
                    cin>>buscarCodigo;

                    buscarEstudiante(buscarCodigo, codigos,nombres,promedios,cantidadEstudiantes);
                }
                break;
            }

            case 6:{
                cout << "\n--- Buscar por nombre ---" << endl;
                if(cantidadEstudiantes == 0) {
                    cout << "No hay estudiantes registrados." << endl;
                    break;
                }else{
                    string buscarNombre;
                    cout << "Ingrese el nombre exacto a buscar: ";
                    cin.ignore();
                    getline(cin, buscarNombre);

                    buscarEstudiante(buscarNombre, codigos, nombres, promedios, cantidadEstudiantes);

                }
                break;
            }

            case 0:
                cout << "\nSaliendo del sistema..." << endl;
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
                break;
        }
        
    }while(opcion!=0);
    
    return 0;
}

float calcularPromedio(float n1, float n2, float n3){
    float promedio = (n1+n2+n3)/3;
    return promedio;
}

void buscarEstudiante(int codigoBuscado, int codigos[], string nombres[],float promedios[], int cantidad){
    bool encontrado = false;
    for(int i = 0; i<cantidad; i++){
        if(codigos[i]==codigoBuscado){
            cout<<"Encontrado: "<<nombres[i]<<" | Promedio: "<<promedios[i]<<endl;
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout<<"Estudiante no encontrado."<<endl;
    }
}

void buscarEstudiante(string nombreBuscado, int codigos[], string nombres[],float promedios[], int cantidad){
    bool encontrado = false;
    for(int i = 0; i<cantidad; i++){
        if(nombres[i]==nombreBuscado){
            cout<<"Encontrado: "<<codigos[i]<<" | Promedio: "<<promedios[i]<<endl;
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout<<"Estudiante no encontrado."<<endl;
    }
}