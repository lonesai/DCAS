# DCAS
Drone Collision Avoidance System (DCAS)
-------------------------------------------------------
DCAS is a program to simulate real life drone movement and how they interact
with each other, given a destination to travel to.

-------------------------------------------------------
Getting Stared: Untar all the tar files found in the include and src
directories. Then go in to the src directory by using the commend line as fallowed.

cd Project1/src

After successfully entering in to the src directory simply run the make commend
to make all the object files and executable called dcas.
To run dcas simply use the commend:

./dcas

This will print out the environment of the drones and drones itself.
EXAMPLE PRINT OUT:

A 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

Where it prints out a 8x8 grid or a size you can specify by hard coding it
with-in "world.h". "A" in the grid represents the staring airport. "0" represents
the free positions and "1" represents where the drone is.

Author:
Sai Lone

