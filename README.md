# JsonReader

## Description

Ce projet a pour objectif de créer une librairie permettant la manipulation de donnée au format .json.
Cela inclu la lecture, la manipulation dans un programme, la conversion à partir, et vers des chaînes de caractères/fichiers aux format .json.

## Utilisation

Actuellement la librairie n'est disponible que pour linux.
Pour l'utiliser il faut tout d'abord compiler la libraire en utilisant le makefile inclu dans le dossier JsonReader.
Ce makefile produira une archive dans le dossier ./JsonReader/bin.
Afin d'être utilisé dans un programme externe il suffit d'inclure les headers de la librairie dans votre projet, et d'inclure l'archive de la librairie lors de la compilation.

## Exemple

Vous pourrez trouver dans ce projet, un programme fournissant un exemple d'utilisation de la librairie.
Il faudra tout d'abord compiler la librairie comme décrit précédemment et inclure l'archive dans le dossier lib/ de l'exemple.
Il suffit ensuite de lancer le makefile et d'éxécuter le programme ./Exemple/exemple.

## Auteur

 - Cuadros Nicolas

## License 

Le code est libre, vous pouvez l'utiliser pour ce que vous souhaitez. Mais citer l'utilisation de cette libraire et son auteur est très appréciable.

## ToDos

- [ ] Ajouter des commentaires aux sources, cela va arriver prochainement. 
- [ ] Ajouter la gestion d'exception lors du parsing et de la manipulation des objets Json.
- [ ] Ajouter une meilleure gestion de la conversion vers/à partir du json. Notamment la conversion de map et de vector.
- [ ] Ajouter la gestion des commentaires lors du parsing, cela n'est pas encore géré et causera un segemntation fault.
- [ ] Améliorer le readme.



