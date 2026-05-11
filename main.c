//
//  main.c
//  Administrador_tienda
//
//  Created by Derek Witt on 08/05/26.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Tienda
{
    char idproducto[13];
    char nombre[50];
    float precio;
    int stock;
};


void ingreso_productos(void)
{
    struct Tienda *productos = NULL;
    
    int i = 0;
    
    int size = 0;
    
    int plus;
    
    if (size == i)
    {
        printf("\n Ingrese Nombre del producto : ");
        scanf("%s", &productos[i].nombre[50]);
        printf("\n Ingrese precio : ");
        scanf("%f", &productos[i].precio);
        printf("\n Ingrese stock : ");
        scanf("%d", &productos[i].stock);
        i ++;
    }
    else
    {
        printf("\n Cuantos nuevos productos desea agregar : ");
        scanf("%i", &plus);
        productos = (int*) malloc (size += plus * sizeof(int));
    }
}



int main(int argc, const char * argv[])
{
    do
    {
        printf("\n  -- Inventario Tienda -- \n"
               "\n 1 - Agregar Productos \n"
               "\n 2 - Comprar Productos \n"
               "\n 3 - Mostrar Catalogo \n"
               "\n 4 - Salir \n"
               "\n Selecciona: ");
        scanf("%i", &argc);
        switch (argc)
        {
            case 1:
            {
                ingreso_productos();
                break;
            }
        }
    }
    while (argc != 4);
    return EXIT_SUCCESS;
}
