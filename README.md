
# Driver para sensor de temperatura y humedad AHT10 para linux embebido

El repositorio se encuentran las fuentes del driver y la app 

## Archivos de repositorio 
1.Documentacion:Se encuentra la documentacion del sensor aht10

2.dts:Se encuentra el device tree source al cual se modifico para incluir nuestro device para la raspberry pi 2 

3.Sources:

    aht10_driver.c es el codigo del driver
    app_aht10.c :es la app para probar el driver 

## Compilacion del driver 
Para compilar el driver hay que hacer los siguientes pasos 

* Exportar algunas variables de entorno como:


    export ARCH=arm
    
    export CROSS_COMPILE=arm-linux-
    
    export PATH=$PATH:direccion de cross compilador para la arquitectura deseada

* Modificar variable KDIR del Makefile con la direcccion de los headers del kernel que se va a utilizar, luego hacer make 
