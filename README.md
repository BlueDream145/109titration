# 109titration
Epitech Project, MATHS 109

Subject:

The benzoic acid (whom molecule is hereby represented) is used in industry as a food
preservative under the E220 code. It is a white silky-looking solid.
To dertermine the concentration of this additive in a solution, one can realize a pH titration:
soda is progressivly added to the solution, and pH is then read.
The generated curve is typical, and has an area where pH brutally increases: it is the
pH-jump.

To find the volume of preservative of the initial solution, the volume of added
soda at the equivalent point (ie at the middle of the pH-jump) must be
read.
There are two main approaches to do so :
• the derivative method, which consists in calculating the derivative of the curve ; the equivalent point matches
with the maximum of this derivative,
• the parallel tangents method, which consists in drawing two parallel tangents from one part and another of
the pH-jump, then to draw a third straight line quidistant from the two first. The equivalent point is at the
intersection between this last line and the curve.

Lucky you, only the first approach is to be coded here.
Your program has to read pH and soda volume (in ml) couples from a csv file, and output :
1. the derivative values for each given volume,
2. the closest point from the equivalent point amongst those given points,
3. the second derivative values for each given volume,
4. an approximation of the second derivative values every 0.1ml around the above closest point from the equiv-
alent point,
5. the proper equivalent point, estimaed from the second derivative.

Usage:

./109titration file

file     a csv file containing "vol;ph" lines

Example:


![alt text](https://raw.githubusercontent.com/alexandre10044/109titration/master/example.png)
