# chip_information pour les ESP8266, ESP32, AVR et SAM

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-compatible-brightgreen.svg)](https://platformio.org/)
[![ESP8266](https://img.shields.io/badge/ESP8266-Supported-green.svg)](https://www.espressif.com/)
[![ESP32](https://img.shields.io/badge/ESP32-Supported-green.svg)](https://www.espressif.com/)
[![Arduino Uno](https://img.shields.io/badge/Arduino_Uno-Supported-green.svg)](https://www.arduino.cc/)
[![Arduino Due](https://img.shields.io/badge/Arduino_Due-Supported-green.svg)](https://www.arduino.cc/)
![GitHub release](https://img.shields.io/github/v/release/Fo170/chip_information)
![GitHub last commit](https://img.shields.io/github/last-commit/Fo170/chip_information)

Une bibliothèque Arduino **header-only** qui affiche les caractéristiques du microcontrôleur (CPU, fréquence, flash, heap, version SDK) sur le port série.

# Fonctionnalités

📟 **Informations complètes** : modèle du chip, révision, nombre de cœurs, fréquence CPU

💾 **Flash** : taille et type (interne/externe) de la mémoire flash

🧠 **Heap** : heap libre (ESP8266) ou minimum libre (ESP32)

♾️ **Multi-architecture** : ESP8266, ESP32, AVR (Uno), SAM (Due)

📝 **Sortie formatée** : affichage clair via Serial

# Installation

### Via PlatformIO (recommandé)

Ajoutez la dépendance à votre `platformio.ini` :

```ini
lib_deps =
    https://github.com/Fo170/chip_information.git@^1.1.0
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
Fonction générique, un seul nom d'appel quelle que soit la plateforme. Elle affiche :
- **ESP8266** : version SDK, version du core, version et mode de démarrage, fréquence du processeur, heap libre.
- **ESP32** : nom du chip, nombre de cœurs, WiFi/BT/BLE, révision du silicium, taille et type de flash, minimum de heap libre, fréquence, modèle, version SDK.
- **AVR (Uno, Mega, ATtiny…)** : modèle détecté via les macros du compilateur, fréquence `F_CPU`, tailles flash/SRAM/EEPROM.
- **SAM (Due)** : modèle SAM3X8E, fréquence, tailles flash (512 Ko) et SRAM (96 Ko).

# Support des plates-formes

ESP8266 : API Arduino core 2.x

ESP32 : API Arduino core 2.x + API native IDF (code Espressif CC0-1.0)

AVR : macros `avr/io.h` (`F_CPU`, `FLASHEND`, `RAMEND`, `E2END`) + macros de modèle

SAM : Arduino Due, constantes SAM3X8E

# Licence

Cette bibliothèque est distribuée sous GPL-3.0-only. Voir le fichier LICENSE pour plus de détails.

# Auteur

Développé par FOURNET Olivier. Retrouvez le projet sur GitHub.