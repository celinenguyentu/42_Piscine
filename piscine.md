# Piscine 42

## Sommaire

- [Shell-00](#Shell-00)
- [Shell-01](#Shell-01)

---

## Shell-00 

### ex00 - Z

- `cat [file]` lit et affiche le contenu du fichier `file`. Si ce fichier ne termine pas avec une nouvelle ligne, la commande affiche `%` à la fin de son contenu.
- `echo '[text]'` affiche le `text` tel qu'il est écrit alors que `echo "[text]"` affiche la valeur de la variable `text` car il est interprété par le shell. La commande `printf '[text]'` permet la même chose à la différence qu'elle n'ajoute pas automatiquement un retour à la ligne, il faut alors l'inclure avec `\n` entre les guillemets.
- `[command] > [file]` redirige le résultat de `command` vers `file` en l'écrasant. Pour ajouter une nouvelle ligne à la suite du contenu de `file`, il faut utiliser `[command] >> [file]`.

### ex01 - testShell00 

- `touch [file]` crée le fichier `file` dans le répertoire courant.
- `ls -l` liste le contenu du répertoire courant et l'option `-l` (format long) permet d'afficher des informations supplémentaires sur les fichiers et répertoires qu'il contient. 

Chaque ligne correspond à un élément et comporte les colonnes :
1. permissions
2. nombre de liens durs _(hardlink)_ qui référencent ce fichier(sous-répertoire de niveau 1)
3. propriétaire
4. groupe de propriétaires
5. taille en octets (dépend du contenu du fichier)
6. date de la dernière modification
7. nom du fichier ou dossier et lien éventuel

Les permissions sont les droits que possède un utilisateur sur le fichier ou dossier. Elle est constituée de 10 caractères. Le premier caractère indique s'il s'agit d'un fichier `-`, d'un répertoire _(directory)_ `d`, d'un lien `l`, d'un caractère `c` ou d'un block `b``. Les neufs autres indiquent, par groupe de trois, les droits du propriétaire, du groupe et des autres utilisateurs à l'aide des caractères `r` _(read)_, `w` _(write)_, `x` _(execute)_ dans cet ordre, chacun remplacé par `-` lorsque ce droit n'est pas attribué. 

> ex. `-r--r-xr-x`: un fichier que le propriétaire peut lire, le groupe peut lire et exécuter, et les autres peuvent lire et exécuter.

- `chmod [permissions][file]` modifie les permissions du fichier

Pour modifier les permissions en mode symbolique, on utilise les lettres désignant les catégories d'utilisateurs (`u` propriétaire, `g` groupe, `o` autres, `a` tous) suivis de `+`, `-` ou `=`(ajout, suppression ou définition) et des droits d'accès sous forme de lettre.

> ex. `chmod ugo+rw fichier.txt` équivaut à `chmod a+rw fichier.txt` et ajoute à tous le droit de lecture et d'écriture.

> ex. `chmod go-w fichier.txt` retire le droit d'écriture au groupe et aux autres.

Pour modifier les permissions en mode octal, on associe un chiffre à un ensemble de droits attribué à chacune des catégorie d'utilisateurs.  

| Valeur octal      | 0     | 1        | 2      | 3                | 4    | 5              | 6            | 7    |
| ----------------- | ----- | -------- | ------ | ---------------- | ---- | -------------- | ------------ | ---- |
| Valeur symbolique | ---   | --x      | -w-    | -wx              | r--  | r-x            | rw-          | rwx  |
| Droits            | aucun | exécuter | écrire | écrire, exécuter | lire | lire, exécuter | lire, écrire | tous |

> ex. `chmod 750 fichier.txt` attribue tous les droits au propriétaire, le droit de lire et d'exécuter au groupe, aucun droit aux autres.

Parfois sur OSX, les permissions sont suivies de `@` qui indique que le fichier possède des attributs étendus (des informations supplémentaires comme l'encodage). On les affiche avec `xattr -l [file]` et on les supprime avec `xattr -c [file]`.

- `touch -t [YYYYMMDDhhmm[.ss]][file]` modifie la date de création et modification de _(timestamp)_ `file`.
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

> ex. Ici, `test0`, `text1` et `test2` sont trois références du même fichier, on a créé des hardlinks de `test0`. `test4` est un symlink vers le fichier `test0` et `test5` est un symlink vers le dossier `test3`.
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
- `-F` insère une barre oblique après chaque nom de répertoire, un astérisque après chaque nom de fichier exécutable, un signe égal si le fichier est un socket, une barre verticale si le fichier est un FIFO et un @ pour un lien symbolique. 

### ex05 - GiT commit

Un script shell est un fichier contenant une ou plusieurs commandes. Il permet d'exécuter facilement une série de commandes importante ou compliquée et des tâches de routine. On crée un script shell à l'aide d'un éditeur de texte. Il peut contenir des commandes du système d'exploitation et des commandes intégrée au shell. 

Pour exécuter un script shell, il suffit d'entrer son nom sur la ligne de commande du Terminal. On peut aussi l'exécuter sans le rendre exécutable sous contrôle d'un shell avec une commande de shell (comme `bash`).

- `bash [file].sh` exécute `file` sans le rendre exécutable avec `bash`.
- `[command] | cat -e` lit et affiche le résultat de la `command` en montrant les caractères non affichables et avec `$` à la fin de chaque ligne avec l'option `-e`.
- `git log` affiche les commits réalisés sur la branche courante en chronologie inversée.
    - `--pretty=tformat:%H` permet de contrôler le format de l'affichage.
        -  `tformat:` permet comme `format:` de spécifier de manière personalisée quelles informations afficher (fonctionnent comme `fprint`), mais fournit une sémantique "terminator" (chaque commit a le caractère de fin, c'est-à-dire une nouvelle ligne).
        - `%H` référence le hash, ou identifiant, ou empreinte du commit.
    - `-5` applique une limitation en nombre de commits, ici 5.

### ex06 - gitignore

- `git status` montre le statut de l'arbre de travail local en détaillant l'état des fichiers modifiés, indexés et ignorés par le dépot distant.
- `git ls-files` liste les fichiers du répertoire courant qui sont dans le commit (dépot local), l'index et le répertoire de travail.
    - `--cached` spécifie de lister les fichiers _tracked_, donc suivis par le dépot. Un fichier est suivi à partir du moment où il est indexé.
    - `--modified` spécifie de lister les fichiers indexés qui ont été modifiés depuis le dernier commit.
    - `--stage` spécifie de lister les fichiers qui sont indexés.
    - `--others` spécifie de lister les fichiers _untracked_, c'est-à-dire ignorés, qui ne sont pas pris en compte par le dépot local, ceux qui n'ont jamais été indexé ni commit. 
    - `--ignored` montre seulement les fichiers ignorés. 
    - `--exclude-standard` permet d'exclure les fichiers intentionnellement ignorés et exclus par l'utilisateur (avec le fichier `.gitignore` par exemple) lorsque l'options `others` est utilisée.

### ex07 - diff
### ex08 - clean
### ex09 - Illusions, not tricks, Michael...



[[retour au Sommaire]](#Sommaire)
## Shell-01