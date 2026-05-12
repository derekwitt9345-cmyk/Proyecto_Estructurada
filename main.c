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

void mostrar_catalogo(){
    // verificamos si es que hay productos registrados
    if(count == 0){
        printf("\n El inventario esta vacio.\n");
        return;
    }
    // si si hay mostramos el catalogo
    //aqui le pedi a la IA para que me ayudara a darle un formato de tabla sin que se deforme la tabla
    printf("\n %-4s | %-20s | %-10s | %-5s", "ID", "Nombre", "Precio", "Stock");
    printf("\n---------------------------------------------------------");
    for (int i = 0; i < count; i++) {
        printf("\n [%02d] | %-20.20s | $%9.2f | %5d",
        i + 1,
        productos[i].nombre,
        productos[i].precio,
        productos[i].stock);
    }
    printf("\n");
}

void comprar_producto(){
    //declaramos variables para el opcion de ID de producto y la cantidad que desea comprar...
    int cantidad = 0, op_id = 0, intentos = 3;

    //verificamos si hay productos, si no hay no mostrara el catalogo
    if(count == 0){
        printf("\n %c No hay productos registrados para vender. %c\n",158,158);
        return;
    }

    // mostramos el catalogo
    mostrar_catalogo();

    //le damos al usuario intentos de compra, si llega a 0 o si se realiza exitosamente la compra se detiene
    do{
        printf("\n\t Intentos de compra: %d\n", intentos);
        printf(" Ingrese el ID del producto que desea comprar: ");
        scanf("%d",&op_id);
        if(op_id <= 0 || op_id > count){ //verificamos que este en "rango" con el ID mostrado
            printf("\n %c ID ingresado fuera del rango... Intentelo de nuevo %c \n",158,158);
            intentos--;
            continue;
        }

        op_id--;

        printf("\n Cuantas unidades deseas comprar? \n Unidades: ");
        scanf("%d", &cantidad);
        if(cantidad <= 0 || cantidad > productos[op_id].stock){
            printf("\n %c Cantidad de productos fuera de rango... Intentelo de nuevo %c \n",158,158);
            intentos--;
            continue;
        }

        productos[op_id].stock = productos[op_id].stock - cantidad;
        break;
    }while(intentos != 0);

    if(intentos == 0)
        printf("\n Se te acabaron los intentos de compra... Intentelo de nuevo mas tarde \n");
    else
        printf(" \n\n\t %c Compra realizada exitosamente! %c \n",254,254);
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
                comprar_producto();
                break;
            case 3:
                mostrar_catalogo();
                break;
            case 4:
                printf("\n\t %c Has salido del sistema... %c\n", 254,254);
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
