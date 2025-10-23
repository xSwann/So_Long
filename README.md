# So_long (42)

> A small 2D game built with the **MiniLibX** graphics library. The goal is to collect all items on the map and reach the exit.

---

## 🎯 Objective

The program loads a map from a `.ber` file, renders a 2D grid, and lets the player move with the keyboard. The game ends when all collectibles are gathered and the exit is reached.

---

## ✨ Features

* 2D tile-based rendering with **MiniLibX**
* Map parsing and validation (walls, characters, rectangular shape)
* Player movement with collision detection
* Collectibles and exit logic
* Error handling for invalid maps

---

## 🎮 Controls

| Key   | Action     |
| ----- | ---------- |
| W / ↑ | Move up    |
| S / ↓ | Move down  |
| A / ← | Move left  |
| D / → | Move right |
| ESC   | Quit       |

---

## 🔧 Build

Compile with the included Makefile:

```bash
make        # build so_long
make clean  # remove object files
make fclean # remove objects and binary
make re     # rebuild
```

> MiniLibX must be installed on your system (see installation below).

---

## ▶️ Usage

Run the program with a valid `.ber` map:

```bash
./so_long maps/<your_map>.ber
```

---

## 🗂️ Project structure

```
So_Long/
├─ Makefile
├─ README.md
├─ get_next_line/
├─ as/
├─ include/
├─ maps/
└─ src/
```

---

## 🗺️ Map rules

A valid `.ber` map must:

* Be **rectangular**
* Be **surrounded by walls**
* Contain **exactly one player `P`**
* Contain **at least one exit `E`**
* Contain **at least one collectible `C`**
* Use only characters: `0`, `1`, `C`, `E`, `P`

**Example**

```
111111
1P0C11
1000E1
111111
```

---

## 🛠️ Map validation

The project validates maps before launching the game (shape, borders, allowed characters; path validity enforced in code).

---

## 📦 Installing MiniLibX

### macOS (Homebrew)

```bash
brew update
brew install minilibx
# or use the official repo if needed:
# git clone https://github.com/42Paris/minilibx-mac.git
# make -C minilibx-mac
```

### Linux (X11)

```bash
sudo apt update
sudo apt install -y build-essential xorg libxext-dev libx11-dev
# Optional: libbsd-dev if required by your distro
# git clone https://github.com/42Paris/minilibx-linux.git
# make -C minilibx-linux
```

> After installation, ensure your **Makefile** includes the proper include/library paths for MiniLibX on your platform.

---

## 🖼️ Screenshots

<img width="1250" height="832" alt="image" src="https://github.com/user-attachments/assets/2a842986-f58d-44ae-8388-b30c27752a20" />


---

## 🎥 Demo video

![Screencastfrom10-23-2025031011PM-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/13719189-a47d-4597-8bcd-b4b8c7cc9edb)


---

## 👤 Author

* Swann — @xSwann
