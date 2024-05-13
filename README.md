# Specs

    CPU: AMD Ryzen 5 5600U with Radeon Graphics 2.30 GHz
    RAM: 16.0 GB (15.3 GB usable)
    SSD: WDC PC SN530 512Gb
    GPU: Integrated with CPU

# v1.5

# Structures vs Classes

##### Data from 1.1

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.006987000s  | 0.064826000s   | 0.6326890s      | 6.262007000s     | 64.8594s          |
| Time taken to sort data       | 0.000997000s  | 0.042884000s   | 0.2950890s      | 3.173142000s     | 30.564123s        |
| Time taken to divide students | 0.000997000s  | 0.002991000s   | 0.0354300s      | 0.257002000s     | 2.654561s         |

##### Data with "Rule of Five"

| Task                          | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
| ----------------------------- | ------------- | -------------- | --------------- | ---------------- | ----------------- |
| Time taken to read data       | 0.006981000s  | 0.063828000s   | 0.628348000s    | 6.200408000s     | 64.8594s          |
| Time taken to sort data       | 0.000952000s  | 0.048868000s   | 0.245346400s    | 2.10981s         | 22.098095s        |
| Time taken to divide students | 0.000000000s  | 0.002992000s   | 0.026930000s    | 0.34083900s      | 3.61350350s       |

# Abstract Class "Zmogus"

#### An abstract class in C++ is a class that contains at least one pure virtual function. A pure virtual function is a virtual function for which we provide only the declaration in the base class, without providing any implementation. Abstract classes are designed to be used as base classes, and they cannot be instantiated directly. Instead, they are intended to serve as interfaces that define a common set of methods that derived classes must implement.

    class Zmogus {
    public:
        virtual void setVardas(std::string vardas) = 0;
        virtual std::string getVardas() const = 0;
        virtual void setPavarde(std::string pavarde) = 0;
        virtual std::string getPavarde() const = 0;
        virtual ~Zmogus() = default;

    };

### The key characteristics of an abstract class are:

- Contains Pure Virtual Functions: An abstract class contains at least one pure virtual function, which is declared with the virtual keyword and assigned the value 0 as its implementation.
- Cannot be Instantiated: Since abstract classes have at least one pure virtual function without an implementation, objects of abstract classes cannot be created directly. Attempting to create an instance of an abstract class will result in a compilation error.
- Used as Base Classes: Abstract classes are meant to be used as base classes. Derived classes inherit from abstract classes and provide concrete implementations for all the pure virtual functions defined in the abstract base class.

# Rule of Five and Overloaded Methods

## Rule of Five

In C++, the Rule of Five refers to a set of guidelines concerning resource management for classes that manage dynamic memory allocation or external resources. The Rule of Five consists of five special member functions that need to be defined or explicitly disabled if one of them is used:

### Destructor

##### Responsible for releasing resources acquired by the object.

    Studentas::~Studentas() {
    nd_rezultatai.clear();
    vardas.clear();
    pavarde.clear();
    egzaminas = 0;

}

### Copy Constructor

#### Creates a new object as a copy of an existing object.

    Studentas::Studentas(const Studentas &copy)
    : vardas(copy.vardas), pavarde(copy.pavarde), nd_rezultatai(copy.nd_rezultatai),egzaminas(copy.egzaminas) {}

### Copy Assignment Operator

#### Assigns the state of one object to another existing object.

    Studentas& Studentas::operator=(const Studentas& copy)
    {
        if(this !=&copy)
        {
            vardas = copy.vardas;
            pavarde = copy.pavarde;
            nd_rezultatai = copy.nd_rezultatai;
            egzaminas = copy.egzaminas;
        }
        return *this;
    }

### Move Constructor

#### Transfers resources from a temporary object to a new object.

        Studentas& Studentas::operator=(Studentas&& copy) noexcept {
            if (this!= &copy) {
                // Swap the members of the current object with the members of the other object
                std::swap(vardas, copy.vardas);
                std::swap(pavarde, copy.pavarde);
                std::swap(nd_rezultatai, copy.nd_rezultatai);
                std::swap(egzaminas, copy.egzaminas);
            }
            return *this;
        }

### Move Assignment Operator

#### Transfers resources from one object to another existing object.

        Studentas& Studentas::operator=(Studentas&& copy) noexcept {
            if (this!= &copy) {
                // Swap the members of the current object with the members of the other object
                std::swap(vardas, copy.vardas);
                std::swap(pavarde, copy.pavarde);
                std::swap(nd_rezultatai, copy.nd_rezultatai);
                std::swap(egzaminas, copy.egzaminas);
            }
            return *this;
        }

## Overloaded Methods

The `Studentas` class overloads the input and output operators (`operator<<` and `operator>>`) to provide serialization and deserialization capabilities. These overloaded methods allow objects of the `Studentas` class to be written to an output stream (e.g., `std::cout` or a file) and read from an input stream (e.g., `std::cin` or a file).

