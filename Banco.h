#ifndef BANCO_H
#define BANCO_H
#include <string>
#include <iostream>
//#include <sstream>
#include <vector>
#include <algorithm>
#include "Cliente.h"
using namespace std;

//Clase Banco
class Banco {
    private:
        //Variables privadas nombre y vector cliente que es un vector 
        //de punteros a objetos Cliente
        string nombre;
        vector<Cliente*> clientes;

    public:
        //Constructor de la clase 
        Banco(string nombre) : nombre(nombre) {}

        //getter
        string getNom(){
            return nombre;
        }
        //setter
        void setNom(string newNom){
            nombre= newNom;
        }

        //Método que agrega un puntero a un objeto Cliente al vector clientes
        void agregarCliente(Cliente* cliente) {
            clientes.push_back(cliente);
        }
        //Método que elimina un cliente del vector clientes según su id
        void eliminarCliente(string id) {
            //El algoritmo remove_if reordena el vector clientes, moviendo los clientes
            // de los cuales coincide el id proporcionado al final
            auto it = remove_if(clientes.begin(), clientes.end(), [&](Cliente* cliente) {
                return cliente->getId() == id;
            });
            //Ciclo que verifica si se encontró un cliente con el id proporcionado
            if (it != clientes.end()) {
                //Si la condición se cumple, se libera la memoria del cliente y se 
                // elimina el cliente del vector clientes
                delete *it;
                clientes.erase(it, clientes.end());
            } else {
                cout << "Cliente no encontrado." << endl;
            }
        }
        //Método que busca un cliente por su id y si lo encuentra devuelve un puntero 
        // al cliente, si no devuelve nullptr
        Cliente* buscarCliente(string id) const {
            for (const auto& cliente : clientes) {
                if (cliente->getId() == id) {
                    return cliente;
                }
            }
            return nullptr;
        }
        // Destructor de Banco que libera la memoria de todos los objetos Cliente
        // almacenados en el vector clientes
        ~Banco() {
            for (auto cliente : clientes) {
                delete cliente;
            }
        }
};
#endif
