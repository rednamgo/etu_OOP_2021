# etu_OOP_2021

## Notice
_This code is for study purposes only._ It may not contain the best or the most sound solutions, but it is what it is and it works.
This repository will contain 6 homework tasks from 2021 OOP course of ETU and with UML-diagrams for them. As it is a study project, the overall result is a mess, but might help some poor student.

## Tasks

### Lab1 - Creating classes, constructors and class methods
1. Create a game field and tile class. Filed should store tiles as dynamic 2D array
2. Tile class should store information about its status and what it stores inside
3. Create tile interface
4. Spawn entrance and exit tiles. Make sure they're far enough from each other
5. For the field class implement copy and move constructors and operators
6. Make sure there's no memory leaks

### Lab2 - Interfaces, polymorphism
1. There are 3 types of objects to store in tile: Player, Enemy, Item
2. Implement player class. Player should have their own stats that can change in game. Player must have interaction, attack and movement methods implemented. Interaction with exit tile should be implemented
3. Implement 3 types of enemies. They should have their own stats, preferably different. Implement movement behaviour. In death they should be deleted from the game field. Enemies must have their own interface
4. Implement 3 types of items. Each item should have it's own effects when picked up, after which it dissapears from field. Items hsould have their own interface
5. Polymorphism ideas must be used

### Lab3 - Loggers, methods override
...


## Sources and useful materials
- General:
  - [Complete roguelike tutorial using C++ and libtcod](http://www.roguebasin.com/index.php/Complete_roguelike_tutorial_using_C%2B%2B_and_libtcod_-_part_1:_setting_up)
  - [Roguelike game in C++](https://solarianprogrammer.com/2012/07/12/roguelike-game-cpp-11-part-0/)
- Pathfinding:
  - [Implementation of A*](https://www.redblobgames.com/pathfinding/a-star/implementation.html#python-astar) 
  - [Flow Field Pathfinding for Tower Defense](https://www.redblobgames.com/pathfinding/tower-defense/) 
  - [Distance to Selected Points](https://www.redblobgames.com/pathfinding/distance-to-any/)
  - [The Incredible Power of Dijkstra Maps (article)](http://www.roguebasin.com/index.php?title=The_Incredible_Power_of_Dijkstra_Maps)
  - [Dijkstra Maps Visualized](http://www.roguebasin.com/index.php?title=Dijkstra_Maps_Visualized#--_Variable_strengths.2C_and_what_distance_really_means_--)
- AI:
  - [Implementing a State Design Pattern for an A.I. System](https://www.haroldserrano.com/blog/category/Design+Patterns)
- Other patterns:
  - [How to implement the Observer Design Pattern](https://www.haroldserrano.com/blog/implementing-the-observer-design-pattern)
  - [Game Programming Patterns](http://gameprogrammingpatterns.com/contents.html)
  - [The Prototype Design Pattern](http://gameprogrammingpatterns.com/prototype.html)
