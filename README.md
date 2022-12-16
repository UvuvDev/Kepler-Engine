# Kepler ENGINE
An engine for making games. For now, 2D only, but future versions will support 3D.

## Important notes

1. Uses Raylib. Get it however you wish, though a solution file is included for raylib as well. You may need to do some extra things to get it running. 

2. Whenever you make new files, you MUST run the premake.exe file. It is **required** for it to compile. This is due to the way the project is set up, it allows for a quicker start (no linking) but it makes it annoying to do anything. 

## Steps to start out

1. Clone repo.
2. Run the premake file (whichever one applies to you, .exe, .bat, etc). 
3. Go into game, and thats where all your files should be located. Delete all the .c and .h files that aren't a part of the Raylib solution (like raylib.h, and anything else in that dir).
4. Copy and paste all the files in the game engine into /game. Yes it is annoying there is no organization, I have issues with setting up projects, for now I'm using VS2022 and filters to fix the annoyances. Will be updated later on to be organized into seperate lib, include, and src directories.
