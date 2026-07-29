<h1 align="center">Password Management Toolkit</h1>

<p align="center">
  <strong>A modular password generation and password strength analysis toolkit written in C.</strong>
</p>

<p align="center">
  Evaluate password strength, generate cryptographically strong passwords,
  and enforce common password security best practices—all from a simple
  command-line interface.
</p>

<div align="center">

![Last Commit](https://img.shields.io/github/last-commit/sasly2048/Password-Management-Toolkit)
![Language](https://img.shields.io/badge/Language-C-A8B9CC?logo=c&logoColor=white)
![License](https://img.shields.io/github/license/sasly2048/Password-Management-Toolkit)
![Made with Love](https://img.shields.io/badge/Made%20with-%E2%9D%A4-red)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-0078D4)

</div>

<div align="center">

[![Ko-fi](https://img.shields.io/badge/Support-Ko--fi-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/sasly204800)

</div>

---

## Features

- **Password Strength Checker** — analyzes password length, character diversity, and repeated-character patterns to produce a strength classification and improvement suggestions.
- **Random Password Generator** — generates a password of a user-specified length guaranteed to include at least one uppercase letter, one lowercase letter, one digit, and one special character, then evaluates it with the same strength checker.

---

## Password Strength Criteria

| Criteria                     | Description                                         |
| ---------------------------- | --------------------------------------------------- |
| Password length              | Rewards longer passwords                            |
| Uppercase letters (A–Z)      | Improves character-set diversity                    |
| Lowercase letters (a–z)      | Improves character-set diversity                    |
| Digits (0–9)                 | Adds numerical complexity                           |
| Special characters           | Increases password complexity                       |
| Repeated-character detection | Penalizes repetitive patterns that weaken passwords |

**Score Classification**

| Score | Classification |
| ----- | -------------- |
| 0     | 🔴 Very Weak   |
| 1     | 🟠 Weak        |
| 2     | 🟡 Fair        |
| 3     | 🟢 Moderate    |
| 4     | 🔵 Strong      |
| 5     | 🟣 Very Strong |
| 6     | ⭐ Excellent   |

---

## Build & Run

### GCC

```bash
gcc main.c password_generator.c strength_checker.c secure_random.c utils.c -o password_toolkit
```

### MSVC

```bat
cl main.c password_generator.c strength_checker.c secure_random.c utils.c bcrypt.lib
```

On Windows, the project uses **BCryptGenRandom()** for cryptographically
secure random number generation.

**Test online (GitHub Codespaces):**
[Open in Codespaces](https://github.com/codespaces/psychic-space-parakeet-4j664xp54gv9cjxq5?editor=web)

```bash
gcc main.c password_generator.c strength_checker.c secure_random.c utils.c -o password_toolkit
./password_toolkit
```

---

## Sample Usage

```
Select from the following:
1. Generate a Random Password & Check its Strength
2. Check the Strength of your own Password

Enter your choice: 1
Enter desired password length (minimum 8): 12

Generated Password: k7@Rz!qP9mXe

================================================================
Password Strength: Very Strong
All conditions satisfied!
================================================================
```

---

## Why are there `.h` files?

C projects are typically split into:

- **Header files (`.h`)** -- Declare functions, constants, types, and
  macros so other source files know what is available.
- **Source files (`.c`)** -- Contain the actual implementation.

For example:

```c
// password_generator.h
void generate_password(char *out, int length);
```

```c
// password_generator.c
void generate_password(char *out, int length)
{
    /* implementation */
}
```

`main.c` includes the header:

```c
#include "password_generator.h"
```

allowing it to call `generate_password()` without knowing how it is
implemented.

## Known Limitations

- **Platform-dependent randomness :** Windows builds use BCryptGenRandom() for cryptographically secure random number generation. The current non-Windows implementation is a development fallback and should be replaced with a platform-native CSPRNG such as getrandom() or arc4random_buf() for production use.
- **Limited input handling :** Basic numeric validation is implemented, but additional validation and error recovery could further improve robustness.
- **Single-pass menu :** The program performs one operation and exits rather than looping back to the menu.
- **Plaintext terminal echo :** Passwords entered for strength-checking are not masked during input.

These are documented deliberately as an active learning/portfolio project.

---

## Repository Structure

```text
Password-Management-Toolkit/
│
├── main.c                  # Program entry point and menu
│
├── constants.h             # Shared constants and configuration
│
├── password_generator.c    # Password generation logic
├── password_generator.h    # Password generator interface
│
├── strength_checker.c      # Password strength analysis
├── strength_checker.h      # Strength checker interface
│
├── secure_random.c         # Cryptographically secure random number generation
├── secure_random.h         # Secure RNG interface
│
├── utils.c                 # Common helper functions
├── utils.h                 # Utility function declarations
│
└── README.md
```

---

## 📄 License

Licensed under the [MIT License](LICENSE).
