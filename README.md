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

### Strategy 2

##### Vector

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.0209572s    | 0.163544s      | 1.6192s         | 15.753s          | 154.891s          |
| Time taken to sort data       | 0.00586344s   | 0.0549243s     | 0.591112s       | 5.76212s         | 66.2378s          |
| Time taken to divide students | 0.000764175s  | 0.00705321s    | 0.0999966s      | 0.880787s        | 8.2326s           |

##### List

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.012965s     | 0.138629s      | 1.3085s         | 12.9733s         | 127.401s          |
| Time taken to sort data       | 0.002991s     | 0.050864s      | 0.670208s       | 8.34269s         | 100.224s          |
| Time taken to divide students | 0.00009843s   | 0.004987s      | 0.061835s       | 0.63929s         | 9.9561s           |

##### Deque

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.013963s     | 0.132645s      | 1.2919s         | 12.8522s         | 129.165s          |
| Time taken to sort data       | 0.007979s     | 0.186501s      | 2.63058s        | 9.5421s          | 101.984s          |
| Time taken to divide students | 0.000997s     | 0.007979s      | 0.077305s       | 1.65432s         | 9.93604s          |

### Strategy 3

#### Vector

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.013962s     | 0.133641s      | 1.3283s         | 13.0426s         | 134.065s          |
| Time taken to sort data       | 0.00681s      | 0.175529s      | 0.7774s         | 7.856s           | 87.2209s          |
| Time taken to divide students | 0.000997s     | 0.012965s      | 0.141132s       | 1.0874s          | 11.098s           |

#### List

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.0208152s    | 0.133641s      | 1.54981s        | 15.6058s         | 153.042s          |
| Time taken to sort data       | 0.00485212s   | 0.0577385s     | 0.730288s       | 10.3186s         | 111.985s          |
| Time taken to divide students | 0.000438091s  | 0.00416862s    | 0.0714406s      | 0.814364s        | 8.21541s          |

#### Deque

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.013962s     | 0.129581s      | 1.28972s        | 12.8755s         | 138.635s          |
| Time taken to sort data       | 0.007978s     | 0.187784s      | 0.72893s        | 7.6598s          | 78.6523s          |
| Time taken to divide students | 0.000998s     | 0.009481s      | 0.100241s       | 1.0698s          | 10.5069s          |

**Comments:**

List strategy outperforms both Vector and Deque in terms of time taken to read data for all student sizes. However, when it comes to sorting data and dividing students, the Vector strategy seems to perform better compared to List and Deque, especially as the number of students increases.

The decision on which strategy is better depends on the specific requirements and constraints of the application. For instance:

- **Vector**: Efficient for tasks that require frequent access to elements and relatively fewer insertions and deletions.
- **List**: Suitable for scenarios where frequent insertions and deletions are required, as it offers constant-time insertion and deletion operations.
- **Deque**: A compromise between Vector and List, offering efficient random access to elements and constant-time insertion and deletion at both ends.

Consider the specific operations and performance requirements of your application to determine the most appropriate container strategy.

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

-Type `make optimize`
-Type `./run_01 `
`./run_02`
`./run_03`
