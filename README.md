# controller-logic

A platform‑agnostic way to share common logic across multiple controllers.

## Getting Started

These instructions assume you have a C/C++ compiler installed.

1. Installing [Meson](https://mesonbuild.com/Getting-meson.html) this assumes that you have [Python 3](https://www.python.org/) installed. *A sidenote: using a tool such as [pipx](https://github.com/pypa/pipx) simplifies this process a lot by just being able to run `pipx install meson` globally.*
2. [Ninja](https://ninja-build.org/) – this is the build tool that is going to be used to actually compile the code. It’s a lot like [GNU Make](https://www.gnu.org/software/make/) but not quite.
3. [VSCode](https://code.visualstudio.com/) – assuming that you have no editor set up. If you have one such as [Visual Studio](https://visualstudio.microsoft.com/), you can read the Meson docs for generating the proper build scripts for those tools.
4. :tada: Now the fun part: installing extensions in [VSCode](https://code.visualstudio.com/)!
    - [Meson](https://marketplace.visualstudio.com/items?itemName=mesonbuild.mesonbuild) – this extension gives support for **syntax** highlighting and a nice place to build and test the project.  
    - [clangd](https://marketplace.visualstudio.com/items?itemName=llvm-vs-code-extensions.vscode-clangd) – this extension will allow for the **IntelliSense** that we are all used to.
    *Another sidenote: if IntelliSense isn’t working out of the box, you may need to run  `ln -s builddir/compile_commands.json compile_commands.json` in the project’s root directory so that clangd can locate the generated compile‑commands file.*
5. `meson setup builddir`  
   This will now find the installed compiler on your system and download the required **dependencies**.
6. Compiling the project is as simple as:

   ```bash
   cd builddir && meson compile
   ```

    which will then produce the build.
