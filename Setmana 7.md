## Setmana sobre Shell Script

### Resum teòric

Aquesta setmana hem treballat el **Shell Scripting**, una eina molt bona per automatitzar tasques en entorns Unix/Linux. Els punts més importants que he après són:

- **Què és un shell script?**

  - Un conjunt d'ordres escrites en un fitxer que el sistema operatiu interpreta seqüencialment.
  - És útil per a tasques repetitives i processos automatitzats.
- **Estructura bàsica d'un script**:

  - Els scripts comencen amb la línia `#!/bin/bash` (o un altre shell).
  - Ordres del sistema i funcions escrites en seqüència.
- **Elements clau**:

  - **Variables**:
    ```bash
    nom="Xavier"
    echo "Hola, $nom"
    ```
  - **Entrades de l'usuari**:
    ```bash
    echo "Escriu el teu nom:"
    read nom
    echo "Hola, $nom"
    ```
  - **Condicionals**:
    ```bash
    if [ $x -gt 10 ]; then
        echo "El valor és major que 10"
    fi
    ```
  - **Bucles**:
    ```bash
    for i in 1 2 3; do
        echo "Número: $i"
    done
    ```
  - **Funcions**:
    ```bash
    funcio() {
        echo "Això és una funció"
    }
    funcio
    ```
- **Permisos d'execució**:

  - Abans d'executar un script, he de donar permisos:
    ```bash
    chmod +x script.sh
    ./script.sh
    ```

### Exemples pràctics

1. **Script senzill per comprovar si un fitxer existeix**:

   ```bash
   #!/bin/bash
   if [ -f "$1" ]; then
       echo "El fitxer $1 existeix."
   else
       echo "El fitxer $1 no existeix."
   fi
   ```
2. **Bucle per processar diversos fitxers**:

```bash
#!/bin/bash
for fitxer in *.txt; do
    echo "Processant $fitxer"
done

```

### Exemple real

Gràcies a l'après a classe he pogut automatitzar una tasca que abans se'm feia molt repetitiva. En el meu ordinador tinc un Dualboot que em permet iniciar amb ArchLinux o amb Windows11. El 99% del temps utilitzo ArchLinux però per algunes tasques específiques necessito Win11. Per això he creat un script que em permet iniciar Win11 dins de ArchLinux (Com a màquina virtual) llegint les dades fisiques del disc dur.

```bash
#!/bin/bash
sudo umount /dev/disk/by-id/nvme-PC711_NVMe_SK_hynix_512GB____FJA9N703712409R0M_1-part1
sudo virsh start win11
sleep 15
xfreerdp +clipboard -grab-keyboard /v:192.168.122.30 /sound /u:'<usuari>' /p:'<contrasenya>' /size:100% /d: /dynamic-resolution /gfx-h264:avc444 +menu-anims +window-drag
```

El que m'ha permès aquest script és automatitzar la tasca de desmuntar la partició EFI del meu sistema per poder-la carregar des de la màquina virtual. Espero 15 segons que el SO s'iniciï correctament i finalment em connecto a aquesta màquina amb rdp.

### Dubtes i preguntes

* Quins són els avantatges de Bash en comparació amb altres shells com Zsh o Fish?
* Com puc depurar millor els meus scripts en cas d'errors?

### Reflexions personals

Treballar amb shell script m’ha ensenyat un nou llenguatge de programació que em permet fer programes simples i automatitzar tasques. He trobat útil entendre com estructurar scripts amb condicions i bucles per fer-los més versàtils. Tot i això, encara vull practicar més la gestió d'errors i depuració per millorar els meus scripts.
