# TC1030 Simulador de banco
Lilian Rodríguez Uribe 
A01711949

Este proyecto modela una simulación de un banco, donde se pueden realizar operaciones desde un determinado banco. El banco tiene clientes y estos clientes pueden tener distintas cuentas de tipo Cuenta de ahorro o cuenta corriente, las cuales se diferencían porque la cuenta de ahorro tiene una tasas de interés y la cuenta corriente tiene un sobregiro para los retiros.

## Funcionalidad

El main consta de un menú con las posibles operaciones a realizar dentro del banco como crear, eliminar y consultar clientes, a su vez para cada cliente se pueden crear, eliminar y consultar los diferentes tipos de cuentas (cuenta de ahorro o cuenta corriente) y para cada cuenta se pueden realizar depósitos y/o retiros.

## Consideraciones
Compilar con: "g++ Banco.h Cliente.h Cuenta.h main.cpp"
correr en linux: "/a.out"
correr en windows: "a.exe"
