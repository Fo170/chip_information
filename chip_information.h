// chip_information v1.1.0
// Librairie Arduino header-only : affiche les caractéristiques CPU/Flash
// des microcontrôleurs ESP8266, ESP32, AVR (Uno...) et SAM (Due) via le port série.
//
// Auteur : Olivier FOURNET (https://github.com/Fo170)
// Licence : GPL-3.0-only
//
// https://github.com/Fo170/chip_information

#ifndef CHIP_INFORMATION_H
#define CHIP_INFORMATION_H

#include <Arduino.h>

#if defined(ESP8266)
#include <Esp.h>

inline void chip_information(void)
{
  Serial.printf("\n\nVersion Sdk : %s\n", ESP.getSdkVersion());
  Serial.printf("Version de base : %s\n", ESP.getCoreVersion().c_str());
  Serial.printf("Version de démarrage : %u\n", ESP.getBootVersion());
  Serial.printf("Mode de démarrage : %u\n", ESP.getBootMode());
  Serial.printf("Fréquence du processeur : %u MHz\n", ESP.getCpuFreqMHz());
  Serial.printf("Free heap : %u\n", ESP.getFreeHeap());
}

#elif defined(ESP32)
#include <Esp.h>
#include <esp_chip_info.h>
#include <esp_flash.h>
#include <esp_system.h>

// SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
// SPDX-License-Identifier: CC0-1.0
inline void chip_information(void)
{
  // Print chip information
  esp_chip_info_t chip_info;
  uint32_t flash_size;
  esp_chip_info(&chip_info);
  printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
         CONFIG_IDF_TARGET,
         chip_info.cores,
         (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
         (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

  unsigned major_rev = chip_info.revision / 100;
  unsigned minor_rev = chip_info.revision % 100;
  printf("silicon revision v%d.%d, ", major_rev, minor_rev);
  if (esp_flash_get_size(NULL, &flash_size) != ESP_OK)
  {
    printf("Get flash size failed");
    return;
  }

  printf("%uMB %s flash\n", flash_size / (1024 * 1024),
         (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

  printf("Minimum free heap size: %d bytes\n", esp_get_minimum_free_heap_size());

  Serial.printf("Fréquence du processeur : %u MHz\n", ESP.getCpuFreqMHz());
  Serial.printf("getChipRevision : %u\n", ESP.getChipRevision());
  Serial.printf("getChipModel : %s\n", ESP.getChipModel());
  Serial.printf("getChipCores : %u\n", ESP.getChipCores());
  Serial.printf("Version Sdk : %s\n", ESP.getSdkVersion());
  Serial.printf("getFlashChipSize : %u bytes\n", ESP.getFlashChipSize());
}

#elif defined(__AVR__)
#include <avr/io.h>

#if defined(__AVR_ATmega328P__)
#define CHIP_INFORMATION_MODEL "ATmega328P"
#elif defined(__AVR_ATmega2560__)
#define CHIP_INFORMATION_MODEL "ATmega2560"
#elif defined(__AVR_ATmega168__)
#define CHIP_INFORMATION_MODEL "ATmega168"
#elif defined(__AVR_ATmega8__)
#define CHIP_INFORMATION_MODEL "ATmega8"
#elif defined(__AVR_ATtiny84__)
#define CHIP_INFORMATION_MODEL "ATtiny84"
#elif defined(__AVR_ATtiny85__)
#define CHIP_INFORMATION_MODEL "ATtiny85"
#else
#define CHIP_INFORMATION_MODEL "AVR"
#endif

inline void chip_information(void)
{
  Serial.println(F("\n\nModèle : "));
  Serial.println(CHIP_INFORMATION_MODEL);
  Serial.print(F("Fréquence du processeur : "));
  Serial.print(F_CPU / 1000000UL);
  Serial.println(F(" MHz"));
  Serial.print(F("Mémoire flash : "));
  Serial.print(FLASHEND + 1);
  Serial.print(F(" octets ("));
  Serial.print((FLASHEND + 1) / 1024);
  Serial.println(F(" Ko)"));
#if defined(RAMEND)
  const unsigned int ram_size = (RAMEND - 0x100) + 1; // la SRAM AVR commence toujours à 0x100
  Serial.print(F("Mémoire SRAM : "));
  Serial.print(ram_size);
  Serial.print(F(" octets ("));
  Serial.print(ram_size / 1024);
  Serial.println(F(" Ko)"));
#endif
#if defined(E2END)
  Serial.print(F("Mémoire EEPROM : "));
  Serial.print(E2END + 1);
  Serial.println(F(" octets"));
#endif
}

#undef CHIP_INFORMATION_MODEL

#elif defined(ARDUINO_ARCH_SAM)

// Arduino Due (SAM3X8E, Cortex-M3)
inline void chip_information(void)
{
  Serial.println(F("\n\nModèle : SAM3X8E (Cortex-M3)"));
  Serial.print(F("Fréquence du processeur : "));
  Serial.print(F_CPU / 1000000UL);
  Serial.println(F(" MHz"));
  Serial.println(F("Mémoire flash : 512 Ko"));
  Serial.println(F("Mémoire SRAM : 96 Ko"));
}

#endif

#endif // CHIP_INFORMATION_H