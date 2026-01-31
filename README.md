AIM
The aim of this project is to design and develop a modular C++ Electromagnetism (EM) library that numerically implements the fundamental laws of electromagnetism, including Coulomb’s Law, Gauss’s Law, Biot–Savart Law, and Maxwell’s Equations (1D, 2D, and 3D), and to visualize their physical behavior through graphical plots.
This project aims to:
Bridge the gap between theoretical electromagnetism and computational implementation
Help students understand EM laws through numerical simulation
Provide a reusable C++ EM library for educational and research purposes
📚 THEORY (Detailed)
Electromagnetism is one of the four fundamental interactions of nature and is governed by a set of physical laws that describe the behavior of electric and magnetic fields, charges, and currents. These laws are mathematically unified by Maxwell’s equations, which form the foundation of classical electrodynamics.
This library implements these laws numerically to study their behavior using computational methods.
1️⃣ Coulomb’s Law
Coulomb’s Law describes the electrostatic force between two stationary point charges.
Mathematical Form:
where:
1> are electric charges
2> is the distance between charges
3> is the permittivity of free space
Physical Interpretation:
The force is directly proportional to the product of charges
The force is inversely proportional to the square of distance
Like charges repel, unlike charges attract
Numerical Implementation:
In this library, Coulomb’s Law is implemented as a C++ function that computes force for varying distances. The force values are stored in data files and plotted as a Force vs Distance graph, clearly demonstrating the inverse-square behavior.


