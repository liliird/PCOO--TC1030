/*
 *
 * Proyecto Simulación de Banco
 * Lilian Rodríguez Uribe
 * A01711949
 * 14/06/2024
 * Esta clase define objeto de tipo Banco que contiene todas las operaciones
 * para agregar, eliminar y buscar clientes, esta clase es utilizada por la función principal del programa.
 */

#ifndef BANCO_H
#define BANCO_H
#include <string>
#include <iostream>
#include <vector>
#include "Cliente.h" //biblioteca con mis objetos a usar
using namespace std;


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

        /**Método que agrega un puntero a un objeto Cliente al vector clientes (agrega un cliente)
        */
        void agregarCliente(Cliente* cliente) {
            clientes.push_back(cliente);
        }
        /** Método que elimina un cliente del vector clientes según su id
        */
        void eliminarCliente(string id) {
            for (auto it = clientes.begin(); it != clientes.end(); ++it) {
                if ((*it)->getId() == id) {
                    delete *it;
                    clientes.erase(it);
                    cout << "Cliente eliminado correctamente." << endl;
                    return;
                }
            }
            cout << "Cliente no encontrado." << endl;
        }

        /**Método que busca un cliente por su id y si lo encuentra devuelve un puntero 
         *al cliente, si no devuelve nullptr
         */
        Cliente* buscarCliente(string id) const {
            for (const auto& cliente : clientes) {
                if (cliente->getId() == id) {
                    return cliente;
                }
            }
            return nullptr;
        }
        /**  Destructor de Banco que libera la memoria de todos los objetos Cliente
         * almacenados en el vector clientes
         */
        ~Banco() {
            for (auto cliente : clientes) {
                delete cliente;
            }
        }
};
#endif // BANCO_H_