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

int menu_principal(){
    int sel;
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,187);
    printf("\n%c\tInventario Tienda\t%c\n",186,186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
               200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,188);
    printf("\n %c [1] - Agregar Productos"
            "\n %c [2] - Comprar Productos"
            "\n %c [3] - Mostrar Catalogo"
            "\n %c [4] - Salir"
            "\n\n Selecciona: ", 175,175,175,175);
    scanf("%d", &sel);

    return sel;
}

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

    printf("\n %c Producto a%cadido correctamente %c\n",175,164,174);
    count++;
}

int main(int argc, const char * argv[]) {
    int opcion;

    do {
        opcion = menu_principal();

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
                printf("\n\t Has salido del sistema... \n\n\t %c Hasta luego %c\n", 254,254);
                break;
            default:
                printf("\n %c Opcion elegida no valida... Intentelo de nuevo %c\n ", 158,158);
                system("pause");
        }
        system("pause");
        system("cls");
    } while (opcion != 4);

    free(productos);  // liberar memoria al salir
    return EXIT_SUCCESS;
}
