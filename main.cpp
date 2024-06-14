/*
 *
 * Proyecto Simulación de Banco
 * Lilian Rodríguez Uribe
 * A01711949
 * 14/06/2024
 * 
 * Este proyecto es para la clase TC1030 Programación Orientada a
 * Objetos. Es un programa que captura clientes en un banco con 
 * sus respectivas cuentas bancarias, y le permite al usuario realizar 
 * movimientos como un depósito, retiro, y consulta de saldo.
 */

#include "Banco.h" // bibliotecas con objetos de mi proyecto.
#include "Cliente.h"
#include "Cuenta.h"
#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "Menu del Banco" << endl;
    cout << "1. Agregar Cliente" << endl;
    cout << "2. Eliminar Cliente" << endl;
    cout << "3. Buscar Cliente" << endl;
    cout << "4. Agregar Cuenta a Cliente" << endl;
    cout << "5. Eliminar Cuenta de Cliente" << endl;
    cout << "6. Consultar Cuentas de Cliente" << endl;
    cout << "7. Realizar depósito a Cuenta" << endl;
    cout << "8. Realizar retiro de Cuenta" << endl;
    cout << "9. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    Banco banco("Mi Banco");
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1: {
                string id, nombre, direccion, telefono;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                cout << "Ingrese nombre del cliente: ";
                cin >> nombre;
                cout << "Ingrese direccion del cliente: ";
                cin >> direccion;
                cout << "Ingrese telefono del cliente: ";
                cin >> telefono;
                Cliente* cliente = new Cliente(id, nombre, direccion, telefono);
                banco.agregarCliente(cliente);
                cout << "Cliente agregado correctamente." << endl;
                break;
            }
            case 2: {
                string id;
                cout << "Ingrese ID del cliente a eliminar: ";
                cin >> id;
                banco.eliminarCliente(id);
                break;
            }
            case 3: {
                string id;
                cout << "Ingrese ID del cliente a buscar: ";
                cin >> id;
                Cliente* cliente = banco.buscarCliente(id);
                if (cliente) {
                    cout << "Cliente encontrado: " << cliente->getNom() << endl;
                } else {
                    cout << "Cliente no encontrado." << endl;
                }
                break;
            }
            case 4: {
                string clienteId;
                cout << "Ingrese ID del cliente: ";
                cin >> clienteId;
                Cliente* cliente = banco.buscarCliente(clienteId);
                if (cliente) {
                    int tipoCuenta;
                    cout << "Seleccione tipo de cuenta (1. Corriente, 2. Ahorro): ";
                    cin >> tipoCuenta;
                    string idCuenta;
                    double saldoInicial, extra;
                    cout << "Ingrese ID de la cuenta: ";
                    cin >> idCuenta;
                    cout << "Ingrese saldo inicial: ";
                    cin >> saldoInicial;
                    if (tipoCuenta == 1) {
                        cout << "Ingrese sobregiro: ";
                        cin >> extra;
                        CuentaCorriente* cuenta = new CuentaCorriente(idCuenta, saldoInicial, extra);
                        cliente->agregarCuenta(cuenta);
                    } else if (tipoCuenta == 2) {
                        cout << "Ingrese tasa de interes: ";
                        cin >> extra;
                        CuentaAhorro* cuenta = new CuentaAhorro(idCuenta, saldoInicial, extra);
                        cliente->agregarCuenta(cuenta);
                    }
                    cout << "Cuenta agregada correctamente." << endl;
                } else {
                    cout << "Cliente no encontrado." << endl;
                }
                break;
            }
            case 5: {
                string clienteId, idCuenta;
                cout << "Ingrese ID del cliente: ";
                cin >> clienteId;
                Cliente* cliente = banco.buscarCliente(clienteId);
                if (cliente) {
                    cout << "Ingrese ID de la cuenta a eliminar: ";
                    cin >> idCuenta;
                    cliente->eliminarCuenta(idCuenta);
                } else {
                    cout << "Cliente no encontrado." << endl;
                }
                break;
            }
            case 6: {
                string clienteId;
                cout << "Ingrese ID del cliente: ";
                cin >> clienteId;
                Cliente* cliente = banco.buscarCliente(clienteId);
                if (cliente) {
                    cliente->consultarCuentas();
                } else {
                    cout << "Cliente no encontrado." << endl;
                }
                break;
            }
            case 7: {
                string clienteId, idCuenta;
                double cantidad;
                cout << "Ingrese ID del cliente: ";
                cin >> clienteId;
                Cliente* cliente = banco.buscarCliente(clienteId);
                if (cliente) {
                    cout << "Ingrese ID de la cuenta: ";
                    cin >> idCuenta;
                    cout << "Ingrese la cantidad a depositar: ";
                    cin >> cantidad;
                    for (Cuenta* cuenta : cliente->getCuentas()) {
                        if (cuenta->get_id() == idCuenta) {
                            cuenta->depositar(cantidad);
                            cout << "Deposito realizado correctamente." << endl;
                            break;
                        }
                    }
                } else {
                    cout << "Cliente no encontrado." << endl;
                }
                break;
            }
            case 8: {
                string clienteId, idCuenta;
                double cantidad;
                cout << "Ingrese ID del cliente: ";
                cin >> clienteId;
                Cliente* cliente = banco.buscarCliente(clienteId);
                if (cliente) {
                    cout << "Ingrese ID de la cuenta: ";
                    cin >> idCuenta;
                    cout << "Ingrese la cantidad a retirar: ";
                    cin >> cantidad;
                    for (Cuenta* cuenta : cliente->getCuentas()) {
                        if (cuenta->get_id() == idCuenta) {
                            cuenta->retirar(cantidad);
                            
                            break;
                        }
                    }
                } else {
                    cout << "Cliente no encontrado." << endl;
                }
                break;
            }
            case 9:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
        cout << endl;
    } while(opcion != 9);

    return 0;
}
