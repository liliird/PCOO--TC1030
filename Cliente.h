#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Cuenta.h"
using namespace std;

class Cliente {
    private:
        string id;
        string nombre;
        string direccion;
        string telefono;
        vector<Cuenta*> cuentas;

    public:
        Cliente(string id, string nombre, string direccion, string telefono)
        : id(id), nombre(nombre), direccion(direccion), telefono(telefono) {}

        void agregarCuenta(Cuenta* cuenta) {
            cuentas.push_back(cuenta);
        }

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

        void consultarCuentas() const {
            for (const auto& cuenta : cuentas) {
                cout << "Cuenta ID: " << cuenta->get_id() << ", Saldo: " << cuenta->consultarSaldo() << endl;
            }
        }

        string getId(){
            return id;
        }

        ~Cliente() {
            for (auto cuenta : cuentas) {
                delete cuenta;
            }
        }
};
#endif