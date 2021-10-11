 # TRABAJO PRACTICO - SplitApplyCombine
 
Alumno: Jesus Andres Correa Tornero

Padrón: 102310

Link : https://github.com/andy0013/TP2.git


# Introducción

  El trabajo practico en esta ocasion responde a solicitudes del usuario, estas solicitudes son basicamente operaciones matematicas sobre un
  dataset, el cual no nos es posible cargarlo en memoria, por esta razon es que vamos a ir cargando los datos de a particiones y resolviendo
  operaciones sobre las mismas.
  
# MODELO
 
 El modelado del TP fue la etapa mas complicada que se presento. Como se comento previamente, la ejecucion del problema depende de la solicitud
 del usuario, lo que indica, que debemos de leer esa informacion, y luego disparar la ejecucion. Sin embargo, por cuestiones de modelado, seria
 bastante intuitivo, entonces, leer solicitud, disparar ejecucion. Sin embargo, fue algo que genero bastante molestia, ya que, no es nada comodo
 tener un solo metodo, en el cual se realicen estas dos tareas, realmente seria mas comodo tenerlas de manera independiente.
 
 **Pregunta: considerando el dominio del problema mencionado, y ademas, sabiendo que cada analisis que se solicite sera distinto, pero no es probable
 que se soliciten mas de 100 peticiones, seria posible cargar en una cola TODAS las peticiones, y luego ejecutarlas una a una, logicamente
 con el orden de una cola?**
 
 De momento, para resolver el modelo, sin tomar la decision de utilizar una cola, el modelo actual es el presentado:
 
 ![modelo](imagenes/modelo.png)
 
 
 
  
