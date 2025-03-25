# Philosophers

![Philosophers Dining Problem](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7b/An_illustration_of_the_dining_philosophers_problem.png/578px-An_illustration_of_the_dining_philosophers_problem.png)

Un projet de l'école **42** qui explore les problèmes de concurrence en implémentant la solution classique du **problème des philosophes mangeurs**.

## ✨ Objectif

L'objectif principal de ce projet est de comprendre les bases des **threads**, des **mutex** et de la **synchronisation** dans un environnement multi-threadé.

## 📝 Description

Le problème des philosophes mangeurs implique un certain nombre de philosophes assis autour d'une table circulaire avec un bol de riz devant eux. Entre chaque philosophe se trouve une seule fourchette. Pour manger, un philosophe doit prendre les deux fourchettes adjacentes.

Votre mission est d'implémenter une simulation de ce problème en respectant les règles suivantes :

- Chaque philosophe doit prendre les deux fourchettes pour manger.
- Ils ne peuvent manger qu'après avoir pris les deux fourchettes.
- Après avoir mangé, ils reposent les fourchettes et recommencent à penser.

## ⚡ Fonctionnalités

- Création et gestion de **threads** pour chaque philosophe.
- Utilisation de **mutex** pour prévenir les conditions de concurrence.
- Simulation du cycle **penser - manger - dormir**.
- Gestion des cas où un philosophe meurt de faim.

## 🛠️ Compilation et Exécution

Cloner le dépôt :

```bash
git clone https://github.com/Noe-prt/Philosophers.git
cd philosophers
```

Compiler le projet :

```bash
make
```

Exécuter :

```bash
./philo [nombre_de_philosophes] [temps_manger] [temps_dormir] [temps_mort] [optionnel: nombre_repas]
```

Exemple :

```bash
./philo 5 800 200 200 5
```

## 🔥 Exemples de Sortie

![Exemple de simulation](https://i.ibb.co/Z6Y3qqZS/philo2.png)

## 📊 Paramètres

- **nombre_de_philosophes** : Nombre de philosophes (et de fourchettes).
- **temps_manger** : Temps qu'un philosophe passe à manger (en ms).
- **temps_dormir** : Temps qu'un philosophe passe à dormir (en ms).
- **temps_mort** : Temps avant qu'un philosophe meure s'il ne mange pas (en ms).
- **nombre_repas** (optionnel) : Nombre de repas qu'un philosophe doit prendre avant que la simulation s'arrête.

## 💡 Stratégies d'Optimisation

- Utilisation de **mutex** pour protéger l'accès aux ressources partagées.
- Minimiser les sections critiques pour améliorer la performance.
- Implémentation de **timestamps** précis pour un suivi correct des événements.

## 👤 Auteur

Projet réalisé par :

- [Noe-prt](https://github.com/Noe-prt)
