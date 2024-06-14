/*
 *
 * Proyecto Simulación de Banco
 * Lilian Rodríguez Uribe
 * A01711949
 * 14/06/2024
 * Esta clase define Cuenta que contiene todas las operaciones
 * para depositar, retirar, utilizar sobregiro, calcular interés y 
 * consultar saldo.
 * De igual forma esta clase contiene las clases heredadas CuentaCorriente
 * y CuentaAhorro.
 */

#ifndef CUENTA_H
#define CUENTA_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

//Declaro la clase Cuenta 
class Cuenta{
    //Declaro las variables protegidas
    protected:
        string idCuenta;
        double saldo;
        int des;
    //Declaro los metodos que va a tener el objeto
    public:
        Cuenta(): idCuenta(""), saldo(0){}; //Constructor por default
        Cuenta(string id, double sal, string tip): idCuenta(id), saldo(sal), tipo(tip){};
        
        //getters
        string get_id(){
            return idCuenta;
        }
        double get_saldo(){
            return saldo;
        }
    
        //setters
        void set_id(int newIdC){
            idCuenta= newIdC;
        }
        void set_saldo(double newSal){
            saldo= newSal;
        }

        /*Metodo virtual para consultar el sobregiro/tasa de interes
        */
        virtual string to_string() = 0;

        /*Metodo para depositar una cantidad en la cuenta
        */
        void depositar(double cantidad) {
        saldo += cantidad;
        }

        /*Metodo virtual para realizar un retiro de la cuenta
        */
        virtual void retirar(double cantidad) = 0;

        /*Metodo  para consultar el saldo de la cuenta
        */
        double consultarSaldo() const{
            return saldo;
        }

        //Destructor virtual por defecto
        virtual ~Cuenta() = default;
        
};
//Clase CuentaCorriente que hereda de Cuenta
class CuentaCorriente : public Cuenta {
    private:
        double sobregiro;

    public:
        //Constructor
        CuentaCorriente(string id, double saldoInicial, double sobregiroInicial) 
        : Cuenta(id, saldoInicial, "corriente"), sobregiro(sobregiroInicial) {}
        string to_string();
        void retirar(double cantidad);
        
        //Getter
        double getSobregiro(){
            return sobregiro;
        }
        //Setter
        void setSobregiro(double sobG){
            sobregiro=sobG;
        }
        /** Método que me permite usar el sobregiro. Permitiendo retirar una
         * cantidad mayor al saldo disponible, hasta el límite del sobregiro
         */
        
};

/**
 * to_string convierte a atributos a string.
 * Concatena todos los valores de los atributos en un string para ser impreso
 * en este caso es el sobregiro.
 */
string CuentaCorriente::to_string(){
    stringstream aux;
    aux << ", Sobregiro: " << sobregiro << "\n";
    return aux.str();
}

/**
 * Implementación del método virtual donde dependiendo de la cantidad deseada a retirar
 * se resta del saldo total o del sobregiro en caso que el saldo no sea suficiente y 
 * asi lo decida el ususario
*/
void CuentaCorriente::retirar(double cantidad ){
    if (cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retiro realizado correctamente." << endl;
        } else {
            cout << "Desea usar sobregiro? (Si=1 /No=2) ingrese un numero: "<< endl;
            cin >> des;
            if (des==1){
                if (cantidad <=  sobregiro) {
                sobregiro -= cantidad;
                } else {
                cout << "Sobregiro insuficiente." << endl;
                }
            }else{
                cout << "Saldo insuficiente." <<endl;
            }
            
        }
    
    
}
//Clase CuentaAhorro que hereda de Cuenta
class CuentaAhorro : public Cuenta {
    private:
        double tasaInteres;

    public:
        //Constructor
        CuentaAhorro(string id, double saldoInicial, double tasaInteres) 
        : Cuenta(id, saldoInicial, "ahorro"), tasaInteres(tasaInteres) {}
        string to_string();
        void retirar(double cantidad);

        //Getter
        double getTasaInteres(){
            return tasaInteres;
        }
        //Setter
        void setTasaInteres(double tasa){
            tasaInteres=tasa;
        }
        /**Método que calcula el interés en base al saldo y la tasa de interés
         */
        double calcularInteres() const {
            return saldo * tasaInteres;
        }
    
};

/**
 * to_string convierte a atributos a string.
 * Concatena todos los valores de los atributos en un string para ser impreso
 * en este caso es la tasa de interes.
 */
string CuentaAhorro::to_string(){
    stringstream aux;
    aux << ", Tasa de interes: " << tasaInteres << "\n";
    return aux.str();
}

/**
 * Implementación del método virtual donde se realiza la resta de la cantidad a retirar del saldo
 * Asi como tambien se le ofrece al usuario conocer su interes hasta el momento.
*/
void CuentaAhorro::retirar(double cantidad ){
    if (cantidad <= saldo){
        saldo -= cantidad;
        cout << "Retiro realizado correctamente" <<endl;
    }else{
        cout << "Saldo insuficiente" <<endl;
    }
    cout <<"Desea conocer su interes hasta ahora?(Si=1 /No=2) ingrese un numero: "<< endl;
    cin >> des;
    if (des==1){
        cout<<"Interes: " << saldo * tasaInteres<< endl;
    }else if(des!=1 && 2){
        cout<<"Valor invalido. " << endl;
    }
        
    }

#endif // CUENTA_H
        


