#ifndef BANCO_H
#define BANCO_H
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Cliente.h"
using namespace std;

class Banco {
    private:
        string nombre;
        vector<Cliente*> clientes;

    public:
        Banco(string nombre) : nombre(nombre) {}

        void agregarCliente(Cliente* cliente) {
            clientes.push_back(cliente);
        }

        void eliminarCliente(string id) {
            auto it = remove_if(clientes.begin(), clientes.end(), [&](Cliente* cliente) {
                return cliente->getId() == id;
            });
            if (it != clientes.end()) {
                delete *it;
                clientes.erase(it, clientes.end());
            } else {
                cout << "Cliente no encontrado." << endl;
            }
        }

        Cliente* buscarCliente(string id) const {
            for (const auto& cliente : clientes) {
                if (cliente->getId() == id) {
                    return cliente;
                }
            }
            return nullptr;
        }

        ~Banco() {
            for (auto cliente : clientes) {
                delete cliente;
            }
        }
};
#endif