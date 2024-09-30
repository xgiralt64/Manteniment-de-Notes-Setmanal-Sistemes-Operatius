
## Setmana de Punters en C

### Resum teòric

Aquesta setmana hem aprofundit en l'ús de punters en el llenguatge de programació C. Els punters són variables que emmagatzemen l'adreça de memòria d'altres variables, i són essencials per gestionar la memòria dinàmica, arrays i per la manipulació directa de dades a baix nivell. Hem après sobre els següents conceptes clau:
- Declaració de punters (`int *p;`)
- Operadors de punters: `&` (obté l'adreça de memòria d'una variable) i `*` (dereferència, accedeix al valor apuntat per un punter)
- Punter nul (`NULL`) i com evitar errors de segmentació
- Aritmètica de punters: la relació entre arrays i punters, així com el moviment en la memòria a través d'increments i decrements.
- L'ús de punters amb funcions, i com passar paràmetres per referència per modificar els valors originals fora de l'abast de la funció.

### Exemples pràctics

1. **Assignació i dereferenciació de punters**
   ```c
   int a = 10;
   int *p = &a;
   printf("El valor de a és %d\n", *p); // Sortida: El valor de a és 10
   ```

2. **Aritmètica de punters i arrays**
   ```c
   int arr[3] = {10, 20, 30};
   int *ptr = arr;
   printf("Primer element: %d\n", *ptr);    // 10
   printf("Segon element: %d\n", *(ptr+1)); // 20
   printf("Tercer element: %d\n", *(ptr+2));// 30
   ```

3. **Passar punters a funcions**
   ```c
   void incrementa(int *x) {
       (*x)++;
   }
   int valor = 5;
   incrementa(&valor);
   printf("El valor incrementat és %d\n", valor); // Sortida: 6
   ```

### Dubtes i preguntes

- Encara tinc dubtes sobre quan és més adequat utilitzar punters en comparació amb altres mecanismes com arrays estàtics o structs.
- En quines situacions específiques és més eficient utilitzar punters per passar dades a funcions en lloc de passar valors?

### Reflexions personals

Els punters són un concepte fonamental i, alhora, un dels més difícils d'entendre completament en C. He notat que la seva correcta comprensió és clau per treballar amb memòria dinàmica i gestionar correctament recursos com fitxers o dispositius. Aquesta setmana, a més de repassar els exemples de classe, he practicat més exercicis per sentir-me més còmode amb la sintaxi i el comportament dels punters. Crec que encara necessito practicar més per evitar errors de segmentació i millorar en la gestió eficient de la memòria.
