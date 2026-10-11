#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion = 0;
    int opcionEspecialidad = 0;
    int opcionSexoPaciente = 0;
    int opcionSexoMedico = 0;

    string identidadPaciente = "";
    string nombrePaciente = "";
    string sexoPaciente = "";
    string telefonoPaciente = "";
    int edadPaciente = 0;
    bool pacienteRegistrado = false;

    string identidadMedico = "";
    string nombreMedico = "";
    string sexoMedico = "";
    string especialidad = "";
    bool medicoRegistrado = false;

    int Edad_minima = 0;
    int Edad_maxima = 100;

MENU_PRINCIPAL:
    system("cls");
    cout << "--- CLINICAS MEDICAS TEGUCIGALPA ---" << endl;
    cout << "========================================" << endl;
    cout << "REGLAS DE ATENCION DE LA CLINICA:" << endl;
    cout << "1. Edad Permitida: Entre 0 y 100 anios." << endl;
    cout << "2. Pediatria: Solo menores de 18 anios (0 a 17 anios)." << endl;
    cout << "3. Prioridad: Embarazadas, Tercera Edad (60+) e Urgencias." << endl;
    cout << "4. Flujo Obligatorio: Registrar paciente antes del medico y la cita." << endl;
    cout << "========================================" << endl;
    cout << "1. Registrar Paciente" << endl;
    cout << "2. Registrar Medico y Especialidad" << endl;
    cout << "3. Asignar Cita" << endl;
    cout << "4. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 1:
        system("cls");
        cout << "--- REGISTRO DE PACIENTE ---" << endl;
        cin.ignore();

        cout << "Nombre completo: ";
        getline(cin, nombrePaciente);

        cout << "Numero de Identidad del Paciente: ";
        cin >> identidadPaciente;

        cout << "Edad: ";
        cin >> edadPaciente;

        if (edadPaciente >= Edad_minima && edadPaciente <= Edad_maxima) {
            bool sexoValido = false;
            while (sexoValido == false) {
                cout << "Seleccione el Sexo del Paciente:" << endl;
                cout << "1. Masculino" << endl;
                cout << "2. Femenino" << endl;
                cout << "Ingrese una opcion: ";
                cin >> opcionSexoPaciente;

                if (opcionSexoPaciente == 1) {
                    sexoPaciente = "Masculino";
                    sexoValido = true;
                }
                else if (opcionSexoPaciente == 2) {
                    sexoPaciente = "Femenino";
                    sexoValido = true;
                }
                else {
                    cout << "[Error] Opcion invalida. Intente de nuevo." << endl;
                }
            }

            cout << "Numero de telefono: ";
            cin >> telefonoPaciente;

            pacienteRegistrado = true;
            cout << "Paciente registrado correctamente." << endl;
        }
        else {
            pacienteRegistrado = false;
            cout << "Edad incorrecta" << endl;
        }

        system("pause");
        goto MENU_PRINCIPAL;
        break;

    case 2:
    {
        system("cls");
        cout << "--- REGISTRO DE MEDICO Y ESPECIALIDAD ---" << endl;
        cin.ignore();

        if (pacienteRegistrado == false) {
            cout << "Debe registrar los datos del paciente primero." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        cout << "Nombre del Medico: ";
        getline(cin, nombreMedico);

        cout << "Numero de Identidad del Medico: ";
        cin >> identidadMedico;

        bool sexoMedicoValido = false;
        while (sexoMedicoValido == false) {
            cout << "Seleccione el Sexo del Medico:" << endl;
            cout << "1. Masculino" << endl;
            cout << "2. Femenino" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcionSexoMedico;

            if (opcionSexoMedico == 1) {
                sexoMedico = "Masculino";
                sexoMedicoValido = true;
            }
            else if (opcionSexoMedico == 2) {
                sexoMedico = "Femenino";
                sexoMedicoValido = true;
            }
            else {
                cout << "[Error] Opcion invalida. Intente de nuevo." << endl;
            }
        }

        bool especialidadValida = false;

        while (especialidadValida == false) {
            cout << "Seleccione la Especialidad:" << endl;
            cout << "1. Medicina General" << endl;
            cout << "2. Pediatria" << endl;
            cout << "3. Cardiologia" << endl;
            cout << "4. Ortopedia" << endl;
            cout << "5. Ginecologia" << endl;
            cout << "Ingrese una opcion: ";
            cin >> opcionEspecialidad;

            if (opcionEspecialidad == 1) {
                especialidad = "Medicina General";
                medicoRegistrado = true;
                especialidadValida = true;
            }
            else if (opcionEspecialidad == 2) {
                if (edadPaciente >= 0 && edadPaciente <= 17) {
                    especialidad = "Pediatria";
                    medicoRegistrado = true;
                    especialidadValida = true;
                }
                else {
                    cout << "El paciente tiene " << edadPaciente << " anios. Pediatria es solo para menores de 18. Elija otra opcion." << endl;
                }
            }
            else if (opcionEspecialidad == 3) {
                especialidad = "Cardiologia";
                medicoRegistrado = true;
                especialidadValida = true;
            }
            else if (opcionEspecialidad == 4) {
                especialidad = "Ortopedia";
                medicoRegistrado = true;
                especialidadValida = true;
            }
            else if (opcionEspecialidad == 5) {
                if (sexoPaciente == "Femenino") {
                    especialidad = "Ginecologia";
                    medicoRegistrado = true;
                    especialidadValida = true;
                }
                else {
                    cout << "Ginecologia solo aplica para pacientes de sexo femenino. Elija otra opcion." << endl;
                }
            }
            else {
                cout << "Opcion incorrecta." << endl;
            }
        }

        cout << "Medico registrado correctamente en " << especialidad << "." << endl;
        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }
    case 3:
        system("cls");
        cout << "--- ASIGNACION DE CITA ---" << endl;

        if (pacienteRegistrado == true && medicoRegistrado == true) {
            cout << "Cita asignada exitosamente!" << endl;

            cout << "DETALLE DE TURNOS ACTIVOS:" << endl;
            cout << "--------------------------------------------------------------------------------------------------------" << endl;
            cout << " Turno | Identidad Paciente | Paciente           | Sexo P.   | Telefono   | Medico           | Especialidad     | Estado" << endl;
            cout << "--------------------------------------------------------------------------------------------------------" << endl;
            cout << " #1    | " << identidadPaciente << "     | " << nombrePaciente << " | " << sexoPaciente << " | " << telefonoPaciente << " | Dr(a). " << nombreMedico << " | " << especialidad << " | Pendiente" << endl;
            cout << "--------------------------------------------------------------------------------------------------------" << endl;
        }
        else {
            cout << "Complete los datos necesarios para asignar la cita." << endl;

            if (!pacienteRegistrado) {
                cout << "- El paciente no esta registrado o su edad es invalida." << endl;
            }
            if (!medicoRegistrado) {
                cout << "- No se ha registrado el medico de turno." << endl;
            }
        }

        system("pause");
        goto MENU_PRINCIPAL;
        break;

    case 4:
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