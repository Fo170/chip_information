# chip_information pour les ESP8266 et ESP32

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-compatible-brightgreen.svg)](https://platformio.org/)
[![ESP8266](https://img.shields.io/badge/ESP8266-Supported-green.svg)](https://www.espressif.com/)
[![ESP32](https://img.shields.io/badge/ESP32-Supported-green.svg)](https://www.espressif.com/)
![GitHub release](https://img.shields.io/github/v/release/Fo170/chip_information)
![GitHub last commit](https://img.shields.io/github/last-commit/Fo170/chip_information)

Une bibliothèque Arduino **header-only** qui affiche les caractéristiques du microcontrôleur (CPU, fréquence, flash, heap, version SDK) sur le port série.

# Fonctionnalités

📟 **Informations complètes** : modèle du chip, révision, nombre de cœurs, fréquence CPU

💾 **Flash** : taille et type (interne/externe) de la mémoire flash

🧠 **Heap** : heap libre (ESP8266) ou minimum libre (ESP32)

🏗️ **Support multi-architecture** : ESP8266 et ESP32

📝 **Sortie formatée** : affichage clair via Serial

# Installation

### Via PlatformIO (recommandé)

Ajoutez la dépendance à votre `platformio.ini` :

```ini
lib_deps =
    https://github.com/Fo170/chip_information.git@^1.0.0
```

### Via l'IDE Arduino

1. Croquis > Inclure une bibliothèque > Gérer les bibliothèques...
2. Recherchez "chip_information"
3. Cliquez sur "Installer"

# Utilisation

```cpp
#include <Arduino.h>
#include <chip_information.h>

void setup() {
  Serial.begin(115200);
  delay(500);

  chip_information();
}

void loop() {}
```

# Fonctions disponibles

`chip_information()`
Fonction générique, identique sur les deux plateformes. Sur ESP8266 elle affiche : version SDK, version du core, version et mode de démarrage, fréquence du processeur, heap libre. Sur ESP32 : nom du chip, nombre de cœurs, WiFi/BT/BLE, révision du silicium, taille et type de flash, minimum de heap libre, fréquence, modèle, version SDK.

# Support des plates-formes

ESP8266 : 1 fonction, API Arduino core 2.x

ESP32 : 1 fonction, API Arduino core 2.x + API native IDF (code Espressif CC0-1.0)

# Licence

Cette bibliothèque est distribuée sous GPL-3.0-only. Voir le fichier LICENSE pour plus de détails.

# Auteur

Développé par FOURNET Olivier. Retrouvez le projet sur GitHub.