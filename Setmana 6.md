## Setmana sobre Memòria Virtual

### Resum teòric

Aquesta setmana hem estudiat la memòria virtual, una tècnica que permet als sistemes operatius executar programes que excedeixen la capacitat de la memòria principal (RAM). Els punts més destacats són:

- **Què és la memòria virtual?**

  - Combina memòria principal i memòria secundària per proporcionar un espai d'adreçament més gran del que permet la RAM.
  - Augmenta la multiprogramació i permet executar processos més grans que la memòria física.
- **Avantatges i inconvenients**:

  - **Avantatges**:
    - Executar programes grans que no caben a la RAM.
    - Millorar la utilització del sistema.
  - **Inconvenients**:
    - Ralentització per accés a memòria secundària.
    - Problemes com la hiperpaginació.
- **Tècniques de gestió**:

  - **Paginació sota demanda**: Les pàgines es carreguen només quan es necessiten.
  - **Paginació anticipada**: Es carreguen pàgines addicionals esperades segons prediccions.
- **Fallades de pàgina**:

  1. Si hi ha cel·les lliures, es carrega la pàgina directament.
  2. Si no hi ha cel·les lliures, s'ha de reemplaçar una pàgina utilitzant un algorisme (FIFO, LRU, etc.).

  - Temps efectiu d'accés (TEA): El temps mitjà d'accés que combina memòria principal i secundària.

### Algorismes de reemplaçament

1. **FIFO (First-In, First-Out)**: Reemplaça la pàgina que ha estat més temps en memòria.
2. **LRU (Least Recently Used)**: Reemplaça la pàgina que no s'ha utilitzat durant més temps.
3. **Òptim**: Substitueix la pàgina que no serà utilitzada durant més temps (impossible de realitzar, només teòric).
4. **Segona oportunitat**: Combina FIFO amb un bit de referència per donar més oportunitats a pàgines recentment utilitzades.

### Problemes i solucions

- **Hiperpaginació**:
  - Es produeix quan hi ha massa processos i la memòria es dedica principalment a intercanvis de pàgines, reduint l'ús de la CPU.
  - Solució: Reduir el grau de multiprogramació.
- **Anomalies de Belady**:
  - Incrementar el nombre de cel·les pot augmentar les fallades de pàgina amb l'algorisme FIFO.

### Exemples pràctics

1. **Càlcul del TEA (Temps efectiu d'accés)**: TEA = [(1 - P) \* (2 \* Ta)] + [P \* (TmpMs + 3 \* Ta)]



On:

- P: Probabilitat de fallada de pàgina.
- Ta: Temps d'accés a memòria principal.
- TmpMs: Temps d'accés a memòria secundària.

2. **Hiperpaginació**:
   Suposem un sistema amb un ús del 15% de la CPU i una ocupació del dispositiu de paginació del 97%. Això indica que el sistema està saturat i cal reduir processos.

### Dubtes i preguntes

- Quan és més adequat que utilitzi paginació anticipada en lloc de sota demanda?
- Quins factors influeixen més en la hiperpaginació i com es poden predir?

### Reflexions personals

El concepte de memòria virtual m’ha ajudat a entendre com els sistemes operatius gestionen processos més grans que la RAM disponible. Els algorismes com LRU i Segona Oportunitat destaquen per la seva eficàcia en entorns pràctics. També, he après com evitar la hiperpaginació ajustant el nombre de processos actius per mantenir un ús equilibrat de recursos.
