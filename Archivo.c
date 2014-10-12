#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("Nombre del archivo:numeros.txt\n");
    //se declara un puntero para que puedas utilizar el archivo
    FILE *archivo;
    //fopen se utiliza para poder abrir archivos,
    //lleva la ruta como no tiene path significa que se crea en el misma
    //carpeta donde este el programa
    //si es con a+
    // si no existe el archivo lo crea y aparte permite leerlo
    // con w solo escribe y te crea uno nuevo cada que lo corres
    // con r solo es para leer
    //
    archivo = fopen("numeros.txt","a+");
    int op;
    // hice un menu para que pudieras agregar los numeros y puedas consultar lo que
    // tiene el archivo
    while(op!=3)
    {
        printf("----Menu------\n");
        printf("1) Agregar\n");
        printf("2) Mostrar\n");
        printf("3) Salir\n");
        printf("Opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Dame una numero: \n" );
            // como son dos diferentes tipos de numeros te los agrego como cadena
            char entrada[30];
            // detiene el programa para que puedas ingresar el numero
            scanf("%s",entrada);
            // creo una cadena cadGUardar para que tenga el -y le adjunte lo que se leyo
            char cadGuardar[60];
            //copio a la primer cadena el -
            strcpy(cadGuardar,"-");
            //concateno a la cadena lo que se leyó
            strcat(cadGuardar,entrada);
            //fputs se utiliza para guardar la cadena al puntero del archivo
            fputs(cadGuardar,archivo);
            printf("Se guardo en el archivo\n"); //si imprime ese letrero quiere decir que se guardo
            break;
        case 2:
            //regreso el puntero al inicio del archivo
            rewind(archivo);
            //declaro un arreglo para ir almacenando los caracteres leidos
            char aux[30];
            int i=0;
            //hago un ciclo hasta que llegue al final del archivo
            while(!feof(archivo))
            {
               //lee caracter por caracter del archivo
               char car = fgetc(archivo);
               //si no es guion lo va metiendo a aux
               if(car!='-')
                  {
                      aux[i]=car;
                      i++;
                      aux[i]='\0';
                  }
               else // si encuentra el guion
                  {
                      if(i>0)
                      {
                          //convierte la cadena a double, puede funcionar con float
                          double num = atof(aux);
                          //mando llamar una funcion que esta abajo que permite saber si tiene
                          // el numero decimales, pude haber buscado el . pero lo hago con una
                          // resta
                          if(isDecimal(num))
                          {
                              //convierte el num en Entero
                              int numEntero=num;
                              //imprime como entero
                              printf("Numero Entero: %d\n",numEntero);
                          }else // si no quiere decir que fue flotante
                              printf("Numero Flotante: %f\n",num);
                          i=0;
                      }
                  }
            }
            // en el ultimo guion hacemos un proceso mas
            if(i>0)
                {
                    //convierte la cadena a double, puede funcionar con float
                   double num = atof(aux);
                   //mando llamar una funcion que esta abajo que permite saber si tiene
                   // el numero decimales, pude haber buscado el . pero lo hago con una
                   // resta
                    if(isDecimal(num))
                          {
                                 //convierte el num en Entero
                              int numEntero=num;
                              printf("Numero Entero: %d\n",numEntero);
                          }else
                              printf("Numero Flotante: %f\n",num);
                    i=0;

                }
            break;
        case 3:
            break;
        default:
            printf("Opcion incorrecta \n");
        }
    }
    printf("Salida !!");
    fclose(archivo); // cierra el archivo para evitar errores
    return 0;
}

//regresa un 0 si es real y un 1 si es entero
int isDecimal(double num)
{
    // sacamos la parte entera del numero real
    int x = num;
    // creo un double con el numero entero para cuando hagas la resta sea double
    double x2 = x;
    // si alrestar el flotante con el entero sobran decimales returna un 0
    if(num-x2>0)
        return 0;
    else // de lo contrario retorna un 1
        return 1;
}
