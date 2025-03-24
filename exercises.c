#include "arraylist.h"
#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "exercises.h"

// Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
// NO MODIFICAR
void imprime_lista(List *L) {
  int *dato;
  dato = (int *)first(L);
  printf("[");
  while (dato != NULL) {
    printf("%d ", *dato);
    dato = (int *)next(L);
  }
  printf("]\n");
}

// Ojo que la pila se vacía al imprimir y se imprime en orden inverso
// NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
  void *dato;
  printf("[");
  while ((dato = pop(P)) != NULL) {
    printf("%d ", *(int *)dato);
  }
  printf("]\n");
}

/*
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List *crea_lista() {
  List *L = create_list();
  for (size_t i = 1; i <= 10; i++) {
    int *num = malloc(sizeof(int));
    *num = i;
    pushBack(L, num);
  }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y
retorne la suma de sus elementos.
*/

int sumaLista(List *L) {
  if (L == NULL) return 0;
  int suma = 0;
  void *coso = first(L);
  while (coso != NULL){
    suma += *(int*)coso;
    coso = next(L);
  }
  return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
   if (L == NULL) return;
   void * ele1 = first(L);
   while(ele1 != NULL){
     if(*(int*)ele1 == elem){
        popCurrent(L);
        ele1 = first(L);
     } else {
        ele1 = next(L);
     }
   }
}
/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack *P1, Stack *P2) {
  void *valorp1 = top(P1);
  Stack *Ppro = create_stack();
  while(valorp1 != NULL){
    push(Ppro, valorp1);
    pop(P1);
    valorp1 = top(P1);
  }
  void *valorp2 = top(Ppro);
  while(valorp2 != NULL){
    push(P2, valorp2);
    push(P1, valorp2);
    pop(Ppro);
    valorp2 = top(Ppro);
  }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) { 
  Stack *Lapila = create_stack();
  size_t izq = 0;
  size_t der = 0;
  for(size_t i = 0; i < strlen(cadena); i++){
    if(cadena[i] == '('||cadena[i] == '{'||cadena[i] == '['){
      izq ++;
      push(Lapila, &cadena[i]);
    } else if(cadena[i] == ')'||cadena[i] == '}'||cadena[i] == ']'){
      der ++;
      if(cadena[i] == ')' && *(char*)top(Lapila) == '(') pop(Lapila);
      else if(cadena[i] == '}' && *(char*)top(Lapila) == '{') pop(Lapila);
      else if(cadena[i] == ']' && *(char*)top(Lapila) == '[') pop(Lapila);
      else return 0;
    }
  }
  if(izq == der) return 1;
  else return 0;
}
