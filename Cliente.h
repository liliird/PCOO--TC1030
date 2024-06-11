#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
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
        // utiliza el algoritmo remove_if para encontar la cuenta indicada y eliminarla
        void eliminarCuenta(string idCuenta) {
            auto it = remove_if(cuentas.begin(), cuentas.end(), [&](Cuenta* cuenta) {
                return cuenta->get_id() == idCuenta;
            });
            if (it != cuentas.end()) {
                delete *it;
                cuentas.erase(it, cuentas.end());
            } else {
                cout << "Cuenta no encontrada." << endl;
            }
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

        //Destructor de Cliente que libera la memoria de todos los objetos Cuenta almacenados 
        // en el vector cuentas
        ~Cliente() {
            for (auto cuenta : cuentas) {
                delete cuenta;
            }
        }
};
#endif