#include "header.h"

booleano esFechaValida(Fecha fecha)
{
    if(fecha.anio >= ANIO_BASE)
    {
        if(fecha.dia>=1 && fecha.dia<=cantDiaMes(fecha.mes, fecha.anio))
        {
            return VERDADERO;
        }
    }
    return FALSO;
}

int cantDiaMes(int mes, int anio)
{
    const static int cdm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(mes==2 && esBisiesto(anio))
    {
        return 29;
    }
    return cdm[mes-1];
}

booleano continuar(char* mensaje)
{
    char respuesta;
    puts(mensaje);
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta = tolower(respuesta);
    while(respuesta != 's' && respuesta != 'n')
    {
        puts("Respyesta invalida");
        puts("Debe ingresar (s/n): ");
        fflush(stdin);
        scanf("%c", &respuesta);
    }
    return respuesta == 's';
}
