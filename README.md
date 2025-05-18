# **Passerelle LoRa-GSM**  

Un projet combinant des connaissances en électronique et en programmation pour créer un pont entre le GSM et le LoRa.

![image](https://github.com/user-attachments/assets/3acdb9e8-fed4-4b29-99b4-2c63c6d7694c)

----

**Table de matières**
- [**Passerelle LoRa-GSM**](#passerelle-lora-gsm)
  - [ℹ️ **Contexte du projet**](#ℹ️-contexte-du-projet)
  - [🗂️ Dossiers](#️-dossiers)
  - [**Réalisation du projet**](#réalisation-du-projet)
    - [**Définitions :**](#définitions-)

----

## ℹ️ **Contexte du projet**

Il s'agit d'un projet du cours de Projet d'Électronique, encadré par Monsieur Christian Peter (<Christian.PETER@univ-cotedazur.fr>), dans le cadre du cursus d'Ingénierie Électronique et Informatique Industrielle de la Polytech de Sophia Antipolis.  
Ce projet consiste à concevoir une ruche connectée, incluant la collecte de données, la transmission de ces données à distance, l’élimination des parasites par laser, etc.  
Cette partie du projet concerne la communication à distance des données et est réalisée par le groupe composé de:
**Guilherme VENTAPANE RODRIGUES** <guilherme@ventapane.eu>
et
**Jarod LECOEUVRE** <jarod.lecoeuvre@etu.univ-cotedazur.fr>

## 🗂️ Dossiers

- 📁 **Compte-rendu** : Les étapes d'avancement du projet et les tâches que chaque membre du groupe avait effectuées.

- 📁 **Partie_Electronique** : Fichiers liés à la partie électronique du projet, tels que le schéma de la carte, la documentation des composants, etc.
  - 📁 **BOM** : Bill of Material de notre projet. La liste des composants nécessaires avec leurs valeurs, pour être placés sur le PCB.
  - 📁 **Documentation_composants** : Fichiers de documentation pour certains composants utilisés dans le projet.
  - 📁 **Eagle_Components** : Composants supplémentaires pour le logiciel EAGLE, qui n'étaient pas présents par défaut et que nous avons dû télécharger pour compléter notre projet.
  - 📁 **Eagle_Schemas** : Schémas que nous avons utilisés pour notre projet, réalisés avec le logiciel EAGLE d'Autodesk.
  - 📁 **Nano to micro simcard adapter 3d** : Un adaptateur de carte SIM vers micro SIM que nous avons imprimé en 3D pour notre projet.
  - 📁 **Anciens_Schemas** : Fichiers de schémas du groupe de l'année dernière.

- 📁 **Partie_Informatique** : Le dossier où se trouve le code qui tourne sur la carte.
  - 📁 **code_groupe_annee_derniere** : Code du projet du groupe de l'année dernière.
  - 📁 **src** : Les fichiers sources de notre projet, où se trouve le fichier main.ino, le fichier principal de notre projet.


## **Réalisation du projet**  

Pour assurer la communication des données sur de longues distances, une passerelle entre LoRa et GSM sera utilisée.  
Cette passerelle sera réalisée à partir d'un circuit imprimé conçu par nous, ainsi que d'un code exécuté sur un **ESP32** connecté à un **SIM7000G**.

Nous nous basons sur le projet de la promotion précédente, réalisé par **Oumar Sadjo Barry & Mor Dieng** / [oumarsadjo / RucherLoRa](https://github.com/oumarsadjo/RucherLoRa)  
<oumar-sadjo.barry@etu.univ-cotedazur.fr> & <mor.dieng@etu.univ-cotedazur.fr>

### **Définitions :**  

**GSM (Global System for Mobile Communications) :**  
C'est un standard de communication mobile utilisé pour la téléphonie cellulaire et la transmission de données. Il permet l’envoi de messages SMS, les appels et la connexion à Internet via **GPRS/EDGE/3G/4G**. Le GSM est largement utilisé pour les dispositifs IoT nécessitant une connectivité dans des environnements sans Wi-Fi.  

**LoRa (Long Range) :**  
C'est une technologie de communication sans fil à longue portée et à faible consommation d'énergie, utilisée pour connecter des dispositifs IoT aux réseaux LPWAN (**Low Power Wide Area Network**). LoRa permet de transmettre de petits paquets de données sur de longues distances (jusqu'à 15 km en zones rurales) avec une consommation d’énergie minimale.  

**ESP32 :**  
C'est un microcontrôleur développé par Espressif, intégrant **Wi-Fi et Bluetooth**, ainsi que plusieurs broches **GPIO** pour les capteurs et modules externes. Il est largement utilisé dans les projets IoT grâce à sa connectivité, sa puissance et son faible coût.  

**SIM7000 :**  
C'est un module de communication **GSM/GPRS/NB-IoT/LTE Cat-M1** développé par Simcom. Il permet aux dispositifs IoT d'envoyer et de recevoir des données via les réseaux mobiles, en prenant en charge les connexions **basse consommation**, idéales pour les capteurs distants et les applications de surveillance.  

<img width="300" alt="image" src="https://github.com/user-attachments/assets/89d18e22-138f-430b-ac1e-dbb92593b67c"/>
