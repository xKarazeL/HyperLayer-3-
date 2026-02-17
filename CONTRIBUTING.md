# Contributing to HyperLayer Protocol

First off, thank you for considering contributing to HyperLayer Protocol! 🎉

## Code of Conduct

This project and everyone participating in it is governed by respect, professionalism, and collaboration.

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check the issue list as you might find out that you don't need to create one. When you are creating a bug report, please include as many details as possible:

* **Use a clear and descriptive title**
* **Describe the exact steps to reproduce the problem**
* **Provide specific examples**
* **Describe the behavior you observed and what you expected**
* **Include your environment details** (OS, compiler version, etc.)

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues. When creating an enhancement suggestion, please include:

* **Use a clear and descriptive title**
* **Provide a detailed description of the suggested enhancement**
* **Explain why this enhancement would be useful**
* **List some examples of how it would be used**

### Pull Requests

* Fill in the required template
* Follow the C++17 coding style
* Include appropriate test coverage
* Update documentation as needed
* End all files with a newline

## Development Setup

```bash
# Clone the repository
git clone https://github.com/your-username/hyperlayer-protocol.git
cd hyperlayer-protocol

# Build the project
make clean
make

# Run tests
make test
```

## Coding Standards

### C++ Style Guide

* Use C++17 standard features
* Follow modern C++ best practices
* Use smart pointers (unique_ptr, shared_ptr) over raw pointers
* Prefer const correctness
* Use meaningful variable and function names
* Comment complex algorithms

### Example:

```cpp
// Good
std::unique_ptr<QuantumCrypto> crypto = std::make_unique<QuantumCrypto>();

// Avoid
QuantumCrypto* crypto = new QuantumCrypto();
```

### Code Organization

* Keep functions focused and small
* Use namespaces appropriately
* Separate interface (.hpp) from implementation (.cpp)
* Document public APIs

### Commit Messages

* Use the present tense ("Add feature" not "Added feature")
* Use the imperative mood ("Move cursor to..." not "Moves cursor to...")
* Limit the first line to 72 characters or less
* Reference issues and pull requests liberally after the first line

Example:
```
Add quantum-resistant signature verification

- Implement CRYSTALS-Dilithium signature scheme
- Add unit tests for signature verification
- Update documentation

Fixes #123
```

## Testing

* Write unit tests for new features
* Ensure all tests pass before submitting PR
* Test on multiple platforms if possible (Linux, macOS, Windows)

## Documentation

* Update README.md for user-facing changes
* Update WHITEPAPER.md for protocol changes
* Add inline comments for complex logic
* Update API documentation

## Project Structure

```
hyperlayer-protocol/
├── src/
│   ├── hyperlayer_core.hpp      # Core definitions
│   ├── hyperlayer_core.cpp      # Core implementation
│   ├── hyperlayer_core_part2.cpp # Advanced features
│   └── main.cpp                  # Test/demo program
├── docs/
│   ├── README.md                 # User documentation
│   └── WHITEPAPER.md             # Technical specification
├── tests/                        # Test files (future)
├── Makefile                      # Build system
└── LICENSE                       # MIT License
```

## Questions?

Feel free to open an issue with the `question` label.

## Recognition

Contributors will be recognized in the project documentation.

Thank you for contributing to HyperLayer Protocol! 🚀
