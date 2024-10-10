
## Setmana de Processos en Linux

### Resum teòric

Aquesta setmana hem treballat els conceptes relacionats amb la gestió de processos en sistemes operatius basats en Linux. Hem après sobre:

- **Creació de processos amb `fork()`**: Aquesta funció crea un nou procés duplicant el procés actual (procés pare). El nou procés (procés fill) és una còpia quasi exacta del procés pare, excepte pels identificadors de procés (PID) i altres diferències menors.
  
- **Pipes entre processos**: Els pipes són mecanismes per a la comunicació entre processos, que permeten que un procés escrigui informació i un altre la llegeixi. Això es fa mitjançant el sistema de fitxers, connectant la sortida d'un procés a l'entrada d'un altre.

- **Propietats dels processos**: Els processos tenen diverses àrees de memòria:
  - **Data**: Aquí es guarden les variables globals i estàtiques.
  - **Heap**: És l'àrea de memòria per a l'assignació dinàmica durant l'execució.
  - **Stack**: Aquesta àrea gestiona les crides de funcions i les variables locals.
  - **Buffers**: Memòria temporal utilitzada per emmagatzemar dades abans d'escriure-les o llegir-les.

- **Recobriment de processos (`execlp` i altres)**: Les funcions de la família `exec` substitueixen el codi i les dades d'un procés existent per executar un altre programa. `execlp` és una variant que cerca el programa a la variable PATH del sistema, permetent executar un nou programa dins del mateix procés.

- **Senyals**: Els senyals són notificacions que el sistema operatiu envia als processos per indicar esdeveniments com la finalització d'un procés fill, una interrupció per l'usuari, etc. Alguns senyals comuns són:
  - `SIGINT` (Interrupció, per exemple Ctrl+C)
  - `SIGTERM` (Sol·licitud de finalització)
  - `SIGKILL` (Finalització forçada)
  
- **Procés zombi**: Un procés es converteix en un procés zombi quan finalitza però el seu procés pare no ha recollit el seu codi de sortida mitjançant `wait()`. Això deixa una entrada en la taula de processos.

### Exemples pràctics

1. **Creació de processos amb `fork()`**
   ```c
   pid_t pid = fork();
   if (pid == 0) {
       // Codi del procés fill
       printf("Soc el procés fill\n");
   } else {
       // Codi del procés pare
       printf("Soc el procés pare\n");
   }
   ```

2. **Pipe entre processos**
   ```c
   int fd[2];
   pipe(fd); // Crea un pipe
   if (fork() == 0) {
       // Procés fill: escriptor
       close(fd[0]);
       write(fd[1], "Hola, pare", 10);
       close(fd[1]);
   } else {
       // Procés pare: lector
       char buffer[11];
       close(fd[1]);
       read(fd[0], buffer, 10);
       buffer[10] = '\0';
       printf("Missatge del fill: %s\n", buffer);
       close(fd[0]);
   }
   ```

3. **Utilització de `execlp`**
   ```c
   if (fork() == 0) {
       // Procés fill substituït
       execlp("ls", "ls", "-l", (char *)NULL);
   }
   ```

4. **Gestió de senyals amb `signal()`**
   ```c
   void manejador(int senyal) {
       printf("He rebut el senyal %d\n", senyal);
   }
   signal(SIGINT, manejador);
   ```

### Dubtes i preguntes

- Què passa exactament amb la memòria assignada al heap en un procés fill quan es crida a `execlp`? Es pot perdre memòria?
- Com puc gestionar millor els processos zombies en aplicacions grans i complexes?

### Reflexions personals

La gestió de processos en Linux és crucial per a comprendre com funciona el sistema operatiu a nivell intern. He trobat molt interessant la funció `fork()` i com pot dividir un procés en dos. Els pipes també són molt útils per la comunicació entre processos, tot i que encara em costa gestionar correctament els descriptors de fitxer. Aquesta setmana he après molt sobre el funcionament intern dels processos, però necessito practicar més en la gestió de senyals i els processos zombi.
