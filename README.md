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

## 📝 Map File Format (`*.cub`)

Example of a minimal `.cub` file:

