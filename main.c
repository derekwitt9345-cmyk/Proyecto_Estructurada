#include "stdio.h"
#include "stdlib.h"

typedef struct{
        char nombre[50];
        float precio;
        int stock;
    } producto;

void agregar_producto(producto inventario[], int *totalProd); // Funcion para agregar producto

int main(){
    int totalProd = 0, op = 0;
    producto inventario[100];
    do{
        printf("\n\t%c%c%c\tInventario de Tienda\t%c%c%c", 178,177,176,176,177,178);
        printf("\n %c [1] Agregar Producto\n %c [2] Comprar Producto\n %c [3] Mostrar Catalogo\n %c [4] Salir", 175,175,175,175);
        printf("\n Opcion: ");
        scanf("%d", &op);

        switch(op){
            case 1: agregar_producto(inventario, &totalProd);
                break;
            case 2: //comprar_producto();
                break;
            case 3: //mostrar_catalogo();
                break;
            case 4:
                op = 4;
                break;
            default:
                printf("\n %c Opcion elegida no valida... Intentelo de nuevo %c\n ", 158,158);
                system("pause");
        }
        system("cls");
    }while(op != 4);

    printf("\n\t Has salido del sistema... \n\n\t %c Hasta luego %c\n", 254,254);
    return 0;
}

void agregar_producto(producto inventario[], int *totalProd){
    printf(" \n Por favor ingrese el nombre del producto: ");
    scanf("%s", inventario[*totalProd].nombre);
    fflush(stdin);
    printf(" \n Por favor ingrese el precio del producto: ");
    scanf("%f", &inventario[*totalProd].precio);
    printf(" \n Por favor ingrese el stock del producto: ");
    scanf("%d", &inventario[*totalProd].stock);

    (*totalProd)++;

    printf(" \n\t %c Producto Guardado Exitosamente %c", 157, 157);
}
