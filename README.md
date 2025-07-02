# Computer Algebra System (\*\*WIP\*\*)

This is a simple command-line CAS written in C++.

**_NOTE: This program was developed on Linux, and it has not been tested on Windows or MacOS._**

This repo was rebased in June 2025, which reset the commit timestamps.

---

## Installation

`Make` and `gcc` need to be installed on your system to compile this project.

**Linux (only build):**  
```git clone https://github.com/TheLogicle/CAS && cd CAS && make```

**Linux (build & install):**  
```git clone https://github.com/TheLogicle/CAS && cd CAS && make && sudo install cas /usr/bin```

---

## Usage

Run `cas` in the terminal, and a prompt will appear *(If you only built the program without installing, the executable file is named `cas` in your local repository.)*

### Currently supported at this moment in development:
- Whole numbers and positive decimals
- Basic math expressions with order of operations (e.g. entering `4+5*2` will yield `14`)
- Parentheses (e.g. entering `(5-3)*6` will yield `12`)

### Not supported yet, but planned:
- Negative numbers
- Multiplication by juxtaposition
- Variables
