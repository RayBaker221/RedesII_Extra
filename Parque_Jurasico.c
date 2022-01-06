#include "rshmem.h"
#include <sys/sem.h>

/* FUNCION PRINCIPAL */
main() {
key_t claveCoche; /* cualificador de semaforo */
key_t claveMuseo; /* cualificador de semaforo */
key_t claveFinvuelta; /* cualificador de semaforo */
int Coche, Museo, Finvuelta; /* semaforos */
/* obtener una clave cualquiera para el recurso ipc */
if ((key_t) -1 == (claveCoche = ftok("ejemplo", 's')) ||
(key_t) -1 == (claveMuseo = ftok("ejemplo", 'w')) ||
(key_t) -1 == (claveFinvuelta = ftok("ejemplo", 'j'))) {
fprintf(stderr,"main: Error al crear la clave con ftok(3)\n");
exit(1);
}

/* creamos los semaforos, asignando los valores iniciales */
if (-1 ==(Coche = semCreate(claveCoche,2))){
fprintf(stderr,"main: No puede crear el semaforo\n");
exit(1);
}
if (-1 ==(Museo = semCreate(claveMuseo,0))){
fprintf(stderr,"main: No puede crear el semaforo\n");
semClose(Coche);
exit(1);
}
if (-1 ==(Finvuelta = semCreate(claveFinvuelta,1))){
fprintf(stderr,"main: No puede crear el semaforo\n");
semClose(Coche);
semClose(Museo);
exit(1);
}
/* PROCESO 1 */
if (0!=fork()) {
int i ;
for (i=0; i< 1000; i++){
TP
semSignal(Museo);
semWait(Coche);
}
semClose(Museo);
semClose(Coche);
exit(0);

/* PROCESO 2 */
}else if (0!=fork()){
int i ;
if(-1==(Coche=semOpen(claveCoche)))
fprintf(stderr,"No tengo el cualificador de Coche\n");
if(-1==(Museo=semOpen(claveMuseo)))
fprintf(stderr,"No tengo cualificador de Museo\n");
for (i=0; i< 1000; i++){
TP
semSignal(Museo);
semWait(Coche);
}
semClose(Museo);
semClose(Coche);
exit(0);
/* PROCESO 3 */
}else if (0!=fork()){
int i ;
if(-1==(Coche=semOpen(claveCoche)))
fprintf(stderr,"No tengo el cualificador de Coche\n");
if(-1==(Museo=semOpen(claveMuseo)))
fprintf(stderr,"No tengo cualificador de Museo\n");
for (i=0; i< 1000; i++){
TP
semSignal(Museo);
semWait(Coche);
}
semClose(Museo);
semClose(Coche);
exit(0);

/* PROCESO 4 */
}else if (0!=fork()){
int i ;
if(-1==(Coche=semOpen(claveCoche)))
fprintf(stderr,"No tengo el cualificador de Coche\n");
if(-1==(Museo=semOpen(claveMuseo)))
fprintf(stderr,"No tengo cualificador de Museo\n");
for (i=0; i< 1000; i++){
TP
semSignal(Museo);
semWait(Coche);
}
semClose(Museo);
semClose(Coche);
exit(0);

/* PROCESO 5 */
}else if (0!=fork()){
int i ;
if(-1==(Coche=semOpen(claveCoche)))
fprintf(stderr,"No tengo el cualificador de Coche\n");
if(-1==(Museo=semOpen(claveMuseo)))
fprintf(stderr,"No tengo cualificador de Museo\n");
if(-1==(Finvuelta=semOpen(claveFinvuelta)))
fprintf(stderr,"No tengo el cualificador de Finvuelta\n");
for (i=0; i< 1000; i++){
semWait(Museo);
semWait(Finvuelta);
semSignal(Coche);
TP
semSignal(Finvuelta);
}
semClose(Museo);
semClose(Coche);
semClose(Finvuelta);
exit(0);

/* PROCESO 6 */
}else {
int i;
if(-1==(Coche=semOpen(claveCoche)))
fprintf(stderr,"No tengo el cualificador de Coche\n");
if(-1==(Museo=semOpen(claveMuseo)))
fprintf(stderr,"No tengo cualificador de Museo\n");
if(-1==(Finvuelta=semOpen(claveFinvuelta)))
fprintf(stderr,"No tengo el cualificador de Finvuelta\n");
for (i=0; i< 1000; i++){
semWait(Museo);
semWait(Finvuelta);
semSignal(Coche);
TP
semSignal(Finvuelta);
}
semClose(Museo);
semClose(Coche);
semClose(Finvuelta);
exit(0);
}
}