### Output Operator (`operator<<`)

#### The output operator `operator<<` is overloaded to serialize a `Studentas` object to an output stream. It prints the `vardas`, `pavarde`, `egzaminas`, and `nd_rezultatai` member variables to the output stream.

    std::ostream& operator<<(std::ostream& output, const Studentas &student) {
        output << student.vardas << " " << student.pavarde << " " << student.egzaminas << " ";
        for (int pazymys : student.nd_rezultatai) {
            output << std::to_string(pazymys) << " "; // Pries printinant pakeist int'a i string'a
        }
        return output;
    }

### Input Operator (`operator>>`)

#### The input operator `operator>>` is overloaded to deserialize a `Studentas` object from an input stream. It reads `vardas`, `pavarde`, `egzaminas`, and `nd_rezultatai` from the input stream and constructs a `Studentas` object accordingly.

    std::istream& operator>>(std::istream& input, Studentas &student) {
        input >> student.vardas >> student.pavarde;
        input >> student.egzaminas;
        student.nd_rezultatai.clear();
        int pazymys;
        while (input >> pazymys) {
            student.nd_rezultatai.push_back(pazymys);
        }
        return input;
    }

# v2.0

# Installing Doxygen

## What is Doxygen?

Doxygen is a documentation generator tool that is used to generate documentation from source code. It supports several programming languages and can generate documentation in various formats, such as HTML, LaTeX, RTF, and more.

## Installation Steps:

### 1\. Download Doxygen:

You can download the latest version of Doxygen from the official website: www.doxygen.nl/download.html.

### 2\. Install on Windows:

#### Using Installer:

- Double-click the downloaded installer file.
- Follow the on-screen instructions provided by the installer.
- Once installed, Doxygen should be accessible from the Start menu.

#### Using Zip Archive:

- Extract the downloaded zip archive to a location of your choice.
- Add the path to the Doxygen executable to your system's PATH environment variable.

### 3\. Install on macOS:

#### Using Homebrew:

If you have Homebrew installed, you can install Doxygen using the following command:

Copy code

`brew install doxygen`

#### Manual Installation:

- Download the macOS version from the official website.
- Mount the downloaded disk image and drag the Doxygen application to your Applications folder.

### 4\. Install on Linux:

#### Using Package Manager:

- On Debian/Ubuntu:

  arduino

  Copy code

  `sudo apt-get install doxygen`

- On Fedora:

  Copy code

  `sudo dnf install doxygen`

#### Manual Installation:

- Download the Linux version from the official website.
- Extract the downloaded archive to a location of your choice.
- Add the path to the Doxygen executable to your system's PATH environment variable.

### 5\. Verify Installation:

To verify that Doxygen has been installed correctly, open a terminal or command prompt and type:

Copy code

`doxygen -v`

You should see the version information displayed if Doxygen has been installed successfully.

## Additional Resources:

- Doxygen Documentation
- [Doxygen GitHub Repository](https://github.com/doxygen/doxygen)

Now that you've installed Doxygen, you can start generating documentation for your projects!

# Using Overleaf.com for LaTeX

## What is Overleaf?

Overleaf is an online LaTeX editor that allows you to create, edit, and collaborate on LaTeX documents in real-time. It provides a user-friendly interface and powerful LaTeX tools, making it a popular choice for academics, researchers, and students.

## Getting Started:

### 1\. Create an Account:

If you haven't already, sign up for an account on Overleaf.com.

### 2\. Create a New Project:

Once logged in, click on the "New Project" button to create a new LaTeX project.

### 3\. Choose a Template (Optional):

Overleaf offers a variety of templates for different types of documents, such as research papers, presentations, and CVs. You can choose a template to start with or create a blank document.

### 4\. Writing and Editing:

Use the LaTeX editor provided by Overleaf to write and edit your document. You can type directly into the editor or upload existing LaTeX files.

### 5\. Collaboration:

Overleaf allows you to collaborate with others on your LaTeX documents in real-time. You can share your project with collaborators and work together on the same document simultaneously.

### 6\. Compiling:

Overleaf automatically compiles your LaTeX document as you type, so you can see the output in real-time. You can also manually compile your document by clicking the "Recompile" button.

### 7\. Downloading:

Once you're satisfied with your document, you can download it in various formats, such as PDF, LaTeX, and Word.

## Additional Features:

- **Rich Text Editor**: Overleaf provides a rich text editor mode for users who are not familiar with LaTeX syntax.
- **Version History**: Overleaf keeps track of the version history of your documents, allowing you to revert to previous versions if needed.
- **Publishing**: You can publish your documents directly from Overleaf to various journals and preprint repositories.

## Resources:

- Overleaf Documentation
- Overleaf Templates

With Overleaf, you can easily create professional-quality LaTeX documents without the need for complex software installations. Start using Overleaf today to streamline your LaTeX workflow!

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
