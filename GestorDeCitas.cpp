#include <iostream>
#include <string>

using namespace std;

int main() {

    int opcion = 0;
    int opcionEspecialidad = 0;


    string nombrePaciente = "";
    int edadPaciente = 0;
    bool pacienteRegistrado = false;


    string nombreMedico = "";
    string especialidad = "";
    bool medicoRegistrado = false;

    int Edad_minima = 0;
    int Edad_maxima = 100;


MENU_PRINCIPAL:
    system("cls");
    cout << "\t--- CLINICAS MEDICAS TEGUCIGALPA ---" << endl;
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
        cout << "\t--- REGISTRO DE PACIENTE ---" << endl;
        cin.ignore();

        cout << "Nombre completo: ";
        getline(cin, nombrePaciente);

        cout << "Edad: ";
        cin >> edadPaciente;

        if (edadPaciente >= Edad_minima && edadPaciente <= Edad_maxima) {
            pacienteRegistrado = true;
            cout << "\n Paciente registrado correctamente." << endl;
        }
        else {
            pacienteRegistrado = false;
            cout << "\n Edad incorrecta" << endl;
        }

        system("pause");
        goto MENU_PRINCIPAL;
        break;

    case 2:
    {
        system("cls");
        cout << "\t--- REGISTRO DE MEDICO Y ESPECIALIDAD ---" << endl;
        cin.ignore();

        if (pacienteRegistrado == false) {
            cout << "\n Debe registrar los datos del paciente." << endl;
            system("pause");
            goto MENU_PRINCIPAL;
        }

        cout << "Nombre del Medico: ";
        getline(cin, nombreMedico);

        bool especialidadValida = false;

        while (especialidadValida == false) {
            cout << "\n Seleccione la Especialidad:" << endl;
            cout << "1. Medicina General" << endl;
            cout << "2. Pediatria " << endl;
            cout << "3. Cardiologia" << endl;
            cout << "4. Ortopedia" << endl;
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
                    cout << "\n El paciente tiene " << edadPaciente << " anios. Elija otra opcion.\n" << endl;
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
            else {
                cout << "\n Opcion incorrecta.\n" << endl;
            }
        }

        cout << "\n Medico registrado correctamente en " << especialidad << "." << endl;
        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }
    case 3:
        system("cls");
        cout << "\t--- ASIGNACION DE CITA ---" << endl;

        if (pacienteRegistrado == true && medicoRegistrado == true) {
            cout << "Cita asignada exitosamente:\n" << endl;
            cout << "PACIENTE: " << nombrePaciente << " (Edad: " << edadPaciente << ")" << endl;
            cout << "MEDICO ASIGNADO: Dr. " << nombreMedico << " (" << especialidad << ")" << endl;
        }
        else {
            cout << " Complete los datos necesarios para asignar la cita." << endl;

            // Uso del operador logico NOT (!)
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
        cout << "\n Opcion invalida. Intente de nuevo." << endl;
        system("pause");
        goto MENU_PRINCIPAL;
        break;
    }

    return 0;
}