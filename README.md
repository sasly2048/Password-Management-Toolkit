<h1 align="center">Password Management Toolkit</h1>

<p align="center">
  <strong>A lightweight C toolkit for password analysis and secure password generation.</strong>
</p>

<p align="center">
  Evaluate password strength, generate cryptographically strong passwords,
  and enforce common password security best practices—all from a simple
  command-line interface.
</p>

---

## Features

- **Password Strength Checker** — scores a user-supplied password against five security criteria and returns a strength classification with targeted improvement suggestions.
- **Random Password Generator** — generates a password of a user-specified length guaranteed to include at least one uppercase letter, one lowercase letter, one digit, and one special character, then evaluates it with the same strength checker.

---

## Password Strength Criteria

| Criteria | Description | Points |
|---|---|---|
| Length ≥ 8 characters | Ensures a baseline resistance to brute-force attacks | +1 |
| Contains uppercase letters (A–Z) | Improves character-set complexity | +1 |
| Contains lowercase letters (a–z) | Improves character-set diversity | +1 |
| Contains digits (0–9) | Adds numerical entropy | +1 |
| Contains special characters (`!@#$...`) | Adds unpredictability | +1 |

**Score Classification**

| Score | Classification |
|---|---|
| 0 – 1 | 🔴 Very Weak |
| 2 | 🟠 Weak |
| 3 | 🟡 Moderate |
| 4 | 🟢 Strong |
| 5 | 🟣 Very Strong |

---

##  Build & Run

**Local (gcc/clang — Linux, macOS, WSL, or Windows via MinGW/clang):**
```bash
gcc code.c -o password_toolkit
./password_toolkit
```

**Windows (MSVC):**
```powershell
cl code.c /Fe:password_toolkit.exe
.\password_toolkit.exe
```

**Test online (GitHub Codespaces):**
[Open in Codespaces](https://github.com/codespaces/psychic-space-parakeet-4j664xp54gv9cjxq5?editor=web)
```bash
gcc code.c -o code && ./code
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

## Known Limitations

- **Not cryptographically secure.** The generator uses the C standard library `rand()`, seeded with `srand(time(NULL))`. This is a pseudo-random number generator (PRNG) that is predictable and unsuitable for producing real security credentials — do not use generated passwords for actual accounts. A production version should use a CSPRNG (e.g. `/dev/urandom` on Linux, `BCryptGenRandom` on Windows, or `arc4random_buf` where available).
- **No input validation on numeric input.** `scanf("%d", &length)` does not check for a failed read; non-numeric input results in undefined behavior.
- **Single-pass menu.** The program performs one operation and exits rather than looping back to the menu.
- **Plaintext terminal echo.** Passwords entered for strength-checking are not masked during input.

These are documented deliberately as an active learning/portfolio project — see Roadmap below for planned fixes.

---

## Repository Structure

```
Password_Management_Toolkit/
├── code.c        # Core program: strength checker + password generator
└── README.md
```

---

## 📄 License

Licensed under the [MIT License](LICENSE).
