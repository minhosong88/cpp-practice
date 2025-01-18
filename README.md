# cpp-practice

### Installation Guide(VSCODE)

- Go to : https://www.msys2.org/#installation
- 1.  Download the installer: msys2-x86_64-20241208.exe(https://github.com/msys2/msys2-installer/releases/download/2024-12-08/msys2-x86_64-20241208.exe)
- 2.  Run the installer. Installing MSYS2 requires 64 bit Windows 10 or newer.
- 3.  Enter your desired Installation Folder (short ASCII-only path on a NTFS volume, no accents, no spaces, no symlinks, no subst or network drives, no FAT)
- 4.  MSYS2 is ready for you and a terminal for the UCRT64 environment will launch.
- 5.  You will probably want to install some tools like the mingw-w64 GCC to start compiling projects. Run the following command:
- Complier

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

- Debugger

```bash
pacman -S mingw-w64-ucrt-x86_64-gdb
```

- Or toolchains

```bash
pacman -S mingw-w64-ucrt-x86_64-toolchain
```

- Verify the installation

```bash
gcc --version   # Check GCC version
g++ --version   # Check G++ version
gdb --version   # Check GDB version
```

- 6. Set Up Path in VS Code
     After installing these tools, ensure that the binaries are in your PATH environment variable:

- Add the following to your system PATH: `C:\msys64\ucrt64\bin` (or equivalent, depending on your installation).
- Restart VS Code to ensure the PATH changes are recognized.

### Create a Default Template for C++ in VSC

1. File > Preferences > Configure User Snippets
2. Select `cpp` or `cpp.json`
3. Add default snippet

```json
    "C++ Template": {
        "prefix": "cppmain",
        "body": [
            "#include <iostream>",
            "",
            "",
            "int main() {",
            "    ${1:// Your code here}",
            "    return 0;",
            "}"
        ],
        "description": "Default C++ template"
    }
```

- **prefix:** Shortcut to trigger the snippet (e.g., cppmain).
- **body:** The content of the template.
- **description:** A description of the snippet.
