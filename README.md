#  Electromagnetic Theory Library (C++)

A comprehensive *C++ Electromagnetic Theory library* that numerically implements the *fundamental laws of electromagnetism* and visualizes their physical behavior .  
This project bridges *theoretical electromagnetism* with *computational physics*.

-----
##  AIM

The aim of this project is to design and develop a modular *Electromagnetic Theory library in C++* that numerically implements the fundamental laws of electromagnetism—*Coulomb’s Law, Gauss’s Law, Biot–Savart Law, and Maxwell’s Equations (1D, 2D, and 3D)*—and to visualize their behavior through computational simulations .

------
##  FEATURES

 Modular C++ library design  
 Numerical implementation of EM laws  
 1D, 2D, and 3D Maxwell equation solvers   
 Clean, academic, and extendable structure  

------
##  THEORY

Electromagnetism is a fundamental branch of physics that deals with the interaction of *electric charges, currents, electric fields, and magnetic fields*.  
The entire classical theory of electromagnetism is unified through *Maxwell’s equations*, which explain how electric and magnetic fields are generated and how they propagate through space as electromagnetic waves.

This library implements the major laws of electromagnetism numerically to help students and researchers *understand physical behavior through computation*.


## (1️) Coulomb’s Law

Coulomb’s Law describes the *electrostatic force* between two stationary point charges.

### Mathematical Form
F = (1 / 4πϵ₀) × (q₁ q₂ / r²)
---
### Physical Interpretation
- Force is directly proportional to the product of charges  
- Force is inversely proportional to the square of distance  
- Like charges repel, unlike charges attract
  
---
### Computational Approach
The force is computed numerically for varying distances, and the inverse-square nature is verified through analysis of the numerical data.

---

## (2) Gauss’s Law (Electric)

Gauss’s Law relates the *electric flux* through a closed surface to the *total charge enclosed*.

### Mathematical Form
∮ E · dA = Q / ϵ₀
---
### Physical Interpretation
- Electric flux depends only on enclosed charge  
- Independent of the shape of the Gaussian surface  
- Demonstrates symmetry in electric fields  

### Computational Approach
Electric flux is computed numerically for different charge values and visualized to verify linear proportionality.

---

## (3️) Biot–Savart Law

The Biot–Savart Law describes the *magnetic field produced by a steady electric current*.

### Mathematical Form (Straight Current-Carrying Wire)
B = (μ₀ I) / (2π r)
---
### Physical Interpretation
- Magnetic field strength decreases with distance  
- Direction is determined by the right-hand thumb rule  

### Computational Approach
Magnetic field values are calculated for different distances as numerical data to demonstrate magnetic field decay.

---

## (4) Maxwell’s Equations

Maxwell’s equations unify electricity and magnetism and predict the existence of *electromagnetic waves*.

### Differential Form
∇ · E = ρ / ϵ₀        (Gauss’s Law – Electric) 
∇ · B = 0            (Gauss’s Law – Magnetism) 
∇ × E = −∂B/∂t       (Faraday’s Law) 
∇ × B = μ₀J + μ₀ϵ₀∂E/∂t (Ampère–Maxwell Law)
---
---

## (5) Maxwell’s Equations – 1D Simulation

### Description
In one dimension, Maxwell’s equations describe *electromagnetic wave propagation* along a single axis.

### Numerical Method
- Finite Difference Time Domain (FDTD)
- Discretized space and time

### Outcome
- Demonstrates oscillatory electric and magnetic fields  
- Visualizes EM wave behavior  

---

## (6) Maxwell’s Equations – 2D Simulation

### Description
In two dimensions, electromagnetic fields evolve on a planar grid.

### Numerical Method
- Finite difference spatial derivatives
- Field evolution over time

### Outcome
- Demonstrates interaction of fields in space  
- Useful for surface and planar EM problems  

---

## (7) Maxwell’s Equations – 3D Representation

### Description
A simplified numerical representation of three-dimensional electric field components.

### Purpose
- Visualize time evolution of Ex, Ey, and Ez  
- Introduce 3D electromagnetic behavior  

### Educational Value
- Foundation for advanced 3D FDTD solvers  
- Bridges theory with real-world EM simulations  

---



##  REQUIREMENTS

- C++ Compiler (g++)
- GNU Make

---
##  HOW TO RUN

```bash
 .\a.exe
 .\gauss_test.exe
 .\biot_savart_test.exe
 .\maxwell1d_test.exe
 .\maxwell2d_test.exe
 .\maxwell3d_test.exe
```
## Project Structure
```bash
EMTheory/
├─ include/               # Header files
│  ├─ emt.hpp
│  ├─ coulomb.hpp
│  ├─ gauss.hpp
│  ├─ biot_savart.hpp
│  ├─ maxwell1d.hpp
│  ├─ maxwell2d.hpp
│  └─ maxwell3d.hpp
├─ src/                   # Implementation files
│  ├─ emt.cpp
│  ├─ coulomb.cpp
│  ├─ gauss.cpp
│  ├─ biot_savart.cpp
│  ├─ maxwell1d.cpp
│  ├─ maxwell2d.cpp
│  └─ maxwell3d.cpp
├─ examples/              # Example programs
│  ├─ test_coulomb.cpp
│  ├─ test_gauss.cpp
│  ├─ test_biot_savart.cpp
│  └─ test_maxwell.cpp
├─ .vscode/               # VS Code configuration (optional)
└─ README.md              # Documentation
```
## Concluision
EMTheory provides a structured and extensible foundation for exploring classical electromagnetic theory using modern C++. By organizing core electromagnetic laws into clear modules with example-driven usage, the library bridges the gap between theoretical physics and practical scientific computing.


The project is well-suited for educational purposes, numerical experimentation, and as a starting point for advanced simulations involving electromagnetic fields. Its modular design allows users to easily extend functionality, integrate numerical solvers, or connect visualization tools as future enhancements.


With continued development—such as time-dependent solvers, visualization support, and CMake integration—EMTheory has the potential to grow into a robust open-source toolkit for students, educators, and researchers in physics and engineering.

----

