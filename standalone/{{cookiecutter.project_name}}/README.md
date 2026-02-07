# {{ cookiecutter.project_name }}

## Requirements

## Building

### Installing
Example commands to install:
```sh
git clone https://github.com/{{ cookiecutter.github_username }}/{{ cookiecutter.repo_name }}.git
cd {{ cookiecutter.repo_name }}
cmake -S . -B build -DBUILD_{{ cookiecutter.project_upper }}_DOCS=ON -DENABLE_TESTING_{{ cookiecutter.project_upper }}=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build
cmake --install build --prefix "/your/install/dir"
```

## Usage

## Issue Report
If you find any issues on this project, please [report it on GitHub](https://github.com/{{ cookiecutter.github_username }}/{{ cookiecutter.repo_name }}/issues).

## Acknowledgements
- This project utilizes OSS (Open Source Software)
    See [NOTICE.md](NOTICE.md)
