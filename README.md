# C++
Para cualquier estudiante que haya tendio asesorías conmigo...


# Programación Orientada a Objetos

La Programación Orientada a Objetos (POO) es un paradigma de programación en el cual los propios objetos que estemos abstrayendo del mundo real tienen datos y realizan cosas.

Para ello, primero tenemos que entender el concepto de clase.

Una *clase* es la plantilla de un objeto. Contiene todos los detalles y datos del objeto, los cuales llamaremos *atributos*. 

Por otro lado, utilizaremos *métodos* para trabajar con esos atributos. Un método es una función. No hay más.
Los métodos representan el comportamiento de los objetos y pueden modificar los atributos de la instancia o realizar acciones más complejas.

### ¿Qué es un objeto?

Los objetos son instancias concretas de una clase que representan entidades específicas. Podemos entender las instancias como las transformaciones de clase a objeto. Para ello necesitamos los constructores. 

Tomemos como ejemplo un programa que construye triángulos. Primero necesitamos generar los puntos que compondrán el triángulo: 

```cpp
// importamos las librerias
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

// definimos la clase punto
class Punto{
public:
  double x{}, y{};
  double angulo_radianes{}, angulo{};
  string etiqueta{}, cuadrante{};
``` 

Un punto se identifica por sus coordenadas en los ejes (x,y). Los demás atributos nos ayudarán a determinar si tres puntos generan un triángulo válido.

Nótese cómo establecemos los atributos de la clase como públicos. En otros casos se pueden establecer como privados y hacer uso de la encapsulación. La encapsulación es un concepto de la POO que implica ocultar los detalles internos de la implementación de una clase y exponer solo lo necesario. 
Se logra mediante la definición de atributos y/o métodos como privados o públicos. Aquellos atributos que sean privados se deberán acceder y modeificar por medio de métodos llamados *getters* y *setters*


### Constructores:

Los constructores son métodos especiales utilizados para inicializar los atributos de un objeto cuando se crea una nueva instancia de la clase.
Ayudan a establecer un estado inicial coherente para el objeto.

Existen constructores por omisión y parametrados. Por motivos educativos, en este programa utilizamos los dos:

```cpp
    Punto(); // por omisión
    Punto(double X, double Y, string e); //parametrado
```
Note cómo el constructor tiene que tener exactamente el mismo nombre que la clase. También vale la pena resaltar que esta es meramente la definición de los constructores. Es buena práctica dejar dentro de la clase solamente las definiciones de los constructores y los métodos; y las implementaciones afuera de ellas. Incluso lo ideal es separar las definiciones en documentos .h, tal y como se muestra en la Actividad05 en el repositorio.

```cpp
class Punto{
public:
  double x{}, y{};
  double angulo_radianes{}, angulo{};
  string etiqueta{}, cuadrante{};

  Punto();
  Punto(double X, double Y, string e);

  void determinaCuadrante();
  void calculaAngulo();
  void imprimePunto();
  void imprimeInfo(); 
};
```
La definición de nuestra clase "Punto está terminada". Ahora sí vamos a completar los constructores para crear los puntos:

```cpp
Punto::Punto(){
  cout << "ingrese la coordenada en x: ";
  cin >> x;
  cout << "ingrese la coordenada en y: ";
  cin >> y;
  cout << "ingrese el nombre de la etiqueta: ";
  cin >> etiqueta;
  determinaCuadrante();
  calculaAngulo();
}

Punto::Punto(double X, double Y, string e){
  x = X;
  y = Y;
  etiqueta = e;
  determinaCuadrante();
  calculaAngulo();
}
```
El primer constructor es por omisión. Nótese como no lleva nada dentro del paréntesis. Eso nos permite asignarle valor a los atributos directamente dentro del programa. El segundo constructor, por parámetros, crea una copia de los atributos que componen al objeto, para asignarles valor en la función main(). Esto hará más sentido más adelante. 

Un programa no necesariamente requiere tener ambos tipos de constructores, pero resulta útil conocer ambos para diferentes tipos de implementaciones.

Ahora implementemos todas las funciones:
 ```cpp
 void Punto::determinaCuadrante() {
if (x >= 0 && y >= 0) {
    cuadrante = "1";
} else if (x < 0 && y >= 0) {
    cuadrante = "2";
} else if (x < 0 && y < 0) {
    cuadrante = "3";
} else if (x >= 0 && y < 0) {
    cuadrante = "4";}
}

void Punto::calculaAngulo(){
  angulo_radianes = atan(y/x);
  if (cuadrante == "1") {
    angulo = angulo_radianes * (180/M_PI);
  } 
  else if (cuadrante == "2") {
    angulo = 180 + (angulo_radianes * (180/M_PI));
  }
  else if (cuadrante == "3") {
    angulo = 180 + (angulo_radianes * (180/M_PI));
  } 
  else if (cuadrante == "4") {
    angulo = 360 + (angulo_radianes * (180/M_PI));
  }
}

void Punto::imprimePunto(){
  cout << etiqueta << "(" << x << ", " << y << ")" << endl;
}

void Punto::imprimeInfo(){
  cout << "El punto " << etiqueta << " se encuentra en el cuadrante " << cuadrante << ", con un ángulo de " << angulo << endl;
}
 ```

Sin entrar en demasiado detalle, estas funciones determinan en qué cuadrante se encuentran los puntos generados, y determinan si los puntos generan un triángulo válido.


### Composición:
A la hora de diseñar nuestros programas, debemos pensar en cómo se va a relacionar una clase con otra. En nuestro caso, tendremos una relación "has-a", que implica que una clase se compone de objetos de otra clase. Como un triágulo se compone de múltiples puntos, sabemos que es buena idea usar composición. 

