# Skyward Suspicion
A narrative mystery game where you play as an airship cargo captain who must identify and remove a fraudulent package before departure.

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/2c2b9253-114d-41cf-8112-b8dba480c552" />

## Overview
Welcome aboard, Captain.

You've just received word that **one of the six packages on your manifest is fraudulent**. Your mission is clear: identify the fake delivery and remove it before your airship departs.

Question your customers, analyze the clues, and make the right choice — or face the consequences.

**Skyward Suspicion** is an interactive text-based detective game that combines mystery-solving with data structure manipulation. Navigate through character dialogues, piece together clues from accusations and riddles, and use your deductive reasoning to solve the case.

## Features
- **Interactive Mystery Narrative**  
  Engage with six unique customers, each with their own personality, dialogue, and secrets.

- **Detective Gameplay**  
  Analyze clues, accusations, and pricing inconsistencies to unmask the fraudulent order.

- **Dynamic Manifest System**  
  Add, view, modify, and remove deliveries using a custom linked list structure.

- **Multiple Endings**  
  Experience different outcomes based on your final decision.

- **ASCII Art Visuals**  
  Immerse yourself in an airship hangar brought to life through terminal visuals.

- **Clue System**
  - Customer accusations
  - Character-specific riddles
  - Price and quantity analysis
  - Behavioral tells

## The Suspects
Your manifest contains deliveries for six customers:

- **Bulk Ryker** — A loud lifter with impossible discounts  
- **Buck Hawthorne** — Easygoing, but vague  
- **Old Man Ripple** — Talks more than he answers  
- **Bramble Nett** — Sharp as a thorn  
- **Vesper Morrow** — Odd, quiet, noticeable  
- **Linton Yarrow** — Nervous, fidgety, and suspicious  

**One of them is not who they claim to be. Can you figure out which one?**

---

## Installation

### Prerequisites
- A C++ compiler with C++17 support (e.g., `g++`)
- Make build system
- Linux/Unix or Windows with development tools

### Building the Game
```bash
git clone https://github.com/yourusername/skyward-suspicion.git
cd skyward-suspicion
make
````

### How to Play

-Read the Opening Scene to understand your mission.
-Meet All Six Customers and listen carefully.
-Collect Clues

-Pay attention to:
  -What customers say about each other
  -Price inconsistencies
  -Riddles and cryptic lines
  -Odd behaviors or reactions
  
-Manage the Manifest
-Use the linked list menu to view, add, remove, or modify cargo orders.
-Make Your Decision
-Choose which package to remove.

-Experience the Ending
-Your deduction determines victory or disaster.

### Project Structure
```bash
skyward-suspicion/
├── AirshipOrderList.hpp      # Linked list structure header
├── AirshipOrderList.cpp      # Manifest management logic
├── DisplayManager.hpp        # Scene and dialogue header
├── DisplayManager.cpp        # Narrative implementation
├── GameManager.hpp           # Game flow control header
├── GameManager.cpp           # Game logic and state
├── program5_driver.cpp       # Program entry point
├── Makefile                  # Build system
└── README.md                 # This file
```
