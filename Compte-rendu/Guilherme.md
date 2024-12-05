# Compte Rendu Guilherme VENTAPANE RODRIGUES

## Lundi 23 Septembre 2024
- Essai d'adapter Altium pour l'installer sur Mac.
- Problème d'installation, Jarod va l'installer sur Windows.
- Découverte d'un problème de liaison entre VCC et la masse.

## Mardi 12 Novembre 2024
- Nous avons vu avec Monsieur Peter que le projet de l'année dernière avait plusieurs autres problèmes donc on devra tout réfaire.
- Court-circuit à l'entrée du circuit.
  ![image](https://github.com/user-attachments/assets/4c9664af-8ab2-4228-a892-88fa458c01a7)
- Tous les composants sont liés à la masse.
  ![image](https://github.com/user-attachments/assets/6b201a64-f41a-4265-9bcb-72407d0c83f5)
- LEDs alimentées entre masse et masse.
  ![image](https://github.com/user-attachments/assets/b70d72b0-e847-4489-95e2-e112881b2ec5)
- Utilisation des NMOS à la place des PMOS.
  ![image](https://github.com/user-attachments/assets/4eef47ae-e349-4b70-af49-58a68e484c0d)
- LEDs liées entre la masse et rien.
  ![image](https://github.com/user-attachments/assets/49a45590-99e6-4a7c-a344-1f0d12d132e3)  

- Recherche de la documentation des composants principaux du circuit. Une partie était disponible sur GitHub.
- Commencé à regarder comment importer des nouveaux composants dans Fusion.
- Écriture du brouillon du cahier des charges.

### Liste de composants :
- SimCom SIM7000G : [https://www.manualslib.com/manual/1498555/Simcom-Sim7000g.html?page=20#manual](https://www.manualslib.com/manual/1498555/Simcom-Sim7000g.html?page=20#manual)
- ESP32 Wrover B.
- Antenne GSM.
- ...

## Du 18 au 20 Novembre 2024 (à la maison)
- Créé un compte étudiant Autodesk.
- Téléchargé le logiciel Autodesk Fusion.
- Travaillé à la maison pour comprendre comment utiliser le logiciel.
- Pris des cours d'électronique en ligne pour Fusion.
- Dessiné et simulé des circuits simples pour m'entraîner.

## Lundi 25 Novembre 2024
- Passé le cahier des charges de la version lablette à la version Markdown, sur GitHub.
- Ouverture des fichiers de dessin dans Eagle.
- Ajout de la documentation et des schémas sur GitHub.
- Recherche de la documentation des composants :
  - TXB0108PWR : [https://www.ti.com/lit/ds/symlink/txb0108.pdf](https://www.ti.com/lit/ds/symlink/txb0108.pdf)
  - Cherché le symbol et le footprint des composants pour pouvoir les ajouter dans Eagle.
  - Ajouté les composants dans Eagle.
  - Commencé à reconstruire le circuit.

## Mardi 26 Novembre 2024
- Revenu au schéma précédent car il avait déjà les composants nécessaires.
- Remplacé une entrée par 3V.
- Modifié la liste de composants.

- Problèmes trouvés et corrigés avec des composants :
  - R9 : Rien de branché.
  - JP2 lié à rien.
  - R20 et R18 liées à rien -> Branché à Q7, C5, D3 et la masse.
  - Q8 : l'une des pattes pas branchée !!! (toujours pas réglé).
  - R10 : Une seule patte branchée.
  - LED R1 liée que dans une seule patte.

## Jeudi 5 Décembre 2024 (à la maison)
- Continué à faire le routage du circuit.
- TODO : Vérifier si j'ai choisi la bonne taille pour les pistes.
- Appris comment faire le routage de la partie bottom avec : [https://www.autodesk.com/products/fusion-360/blog/routing-autorouting-pcb-layout-basics-2/](https://www.autodesk.com/products/fusion-360/blog/routing-autorouting-pcb-layout-basics-2/)
- Beaucoup avancé le routage top et bottom.