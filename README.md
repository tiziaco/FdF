# FdF - 3D Landscape Modeling with MiniLibX

In this first graphic project, the primary goal is to create visually appealing 3D landscapes by representing models in isometric projection. 

Leveraging the MiniLibX library, you'll delve into graphics programming, mastering fundamental skills such as opening windows, handling keyboard and mouse events, and rendering landscapes from specific viewpoints. This project provides a hands-on experience in utilizing MiniLibX to manipulate and visualize 3D coordinates stored in file, offering valuable insights into computer graphics and enhancing your understanding of complex phenomena through landscape representation.

## Rendering

The coordinates of the landscape are stored in a .fdf file, passed as a parameter to your program. Here's an example of an .fdf file:

```plaintext
$> cat 42.fdf
0000000000000000000 0000000000000000000
0 010100 010100 0 0101010101000 0 0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0 0 0101010101010000 01010101000 0
0 0 0101010101000 010100 0 0 0 0 0 0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 010100 0 010101010101000 0000000000000000000
0000000000000000000
```

Each number in the file represents a point in space:

- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

## Getting Started

1. Clone the repository:

   ```bash
   git clone https://github.com/tiziaco/fdf.git
   ```

2. Navigate to the project directory:

   ```bash
   cd fdf
   ```

3. Compile and run your program with a .fdf file:

   ```bash
   make
   ./fdf 42.fdf
   ```

---
