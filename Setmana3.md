## Setmana de Planificació de Processos en Sistemes Operatius

### Resum teòric

Aquesta setmana hem explorat els principis de la planificació de processos, incloent conceptes, objectius i algorismes utilitzats per gestionar l'accés a la CPU i altres recursos:

- **Necessitat de planificació**: La multiprogramació implica que diversos processos competeixen per recursos limitats, com la CPU. El sistema operatiu decideix quin procés s'executa mitjançant un planificador (scheduler).
- **Objectius de la política de planificació**:
  - **Equitat**: Garantir accés equitatiu als recursos.
  - **Rendiment**: Optimitzar mètriques com el throughput, temps d'espera, temps de resposta, etc.
  - **Compliment de polítiques**: Assegurar-se que les polítiques del sistema es respecten.
- **Modes de planificació**:
  - **No apropiatius**: El procés executa fins que acaba o es bloqueja.
  - **Apropiatius**: El sistema pot interrompre el procés en execució per assignar la CPU a un altre.

### Algorismes estudiats

1. **FCFS (First-Come, First-Served)**:

   - Assigna la CPU segons l'ordre d'arribada dels processos.
   - Simple d'implementar però pot patir l'efecte convoy, on processos curts esperen darrere de processos llargs.
2. **SJF (Shortest Job First)**:

   - Prioritza processos amb temps de burst més curts.
   - Redueix el temps d'espera mitjà però pot provocar fam (inanició) per processos llargs.

### Mètriques de rendiment

- **Temps d'espera**: Temps a la cua de processos preparats.
- **Temps de retorn**: Temps des de l'arribada fins a la finalització.
- **Throughput**: Nombre de processos completats per unitat de temps.

### Exemples pràctics

1. **Algorisme FCFS**

   ```text
   Processos:
   A: Arribada = 0, Burst = 7
   B: Arribada = 2, Burst = 4
   C: Arribada = 3, Burst = 2

   Ordre d'execució: A → B → C
   Temps d'espera (mitjà): (0 + 5 + 8) / 3 = 4.3
   ```
2. **Algorisme SJF**

   ```text
   Processos:
   A: Arribada = 0, Burst = 7
   B: Arribada = 2, Burst = 4
   C: Arribada = 3, Burst = 2

   Ordre d'execució: C → B → A
   Temps d'espera (mitjà): (0 + 7 + 4) / 3 = 3.6
   ```

### Reflexions personals

La planificació de processos és fonamental per garantir l'eficiència i l'equitat en un sistema operatiu. Aquesta setmana he descobert com la selecció d'un algorisme afecta el rendiment i l'experiència de l'usuari. Crec que aprofundir en els algorismes avançats, com planificadors multilevel o d'assignació dinàmica, serà molt enriquidor.
