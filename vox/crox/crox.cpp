// Return codes: https://man.freebsd.org/cgi/man.cgi?query=sysexits&apropos=0&sektion=0&manpath=FreeBSD+4.3-RELEASE&format=html

#include "Crox.hpp" 

#include <iostream>
#include <vector>
#include <fstream>

static void run(const std::string& source);
static void runFile(const std::string& path);
static void runPrompt();

bool hadError = false;

// Error Handling
namespace Lox {
    void error(const int line, const std::string& message) {
        report(line, "", message);
    }
}

static void report(const int line, const std::string& where, const std::string& message) {
    std::cerr << "[Line " << line << "] Error" << where << ": " << message;

    hadError = true;
}

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr << "\
        Usage: crox <script>\
               crox (REPL)\
        ";

        std::exit(64);  // EX_USAGE
    }
    else if (argc == 2) {
        runFile(argv[1]);
    }
    else {
        runPrompt();
    }
        

    std::exit(0); // EX_OK
}

static void run(const std::string& source) {
    Scanner scanner = Scanner(source);
    vector<Token> tokens = scanner.scanTokens();

    for (Token token: tokens) {
        std::cout << token;
    }
}

// Run a script
static void runFile(const std::string& path) {
    std::ifstream file {path};

    // File was not opened successfully
    if (!file) {
        std::cerr << "Could not open file: " + path;
    }

    std::string bytes { std::istreambuf_iterator<char> {file}, {}};

    run(bytes);

    if (hadError) std::exit(65); // EX_DATAERR
}

// REPL
static void runPrompt() {
    while (true) {
        std::cout << "\nLox REPL\n";
        std::cout << ">> ";    
        std::string line;

        std::getline(std::cin, line); // read user command

        if (line.empty() or std::cin.eof()) break; // empty comand => do nothing
        
        if (line == "exit") break; // exit instruction

        run(line);

        hadError = false;
    }
} 