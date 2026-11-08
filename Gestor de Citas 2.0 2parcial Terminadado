#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int MaxPacientes = 20;
const int MaxMedicos = 10;
const int MaxCola = 20;

struct Paciente {
    string identidad = "";
    string nombre = "";
    string sexo = "";
    string telefono = "";
    int edad = 0;
    int estado = 0;
    int especialidad = -1;
    int medico = -1;
    int llegada = 0;
    int turno = 0;
};

struct Medico {
    string nombre = "";
    string sexo = "";
    int especialidad = 0;
};

struct ColaEspecialidad {
    int pacientes[MaxCola];
    int frente = 0;
    int cantidad = 0;
};

int main() {
    int TiempoConsulta = 15;
    int TiempoLlegada = 5;

    int opcion = 0;
    int opcionEspecialidad = 0;
    int opcionSexoPaciente = 0;
    int opcionSexoMedico = 0;
    int i = 0;
    int j = 0;

    Paciente pacientes[MaxPacientes];
    Paciente nuevoPaciente;
    int cantPacientes = 0;

    Medico medicos[MaxMedicos];
    Medico nuevoMedico;
    int cantMedicos = 0;

    string nombreEspecialidad[5] = { "Medicina General", "Pediatria", "Cardiologia", "Ortopedia", "Ginecologia" };
    ColaEspecialidad colas[5];

    int reloj = 0;
    int contadorTurnos = 0;
    int totalCitas = 0;
    int totalAtendidos = 0;
    int totalCancelados = 0;
    int totalReasignados = 0;
    int sumaEspera = 0;

    string identidadTmp = "";
    int posicion = -1;
    int posicionCola = -1;
    int esp = 0;
    int medicoEncontrado = -1;
    int espera = 0;
    int p = 0;
    bool sexoValido = false;
    bool sexoMedicoValido = false;
    bool especialidadValida = false;
    bool permitido = false;

    int Edad_minima = 0;
    int Edad_maxima = 100;

MENU_PRINCIPAL:
    system("cls");
    cout << "--- CLINICAS MEDICAS TEGUCIGALPA ---" << endl;
    cout << endl;
    cout << "REGLAS DE ATENCION DE LA CLINICA:" << endl;
    cout << "-. Edad Permitida: Entre 0 y 100 anios." << endl;
    cout << "-. Pediatria: " << endl;
    cout << "-. Prioridad: Embarazadas, Tercera Edad (60+) e Urgencias." << endl;
    cout << ". Flujo Obligatorio: Registrar paciente antes del medico y la cita." << endl;
    cout << endl;
    cout << "1. Registrar Paciente" << endl;
    cout << "2. Registrar Medico y Especialidad" << endl;
    cout << "3. Asignar Cita" << endl;
    cout << "4. Atender Siguiente Paciente" << endl;
    cout << "5. Ver Colas por Especialidad" << endl;
    cout << "6. Buscar Paciente" << endl;
    cout << "7. Cancelar Cita" << endl;
    cout << "8. Reasignar Cita" << endl;
    cout << "9. Indicadores" << endl;
    cout << "10. Salir" << endl;
    cout << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
    {
        system("cls");
        cout << "--- REGISTRO DE PACIENTE ---" << endl;

        if (cantPacientes >= MaxPacientes) {
            cout << "Se alcanzo el limite de pacientes." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        nuevoPaciente = Paciente();
        cin.ignore();

        cout << "Nombre completo: ";
        getline(cin, nuevoPaciente.nombre);

        cout << "Numero de Identidad del Paciente: ";
        cin >> nuevoPaciente.identidad;

        posicion = -1;
        for (i = 0; i < cantPacientes; i++) {
            if (pacientes[i].identidad == nuevoPaciente.identidad) {
                posicion = i;
            }
        }
        if (posicion != -1) {
            cout << "Ya existe un paciente con esa identidad." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        cout << "Edad: ";
        cin >> nuevoPaciente.edad;

        if (nuevoPaciente.edad >= Edad_minima && nuevoPaciente.edad <= Edad_maxima) {
            sexoValido = false;
            while (sexoValido == false) {
                cout << "Seleccione el Sexo del Paciente:" << endl;
                cout << "1. Masculino" << endl;
                cout << "2. Femenino" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcionSexoPaciente;

                if (opcionSexoPaciente == 1) {
                    nuevoPaciente.sexo = "Masculino";
                    sexoValido = true;
                }
                else if (opcionSexoPaciente == 2) {
                    nuevoPaciente.sexo = "Femenino";
                    sexoValido = true;
                }
                else {
                    cout << " Dato incorrecto." << endl;
                }
            }

            cout << "Numero de telefono: ";
            cin >> nuevoPaciente.telefono;

            pacientes[cantPacientes] = nuevoPaciente;
            cantPacientes++;

            cout << "Paciente registrado correctamente." << endl;
        }
        else {
            cout << "Edad incorrecta" << endl;
        }

        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 2:
    {
        system("cls");
        cout << "--- REGISTRO DE MEDICO Y ESPECIALIDAD ---" << endl;

        if (cantPacientes == 0) {
            cout << "Debe registrar los datos del paciente primero." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        if (cantMedicos >= MaxMedicos) {
            cout << "Se alcanzo el limite de medicos." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        nuevoMedico = Medico();
        cin.ignore();

        cout << "Nombre del Medico: ";
        getline(cin, nuevoMedico.nombre);

        sexoMedicoValido = false;
        while (sexoMedicoValido == false) {
            cout << "Seleccione el Sexo del Medico:" << endl;
            cout << "1. Masculino" << endl;
            cout << "2. Femenino" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcionSexoMedico;

            if (opcionSexoMedico == 1) {
                nuevoMedico.sexo = "Masculino";
                sexoMedicoValido = true;
            }
            else if (opcionSexoMedico == 2) {
                nuevoMedico.sexo = "Femenino";
                sexoMedicoValido = true;
            }
            else {
                cout << " Opcion incorrecta. " << endl;
            }
        }

        especialidadValida = false;
        while (especialidadValida == false) {
            cout << "Seleccione la Especialidad:" << endl;
            cout << "1. Medicina General" << endl;
            cout << "2. Pediatria" << endl;
            cout << "3. Cardiologia" << endl;
            cout << "4. Ortopedia" << endl;
            cout << "5. Ginecologia" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcionEspecialidad;

            if (opcionEspecialidad >= 1 && opcionEspecialidad <= 5) {
                especialidadValida = true;
            }
            else {
                cout << "Opcion incorrecta." << endl;
            }
        }

        nuevoMedico.especialidad = opcionEspecialidad - 1;
        medicos[cantMedicos] = nuevoMedico;
        cantMedicos++;

        cout << "Medico registrado correctamente en " << nombreEspecialidad[opcionEspecialidad - 1] << "." << endl;
        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 3:
    {
        system("cls");
        cout << "--- ASIGNACION DE CITA ---" << endl;

        if (cantPacientes == 0 || cantMedicos == 0) {
            cout << "Complete los datos necesarios para asignar la cita." << endl;
            if (cantPacientes == 0) {
                cout << "- No hay pacientes registrados." << endl;
            }
            if (cantMedicos == 0) {
                cout << "- No se ha registrado el medico de turno." << endl;
            }
            system("pause");
            goto MENU_PRINCIPAL;
        }

        cout << "Identidad del paciente: ";
        cin >> identidadTmp;

        posicion = -1;
        for (i = 0; i < cantPacientes; i++) {
            if (pacientes[i].identidad == identidadTmp) {
                posicion = i;
            }
        }

        if (posicion == -1) {
            cout << "Paciente no encontrado." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        if (pacientes[posicion].estado == 1) {
            cout << "El paciente ya tiene una cita en espera." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        especialidadValida = false;
        while (especialidadValida == false) {
            cout << "Seleccione la Especialidad:" << endl;
            cout << "1. Medicina General" << endl;
            cout << "2. Pediatria" << endl;
            cout << "3. Cardiologia" << endl;
            cout << "4. Ortopedia" << endl;
            cout << "5. Ginecologia" << endl;
            cout << "0. Volver" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcionEspecialidad;

            if (opcionEspecialidad == 0) {
                goto MENU_PRINCIPAL;
            }

            if (opcionEspecialidad < 1 || opcionEspecialidad > 5) {
                cout << "Opcion incorrecta." << endl;
            }
            else {
                esp = opcionEspecialidad - 1;
                permitido = true;

                if (opcionEspecialidad == 2 && pacientes[posicion].edad > 17) {
                    cout << "El paciente tiene " << pacientes[posicion].edad << " anios. Pediatria es solo para menores de 18. Elija otra opcion." << endl;
                    permitido = false;
                }
                if (opcionEspecialidad == 5 && pacientes[posicion].sexo != "Femenino") {
                    cout << "Ginecologia solo aplica para pacientes de sexo femenino. Elija otra opcion." << endl;
                    permitido = false;
                }

                if (permitido == true) {
                    medicoEncontrado = -1;
                    for (i = 0; i < cantMedicos; i++) {
                        if (medicos[i].especialidad == esp && medicoEncontrado == -1) {
                            medicoEncontrado = i;
                        }
                    }
                    if (medicoEncontrado == -1) {
                        cout << "No hay medico registrado en " << nombreEspecialidad[esp] << ". Elija otra opcion." << endl;
                    }
                    else if (colas[esp].cantidad >= MaxCola) {
                        cout << "La cola de " << nombreEspecialidad[esp] << " esta llena. Elija otra opcion." << endl;
                    }
                    else {
                        especialidadValida = true;
                    }
                }
            }
        }

        reloj = reloj + TiempoLlegada;
        contadorTurnos++;
        totalCitas++;

        colas[esp].pacientes[(colas[esp].frente + colas[esp].cantidad) % MaxCola] = posicion;
        colas[esp].cantidad++;

        pacientes[posicion].estado = 1;
        pacientes[posicion].especialidad = esp;
        pacientes[posicion].medico = medicoEncontrado;
        pacientes[posicion].llegada = reloj;
        pacientes[posicion].turno = contadorTurnos;

        cout << "Cita asignada exitosamente!" << endl;
        cout << "DETALLE DE TURNOS ACTIVOS:" << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << " Turno | Identidad Paciente | Paciente           | Sexo P.   | Telefono   | Medico           | Especialidad     | Estado" << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << " #" << pacientes[posicion].turno << "    | " << pacientes[posicion].identidad << "     | " << pacientes[posicion].nombre << " | " << pacientes[posicion].sexo << " | " << pacientes[posicion].telefono << " | Dr(a). " << medicos[medicoEncontrado].nombre << " | " << nombreEspecialidad[esp] << " | Pendiente" << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << "Posicion en la cola: " << colas[esp].cantidad << endl;
        cout << "Tiempo estimado de espera: " << (colas[esp].cantidad - 1) * TiempoConsulta << " minutos." << endl;

        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 4:
    {
        system("cls");
        cout << "--- ATENDER SIGUIENTE PACIENTE ---" << endl;

        cout << "1. Medicina General" << endl;
        cout << "2. Pediatria" << endl;
        cout << "3. Cardiologia" << endl;
        cout << "4. Ortopedia" << endl;
        cout << "5. Ginecologia" << endl;
        cout << "Seleccione la cola a atender: ";
        cin >> opcionEspecialidad;

        if (opcionEspecialidad < 1 || opcionEspecialidad > 5) {
            cout << "Opcion incorrecta." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        esp = opcionEspecialidad - 1;

        if (colas[esp].cantidad == 0) {
            cout << "No hay pacientes en espera en " << nombreEspecialidad[esp] << "." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        p = colas[esp].pacientes[colas[esp].frente];
        colas[esp].frente = (colas[esp].frente + 1) % MaxCola;
        colas[esp].cantidad--;

        espera = reloj - pacientes[p].llegada;
        sumaEspera = sumaEspera + espera;
        totalAtendidos++;
        pacientes[p].estado = 2;
        reloj = reloj + TiempoConsulta;

        cout << "Atendiendo turno #" << pacientes[p].turno << endl;
        cout << "Paciente: " << pacientes[p].nombre << endl;
        cout << "Medico: Dr(a). " << medicos[pacientes[p].medico].nombre << endl;
        cout << "Especialidad: " << nombreEspecialidad[esp] << endl;
        cout << "Tiempo de espera: " << espera << " minutos." << endl;

        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 5:
    {
        system("cls");
        cout << "--- COLAS POR ESPECIALIDAD ---" << endl;

        for (i = 0; i < 5; i++) {
            cout << endl;
            cout << nombreEspecialidad[i] << " (" << colas[i].cantidad << " en espera)" << endl;

            if (colas[i].cantidad == 0) {
                cout << "   Cola vacia." << endl;
            }
            else {
                for (j = 0; j < colas[i].cantidad; j++) {
                    p = colas[i].pacientes[(colas[i].frente + j) % MaxCola];
                    cout << "   " << j + 1 << ". Turno #" << pacientes[p].turno << " | " << pacientes[p].nombre << " | " << pacientes[p].identidad << " | Dr(a). " << medicos[pacientes[p].medico].nombre << " | Espera aprox: " << j * TiempoConsulta << " min" << endl;
                }
            }
        }
        cout << endl;

        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 6:
    {
        system("cls");
        cout << "--- BUSCAR PACIENTE ---" << endl;

        if (cantPacientes == 0) {
            cout << "No hay pacientes registrados." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        cout << "Identidad del paciente: ";
        cin >> identidadTmp;

        posicion = -1;
        for (i = 0; i < cantPacientes; i++) {
            if (pacientes[i].identidad == identidadTmp) {
                posicion = i;
            }
        }

        if (posicion == -1) {
            cout << "Paciente no encontrado." << endl;
        }
        else {
            cout << "Nombre: " << pacientes[posicion].nombre << endl;
            cout << "Identidad: " << pacientes[posicion].identidad << endl;
            cout << "Edad: " << pacientes[posicion].edad << endl;
            cout << "Sexo: " << pacientes[posicion].sexo << endl;
            cout << "Telefono: " << pacientes[posicion].telefono << endl;

            if (pacientes[posicion].estado == 0) {
                cout << "Estado: Sin cita asignada." << endl;
            }
            else {
                esp = pacientes[posicion].especialidad;
                cout << "Turno: #" << pacientes[posicion].turno << endl;
                cout << "Especialidad: " << nombreEspecialidad[esp] << endl;
                cout << "Medico: Dr(a). " << medicos[pacientes[posicion].medico].nombre << endl;

                if (pacientes[posicion].estado == 1) {
                    posicionCola = 0;
                    for (j = 0; j < colas[esp].cantidad; j++) {
                        if (colas[esp].pacientes[(colas[esp].frente + j) % MaxCola] == posicion) {
                            posicionCola = j + 1;
                        }
                    }
                    cout << "Estado: Pendiente (posicion " << posicionCola << " en la cola)." << endl;
                    cout << "Tiempo estimado de espera: " << (posicionCola - 1) * TiempoConsulta << " minutos." << endl;
                }
                else if (pacientes[posicion].estado == 2) {
                    cout << "Estado: Atendido." << endl;
                }
                else {
                    cout << "Estado: Cancelado." << endl;
                }
            }
        }

        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 7:
    {
        system("cls");
        cout << "--- CANCELAR CITA ---" << endl;

        cout << "Identidad del paciente: ";
        cin >> identidadTmp;

        posicion = -1;
        for (i = 0; i < cantPacientes; i++) {
            if (pacientes[i].identidad == identidadTmp) {
                posicion = i;
            }
        }

        if (posicion == -1) {
            cout << "Paciente no encontrado." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        if (pacientes[posicion].estado != 1) {
            cout << "El paciente no tiene una cita en espera." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        esp = pacientes[posicion].especialidad;

        posicionCola = -1;
        for (j = 0; j < colas[esp].cantidad; j++) {
            if (colas[esp].pacientes[(colas[esp].frente + j) % MaxCola] == posicion) {
                posicionCola = j;
            }
        }

        for (j = posicionCola; j < colas[esp].cantidad - 1; j++) {
            colas[esp].pacientes[(colas[esp].frente + j) % MaxCola] = colas[esp].pacientes[(colas[esp].frente + j + 1) % MaxCola];
        }
        colas[esp].cantidad--;

        pacientes[posicion].estado = 3;
        totalCancelados++;

        cout << "Cita del turno #" << pacientes[posicion].turno << " cancelada correctamente." << endl;

        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 8:
    {
        system("cls");
        cout << "--- REASIGNAR CITA ---" << endl;

        cout << "Identidad del paciente: ";
        cin >> identidadTmp;

        posicion = -1;
        for (i = 0; i < cantPacientes; i++) {
            if (pacientes[i].identidad == identidadTmp) {
                posicion = i;
            }
        }

        if (posicion == -1) {
            cout << "Paciente no encontrado." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        if (pacientes[posicion].estado != 1) {
            cout << "El paciente no tiene una cita en espera." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        cout << "Especialidad actual: " << nombreEspecialidad[pacientes[posicion].especialidad] << endl;

        especialidadValida = false;
        while (especialidadValida == false) {
            cout << "Seleccione la nueva Especialidad:" << endl;
            cout << "1. Medicina General" << endl;
            cout << "2. Pediatria" << endl;
            cout << "3. Cardiologia" << endl;
            cout << "4. Ortopedia" << endl;
            cout << "5. Ginecologia" << endl;
            cout << "0. Volver" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcionEspecialidad;

            if (opcionEspecialidad == 0) {
                goto MENU_PRINCIPAL;
            }

            if (opcionEspecialidad < 1 || opcionEspecialidad > 5) {
                cout << "Opcion incorrecta." << endl;
            }
            else {
                esp = opcionEspecialidad - 1;
                permitido = true;

                if (esp == pacientes[posicion].especialidad) {
                    cout << "El paciente ya esta en esa especialidad. Elija otra opcion." << endl;
                    permitido = false;
                }
                if (opcionEspecialidad == 2 && pacientes[posicion].edad > 17) {
                    cout << "El paciente tiene " << pacientes[posicion].edad << " anios. Pediatria es solo para menores de 18. Elija otra opcion." << endl;
                    permitido = false;
                }
                if (opcionEspecialidad == 5 && pacientes[posicion].sexo != "Femenino") {
                    cout << "Ginecologia solo aplica para pacientes de sexo femenino. Elija otra opcion." << endl;
                    permitido = false;
                }

                if (permitido == true) {
                    medicoEncontrado = -1;
                    for (i = 0; i < cantMedicos; i++) {
                        if (medicos[i].especialidad == esp && medicoEncontrado == -1) {
                            medicoEncontrado = i;
                        }
                    }
                    if (medicoEncontrado == -1) {
                        cout << "No hay medico registrado en " << nombreEspecialidad[esp] << ". Elija otra opcion." << endl;
                    }
                    else if (colas[esp].cantidad >= MaxCola) {
                        cout << "La cola de " << nombreEspecialidad[esp] << " esta llena. Elija otra opcion." << endl;
                    }
                    else {
                        especialidadValida = true;
                    }
                }
            }
        }

        p = pacientes[posicion].especialidad;

        posicionCola = -1;
        for (j = 0; j < colas[p].cantidad; j++) {
            if (colas[p].pacientes[(colas[p].frente + j) % MaxCola] == posicion) {
                posicionCola = j;
            }
        }

        for (j = posicionCola; j < colas[p].cantidad - 1; j++) {
            colas[p].pacientes[(colas[p].frente + j) % MaxCola] = colas[p].pacientes[(colas[p].frente + j + 1) % MaxCola];
        }
        colas[p].cantidad--;

        colas[esp].pacientes[(colas[esp].frente + colas[esp].cantidad) % MaxCola] = posicion;
        colas[esp].cantidad++;

        pacientes[posicion].especialidad = esp;
        pacientes[posicion].medico = medicoEncontrado;
        totalReasignados++;

        cout << "Cita reasignada a " << nombreEspecialidad[esp] << " con Dr(a). " << medicos[medicoEncontrado].nombre << "." << endl;
        cout << "Posicion en la nueva cola: " << colas[esp].cantidad << endl;

        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 9:
    {
        system("cls");
        cout << "--- INDICADORES ---" << endl;
        cout << endl;
        cout << "Pacientes registrados: " << cantPacientes << endl;
        cout << "Medicos registrados: " << cantMedicos << endl;
        cout << "Citas asignadas: " << totalCitas << endl;
        cout << "Pacientes atendidos: " << totalAtendidos << endl;
        cout << "Citas canceladas: " << totalCancelados << endl;
        cout << "Citas reasignadas: " << totalReasignados << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pacientes en espera por especialidad:" << endl;

        for (i = 0; i < 5; i++) {
            cout << "   " << nombreEspecialidad[i] << ": " << colas[i].cantidad;
            if (colas[i].cantidad > 0) {
                cout << " (ultimo espera aprox. " << (colas[i].cantidad - 1) * TiempoConsulta << " min)";
            }
            cout << endl;
        }

        cout << "----------------------------------------" << endl;
        if (totalAtendidos > 0) {
            cout << "Tiempo promedio de espera: " << (double)sumaEspera / totalAtendidos << " minutos." << endl;
        }
        else {
            cout << "Tiempo promedio de espera: aun no hay pacientes atendidos." << endl;
        }
        cout << "Tiempo transcurrido de la jornada: " << reloj << " minutos." << endl;
        cout << endl;

        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    case 10:
        system("cls");
        cout << "Gracias, Feliz Dia!" << endl;
        break;

    default:
        cout << "Opcion invalida. Intente de nuevo." << endl;
        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    return 0;
}
