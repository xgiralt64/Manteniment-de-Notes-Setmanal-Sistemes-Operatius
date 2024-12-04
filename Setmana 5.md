## Setmana sobre Gestió de la Memòria

### Resum teòric

Aquesta setmana hem estudiat els mecanismes de gestió de la memòria en sistemes operatius, que són essencials per garantir l'ús eficient i segur dels recursos de memòria. Els punts més destacats són:

- **Necessitat de la gestió de la memòria**:

  - Permetre l'execució simultània de múltiples processos.
  - Garantir que la memòria es comparteixi de manera controlada i protegida.
- **Components del mapa de memòria d’un procés**:

  1. **Codi**: Regió de mida fixa, només de lectura i execució.
  2. **Dades inicialitzades**: Variables globals i estàtiques inicialitzades.
  3. **Dades no inicialitzades**: Variables globals i estàtiques no inicialitzades.
  4. **Heap**: Per a l’assignació dinàmica de memòria.
  5. **Stack**: Per gestionar les crides a funcions i variables locals.
- **Tècniques de gestió**:

  - **Paginació**: Divideix la memòria en blocs de mida fixa (pàgines) per evitar la fragmentació externa.
  - **Segmentació**: Organitza la memòria en segments lògics com codi, dades, etc.
  - **Segmentació paginada**: Combinació de les dues tècniques anteriors per millorar la flexibilitat i reduir la fragmentació.
- **Reubicació de memòria**: Tradueix adreces lògiques a físiques, ja sigui en temps de compilació, càrrega o execució.
- **Problemes clàssics**:

  - **Fragmentació interna**: Espai no utilitzat dins d'una partició o pàgina.
  - **Fragmentació externa**: Espai lliure que no és contigu i, per tant, no es pot utilitzar.

### Dubtes i preguntes

* Quina és la millor tècnica per evitar la fragmentació en sistemes amb càrregues molt variables?
* Quins són els avantatges pràctics d’utilitzar segmentació paginada sobre la segmentació o paginació simples?

### Reflexions personals

El tema de gestió de la memòria m’ha fet entendre com el sistema operatiu organitza i protegeix la memòria entre diferents processos. Conceptes com el **heap** i la **pila** m’han semblat especialment importants per entendre l’assignació dinàmica i la gestió de crides recursives. També he trobat útil veure com la combinació de segmentació i paginació aporta un equilibri entre flexibilitat i eficiència.

Aquest coneixement m’ajuda a entendre millor com optimitzar els programes en termes de memòria i com prevenir problemes com **fuites de memòria** o accés a zones no vàlides
