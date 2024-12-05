# Compte Rendu Guilherme VENTAPANE RODRIGUES

## 23 Septembre 2024
- Essai d'adapter Altium pour l'installer sur Mac.
- Problème d'installation, Jarod va l'installer sur Windows.
- Découverte d'un problème de liaison entre VCC et la masse.

## 12 Novembre 2024
- Nous avons vu avec Monsieur Peter que le projet de l'année dernière avait plusieurs autres problèmes donc on devra tout réfaire.
- Recherche de la documentation des composants principaux du circuit. Une partie était disponible sur GitHub.
- Commencé à regarder comment importer des nouveaux composants dans Fusion.
- Écriture du bruillon du cahier de charges.

### Liste de composants:
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

## 25 Novembre 2024
- Passé le Cahier de Charges de la version lablette à la version MarkDown, sur GitHub.
- Ouverture des fichiers de dessin dans Eagle.
- Rajout de la documentation et des schémas sur GitHub.
- Recherche de la documentation des composants:
*** Composants : ***
- TXB0108PWR : https://www.ti.com/lit/ds/symlink/txb0108.pdf
- Cherché le Symbol et Footprint des composants pour pouvoir les rajouté dans Eagle.
- Rajouté les composants dans Eagle.
- Commencé à reconstruire le circuit.

## 26 Novembre 2024
- Revenu au schéma précedent car il avait déjà les composants nécessaire.
- Remplacé une entrée par 3V.
- Modifié la 


- Problémes trouvés, et corrigés, avec des composants:
        - R9 : Rien de branché.
        - JP2 lié à rien.
        - R20 et R18 liées à rien -> Branché à Q7, C5, D3 et la masse.
        - Q8 : l'une des pates pas branchées !!!(tjrs pas reglé).
        - R10 : Qu'une pate branchée
        - LED R1 lié que dans une seule pate

## 5 Décembre 2024 (à la maison)
- Continué à faire le routage du circuit
TODO: Vérifier si j'ai choisi la bonne taille pour les pistes