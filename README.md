# Orbit ⌚⚡

**A WiFi security testing tool built into a wristwatch.** SKMEI watch case, custom ESP8266 PCB, OLED display, running a modified build of the ESP8266 Deauther — Orbit is the hardware, this repo covers both the hardware design and the firmware adaptation.

![License: MIT](https://img.shields.io/badge/license-MIT-yellow.svg)
![Platform](https://img.shields.io/badge/platform-ESP8266%20%7C%20ESP--12E%2FF-blue)
![Status](https://img.shields.io/badge/status-hardware%20verified-brightgreen)

![Orbit watch](docs/images/orbit-watch.png)
*Orbit, worn and running*

---

## What this is

Orbit is a custom-built, wristwatch-form-factor WiFi security testing tool, based on a raw ESP-12E/F module. It features a 1.3" I2C OLED display, three-button navigation, a WS2812 RGB status LED, and a 3.7V LiPo power system, all housed inside a repurposed SKMEI digital watch case.

This repository covers both the **hardware** (KiCad schematics, wiring, BOM, 3D model) and the **firmware** (a modified build of spacehuhn's ESP8266 Deauther, adapted to Orbit's exact pinout).

> ⚠️ **Legal notice:** This tool can interfere with wireless communications (deauthentication, scanning, packet capture). Only use it on networks you own or have explicit written authorization to test. Unauthorized use may violate wireless regulations (e.g. FCC Part 15 in the US) and computer misuse laws in most jurisdictions. You are responsible for how you use this.

---

## Hardware

| Component | Spec |
|---|---|
| MCU | ESP-12E / ESP-12F (ESP8266) |
| Display | 1.3" I2C OLED (SH1106, 128×64) |
| Buttons | 3× tactile (Up / Down / OK) + Flash + Reset |
| LED | WS2812B RGB |
| Power | 3.7V single-cell LiPo, no regulator |
| Case | Modified SKMEI digital watch |

Full KiCad schematics — main board and a separate flasher board (FT232RL USB-TTL) — are in [`hardware/`](./hardware), with PDF and SVG exports included for quick viewing without KiCad installed.

---

## Pinout

| Function | GPIO |
|---|---|
| Button UP | 14 |
| Button DOWN | 12 |
| Button OK | 13 |
| OLED SCL | 5 |
| OLED SDA | 4 |
| WS2812 DIN | 2 |
| Flash button | 0 |
| Reset | RST |

---

## Bill of Materials

| Qty | Part |
|---|---|
| 1x | ESP-12E/F module |
| 1x | 1.3" I2C OLED (SH1106, 128×64) |
| 1x | WS2812B RGB LED breakout |
| 5x | Tactile push buttons |
| 5x | 10kΩ resistors (boot config + pull-down) |
| 1x | 3.7V LiPo battery (400mAh+) |
| 1x | SPST slide switch |
| 1x | FT232RL USB-TTL module (flasher board only) |
| — | SKMEI digital watch case (donor) |

---

## Firmware

Orbit's firmware is a modified build of [spacehuhn's ESP8266 Deauther](https://github.com/SpacehuhnTech/esp8266_deauther) (MIT License), adapted to Orbit's exact GPIO pinout and rebranded boot screen.

**Get the prebuilt binary:** grab `Orbit-firmware-v1.0.bin` from [Releases](../../releases).

**Or build from source:**
```bash
git clone https://github.com/shasradha/Orbit.git
cd Orbit/firmware/orbit_deauther
```
Open `orbit_deauther.ino` in Arduino IDE 2, install the ESP8266 board package (Tools → Board → Boards Manager → search "esp8266"), select **Generic ESP8266 Module**, compile.

⚠️ **Status:** Compiles cleanly with Orbit's custom pin configuration. Not yet flash-tested on physical hardware after this specific modification — testing reports and issues welcome. The underlying hardware, OLED, and button wiring have been previously verified working on this exact board (see photo above).

**Flashing:** use the included [flasher circuit](./hardware/orbit-flash-circuit) (FT232RL-based) or any USB-TTL adapter:
```bash
esptool.py -p <PORT> -b 115200 write_flash 0 Orbit-firmware-v1.0.bin
```

---

## 3D Model

A 3D model of the Orbit enclosure, reconstructed from real device photos and refined in Blender, is available for interactive preview:

- **[Orbit — 3D Model](https://studio.tripo3d.ai/3d-model/440f1f53-c45f-4885-87b7-a15c8f742168?invite_code=AO12LG)**

This is AI-reconstructed for a visual preview — not dimensionally exact. The Blender source file is in [`hardware/3d/`](./hardware/3d) for anyone who wants to inspect or rebuild it.

---

## Gallery

![Orbit packet monitor](docs/images/orbit-packet-monitor.png)
*Live WiFi channel activity monitor, running on the assembled watch*

---

## Credits

- **[Spacehuhn Technologies](https://github.com/SpacehuhnTech)** — original ESP8266 Deauther firmware (MIT License)
- Hardware design, KiCad schematics, and firmware adaptation: **Shasradha** / Karmakar Industries

---

## License

MIT — see [LICENSE](LICENSE) for the original firmware license and [NOTICE.md](NOTICE.md) for Orbit-specific hardware and firmware modifications. Hardware design (KiCad files, BOM, schematics, 3D model) is also MIT licensed.

---

## Disclaimer

This project is for authorized security research and education only. The author is not responsible for misuse of this tool.
