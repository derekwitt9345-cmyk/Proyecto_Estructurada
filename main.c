//
//  main.c
//  Administrador_tienda
//
//  Created by Derek Witt on 08/05/26.
//

#include <stdlib.h>
#include <stdio.h>

struct Tienda {
    char idproducto[13];
    char nombre[50];
    float precio;
    int stock;
};

// Variables globales para persistir entre llamadas
struct Tienda *productos = NULL;
int size = 0;
int count = 0;  // cuántos productos hay actualmente

void ingreso_productos(void) {
    // Si no hay espacio, pedir cuántos agregar
    if (count == size) {
        int plus;
        printf("\n Cuantos nuevos productos desea agregar: ");
        scanf("%d", &plus);

        // Redimensionar el arreglo
        size += plus;
        productos = (struct Tienda *)realloc(productos, size * sizeof(struct Tienda));

        if (productos == NULL) {
            printf("Error: no se pudo asignar memoria\n");
            return;
        }
    }

    // Ingresar el producto en la posición actual
    printf("\n Ingrese Nombre del producto: ");
    scanf("%49s", productos[count].nombre);

    printf("\n Ingrese precio: ");
    scanf("%f", &productos[count].precio);

    printf("\n Ingrese stock: ");
    scanf("%d", &productos[count].stock);

    count++;
}

int main(int argc, const char * argv[]) {
    int opcion;

    do {
        printf("\n  -- Inventario Tienda --\n"
               "\n 1 - Agregar Productos"
               "\n 2 - Comprar Productos"
               "\n 3 - Mostrar Catalogo"
               "\n 4 - Salir"
               "\n\n Selecciona: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingreso_productos();
                break;
            case 2:
                printf("\n (por implementar)\n");
                break;
            case 3:
                printf("\n -- Catalogo --\n");
                for (int i = 0; i < count; i++) {
                    printf("\n [%d] Nombre: %s | Precio: %.2f | Stock: %d",
                           i + 1,
                           productos[i].nombre,
                           productos[i].precio,
                           productos[i].stock);
                }
                printf("\n");
                break;
            case 4:
                printf("\n Saliendo...\n");
                break;
            default:
                printf("\n Opcion invalida\n");
        }
    } while (opcion != 4);

    free(productos);  // liberar memoria al salir
    return EXIT_SUCCESS;
}
