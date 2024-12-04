## Setmana sobre Interbloqueig

### Resum teòric

Aquesta setmana hem treballat els conceptes d’interbloqueig, que és una situació on dos o més processos queden bloquejats perquè cadascun espera que l’altre alliberi un recurs per poder continuar. Hem estudiat:

- **Condicions de Coffman**: Perquè es produeixi un interbloqueig, han d’existir aquestes quatre condicions:

  1. **Exclusió mútua**: Només un procés pot utilitzar un recurs alhora.
  2. **Mantenir i esperar**: Els processos que tenen un recurs poden demanar-ne d’altres.
  3. **No apropiació**: Els recursos no es poden retirar forçosament d’un procés.
  4. **Espera circular**: Existeix una cadena de processos on cadascun espera un recurs que té el següent.
- **Eines per a la detecció i prevenció**:

  - **Graf d’assignació de recursos**: Representa processos i recursos com a nodes, i les seves dependències com a arestes.
  - **Algorisme del banquer**: Assegura que els recursos només es concedeixen si l’estat resultant és segur.

### Exemples pràctics

1. **Problema dels filòsofs**:
   Cinc filòsofs asseguts al voltant d’una taula amb cinc plats i un nombre limitat de coberts (forquilles i ganivets). Un filòsof només pot menjar si té tots dos coberts, i si no els aconsegueix, es queda esperant. Aquesta situació pot conduir a un interbloqueig si tots agafen un cobert i esperen indefinidament pel segon. Primer em va costar una mica d'entendre aquest problema però despres em va ajudar a entendre millor perque passen els interbloquejos i com es poden solucionar.
2. **Evitar espera circular**: Ordenar els recursos per evitar cadenes circulars de dependències.

### Dubtes i preguntes

* Quins són els casos pràctics més comuns d’interbloqueig en sistemes moderns?
* En quines situacions seria més efectiu aplicar l’algorisme del banquer en lloc d’una detecció dinàmica?

### Reflexions personals

El **problema dels filòsofs** m’ha ajudat molt a entendre com els recursos compartits poden conduir a situacions d’interbloqueig. M’ha fet reflexionar sobre com un disseny inadequat en la gestió de recursos pot afectar la fluïdesa i l’eficiència del sistema. També m’ha semblat curiós com les condicions de Coffman actuen com a base per analitzar si un sistema pot evitar aquest tipus de conflicte.

Aquest tema em sembla especialment important en sistemes distribuïts, on la gestió de recursos i la comunicació entre processos són encara més complicades.