```cpp
class Triangulo{
public:
  Punto p0, p1, p2;
  string etiqueta;
  double area, perimetro;

  Triangulo();
  Triangulo(string e, double a, double p, Punto punto0, Punto punto1, Punto punto2);

  double distanciaLado(Punto &pA, Punto &pB);
  bool esValido();
  void calculaPerimetro();
  void calculaArea();
  void imprimeTriangulo();
  
};
```

Note cómo en los atributos definimos uno de de tipo Punto (se tiene que llamar exactamente igual que la clase). 

También note cómo se establecieron los parámetros del constructor parametrado, utilizando objetos de tipo Punto:

```cpp
Triangulo::Triangulo() : p0{}, p1{}, p2{}{
 cin >> etiqueta;
 area = 0.0;
 perimetro = 0.0;
 calculaPerimetro();
 calculaArea();
}

Triangulo::Triangulo(string e, double a, double p, Punto punto0, Punto punto1, Punto punto2){
etiqueta = e;
area = a;
perimetro = p;
calculaPerimetro();
calculaArea();
}
```

Solo por cultura, y espero no confundir a nadie, los constructores parametrados también pueden ser implementados de la siguiente manera:

```cpp
Triangulo::Triangulo(string e, double a, double p, Punto punto0, Punto punto1, Punto punto2): p0(punto0), p1(punto1), p2(punto2), etiqueta(e), area(a), perimetro(p){
calculaPerimetro();
calculaArea();
}
```

Independientemente de cómo decidan implementarlos, noten cómo todos los objetos que vienen de la clase "Punto" deben ser definidos como de tipo "Punto". Continuemos con los métodos:

```cpp
double Triangulo::distanciaLado(Punto &pA, Punto &pB) {
  return sqrt(pow(pB.x - pA.x, 2) + pow(pB.y - pA.y, 2));
}

bool Triangulo::esValido() {
    if (p1.x == p2.x && p1.x == p2.x || p1.y == p2.y && p1.y == p2.y) {
        return false;
    }
    double ladoA = distanciaLado(p1, p2);
    double ladoB = distanciaLado(p0, p2);
    double ladoC = distanciaLado(p0, p1);

    if (ladoA + ladoB <= ladoC || ladoA + ladoC <= ladoB || ladoB + ladoC <= ladoA) {
        return false;
    }
    return true;
}
```
Quiero enfatizar en los parámetros que se usan en este método *distanciaLado(Punto &pA, Punto &pB)*. Nótese la utilziación del símbolo "&" antes de los atributos. Eso es una referencia. Sin entrar en muchos detalles de nuevo, la idea es que no tengamos que crear copias nuevas de variables que ya existen porque no es eficiente en memoria. Una referencia, valga la redundancia, refiere a una dirección en memoria y se comporta como una variable normal. 

Entraré mas a detalle del tema en otro apunte. Por el momento tienes que saber que a esto que estamos haciendo se le llama paso por referencia.

Volviendo al tema, en la función *esValido()*, es notable la utilización de puntos "." dentro del primer condicional:

```cpp
if (p1.x == p2.x && p1.x == p2.x || p1.y == p2.y && p1.y == p2.y) {
        return false;
    }
```
Si examinamos bien el programa, recordaremos que "p1", "p2" y "p3" son objetos de tipo punto. Y dentro de la clase "Punto" tenemos las variables "x" y "y". Para acceder a esas variables utilizamos los puntos.

Acabemos con el programa ptm

```cpp
void Triangulo::calculaPerimetro(){
  double ladoA = distanciaLado(p1, p2);
  double ladoB = distanciaLado(p0, p2);
  double ladoC = distanciaLado(p0, p1);
  perimetro = ladoA + ladoB + ladoC;
}

void Triangulo::calculaArea(){
  double ladoA = distanciaLado(p1, p2);
  double ladoB = distanciaLado(p0, p2);
  double ladoC = distanciaLado(p0, p1);
  double S = perimetro / 2.00; 
  area = sqrt(S * (S - ladoA) * (S - ladoB) * (S - ladoC));
}

void Triangulo::imprimeTriangulo(){
  cout << "El triángulo " << etiqueta << endl;
  p0.imprimePunto(), p1.imprimePunto(), p2.imprimePunto();

  if (esValido()) {
      cout << fixed << setprecision(2) << "Es un triángulo válido con área de " << area << " y perímetro de " << perimetro << endl;
      cout << "" << endl;
  } else {
      cout << "No es un triángulo válido." << endl;
      cout << "" << endl;
  }
}

int main() {
  Punto p1{3, 2, "A"}, p2{-8, 7, "B"}, p3{2, 6, "C"};
  Punto p4{1, 1, "A"}, p5{2, 2, "B"}, p6{3, 3, "C"};
  /*p1.imprimePunto();
  p1.imprimeInfo();          
  p2.imprimePunto();
  p2.imprimeInfo();
  p3.imprimePunto();
  p3.imprimeInfo();*/
  Triangulo t1{"ABC", 0.0, 0.0, p1, p2, p3};
  Triangulo t2{"ABC", 0.0, 0.0, p4, p5, p6};
  t1.imprimeTriangulo();
  t2.imprimeTriangulo();
return 0;}
```

Miren cómo tenemos dos maneras de crear una isntancia de la clase "Punto" (o en otras palabras, tenemos dos maneras de crear el objeto punto):

Punto p1{3, 2, "A"}, p2{-8, 7, "B"}, p3{2, 6, "C"}; --- parametrado
Punto p1; --- por omisión

Del mismo modo tenemos dos maneras de instanciar a la clase Triangulo:

Triangulo t1{"ABC", 0.0, 0.0, p1, p2, p3}; --- parametrado
Triangulo t1;

