#### Instalación y Uso de MinGW 

Desgraciadamente, una computadora no entiende C++ por sí sola. Por ello, se requiere de un compilador para correr los programas.

Un compilador es un programa que traduce el código de c++ a código de máquina. Simplificando las cosas, convierte nuestro archivo de C++ (.cpp) a un archivo ejecutable (.exe). El compilador más usado para correr programas en C++ es g++, que se encuentra dentro del ambiente de MinGW.

Para instalar MinGW:  https://sourceforge.net/projects/mingw/
Tutorial recomendado por Bengie: https://www.youtube.com/watch?v=fsmVbLMzBoo
Tutorial que yo recomiendo: https://www.youtube.com/watch?v=GEZLjRSY_m8

 Una vez que se hagan bolas para instalarlo, se puede comprobar si se instaló correctamente corriendo este comando en la terminal:

 ```
 g++ --version
 ```

Si aparece la versión del compilador, está instalado correctamente. Si no, se hizo algo mal y no los culpo porque me tardé horas instalándolo.

Ahora vamos a correr un programita para ver su funcionamiento. En un folder creamos un archivo llamado "experimento.cpp". Dentro del mismo pondremos el siguiente código:

```cpp
#include <iostream>


int main(){

std::cout << "Hello World";
return 0;
}
``` 

La idea es que el programa imprima el mensaje "Hello World". Un clásico.

Para correrlo, volvemos a la consola, y en el directorio en el que se encuentre el archivo "experimento.cpp" ponemos el siguiente comando:

 ```
g++ -o experimento experimento.cpp
 ```

Donde g++ es el compilador, "-o experimento" es un comando que indica cómo queremos que se llame el archivo ejecutable, y "experimento.cpp" es el nombre del archivo. Ojo, como instalamos MinGW, ahora contamos con el compilador para C y para C++. En los tutoriales es probable que en vez de usar el comando g++ usen gcc. NO debemos usar gcc, ese es el compilador para el lenguaje C, y no va a correr el programa.

Si al correr el comando de arriba no se arroja ningún problema en la consola, se crea un archivo .exe dentro del mismo folder con el nombre que le especificamos. Para correrlo, y ahora sí ver el funcionamiento del programa, es tan sencillo como poner el nombre del archivo en la consola:

 ```
experimento.exe
 ```

Se corre el archivo y se desplega el "Hello World" :)
