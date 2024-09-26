A space exploration mission has been launched by a company called SpaceZ. The spaceships they have are limited in number. They only have N
 spaceships which have no acceleration, only speed. The universe is huge, and with unlimited number of resources they may explore much of it but since the resources SpaceZ has, is limited, they have set a goal to explore M
 planets. 

Each of the spaceship can reach any of the M
 planets, but once a spaceship arrives at a particular planet, it is closed off to everyone and cannot be explored by any other spaceship. This has been done so that there is no duplicated effort by their spaceships.

The board of directors have decided that the mission may be deemed successful when K
 spaceships have completed their exploration.

You have been hired as an analyst who is provided the coordinates of N
 spaceships in the form (x,y)
 and M
 planets in the form (p,q)
, along with the speed S
 of each spaceship.

Time for a spaceship to go to a planet, is defined as t=⌈(p−x)2+(q−y)2S2⌉
 in minutes.

You need to find the value of the minimum time needed to complete the space exploration mission i.e the minimum time to reach the goal set by the board of directors of SpaceZ if possible.

Input

The first line contains a single integer t, the number of test cases. Description of the test cases is as follows:

The next line of input contains 3 space-separated integers N
 , M
 and K
.

The next N
 lines, each have 2
-space separated integers x
 and y
.

The next M
 lines, each have 2
-space separated integers p
 and q
.

The final line contains N
 space-separated integers indicating S
.

Constraints 

1≤t≤10

1≤N≤200

1≤M≤200

1≤K≤N

0≤x,y,p,q≤106

1≤S≤50

Output 

For each testcase, get the minimum time needed to complete the space exploration mission i.e the minimum time to reach the goal set by the board of directors of SpaceZ in minutes and display it in seconds. If it is not possible to complete the space exploration, print −1
.

Example

Input:
1
3 2 1
1 1
2 2
3 3
34 59
14 20
1 2 3
Output:
2760
Explanation

To complete the exploration as decided by the board of directors, 1
 spaceship must reach a planet. We see that the spaceship at coordinate (3,3)
 gets this goal done in the minimum time 2760
s by reaching the planet at coordinate (14,20)
 using the following formula:

t=⌈(3−14)2+(3−20)232⌉min=2760s
