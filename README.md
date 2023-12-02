# Pipex

## Description

Projet `pipex` de l'école 42. L'objectif est de recréer le fonctionnement de la commande shell `pipe` en utilisant des pipes et en redirigeant la sortie standard d'un processus vers l'entrée standard d'un autre.

## Fonctionnalités supportées

- Utilisation de pipes pour rediriger la sortie d'un processus vers l'entrée d'un autre.
- Gestion de la commande de redirection de fichier (`<`, `>`).
- Exécution de commandes externes.

## Comment utiliser

1. Clonez le dépôt : `git clone <lien du dépôt>`.
2. Naviguez dans le répertoire `pipex`.
3. Exécutez `make` pour compiler l'exécutable `pipex`.
4. Vous pouvez maintenant utiliser l'exécutable `pipex` pour exécuter des commandes en utilisant les pipes.

## Exemples

```bash
./pipex file1 "ls -l" "grep a1" file2
