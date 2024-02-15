#título          : Generador y evaluador de contraseñas
#descripción     : Programa en Python que genera contraseñas al azar
#                  y evalúa su seguridad
#autor           : Mateo Minghi
#python_version  : 3.7
#==============================================================================

#bibliotecas
import string
import random

def sacar_valor_numerico(user_input):
    """
    (operadores, funciones)
    recibe: user_input que es un string dado por el usuario
    Saca la suma del valor numérico del primer y último caracter
    del string usando la función ord(),
    que le asgina un Unicode Point al caracter
    devuelve: suma del valor del primer y último caracter 
    API python: https://docs.python.org/3/library/functions.html#ord
    """
    
    valor_numerico = ord(user_input[0]) + ord(user_input[-1])
    return valor_numerico

def convertir_a_string(user_input):
    """
    (variables, uso de funciones)
    recibe: user_input que es un string dado por el usuario
    Función que convierte el valor numérico a string
    para poder manipularlo como string más adelante
    devuelve: resultado del valor numérico en string
    """
    
    valor = sacar_valor_numerico(user_input)
    valor_string = str(valor)
    return valor_string
    
def password(user_input, caracteres1, caracteres2):
    """
    (operadores, funciones)
    recibe: user input string del usuario, caracteres1 caracter al azar, 
            caracteres2 caracter al azar
    Función que toma símbolos al azar y son concatenados
    al valor_string generado anteriormente
    devuelve: la contraseña generada al usuario, compuesta por 
    caracteres al azar, el valor numérico en forma de string
    y la letra final del input en mayúscula
    """
    
    contraseña_final = caracteres1 + convertir_a_string(user_input)\
    + caracteres2 + user_input[-1].upper()
    return contraseña_final

def buscar_elemento(password_final, elementos):
    """
    (ciclos, listas)
    recibe: password_final string generado en la función "password", 
            elementos lista de caracteres especiales
    Función que busca si el password final tiene caracteres especiales
    regresa: si la contraseña es segura o no basándose en si encuentra 
    los caracteres especiales
    """
    for letra in password_final:
        if letra in elementos:
            return "Tu contraseña es segura"      

def generar_contraseña():
    """
    (librerías, funciones)
    Esta función permite que los valores puedan volver a ser utilizados 
    en caso de que el usuario quiera una nueva contraseña.
    Utiliza la libriría random, que genera un valor flotante
    dentro del rango que se le aplique basándose en el "Mersenne Twister",
    un generador de números aleatorios diseñado en 1997.
    regresa: caracteres aleatórios de la librería string en la posición
    aleatoria generada por random. Variables usadas en funciones pasadas.
    API python: https://docs.python.org/3/library/random.html
    """
    
    user_input = str(input("¿Cuál es tu comida favorita? "))
    caracteres1 = string.punctuation[(random.randint(3,5)):random.randint(3,5)]
    caracteres2 =\
    string.punctuation[(random.randint(6,8))::random.randint(3,5)]
    
    nueva_contraseña = password(user_input, caracteres1, caracteres2)
    
    print("Tu contraseña es: ", nueva_contraseña)
    print(buscar_elemento(nueva_contraseña, elementos))
    
    return nueva_contraseña

def crear_lista_contraseña():
    """
    (ciclos, condicionales, funciones)
    Función que crea una lista por cada contraseña nueva
    para poder anidarla en la lista contraseñas_totales.
    Este ciclo corre a la par que se corre el ciclo general
    del programa, tomando la contraseña generada anteriormente
    y mentiéndola en una lista de contraseñas.
    regresa: una lista de contraseñas generadas
    """
    
    contraseñas = []
    while True:
        nueva_contraseña = generar_contraseña()
        contraseñas.append(nueva_contraseña)
        respuesta =\
        input("¿Deseas generar otra contraseña en esta misma lista? (si/no): ")
        if respuesta.lower() != 'si':
            break
    return contraseñas

contraseñas_totales = [] #lista donde se metene listas de contraseñas

elementos = ["!", "#", "$", "%", "&", "(", ")", "<", ">",
            "*", "@", ":", ".", "+", "-", "=", "/"] 


def correr_programa():
    """
    (ciclos, condicionales)
    Función general que hace que corra el programa
    hasta que le indiquemos lo contrario. Necesario para
    poder generar múltiples contraseñas en una lista, 
    y poder generar múltiples listas que se agregan a la lista
    "contraseñas totales"
    regresa: lista de listas de contraseñas
    """
    
    while True:
        contraseñas_generadas = crear_lista_contraseña()
        contraseñas_totales.append(contraseñas_generadas)
        respuesta =\
        input("¿Deseas generar otra lista de contraseñas? (si/no): ")
        if respuesta.lower() != 'si':
            print("Contraseñas generadas:")
            print(contraseñas_totales) 
            #no formateo el print para que se vea la lista anidada
            return False


correr_programa()