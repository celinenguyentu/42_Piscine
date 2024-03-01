# Piscine 42

## Sommaire

- [Shell-00](#shell-00)
- [Shell-01](#shell-01)

---

## Shell-00 

### ex00 - Z

- `cat [file]` lit et affiche le contenu du fichier `file`. Si ce fichier ne termine pas avec une nouvelle ligne, la commande affiche `%` à la fin de son contenu.
- `[command] | cat -e` lit et affiche le résultat de la `command` via une pipeline.
    - `-e` montre les caractères non affichables, notamment avec `$` à la fin de chaque ligne.
- `more` et `less` sont des variantes qui affichent également un contenu mais pas entièrement, on peut se déplacer à l'intérieur avec les flèches du clavier et rechercher des mots avec `/`. La commande `less` est plus avancée que `more` devenue obsolète.
- `echo '[text]'` affiche le `text` tel qu'il est écrit alors que `echo "[text]"` affiche la valeur de la variable `text` car il est interprété par le shell. La commande `printf '[text]'` permet la même chose à la différence qu'elle n'ajoute pas automatiquement un retour à la ligne, il faut alors l'inclure avec `\n` entre les guillemets.
- `[command] > [file]` redirige le résultat de `command` vers `file` en l'écrasant. Pour ajouter une nouvelle ligne à la suite du contenu de `file`, il faut utiliser `[command] >> [file]`.

### ex01 - testShell00 

- `touch [file]` crée le fichier `file` dans le répertoire courant.
- `ls -l` liste le contenu du répertoire courant et l'option `-l` (format long) permet d'afficher des informations supplémentaires sur les fichiers et répertoires qu'il contient. 

Chaque ligne correspond à un élément et comporte les colonnes :
1. permissions
2. nombre de liens durs *(hardlink)* qui référencent ce fichier(sous-répertoire de niveau 1)
3. propriétaire
4. groupe de propriétaires
5. taille en octets (dépend du contenu du fichier)
6. date de la dernière modification
7. nom du fichier ou dossier et lien éventuel

Les permissions sont les droits que possède un utilisateur sur le fichier ou dossier. Elle est constituée de 10 caractères. Le premier caractère indique s'il s'agit d'un fichier `-`, d'un répertoire *(directory)* `d`, d'un lien `l`, d'un caractère `c` ou d'un block `b`. Les neufs autres indiquent, par groupe de trois, les droits du propriétaire, du groupe et des autres utilisateurs à l'aide des caractères `r` *(read)*, `w` *(write)*, `x` *(execute)* dans cet ordre, chacun remplacé par `-` lorsque ce droit n'est pas attribué. 

> \* `-r--r-xr-x`: un fichier que le propriétaire peut lire, le groupe peut lire et exécuter, et les autres peuvent lire et exécuter. <br>
> \* `drwx------` : un répertoire/dossier que seul le propriétaire peut lire, écrire et exécuter.

- `chmod [permissions][file]` modifie les permissions du fichier

Pour modifier les permissions en mode symbolique, on utilise les lettres désignant les catégories d'utilisateurs (`u` propriétaire, `g` groupe, `o` autres, `a` tous) suivis de `+`, `-` ou `=`(ajout, suppression ou définition) et des droits d'accès sous forme de lettre.

Pour modifier les permissions en mode octal, on associe un chiffre à un ensemble de droits attribué à chacune des catégorie d'utilisateurs.  

| Valeur octal      | 0     | 1        | 2      | 3                | 4    | 5              | 6            | 7    |
| ----------------- | ----- | -------- | ------ | ---------------- | ---- | -------------- | ------------ | ---- |
| Valeur symbolique | ---   | --x      | -w-    | -wx              | r--  | r-x            | rw-          | rwx  |
| Droits            | aucun | exécuter | écrire | écrire, exécuter | lire | lire, exécuter | lire, écrire | tous |

> \* `chmod ugo+rw fichier.txt` équivaut à `chmod a+rw fichier.txt` et ajoute à tous le droit de lecture et d'écriture. <br>
> \* `chmod go-w fichier.txt` retire le droit d'écriture au groupe et aux autres. <br>
> \* `chmod 750 fichier.txt` attribue tous les droits au propriétaire, le droit de lire et d'exécuter au groupe, aucun droit aux autres.

Parfois sur OSX, les permissions sont suivies de `@` qui indique que le fichier possède des attributs étendus (des informations supplémentaires comme l'encodage). On les affiche avec `xattr -l [file]` et on les supprime avec `xattr -c [file]`.

- `touch -t [YYYYMMDDhhmm[.ss]][file]` modifie la date de création et modification de *(timestamp)* `file`.
- `touch -mt [YYYYMMDDhhmm[.ss]][file]` modifie la date de moditication de `file`.
- `tar -cf [folder].tar [files]` crée une compression `.tar` nommé `folder` en compressant le(s) fichier(s) `files`. L'option `-c` signifie qu'on crée un nouveau fichier et `-f` qu'on le nomme. 

### ex02 - Owi, encore ...

- `ln [sourcefile][link]` permet de créer un lien dur nommé `[link]` depuis le fichier `[sourcefile]`.
- `ln -s [sourcefile][link]` permet de créer un lien symbolique nommé `[link]` depuis le fichier `[sourcefile]`.
- `ls -li` permet de lister les fichiers du répertoire courant avec leur référence d'inode (première colonne).

Un inode est une base de données attachée à un fichier ou un dossier qui réunit ses informations comme sa taille, son propriétaire, son timestamp, ses permissions et son adresse (localisation) dans le disque dur. Si on déplace un fichier d'un dossier à un autre, l'adresse indiquée dans son inode change automatiquement. Une inode a une référence/numéro unique visible avec la commande `ls -li`. Lorsqu'on copie un fichier, on crée en réalité un nouveau fichier en le dupliquant, donc le nouveau fichier a un inode différent. Lorsqu'on déplace un fichier, son inode reste le même.

Les liens durs et liens symboliques sont deux méthodes pour référencer un fichier dans le system file, expliquées via la notion d'inode. En modifiant le contenu d'un lien, on modifie le contenu du fichier qu'il référence. 

Le lien dur est simplement une référence supplémentaire d'un fichier. Le lien dur pointe vers l'inode du fichier et est essentiellement une copie carbonne synchronisée du fichier. Avec `ls -li`, on peut vérifier que le lien possède le même inode que le fichier original et que le nombre de références/hardlinks a augmenté. On ne peut créer un lien dur que pour les fichiers, pas les dossiers.

Le lien symbolique un fichier qui pointe vers le fichier source (qui lui pointe vers son inode) et est essentiellement un raccourci vers le fichier référencé. Le lien symbolique ne possède pas le même inode que le fichier original, car c'est un fichier en lui-même, non pas une référence. Dans l'inode du lien, on n'aura pas les informations du fichier original mais son adresse. C'est une sorte de lien statique : si on déplace un fichier vers un autre répertoire ou qu'on le supprime, le lien symbolique sera brisé et ne pointera vers rien. Mais si on crée un autre fichier avec le même nom, le lien refonctionne.

💡 Pour modifier le timestamp d'un lien symbolique, il faut ajouter l'option `-h` à la commande `touch`. Sinon, ce n'est pas le timestamp du lien qui sera modifié mais celui du fichier pointé par le lien. 

> Ici, `test0`, `text1` et `test2` sont trois références du même fichier, on a créé des hardlinks de `test0`. `test4` est un symlink vers le fichier `test0` et `test5` est un symlink vers le dossier `test3`.
>``` 
> ls -li
> 38276422 -rw-r--r--  3 celinenguyen  staff   5 Jan 27 00:55 test0
> 38276422 -rw-r--r--  3 celinenguyen  staff   5 Jan 27 00:55 test1
> 38276422 -rw-r--r--  3 celinenguyen  staff   5 Jan 27 00:55 test2
> 38276423 drw-r--r--  1 celinenguyen  staff   0 Jun  1  2023 test3
> 38276434 lrwxr-xr-x  1 celinenguyen  staff   6 Jan 28 16:03 test4 -> test0
> 38276460 lrwxr-xr-x  1 celinenguyen  staff   5 Jun  1  2023 test5 -> test3
>```

### ex03 - Connecte-moi!

Pour créer une clé SSH : <https://www.youtube.com/watch?v=qixAZdj-I4I>
```
ssh-keygen -t ed25519 -C "celine.nguyentu@gmail.com"
pbcopy < ~/.ssh/id_github_ed25519.pub
```

Pour rendre nos fichier, il faut cloner le dépot trouvable sur l'intra sur notre dépot local avec `git clone [lien]`, travailler sur nos fichiers en dépot local (`git add` et `git commit`) puis envoyer le travail sur le dépot distant (`git push`). 
On est authentifié sur Vogsphere à l’aide de notre ticket Kerberos. Un ticket est automatiquement obtenu quand on se logue sur une machine. Néanmoins, au bout d’un certain temps, ce ticket expire. Si on n’arrive pas à se connecter à Vogsphere, on peut renouveler notre ticket avec la commande `kinit`.

- `klist` liste les tickets qu'on possède avec la date d'expiration.
- `kdestroy` détruit tous les tickets possédés.
- `kinit [login42]` demande un nouveau ticket. La commande demandera le password.

### ex04 - midLS

La commande `ls` liste les éléments du répertoire courant.
- `-t` trie par date/heure de modification (plus récent en premier).
- `-u` utilise la date/heure du dernier accès pour l'option `-t` ou `-l`.
- `-U` utilise la date/heure de création pour l'option `-t` ou `-l`.
- `-r` renverse l'ordre de tri.
- `-m` utilise le format de sortie de flux (une série séparée par des virgules).
- `-p` place une barre oblique après chaque nom de répertoire.
- `-F` insère une barre oblique `/` après chaque nom de répertoire, un astérisque `*` après chaque nom de fichier exécutable, un signe égal `=` si le fichier est un socket, une barre verticale `|` si le fichier est un FIFO et un `@` pour un lien symbolique. 

### ex05 - GiT commit

Un script shell est un fichier contenant une ou plusieurs commandes. Il permet d'exécuter facilement une série de commandes importante ou compliquée et des tâches de routine. On crée un script shell à l'aide d'un éditeur de texte. Il peut contenir des commandes du système d'exploitation et des commandes intégrée au shell. 

Pour exécuter un script shell, il suffit d'entrer son nom sur la ligne de commande du Terminal. On peut aussi l'exécuter sans le rendre exécutable sous contrôle d'un shell avec une commande de shell (comme `bash`).

- `bash [file].sh` exécute `file` sans le rendre exécutable avec `bash`ou `/bin/sh`.
- `git log` affiche les commits réalisés sur la branche courante en chronologie inversée.
    - `--pretty=tformat:%H` permet de contrôler le format de l'affichage.
        -  `tformat:` permet comme `format:` de spécifier de manière personalisée quelles informations afficher (fonctionnent comme `fprint`), mais fournit une sémantique "terminator" (chaque commit a le caractère de fin, c'est-à-dire une nouvelle ligne).
        - `%H` référence le hash, ou identifiant, ou empreinte du commit.
    - `-<n>` applique une limitation en nombre de commits.

### ex06 - gitignore

- `git status` montre le statut de l'arbre de travail local en détaillant l'état des fichiers modifiés, indexés et ignorés par le dépot distant.
- `git ls-files` liste les fichiers du répertoire courant qui sont dans le commit (dépot local), l'index et le répertoire de travail selon l'option utilisée.
    - `--cached` spécifie de lister les fichiers *tracked*, donc suivis par le dépot. Un fichier est suivi à partir du moment où il est indexé. C'est l'option utilisée par défaut.
    - `--stage` spécifie de lister les fichiers qui ont été indexés.
    - `--modified` spécifie de lister les fichiers indexés qui ont été modifiés depuis le dernier commit.
    - `--others` spécifie de lister les fichiers *untracked*, c'est-à-dire les fichiers créés dans le répertoire de travail qui ne sont pas pris en compte par le dépot local, ceux qui n'ont jamais été indexé ni commit. 
    - `--ignored` montre seulement les fichiers ignorés et doit être utilisée avec une option d'exclusion. 
    - `--exclude-standard` permet d'exclure les fichiers intentionnellement ignorés et exclus par l'utilisateur (avec le fichier `.gitignore` par exemple).

### ex07 - diff

- `diff [file1][file2]` indique les différences entre `file1` et `file2`.
Dans le retour de cette commande, on peut lire :
    - `<n1>c<n2>` : un changement aux lignes `<n1>` du `file1` et `<n2>` du `file2`
    - `<n1>a<n2>` : un ajout dans `test2` aux lignes `<n1>` du `file1` et `<n2>` du `file2`
    - `<n1>d<n2>` : une suppression dans `test2` aux lignes `<n1>` du `file1` et `<n2>` du `file2`
        - `<n1>` et `<n2>` sont un numéro de ligne ou un intervalle séparé par une virgule.
    - `< [text]` précise la ligne qui diffère et qu'elle provient de `file1`.
    - `> [text]` précise la ligne qui diffère et qu'elle provient de `file2`.
    - Les options `-y`, `-c` et `-u` permettent de modifier l'affichage de la sortie.
- `diff -r [directory1][directory2]` indique les différences de fichiers contenus dans les répertoires `directory1` et `directory2`.

> <table>
> <tr>
> <th> Contenu des fichiers  </th>
> <th> Commande diff </th>
> </tr>
> <tr>
> <td>
>
> | ligne |  test1   |  test2    |
> | ----- | -------- | --------- |
> |   1   | Lundi    | Lundi     |
> |   2   | Mercredi | Mardi     |
> |   3   | Jeudi    | Mercredi  |
> |   4   | Vendredi | Vendredi  |
> |   5   | Samedis  | Samedi    |
> |   6   | Dimanche | Dimanches |
> </td>
> <td>
>
> ```
> $ diff test1 test2
> 1a2
> > Mardi
> 3d3
> < Jeudi
> 5,6c5,6
> < Samedis
> < Dimanche
> ---
> > Samedi
> > Dimanches
> ```
> </td>
> </tr>
> </table>

- `diff [file1][file2] > [file].diff` sauvegarde dans le fichier `file` les modifications pour un usage ultérieur : on crée un patch.
- `patch -i [file].diff [file1]` applique les modifications enregistrées dans `file` au fichier `file1`. En d'autres termes, c'est convertir le contenu de `file1` en `file2` à l'aide du patch. L'option `-i` indique que le fichier qui suit est le patchfile. La commande `cat [file].diff | patch [file1]` est équivalente. 
    - Dans le meilleur des cas, `file1` n'a pas été modifié depuis l'enregistrement du patch et cette commande modifiera simplement ce fichier selon les modifications du patch. 
    - Si `file1` a subi des modifications depuis la création du patch, la commande `patch` sait résoudre les conflits entre les différentes versions dans la mesure du possible. 
    - Dans le pire des cas, `patch` n'est pas en mesure de résoudre tous les conflits et il appliquera tout de même les modifications possibles, préviendra l'utilisateur et créera deux fichiers :
        - `[file1].orig` contenant l'original de `file1` avant toute modification par la commande
        - `[file1].rej` contient les modifications ayant été rejetées pour cause de conflit. Ce fichier est utile pour alors corriger les différences manuellement.  
- `patch -R -i [file].diff [file2]` applique les modifications inverses du patch au fichier `file2`. En d'autres termes, c'est convertir le contenu du fichier `file2` en `file1` à l'aide du patch. Cette commande est utile lorsqu'on veut revenir à une ancienne version d'un fichier qui a été modifié via un patch. C'est pourquoi il faut penser à copier un fichier avant d'y appliquer un patch lorsqu'il en est nécessaire.

### ex08 - clean

- `find [path][options][expression]` recherche des fichiers et répertoires dans un répertoire `path` de manière récursive, c'est-à-dire dans le répertoire courant indiqué et dans ses sous-répertoires, selon des critères et conditions spécifiés par `options` et `expression`. On peut combiner plusieurs critères de recherches en utilisant plusieurs options liées par des opérateurs `-and` (utilisée par défaut), `-or`, `not` qui peuvent être groupés par `\(`et `\)`.
    - `-name [pattern]` spécifie le nom exact ou motif des fichiers recherchés. Le motif doit être écrit entre `""`. La variante `-iname` est *case-insensitive*.
    - `-type [type]` spéficie le type de fichier : `f` pour fichier, `d` pour répertoire
    - `-mtime <n>` spécifie la date de dernière modification où `<n>` est par défaut le nombre de jours précédents mais peut être personalisé avec une autre unité de temps. Les variantes `-ctime` et `-atime` utilisent la date de création et la date de dernier accès.
    - `-empty` spéficie les fichiers ou répertoires vides
    - `-print` affiche les éléments trouvés. Cette option est utilisée par défaut lorsque les options `-exec` ou `-ok` sont absents.
    - `-exec [command]{} \;` exécute une commande sur chaque fichier trouvés. Les accolades indiquent l'emplacement réservée pour le nom du fichier lorsque chaque commande est exécutée. Le point-virgule indique la fin de l'option `-exec`. La variante `-ok` oblige l'utilisateur à confirmer la commande sur chaque fichier.
    - `-delete` supprimer les fichiers et répertoires trouvés. Cette commande ne supprime pas un répertoire s'il n'est pas vide.

💡 Les caractères `;`, `(` et `)` sont des métacaractères du shell. Pour pouvoir les utiliser dans les options ou expression, il faut les précéder d'un backlash `\`.

> \* `find ./ex00 -name "*.txt"` recherche dans le répertoire `ex00` tous les fichiers et répertoires dont le nom termine par `.txt`. <br>
> \* `find ~ -type d \( -name "ex*" -or -name "Shell*" \)` recherche dans le répertoire de l'utilisateur les répertoires dont le nom commence par `ex` ou par `Shell`. <br>
> \* `find . -type f -name "*ex*" -exec grep "Hello" {} \;` recherche dans le répertoire courant les fichiers dont le nom contient `ex` et affiche les lignes dans ces derniers qui contiennent 'Hello'. <br>
> \* `find .. -type d -empty -ok rmdir {}\;` recherche dans le répertoire parent les répertoires vides et les supprime après confirmation manuelle.

### ex09 - Illusions, not tricks, Michael...

Un fichier magique est un fichier utilisé par la commande UNIX `file` pour identifier un type de fichier en examinant son contenu plutôt qu'en se basant sur son extension ou ses métadonnées. Un fichier magique est un fichier texte qui définit les règles du type de fichier selon un format spécifique. Chaque règle est détaillée sur une ligne qui se compose de 4 champs séparés d'une tabulation :
```
offset  type    test    description
!:mime file/mime-type
```
**offset** : Il indique où commencer à examiner le contenu du fichier pour chercher un motif. Il peut être une valeur absolue ou une référence symbolique à un autre décalage *(offset)* dans le fichier. En valeur absolue, on lui donne le nombre de bytes/octets à sauter avant de commencer à chercher. 
> \* `0` pour dire de chercher depuis le début du fichier. <br>
> \* `10` pour dire de sauter 10 octets et commencer à chercher au 11e octet.

**type** : Il spécifie le type de la donnée à examiner après l'*offset* et permet de savoir comment elle doit être interpretée : `string`, `long`, `byte`, `short`, `search`, etc...

**test** : Il décrit le test à effectuer sur la donnée et peut être un string, une expression ou un test plus complexe.

**description** : Il permet d'expliquer le type de fichier dans un format compréhensible, c'est généralement une phrase courte.

**!:mime** : Sur une nouvelle ligne, il spécifie le type mime du fichier. Cette ligne n'est pas obligatoire.

- `file -C -m [magicfile]` compile notre `magicfile`. Cela une meilleure performance et d'être distribué à d'autres systèmes pour être utilisé dans le fichier original. La compilation fournit un fichier `magicfile.mgc`
- `file -m [magicfile][file]` détermine le type de fichier de `file`. L'option `-m` indique qu'on utilise un fichier magique alternatif `magicfile`. 

[[retour au Sommaire]](#sommaire)
## Shell-01

### ex01 - print_groups.sh

L’environnement est une zone que le shell construit à chaque fois qu’il démarre une session qui contient des variables définissant les propriétés du système. Les variables d’environnement sont des variables qui sont définies pour le shell en cours d’utilisation et héritées par tous les shells ou processus enfant. Elles servent à transmettre des informations dans les processus qui se déclenchent depuis le shell. Les varibles de shell sont, à la différence, exclusivement contenues dans le shell dans lequel elles ont été configurées ou définies et garde un suivi des données éphémères. On peut lire, ajouter et modifier des variables d'environnement avec les commandes `printenv` et `env`. Ces variables sont utilisables dans le shell en les appelant par `$variable`.
> \* `SHELL` : cette variable décrit le shell qui interprétera les commandes saisies. Dans la plupart des cas, il s’agira de bash par défaut, mais d’autres valeurs peuvent être configurées. <br>
> \* `USER` : l’utilisateur actuellement connecté. <br>
> \* `LANG` : les paramètres actuels de langue et de localisation, y compris le codage de caractères.

- `export [KEY]=[value]` permet créer et initialiser une variable d'environement
- `unset [KEY]` supprime une variable d'environnement et de shell.
- `groups [users]` affiche l'appartenance aux groupes des utilisateurs spécifiés. Par défaut, elle donne l'appartenance de l'utilisateur actuel. Cette commande a été rendue obsolète par `id -Gn` qui est équivalent.
- `id [options][user]` affiche les identifications système d'un utilisateur : nom d'utilisateur, id réel d'utilisateur, nom des groupes et id réel des groupes. Par défaut, elle prend l'utilisateur actuel.
    - `-G` affiche uniquement les id de groupes (effectif, réel et supplémentaire) sur une même ligne séparés par des espaces.
    - `-n` affiche les noms plutôt que les id lorsque l'option est utilisée avec `-G`.
- `tr [options][string1][string2]` traduit (transforme) et/ou supprime les caractères de l'entrée standard en fonction des `options` et des chaînes spécifiées dans les variables `string1` et `string2`. Cette commande traite non pas la chaînes de caractères `string` mais les caractères contenus dans celle-ci individuellement.
    - Sans option et si `string1` et `string2` sont tout deux spécifiés, la commande remplace chaque caractères dans `string1` trouvé dans l'entrée par le caractère dans `string2` à la même position.
    - `-d [string]` (avec un seul string) supprime chaque occurence des caractères dans `string` 
> \* `tr 'ui' 'ou'` remplace les `u` par des `i` et les `o` par des `u`. <br>
> \* `tr '[a-m]' '[A-M]'` remplace les lettres minuscule de A à M par leur majucule. <br>
> \* `tr '[:upper:]' '[:lower:]'` remplace toutes les majuscules en minuscules.

### ex02 - find_sh

- `basename [string][suffix]` retourne le nom de base d'un fichier contenu dans une chaîne de caractères `string`. Cette commande supprime tous les `/` en fin de chaîne, puis le préfixe de la chaîne jusqu'au dernier `/` inclus, et enfin si le `suffix` n'est pas identique au reste de la chaîne, supprime le `suffix`. La condition de la dernière étape permet de considérer les fichiers cachés par exemple. 

### ex03 - count_files

- `wc [options][file]` compte et affiche le nombre de lignes, de mots et de caractères de `file` ou de l'entrée standard.
    - `-l` permet de compter uniquement le nombre de lignes.

### ex04 - MAC

Une adresse MAC *(Media Access Control)*, aussi appelée adresse ethernet, est un identifiant physique unique stocké dans une carte réseau. Chaque interface réseau a sa propre adresse MAC, donc un même ordinateur peut avoir plusieurs adresses MAC.
- `ifconfig` configure ou affiche les paramètres d'interface réseau.
- `cut [options][file]` couper chaque ligne de `file` pour en récupérer une partie
    - `-d` spécifie le séparateur que l'on veut utiliser
    - `-f` spécifie le numéro des champs que l'on veut extraire
> \* `cut -d : -f 3` affiche le 3ème champs de chaque ligne avec `:` qui sépare les champs. <br>
- `sed [options][command][file]` *(stream editor)* modifie un texte dans `file` ou depuis l'entrée standard. Sa principale fonction consiste à chercher des chaînes de caractères pour les remplacer par une autre. 
    - `-e` indique l'utilisation de un ou plusieurs script SED. L'option doit être ajouté avant chaque script SED. 
    - `-n` indique que seules les lignes concernées par la commande s'affichent.
    - `-i` indique la création d'un fichier temporaire destiné à remplacer le fichier d'origine. Cette option permet de modifier directement le fichier d'origine. À défaut, on peut rediriger le résultat de la commande `sed` dans un nouveau fichier. 
    - `-f` indique que le script est extrait d'un fichier donc doit recourir à un fichier supplémentaire.
    - `-r` permet à la commande d'utiliser les expressions régulières étendues.
    - La syntaxe des commandes `[command]` sont propres à `sed` et sont entre `''` : on les appelle aussi script SED. Elles contiennent une commande SED qui donne la tâche à effectuer, une adresse qui indique la cible de la commande (numéro de ligne ou une expression régulière de la chaîne de caractères ciblé) et parfois un texte de remplacement ou une option de commande SED *(flag)*. Les expression du script SED est entouré de `/` pour les séparés des autres informations.
        - **commandes** : `a` ajoute des lignes, `c` modifie les lignes, `d` supprime des lignes, `p` affiches des lignes, `s` remplace une chaîne de caractères spécifiée par une autre. 
        - **options** : `g` applique la commande à toutes les occurences dans la même ligne, `p` affiche les lignes ciblées et/ou modifiées, `i` rend la commande *case-insensitive*.
> \* `sed -n '10,20p' text.txt` affiche les lignes 10 à 20 de `text.txt`. <br>
> \* `sed -n '/199./p' text.txt` affiche les lignes qui contiennent des années de 1990 à 1999. <br>
> \* `sed -n '/199[2-7]/p' text.txt` affiche les lignes avec des années de 1992 à 1997. <br>
> \* `sed -n -e '1p' -e '/Hello/p' text.txt` affiche la 1ère ligne et celles avec "Hello". <br>
> \* `sed -i -e '1s/Hello/Salut/g' text.txt` remplace dans la 1ère ligne "Hello" par "Salut" à chaque occurence de "Hello" dans la ligne. <br>
> \* `sed 's/Hello/Salut/2 text.txt` remplace "Hello" par "Salut" seulement à la 2ème occurence de "Hello" dans chaque ligne. <br>
> \* `sed -i -e 's/$/ endline/' text.txt` ajoute " endline" à la fin de chaque ligne. <br>
> \* `sed -i -e '2d; 7d' text.txt` supprime les 2ème et 7ème  lignes. <br>
> \* `sed '/^#/d' text.txt` supprime les lignes qui commencent par `#`.

💡 On aurait pu utiliser la commande `awk` à la place de `sed` *(cf. ex06)*.

- `grep [options][pattern][file]` recherche/capture des motifs ou chaîne de caractères définis par `pattern` dans un (ou plusieurs) fichier `file`. Le modèle de recherche `pattern` est une expression régulière. Lorsqu'elle trouve une correspondace, la commande affiche la ligne concernée. La commande `rgrep` est une variante qui équivaut à `grep -r`. D'autres variantes existent mais sont désormais obsolètes.
    - `-c` ne cherche pas le motif ciblé mais compte le nombre de lignes qui le contiennent.
    - `-n` affiche aussi le numéro de ligne où se trouve l'occurence.
    - `-i` indique d'ignorer la casse dans lors de la recherche.
    - `-w` permet de rechercher des mots entiers uniquement, c'est-à-dire les occurences du motif qui sont précédés et suivis d'un espace.
    - `-o` n'affiche que les parties des lignes qui correspondent à la recherche.
    - `-v` inverse la recherche en affichant les lignes excluent donc qui ne correspondent pas au modèle de recherche.
    - `-e` permet de rechercher plusieurs motifs à la fois en précédant chaque motif de `-e`.
    - `-E` permet de rechercher un motif défini par une expression régulière étendue.
    - `-l` donne uniquement le nom des fichiers (une fois) qui contiennent le motif. Si cette option est utilisée en combinaison avec `-c` ou `-n`, elle les annule.
    - `-r` permet une recherche récursive dans les sous-répertoires. La commande affichera aussi le nom du fichier qui contient le motif.
    - `--color=always` colorise le résultat à la sortie de la commande.

> \* `grep Hello text.txt` affiche les lignes qui contiennent "Hello". <br>
> \* `grep -c -i Hello text.txt` compte le nombre d'occurences de "Hello" ou "hello". <br>
> \* `grep -l Hello /test/*txt` affiche les noms des fichiers dans le dossier `test` qui contiennent "Hello". <br>


### ex05 - Can you create it ?

Certains caractères spéciaux sont des métacaractères du shell ou d'expression régulières et sont interprétés comme des commandes, options ou des variables.

**Métacaractères du shell** : <br>
\- `-` peut être interprété comme une option ou comme une entrée/sortie standard par certaines commandes.<br>
\- `#` peut interpréter ce qui suit comme un commentaire par certaines commandes. <br>
\- `\` signifie un retour à la ligne au milieu d'une commande ou permet d'échapper à un métacaractère lorsqu'il le précède. <br>
\- `;` sépare deux commande sur une même ligne. <br>
\- `|` utilise la sortie d'une première commande comme entrée d'une seconde commande. <br>
\- `''` délimite une chaîne de caractères avec des espaces. À l'intérieur, certains métacaractères perdent leur significations. <br>
\- `""` délimite une chaîne de caractères avec des espaces. À l'intérieur, certains métacaractères perdent leur significations. <br>
\- `` ` `` capture la sortie standard pour former un nouvel argument ou une nouvelle commande. <br>
\- `{}` permet de grouper un ensemble de commandes et de les exécuter dans le shell courant. <br>
\- `()` permet de grouper un ensemble de commandes et de les exécuter dans le shell enfant. <br>
\- `*` désigne une chaîne de caractères quelconque sauf le premier `.` d'un fichier caché. <br>
\- `?` désigne un caractère quelconque sauf le premier `.` d'un fichier caché. <br>
\- `[]` désigne les caractères entre crochets, définis par énumération ou par un intervalle. <br>
\- `[!]` désigne l'ensemble des caractères sauf les caractères entre crochets après `!`, définis par énumération ou par un intervalle. <br>
\- `$` indique que ce qui suit doit être interprété comme une variable et désigne sa valeur. <br>
\- `||` et `&&` sont des opérateurs conditionnels d'exécution.


**Métacaractères des expressions régulières (RegEx)** : <br>
\- `.` désigne un caractère quelconque. <br>
\- `*` désigne une occurence quelconque (d'aucune à plusieurs) du caractère qui précède. <br>
\- `+` désigne une occurence quelconque (d'une à plusieurs) du caractère qui précède. <br>
\- `^` désigne un début de ligne. <br>
\- `$` désigne une fin de ligne. <br>
\- `\` permet d'échapper au métacaractère RegEx qui le suit ou de protéger un caractère normal. <br>
\- `{n}` désigne n répétitions du caractère précédent. <br>
\- `[]` désigne les caractères entre crochets, définis par énumération ou par un intervalle. <br>
\- `[^]` désigne l'ensemble des caractères sauf les caractères entre crochets après `^`, définis par énumération ou par un intervalle. <br>


💡 On appelle *wildcard* les métacaractères qui remplacent ou représentent un ou plusieurs caractères. 

Pour utiliser les métacaractères dans des noms de fichiers, il a plusieurs possibilités:
- `--` avant un fichier qui a pour préfix `-` : le *double-dash* indique la fin des options donc ce qui suit sera traité comme des noms de fichiers. 
- `<` ou `>` avant un fichier nommé `-` pour qu'il ne soit pas considéré comme une entrée standard. Cette méthode ne fonctionne qu'avec certaines commandes. 
- `./` avant le nom d'un fichier spécifie qu'il en est un, en utilisant la syntaxe du chemin d'un fichier, ici situé dans le répertoire courant. Cela ne protège pas les caractères `;`, `.`, `'`, `*`, `$`, `?`, `\` (et d'autres ?).
- `""` autour d'un nom de fichier pour le considérer comme un unique string. Cela ne protège pas les caractères `\`, `$` et `` ` `` qui restent toujours interprétés, et ne se protège pas lui-même.
- `''` autour d'un nom de fichier pour le considérer comme un unique string. Cela ne protège pas le caractère `\` et ne se protège pas lui même.
- `\` avant chaque caractère spécial pour annuler sa signification. C'est la méthode la plus fastidieuse mais la plus personalisable et efficace pour les cas complexes. 

> \* `touch -- -test` crée un fichier nommé `-test`. <br>
> \* `cat < -` affiche le fichier nommé `-`. <br>
> \* `rm ./-*` supprime tous les fichiers dont le nom commence par `-`. <br>
> \* `touch "#test"` crée un fichier nommé `#test`. <br>
> \* `touch '$test'` crée un fichier nommé `$test`. <br>
> \* `touch \"\\\?\*\'\#\-\;\'\"` crée un fichier nommé `"\?*'#-;'"`

### ex06 - Skip

- `awk [pattern]{[action]}[file]` applique un certain nombre d'actions sur un fichier. Le `pattern` permet de déterminer sur quels enregistrements de `file` est appliqué l'`action`. Un enregistrement est une chaîne de caractères séparée par un retour chariot, c'est en général une ligne. Un champs est une chaîne de caractères séparée par un espace, c'est en général un mot. On accède à chaque champs de l'enregistrement courant par la variable `$1`, `$2`, ..., `$NF`. La variable `$0` correspond à l'enregistrement complet. 
    - `-F` permet de spécifier le caractère qui sépare les champs si ce n'est pas un espace.
    - `-v` définit une variable qui sera par la suite utilisée dans `action`. Chaque varible définit est précédée de `-v`.
    - Le `pattern` ou motif, peut être une expression régulière, une expression de comparaison, une expression `BEGIN` ou `END`, une caractérisation des lignes. 
    - L'`action` peut être une impression, une affectation, un contrôle de flots ou une fonction prédéfinie.
    - Les variables prédéfinies sont :
        - `NF` : le nombre de champs de l'enregistrement courant
        - `NR` : le nombre d'enregistrements déjà lu
        - `FNR` : le nombre d'enregistrements du fichier

> \* `awk '{print $NF}' text.txt` imprime le dernier champs de chaque ligne de `text.txt`. <br>
> \* `awk 'length($0)>75 {print}' text.txt` imprime les lignes de plus de 75 caractères. <br>
> \* `awk -F "," '{ $2 = "" ; print $0 }' text.txt` imprime chaque ligne après avoir effacé le 2e champs. <br>
> \* `awk '/Hello/ {print $2}' text.txt` imprime le 2e champs de chaque ligne qui contient "Hello". <br>
> \* `awk 'END {print NR}' text.txt` imprime le nombre total de lignes du fichier. <br>
> \* `awk -v a=10 '{print (NR+a)}' text.txt` imprime chaque numéro de ligne incrémenté de 10.

### ex07 - r_dwssap

Le fichier `/etc/passwd` est une base de données textuelle qui permet de garder la trace de chaque utilisateur enregistré qui a accès à un système. Chaque enregistrement décrit un compte d'utilisateur et se compose de sept champs séparés par `:`.

```
Login:Password:UserID:PrincipleGroup:Gecos:HomeDirectory:Shell
```

**Login** (nom d'utilisateur) : C'est la chaîne de caractères que l'utilisateur entre lorsqu'il se connecte au système. Il est unique et sa longueur doit être comprise entre 1 et 32 caractères.

**Password** (mot de passe chifffré) : Cet attribut indique si un mot de passe existe ou si le compte est bloqué. Si l'ID utilisateur possède un mot de passe, la zone de mot de passe contient un point d'exclamation `!`, sinon il contient un point astérisque `*`. Les mots de passe chiffrés ne sont pas stockés dans le fichier `/etc/passwd` lisible par tous les utilisateurs mais dans le fichier `/etc/security/passwd` qui est uniquement visible par l'utilisateur root. 

**UserID ou UID** (numéro ID d'utilisateur) : C'est un nombre utilisé par le système d'exploitation à des fins internes. La valeur est un entier décimal unique. L'UID 0 est réservé à l'utilisateur root, les UID 1-99 sont pour les autres comptes prédéfinis et les UID 100-999 sont réservés par le système pour les comptes administratifs. 

**PrincipleGroup ou GID** (numéro d'ID groupe de l'utilisateur) : C'est un nombre qui identifie le groupe principal de l'utilisateur. La valeur est un entier décimal unique. Les utilisateurs des systèmes LINUX et UNIX sont assignés à un ou plusieurs groupes pour plusieurs raisons : partager des fichiers avec un petit nombre de personnes, faciliter la gestion et surveillance des utilisateurs, donner un accès spécial aux fichiers, répertoires ou périphériques. 

**Gecos** (nom complet de l'utilisateur) : C'est un commentaire dans une chaîne de caractères qui décrit la personne ou le compte. Cela peut être un ensemble de valeurs séparées par des virgules, fournissant le nom complet de l'utilisateur et ses coordonnées. 

**HomeDirectory** (répertoire de base) : C'est le chemin absolu vers le répertoire personel de l'utilisateur, celui dans lequel il se trouve lorsqu'il se connecte. Si l'utilisateur n'a pas de répertoire de base défini, on utilise celui de l'utilisateur invité.

**Shell** (shell de connexion) : C'est le chemin absolu d'un shell (en général) ou d'une commande. C'est le programme qui est lancé chaque fois que l'utilisateur se connecte au système. Il s'agit généralement d'une interface en ligne de commande. Si aucun shell n'est défini pour un utilisateur, le shell système est utilisé.

💡 Il existe des commandes qui permettent de modifier ce fichier : `mkuser`, `rmuser`, `lsuser`, `chuser`, `chfn`, `chsh`, etc...

- `rev [file]` inverse les caractères dans chaque ligne du fichier.
- `sort [file]` trie le contenu de `file` selon le code ASCII. Si plusieurs fichiers sont spécifiés, la commande les concatène et les traite comme un seul fichier. 
    - `-r` inverse l'ordre du tri.
    - `-f` ignore la casse en remplaçant toutes les minuscules par des majuscules pour la comparaison.
    - `-n` tri les valeurs numériques par leur valeur arithmétique.

### ex08 - add_chelou

Une base est un système de numérotation positionnel (versus un système additif comme les nombres romains) décrit par une gamme de symboles différents qui sont utilisés pour représenter un nombre. Chaque symbole représente une unité et son emplacement/rang représente aussi un certain nombre d'unités. Lorsqu'on compte, on énumère chaque symbole un à un dans l'ordre décrit par sa base et lorsqu'on arrive au dernier symbole le rang est désormais plein. Pour continuer à compter, on incrémente le rang suivant et on réinitialise le rang qui était plein. Si le rang suivant est lui au plein, on incrémente le rang qui suit et on réinitialise les rangs pleins.  

**Base 10 (système décimal)**<br>
Il s'appuie sur 10 symboles : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9. C'est le système qu'on utilise dans la vie de tous les jours. Les rangs de ce système sont les unités, les dizaines, les centaines ... <br>
$\overline{678}^{10} = \bold{6}\times10^2 + \bold{7}\times10^1 + \bold{8}$

**Base 2 (système binaire)**<br>
Il s'appuie sur 2 symboles : 0 et 1. C'est le système qu'utilisent les ordinateurs où les rangs de ce système sont des bits. <br>
$\overline{10010}^2= \bold{1}\times2^4 + \bold{0}\times2^3 + \bold{0}\times2^2 + \bold{1}\times2^1 + \bold{0} = \overline{18}^{10} $ <br>
Pour faire la conversion du décimal au binaire : <br>
$
18= 9 \times 2 + \bold0 \\
9 = 4 \times 2  + \bold1 \\
4 = 2 \times 2 + \bold0 \\
2 = 1 \times 2 + \bold0 \\
1 = 0 \times 2 + \bold1 
$

**Base 16 (système héxadécimal)** <br>
Il s'appuie sur 16 symboles : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A (10), B (11), C (12), D (13), E (14), F (15). <br>
$\overline{B8}^{16} = \bold{11} \times 16^1 + \bold{8} = \overline{184}^{10}$ <br>
Pour faire la conversion du décimal au héxadécimal : <br>
$
184 = 11 \times 16 + \bold8 \\
11 = 0 \times 16  + \bold{11} 
$

| Base 10 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
| ------- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| Base 2 | 0 | 1 | 10 | 11 | 100 | 101 | 110 | 111 | 1000 | 1001 | 1010 | 1011 | 1100 | 1101 | 1110 | 1111 | 10000 | 10001 | 10010 | 10011 | 10100 |
| Base 16 | 0 | 1 | 10 | 11 | 100 | 101 | 110 | 111 | 1000 | 1001 | A | B | C | D | E | F | 10 | 11 | 12 | 13 | 14 |
| Base ’\\"?! | ’ | \ | " | ? | ! | \’ | \\\\ | \\" | \\? | \\! | "’ | "\ | "" | "? | "! | ?’ | ?\ | ?" | ?? | ?! | !’ |
| Base mrdoc | m | r | d | o | c | rm | rr | rd | ro | rc | dm | dr | dd | do | dc | om | or | od | oo | oc | cm |
| Base gtaio luSnemf | g | t | a | i | o | ␣ | l | u | S | n | e | m | f | tg | tt | ta | ti | to | t␣ | tl | tu |

- `bc` ouvre un programme de calculatrice dans le shell que l'on quitte avec `quit`. On peut l'utiliser *inline* en pipant le calcul avec `echo`. Cette commande possède un outil pour convertir les nombres d'une base à une autre. Les ordres dans `echo` sont séparés pas `;` et sont constitué d'un ou plusieurs types de base et du nombre à convertir. Le type de base par défaut est le décimal.
    - `ibase` est la base d'entrée *(input base)*
    - `obase` est la base de sortie *(output base)*
    - Lorsqu'on spécifie les deux types de base, toujours donner `obase` avant `ibase`, sinon cela change l'interprétation de la commande. Une fois que la commande lit `ibase`, elle va interpréter l'input de `obase` en base indiquée dans `ibase`.
> \* `echo '2+2' | bc` affiche 4. <br>
> \* `echo 'obase=2;42' | bc` convertit le décimal 42 en binaire et affiche 101010. <br>
> \* `echo 'ibase=2;101010' | bc` convertit le binaire 101010 en décimal et affiche 42. <br>
> \* `echo 'obase=2;ibase=16;2A' | bc` convertit l'héxadécimal 2A en binaire et affiche 101010. <br>

### Quelques commandes supplémentaires
- `[command] 2 > &1` permet de rediriger la sortie d'erreur (2) vers la sortie standard (1). 
- `[command] 2 > [file]` permet de rediriger la sortie d'erreur (2) vers un fichier `file`.
- `[command] > /dev/null` permet de rediriger la sortie standard vers un fichier `/dev/null` qui va juste effacer le contenu. C'est pratique lorsque l'on veut effacer la sortie standard des commandes qui ont fonctionné et ne garder que la sortie d'erreur pour débugger. 
- `[command1] | xargs [options][command2]` permet convertir l'entrée standard de `command2`, provenant de la sortie standard de `command1`, en argument de commande pour `command2`.

[[retour au Sommaire]](#sommaire)
## C-00

- La fonction `main` peut retourner un void. Elle est obligatoire dans un programme. 

- `write(1, 'yo', 2)` pour afficher des char selon le code ASCII. 
La fonction va afficher les bits correspondant au char choisi. Si l'on veut afficher un entier, ce n'est pas une valeur lisible par l'humain donc on ne verra rien dans le terminal. Il faut d'abord convertir l'entier dans sa représentation lisible avec la fonction `sprintf`. le buffer doit être une adresse, reference, ou un string.
un char 'a' est en réalité un code ascii

- `printf("%d", n)` pour afficher des int

[[retour au Sommaire]](#sommaire)
## C-01

Memory addresses in C : <https://www.studysmarter.co.uk/explanations/computer-science/computer-programming/c-memory-address/#:~:text=To%20see%20a%20memory%20address,of%20the%20variable%20%27var%27.>
