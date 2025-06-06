<h1 align="center" color="#009900">📝 Compte Rendu | Guilherme VENTAPANE RODRIGUES</h1>
<h2>Sommaire:</h2>

- [Partie 1 : **Avant** la **présentation 1**](#partie-1--avant-la-présentation-1)
  - [Lundi 23 Septembre 2024](#lundi-23-septembre-2024)
  - [Mardi 12 Novembre 2024](#mardi-12-novembre-2024)
    - [Liste de composants :](#liste-de-composants-)
  - [Du 18 au 20 Novembre 2024 (à la maison)](#du-18-au-20-novembre-2024-à-la-maison)
  - [Lundi 25 Novembre 2024](#lundi-25-novembre-2024)
  - [Mardi 26 Novembre 2024](#mardi-26-novembre-2024)
  - [Jeudi 5 Décembre 2024 (à la maison)](#jeudi-5-décembre-2024-à-la-maison)
  - [Lundi 9 Décembre 2024](#lundi-9-décembre-2024)
  - [Mardi 7 Janvier 2025](#mardi-7-janvier-2025)
  - [Samedi 18 Janvier 2025 (à la maison)](#samedi-18-janvier-2025-à-la-maison)
  - [Dimanche 2 Février 2025 (à la maison)](#dimanche-2-février-2025-à-la-maison)
  - [Lundi 3 Février 2025](#lundi-3-février-2025)
  - [Lundi 10 Février 2025](#lundi-10-février-2025)
- [Partie 2 : **Après** la **présentation 1**](#partie-2--après-la-présentation-1)
  - [Mardi 25 Février 2025](#mardi-25-février-2025)
  - [Vendredi 28 Février 2025](#vendredi-28-février-2025)
  - [Lundi 10 Mars 2025](#lundi-10-mars-2025)
  - [Mardi 11 Mars 2025](#mardi-11-mars-2025)
  - [Lundi 24 et Mardi 25 Mars](#lundi-24-et-mardi-25-mars)
  - [Lundi 7 Avril](#lundi-7-avril)
  - [Vendredi 11 Avril](#vendredi-11-avril)
    - [**Partie 1 : Tester sur la HELTEC ESP32**](#partie-1--tester-sur-la-heltec-esp32)
    - [**Partie 2 : Tester sur notre prototype**](#partie-2--tester-sur-notre-prototype)

# Partie 1 : **Avant** la **présentation 1**

## Lundi 23 Septembre 2024

- Essai d'adapter Altium pour l'installer sur Mac.
- Problème d'installation, Jarod va l'installer sur Windows.
- Découverte d'un problème de liaison entre VCC et la masse.

## Mardi 12 Novembre 2024

- Nous avons vu avec Monsieur Peter que le projet de l'année dernière avait plusieurs autres problèmes donc on devra tout réfaire.
- Court-circuit à l'entrée du circuit.
  
  <img width="500" alt="image" src="https://github.com/user-attachments/assets/4c9664af-8ab2-4228-a892-88fa458c01a7"/>
- Tous les composants sont liés à la masse.
  
  <img width="500" alt="image" src="https://github.com/user-attachments/assets/6b201a64-f41a-4265-9bcb-72407d0c83f5"/>
- LEDs alimentées entre masse et masse.
  
  <img width="500" alt="image" src="https://github.com/user-attachments/assets/b70d72b0-e847-4489-95e2-e112881b2ec5"/>
- Utilisation des NMOS à la place des PMOS.
  
  <img width="500" alt="image" src="https://github.com/user-attachments/assets/4eef47ae-e349-4b70-af49-58a68e484c0d"/>
- LEDs liées entre la masse et rien.
  
  <img width="500" alt="image" src="https://github.com/user-attachments/assets/49a45590-99e6-4a7c-a344-1f0d12d132e3"/>

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

## Lundi 9 Décembre 2024

- Modifié les miles du routage.
- Terminé le routage.
- Regardé le code de la carte avec Jarod pour essayer de faire communiquer la carte avec le PC, puis envoyer un message SMS.

## Mardi 7 Janvier 2025

- J'ai regardé avec Jarod pour essayer de tester la carte avec le code. Nous n'avons toujours pas réussi.
- J'ai trouvé et installé une autre bibliothèque pour le GSM appelée TinyGSM.
- J'ai vu avec le professeur qu'il restait encore plusieurs soucis sur le schéma EAGLE :
  1. V+ branché à ground
     1. Solution : Les remplacer par un nouveau V+ trouvé dans sources1.
  2. Pistes qui passent par la Keepout Zone du SIM7000
     1. Solution : Enlever les pistes ou les passer par la face bottom.
  3. Condensateurs de couplage trop éloignés de la SIM7000
     1. Solution : Déplacer la SIM7000 vers le bas pour avoir la place.
- J'ai enlevé toutes les pistes pour pouvoir déplacer les composants d'une façon plus optimisée.

## Samedi 18 Janvier 2025 (à la maison)

- Continué à faire le cablage

## Dimanche 2 Février 2025 (à la maison)

- Continué à faire le cablage
- Remarqué qu'il manquait beaucoup de cablage sur le schéma du TXT0108PWR, reglé ça:
  1. LTE_RXD
  2. LTE_TXD
  3. LTE_RI
  4. LTE_DRT
  5. LTE_SDA
  6. LTE_SCL
  <img width="294" alt="image" src="https://github.com/user-attachments/assets/f67ade96-abcd-4e3f-924f-8f7eea927137" />
  Corrigé:
  <img width="280" alt="image" src="https://github.com/user-attachments/assets/442baf3d-e4b1-4de5-b71c-3e2a0dafaa94" />

  Connexions maintenat disponibles:
  
  <img width="200" alt="image" src="https://github.com/user-attachments/assets/c86e1030-30b0-412d-bb35-44d4577b28d1" />
- Corrigé la taille des images dans le compte rendu.
- Respecté la zone de Keepout du SIM7000.
- Écriture de la documentation dans Readme.md.

## Lundi 3 Février 2025

- Continué à faire le routage puis passé à Jarod, pour que je puisse regarder le code.
- Fait plusieurs essais avec le code et des nouvelles libraries.
- Pas encore réussi.
- J'amène la carte à la maison pour vérifier le cablage et continuer à faire des essais.
<img width="535" alt="image" src="https://github.com/user-attachments/assets/43da582c-54af-4560-8a36-635efeb3d2db" />

## Lundi 10 Février 2025

Présentation du projet.  
Points d'amélioration :  
- Utiliser Gantt pour la gestion du projet.  
- Utiliser un peu plus d'images.  
- Améliorer ma fluidité en français  

# Partie 2 : **Après** la **présentation 1**  

## Mardi 25 Février 2025  

🚩 **Événement** : Arrivée du circuit imprimé.  
  <img width="300" alt="image" src="https://github.com/user-attachments/assets/16eb6c52-78e2-4b00-bf0b-1f46c6ddeb71"/>

Lors de ce dernier cours, Jarod a réalisé des tests sur son PC avec l'ESP32.  
Pendant ce temps, j'ai décidé de tester chaque carte SIM7000G sur mon ordinateur via la communication par port série, en utilisant une application appelée Serial Tools.  
![image](https://github.com/user-attachments/assets/3218a3e1-caa3-48fd-bd10-c22ec905b483)

Je n'ai obtenu aucun succès avec aucun des circuits.  

Ensuite, nous avons échangé les rôles : j'ai pris en charge la partie ESP32 pendant que Jarod testait les cartes SIM7000G.  
Après plusieurs essais, j'ai imaginé que le problème pouvait venir de la manière dont les câbles étaient connectés à l'ESP32.  

- J'ai consulté la documentation de l'ESP32 Heltec LoRa V3.  
- J'ai consulté la documentation du SIM7000G.  
- J'ai entièrement refait le câblage.  
- J'ai découvert que l'erreur venait du choix des terminaux du GPIO.

![image](https://github.com/user-attachments/assets/8f376e5e-371a-45f1-9889-5c924ae13562)
Comme on peut le voir sur l'image, l'ESP32 possède deux rangées numérotées. Pour moi, il ne semblait pas logique qu'un même numéro représente les deux côtés, étant donné qu'ils ne remplissent pas forcément la même fonction. Après vérification avec le professeur, c'était bien le cas.  

Ainsi, voici le circuit refait :  
  <img width="500" alt="image" src="https://github.com/user-attachments/assets/f163f833-0517-48c7-bb62-70bc993fd5bc"/>

Cette fois, au lieu d'utiliser 16 et 17 pour les sorties GPIO TX et RX, j'ai utilisé 19 et 20, qui sont les sorties correctes du GPIO.  

Cela a fonctionné correctement et nous pouvons maintenant communiquer avec le SIM7000G et progresser avec le projet.  

Cependant, bien que la connexion avec le SIM7000G soit établie, il n'était toujours pas possible de se connecter au réseau GPRS et d'envoyer des messages. J'ai tenté les actions suivantes :  

- Changer l'antenne utilisée pour le LTE.  
- Changer le circuit SIM7000G.  
- Insérer la carte SIM de mon téléphone dans le module.  
- Mettre la carte SIM du SIM7000G dans mon téléphone, où j'ai pu envoyer un message à Jarod.  

Après en avoir discuté avec le professeur, la prochaine étape consistera à essayer avec le code du groupe de l'année dernière.  

## Vendredi 28 Février 2025  

À faire pour ce cours :  

- [x] Continuer à tester les cartes, avec la SIM7000 et le ESP32, avec le code du groupe de l'année dernière.

## Lundi 10 Mars 2025

J'ai testé chacune des cartes pour voir si elles fonctionnent.  
L'une d'elles n'a pas fonctionné et a été remise au professeur.

- J'ai continué à éditer le code, en envoyant diverses commandes AT pour voir le type de message qui apparaissait, comme une manière de déboguer le code.
- Le message NO CARRIER continuait d'apparaître.
- Le professeur a suggéré d'alimenter la carte avec une alimentation externe, car peut-être le problème venait du fait qu'il n'y avait pas assez d'énergie pour permettre au SIM7000 de fonctionner correctement.
- Nous avons réalisé le test et cela a effectivement fonctionné, nous avons commencé à voir des messages différents sur le SIM7000 (sur le port Serial avec Arduino IDE).

## Mardi 11 Mars 2025

- Le professeur a apporté un circuit intégré déjà prêt avec l'intégration entre le SIM7000 et l'ESP32, appelé LilyGO T SIM7000.
- J'ai fait quelques recherches dans la documentation en ligne, mais nous avons décidé qu'il serait préférable que chacun essaie de son côté.
- Ma tâche consistait à tester le code avec l'ancien circuit et Jarod testerait avec le nouveau.
- Pendant un certain temps, j'ai continué à tester notre code sur l'ancien circuit, mais sans beaucoup de succès, jusqu'à ce que je trouve une bonne documentation du LilyGO T SIM7000 qui m'a donné une piste sur ce que je devais faire.

> [!TIP] J'AI RÉUSSI À FAIRE FONCTIONNER LA CARTE ET À ENVOYER UN MESSAGE PAR SMS

J'ai réussi à faire fonctionner ! Grâce au code que j'ai trouvé sur le site  
https://randomnerdtutorials.com/lilygo-t-sim7000g-esp32-lte-gprs-gps/

- J'ai modifié le code selon nos besoins.
- La différence principale est l'utilisation de la bibliothèque TinyGSM.
- L'étape a été validée par le professeur, alors j'ai commencé à placer les composants. Pendant ce temps, Jarod retirait les parties inutiles du code.
- Il faisait des modifications dans le code et l'IDE a cessé d'envoyer le code à la carte.
- J'ai proposé que nous échangions : il continuerait à placer les composants sur le circuit et j'essaierais de résoudre ce nouveau problème sur le code.
- J'ai réussi à résoudre le problème et les circuits envoient, de nouveau, des messages par SMS.

## Lundi 24 et Mardi 25 Mars

- Ces jours-là, nous avons préparé notre propre circuit imprimé.
- Le professeur a appliqué la pâte à souder sur le circuit.
[IMG: Circuit avec la pâte à souder]
- J'ai placé les composants sur la carte.
- Nous avons mis le circuit au four.
- J'ai soudé une partie des composants traversants et Jarod les autres.
[IMG: Circuit avec les composants déjà soudés]
- Nous avons réalisé des tests, mais malheureusement, nous n'arrivions pas à transmettre le code au circuit via l'IDE Arduino.
- Le professeur a suggéré que, comme méthode de débogage pour savoir ce qui n'allait pas avec le circuit, nous devrions placer les composants un par un par groupe de composants.
- Nous avons commencé par l'ESP32, car c'est la partie principale et essentielle de notre circuit.
- Cela devait être fait en appliquant la pâte à souder sur un PCB et, petit à petit, en plaçant les composants, en utilisant un pistolet à air chaud pour faire fondre l'étain.
- **Cela a fonctionné. Nous avons réussi à envoyer un code à notre nouveau PCB, qui, pour l'instant, n'avait que l'ESP32.**

## Lundi 7 Avril

- Nous avons repris les tests sur notre nouveau circuit.
- Au début, cela ne fonctionnait pas, alors j'ai suggéré de remettre le cavalier, et cela a recommencé à fonctionner.
- Jarod a soudé la partie alimentation en utilisant un pistolet à air chaud.

## Vendredi 11 Avril

- Définition des modifications à faire dans le code.
- Nous avons divisé les tâches : je ferais la partie code et lui effectuerait les tests sur la nouvelle carte que nous sommes en train de monter pour déboguer.

### **Partie 1 : Tester sur la HELTEC ESP32**

- Cahier des charges pour les modifications dans le code :
  - Réussir à lire les messages reçus.
  - Envoyer un message.
  - Envoyer une requête REST.

### **Partie 2 : Tester sur notre prototype**

- Jarod a testé le code sur notre circuit et cela a fonctionné. Les messages ont été envoyés et reçus.
- L'étape pour le prochain cours sera de souder le SIM7000 avec les composants nécessaires et de réaliser les tests.
[IMG: Jarod testant le circuit avec le multimètre]