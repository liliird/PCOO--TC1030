/*
 *
 * Proyecto Simulación de Banco
 * Lilian Rodríguez Uribe
 * A01711949
 * 14/06/2024
 * Esta clase define Cliente que contiene todas las operaciones
 * para agregar, eliminar y buscar cuentas, esta clase es utilizada por la función principal del 
 * programa como vector de clientes.
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Cuenta.h"
using namespace std;

//Clase Cliente
class Cliente {
    private:
        string id;
        string nombre;
        string direccion;
        string telefono;
        vector<Cuenta*> cuentas;

    public:
        //Constructor de la clase Cliente
        Cliente(string id, string nombre, string direccion, string telefono)
        : id(id), nombre(nombre), direccion(direccion), telefono(telefono) {}
        //Método que agrega un puntero a un objeto Cuenta al vector cuentas
        void agregarCuenta(Cuenta* cuenta) {
            cuentas.push_back(cuenta);
        }

        //Método que elimina una cuenta del vector cuentas según su idCuenta
        void eliminarCuenta(string idCuenta) {
            for (auto it = cuentas.begin(); it != cuentas.end(); ++it) {
                if ((*it)->get_id() == idCuenta) {
                    delete *it;
                    cuentas.erase(it);
                    cout << "Cuenta eliminada correctamente." << endl;
                    return;
                }
            }
            cout << "Cuenta no encontrada." << endl;
        }

        
        //Método que imprime la información de todas las cuentas asociadas al cliente
        void consultarCuentas() const {
            //Se recorre el vector cuentas y se imprime su id y saldo
            for (const auto& cuenta : cuentas) {
                cout << "Cuenta ID: " << cuenta->get_id() << ", Saldo: " << cuenta->consultarSaldo() << cuenta->to_string()<< endl;
            }
        }
        //getters
        string getId(){
            return id;
        }
        string getNom(){
            return nombre;
        }
        string getDir(){
            return direccion;
        }
        string getTel(){
            return telefono;
        }
        //setters
        void setId(string newId){
            id= newId;
        } 
        void setNom(string newNom){
            nombre= newNom;
        } 
        void setDir(string newDir){
            direccion= newDir;
        } 
        void setTel(string newTel){
            telefono= newTel;
        } 

        // Método para obtener todas las cuentas del cliente
        const vector<Cuenta*>& getCuentas() const {
            return cuentas;
        }


        /*Destructor de Cliente que libera la memoria de todos los objetos Cuenta almacenados 
        * en el vector cuentas
        */
        ~Cliente() {
            for (auto cuenta : cuentas) {
                delete cuenta;
            }
        }
};
#endif //CLIENTE_H