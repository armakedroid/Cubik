# 🕹️ cub3D
*My first RayCaster with miniLibX*

---

## 📘 Overview
**cub3D** is a project inspired by *Wolfenstein 3D*, the first true First-Person Shooter (FPS).  
Your goal is to create a dynamic 3D view inside a maze using **ray-casting**, allowing the player to explore the map in first-person perspective.

---

## 🎯 Objectives
- Implement a **3D graphical representation** of a maze.
- Learn **ray-casting** and **first-person rendering**.
- Work with **miniLibX** for window and graphics management.
- Handle **textures, colors, and events** efficiently.
- Apply **mathematical algorithms** to simulate a realistic 3D environment.

---

## ⚙️ Features

### Mandatory
- Use **miniLibX** to display the game window.
- Smooth window management (resize, minimize, close).
- Display **different wall textures** depending on the wall orientation (N, S, E, W).
- Floor and ceiling colors can be set independently.
- **Keyboard controls**:
  - `W, A, S, D` → Move through the maze
  - Left/Right arrows → Rotate POV
  - `ESC` → Quit program
- Accepts a `.cub` map file as input:
  - Map consists of `0` (empty), `1` (wall), and `N/S/E/W` (player start orientation)
  - Map must be **closed** (surrounded by walls)
  - Supports floor/ceiling colors and wall textures
- Proper **error handling**: on invalid map or configuration, display `"Error\n"` with message.
- Smooth **frame updates** and **real-time movement**.

---

### Bonus (optional)
- Wall collisions
- Minimap system
- Doors that open and close
- Animated sprites
- Mouse-controlled POV rotation
- Additional enhancements such as HUD, shadows, and weapons

> Bonuses are only evaluated if the mandatory part is implemented perfectly.

---

- **Textures**:
  - `NO, SO, WE, EA` → paths to wall textures
- **Colors**:
  - `F` → Floor RGB (0–255)
  - `C` → Ceiling RGB (0–255)
- **Map**:
  - Only `0`, `1`, `N/S/E/W`
  - Must be **closed/surrounded by walls**
  - Must appear at the end of the file
  - Spaces are valid inside the map

---

## 🕹️ Controls
| Key | Action |
|-----|--------|
| W   | Move forward |
| S   | Move backward |
| A   | Move left |
| D   | Move right |
| ←   | Rotate left |
| →   | Rotate right |
| ESC | Exit game |

---

## ⚙️ Requirements
- Written in **C** following the **Norm**.
- Use **Libft** if needed.
- Proper memory management; no leaks.
- Makefile with rules: `all, clean, fclean, re, bonus`
- Allowed functions:
  - `open, close, read, write, printf, malloc, free, perror, strerror, exit`
  - **math library** (`-lm`)
  - **gettimeofday()**
  - **All MiniLibX functions**

---

## 📚 References
- Original Wolfenstein 3D: [Play Online](http://users.atw.hu/wolf3d/)
- Ray-casting tutorials and algorithms
- MiniLibX graphics documentation

---

## 💡 Submission
- Submit your project in the **Git repository**.
- Only files in the repo will be graded.
- Be ready for small modifications during evaluation.


