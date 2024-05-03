# Specs

    CPU: AMD Ryzen 5 5600U with Radeon Graphics 2.30 GHz
    RAM: 16.0 GB (15.3 GB usable)
    SSD: WDC PC SN530 512Gb
    GPU: Integrated with CPU

# Structures vs Classes

##### Vector data from 1.0 with Structures

| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ---------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Skaitymas uztruko:           | 0.015444s     | 0.166344s      | 1.59188s        | 15.4619s         | 165.159s          |
| Rusiavimas uztruko:          | 0.006081s     | 0.0552494s     | 0.538313s       | 6.18915s         | 60.0473s          |
| Studentu skirstymas uztruko: | 0.002001s     | 0.00835907s    | 0.0876151s      | 1.10855s         | 11.3426s          |

##### Vector data from current project with Classes

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.009483000s  | 0.092085000s   | 0.891146000s    | 9.9532s          | 103.299s          |
| Time taken to sort data       | 0.0004988000s | 0.0138054000s  | 0.5996906000s   | 6.36929s         | 64.5623s          |
| Time taken to divide students | 0.000998000s  | 0.009950000s   | 0.102526000s    | 9.69208s         | 100.9854s         |

### Flag 01

##### Vector data from 1.0 with Structures

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.012954s     | 0.119683s      | 1.16192s        | 11.5372s         | 117.231s          |
| Time taken to sort data       | 0.001994s     | 0.027924s      | 1.22572s        | 13.6321s         | 16.1335s          |
| Time taken to divide students | 0.000764175s  | 0.001995s      | 0.021962s       | 0.880787s        | 10.6563s          |

##### Vector data from current project with Classes

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.006981000s  | 0.065823000s   | 0.633815000s    | 6.287439000s     | 61.8652s          |
| Time taken to sort data       | 0.000998000s  | 0.042885000s   | 0.430234000s    | 4.37760320s      | 44.22984s         |
| Time taken to divide students | 0.000000000s  | 0.002991000s   | 0.023937000s    | 0.268325000s     | 2.765211s         |

### Flag 02

##### Vector data from 1.0 with Structures

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.012965s     | 0.118711s      | 1.17678s        | 12.5630s         | 120.65483s        |
| Time taken to sort data       | 0.000981s     | 0.027925s      | 0.280301s       | 3.05608s         | 32.8461s          |
| Time taken to divide students | 0.000998s     | 0.002991s      | 0.022938s       | 0.36046s         | 5.605401s         |

##### Vector data from current project with Classes

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.007978000s  | 0.063828000s   | 0.640313000s    | 6.2466450s       | 63.642132s        |
| Time taken to sort data       | 0.000997000s  | 0.042885000s   | 0.21157780s     | 0.56131s         | 7.65231s          |
| Time taken to divide students | 0.000000000s  | 0.003017000s   | 0.022122000s    | 0.3056012s       | 3.0654s           |

### Flag 03

##### Vector data from 1.0 with Structures

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.0208152s    | 0.133641s      | 1.54981s        | 15.6058s         | 153.042s          |
| Time taken to sort data       | 0.00485212s   | 0.0577385s     | 0.730288s       | 10.3186s         | 111.985s          |
| Time taken to divide students | 0.000438091s  | 0.00416862s    | 0.0714406s      | 0.814364s        | 8.21541s          |

##### Vector data from current project with Classes

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.006987000s  | 0.064826000s   | 0.6326890s      | 6.262007000s     | 64.8594s          |
| Time taken to sort data       | 0.000997000s  | 0.042884000s   | 0.2950890s      | 3.173142000s     | 30.564123s        |
| Time taken to divide students | 0.000997000s  | 0.002991000s   | 0.0354300s      | 0.257002000s     | 2.654561s         |

**RUN FILE SIZES**

#### Structures

- run - 538KB
- run_O1 - 393KB
- run_O2 - 397KB
- run_O3 - 394KB

#### Classes

- run - 568KB
- run_O1 - 374KB
- run_O2 - 371KB
- run_O3 - 411KB

# Running a Makefile for C/C++ Projects

This guide will walk you through the process of running a Makefile for compiling and executing C/C++ programs on both macOS and Windows. If this tutorial does not work for you, try these solutions [Makefile](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows).

## Prerequisites

1.  **Make Installation:**

    - macOS: Make is usually pre-installed. You can verify by opening a terminal and typing `make -v`.
    - Windows: Install Make using a package manager like [Chocolatey](https://chocolatey.org/). Run `choco install make` in PowerShell or Command Prompt.

- **C/C++ Compiler:**

  - Ensure you have a C/C++ compiler installed. On macOS, Clang is typically pre-installed. On Windows, you can use MinGW or Cygwin.

- **Text Editor or IDE:**

  - Use a text editor or IDE to write your C/C++ code and Makefile. Popular choices include Visual Studio Code, Sublime Text, Atom, etc.

---

### 1\. Write Your Code

- Create your C/C++ code in one or more `.cpp` or `.c` files.

### 2\. Write Makefile

- Create a file named `Makefile` (without extension) in the same directory as your source code.
- Open `Makefile` in a text editor and define build rules.

### 3\. Open Terminal/Command Prompt

- macOS: Open Terminal.
- Windows: Open Command Prompt or PowerShell.

### 4\. Navigate to Project Directory

- Use `cd` command to navigate to the directory containing your code and Makefile.

### 5\. Run Make

- Type `make` and press Enter. This executes the default target (`all`) in the Makefile.

### 6\. Run Your Program

- After successful build, an executable file (e.g., `run` on macOS or `run.exe` on Windows) will be generated in the same directory.
- Run the program by typing `./run` on macOS or `run.exe` on Windows, and press Enter.

Congratulations! You've successfully compiled and executed your C/C++ program using a Makefile. If you encounter any errors during compilation, check your Makefile and source code for issues.

### 6\. How To Run Code With Flags

- Type `make optimize`
- Type `./run_o1 `
  `./run_o2`
  `./run_o3`
