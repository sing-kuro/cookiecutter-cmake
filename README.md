# cookiecutter-cmake
A simple template for C++ projects using CMake.

**Projects generated from this template are entirely yours.**  
You do not need to credit this repository when using the generated project.

## Features
- Automated testing using GTest.
- Automatically deploy the docs to GitHub Pages.

## Usage
You need to enable GitHub Pages and set the Source to GitHub Actions in order to automatically publish the docs.

### Creating a project
```bash
$ pip install cookiecutter
$ cookiecutter https://github.com/sing-kuro/cookicutter-cmake.git --directory="standalone" # or --directory="header-only", --directory="library"
  [1/7] project_name (my_project): MyLibrary # The name of the library (alphanumeric letters and underscore are allowed. Must start with an alphabet).
  [2/7] github_username (): sing-kuro # Your GitHub username
  [3/7] repo_name (MyLibrary): my-library # The name of the GitHub repository for this project.
  [4/7] include_dir (MyLibrary): mylib # The header files will live in include/include_dir.
  [5/7] release_branches (master): main, release # Comma-separated list of the branches for GitHub Actions to watch.
  [6/7] project_upper (MYLIBRARY): MY_LIBRARY # Name to use in include guardes and CMake variables.
  [7/7] name_space (MyLibrary): myl # The name space to use in the code.
```

Read the generated README.md for build commands.
