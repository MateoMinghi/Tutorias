#### Instalación y Uso de MinGW 

Desgraciadamente, una computadora no entiende C++ por sí sola. Por ello, se requiere de un compilador para correr los programas.

Un compilador es un programa que traduce el código de c++ a código de máquina. Simplificando las cosas, convierte nuestro archivo de C++ (.cpp) a un archivo ejecutable (.exe). El compilador más usado para correr programas en C++ es g++, que se encuentra dentro del ambiente de MinGW.

Para instalar MinGW:  https://sourceforge.net/projects/mingw/
Tutorial recomendado por Bengie: https://www.youtube.com/watch?v=fsmVbLMzBoo

 Una vez que se hagan bolas para instalarlo, se puede comprobar si se instaló correctamente corriendo este comando en la terminal:

 ```
 g++ --version
 ```

Si aparece la versión del compilador, está instalado correctamente. Si no, se hizo algo mal y no los culpo porque me tardé horas instalándolo.

Ahora vamos a correr un programita para ver su funcionamiento. En un folder creamos un archivo llamado "experimento.pp". Dentro del mismo pondremos el siguiente código:


