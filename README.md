# Terminal-based RPG Game

This project is a terminal-based RPG (Role-Playing Game) where players interact with various characters, explore different locations, and battle enemies (mobs). The game provides a simple RPG experience directly through the command line interface.

## Features

Multiple characters to interact with
Various locations to explore
Turn-based combat system with mobs
Object-oriented structure for game entities (characters, mobs, locations)

## Installation

Clone this repository:
```bash
git clone https://github.com/your-repo-name/terminal-rpg-game.git
```

Navigate to the project directory:
```bash
cd rpg-game
```

Compile the game using g++ or any other C++ compiler:
```bash
g++ main.cpp characters.cpp mobs.cpp locations.cpp  ASCII.cpp fightMech.cpp shop.cpp -o rpg_game
```

Run the game

Go to the excuitable created by the complier or use the one already available 

Usage

Once the game is started, follow the on-screen prompts to explore locations, interact with characters, and fight enemies.


## Files Overview

main.cpp: The main entry point for the game logic and gameplay loop.

characters.cpp / characters.h: Defines the player characters and NPCs (Non-Player Characters).

mobs.cpp / mobs.h: Handles the enemies (mobs) encountered during the game.

locations.cpp / locations.h: Defines various locations the player can visit.

fightMech.cpp / fightMech.h: Manages the battle mechanics in the game, including turn-based combat between the player and enemies. This file contains the logic for attack sequences, health management, and victory/defeat conditions.

shop.cpp / shop.h: Implements the in-game shop system where players can buy and sell items. This file contains the logic for inventory management, item purchasing, and transaction handling.

ASCII.cpp / ASCII.h: Handles ASCII art generation for the game. This file is responsible for displaying various visual elements in the game using ASCII characters, adding an aesthetic touch to battles, locations, and other scenes.



## Technologies Used
C++ for game development

Object-Oriented Programming (OOP) for structuring the game

## Contributing
Feel free to fork this repository, create a new branch for any features, and submit a pull request. Contributions to improve the game, fix bugs, or add new features are always welcome!

## License
This project is open-source and available under the MIT License.
