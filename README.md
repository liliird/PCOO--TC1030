# TC1030 Simulador de banco
Lilian Rodríguez Uribe 
A01711949

Este proyecto modela una simulación de un banco, donde se pueden realizar operaciones desde un determinado banco. El banco tiene clientes y estos clientes pueden tener distintas cuentas de tipo Cuenta de ahorro o cuenta corriente, las cuales se diferencían porque la cuenta de ahorro tiene una tasas de interés y la cuenta corriente tiene un sobregiro para los retiros.

## Funcionalidad

El main consta de un menú con las posibles operaciones a realizar dentro del banco como crear, eliminar y consultar clientes, a su vez para cada cliente se pueden crear, eliminar y consultar los diferentes tipos de cuentas (cuenta de ahorro o cuenta corriente) y para cada cuenta se pueden realizar depósitos y/o retiros, de este último movimiento, en el caso de la cuenta corriente, en caso de que el saldo no sea suficiente para el retiro, el usuario puede elegir si desea hacer uso del sobregiro. En el caso de la cuenta de ahorro, a la hora de realizar el retiro, el usuario puede consultar su interés hasta el momento.

## Consideraciones
Compilar con: "g++ Banco.h Cliente.h Cuenta.h main.cpp"
correr en linux: "/a.out"
correr en windows: "a.exe"
Es importante saber que es necesario crear un cliente y una cuenta para poder realizar movimientos en la misma, en caso de no tener alguno de estos dos, el ciclo indica que el usuario no fue encontrado, ya que para poder acceder a una cuenta, primero se ingresa al cliente y si el ciclo no lo encuentra, mandará el mensaje ya indicado.
Por ejemplo, si queremos realizar un depósito, primero debimos haber creado un cliente y posteriormente una cuenta del tipo de preferencia, de otra manera, veremos en pantalla el mensaje "Cliente no encontrado".
