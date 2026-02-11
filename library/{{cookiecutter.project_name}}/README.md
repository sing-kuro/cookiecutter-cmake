# {{ cookiecutter.project_name }}

## Requirements

## Building

### Installing
Example commands to install the library:
```sh
git clone https://github.com/{{ cookiecutter.github_username }}/{{ cookiecutter.repo_name }}.git
cd {{ cookiecutter.repo_name }}
cmake -S . -B build -DBUILD_{{ cookiecutter.project_upper }}_DOCS=ON -DENABLE_TESTING_{{ cookiecutter.project_upper }}=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build
cmake --install build --prefix "/your/install/dir"
```

### Linking
In your project's `CMakeLists.txt`, add:
```cmake
find_package({{ cookiecutter.project_name }} REQUIRED)
target_link_libraries(YourApp PRIVATE {{ cookiecutter.project_name }}::{{ cookiecutter.project_name }})
```

If you have installed the library on your machine:
```sh
cmake -S . -B build -DCMAKE_PREFIX_PATH="/your/install/dir"
```

If you want to avoid installing the library locally:
```sh
cmake -S . -B build -D{{ cookiecutter.project_name }}_DIR=/path/to/{{ cookiecutter.project_name }}/build
```

If you prefer to use CMake's `FetchContent`:
```cmake
include(FetchContent)

FetchContent_Declare(
    {{ cookiecutter.project_name }}
    GIT_REPOSITORY https://github.com/{{ cookiecutter.github_username }}/{{ cookiecutter.repo_name }}.git
    GIT_TAG # The commit hash you want to use
)

FetchContent_MakeAvailable({{ cookiecutter.project_name }})

add_executable(YourApp main.cpp)
target_link_libraries(YourApp PRIVATE {{ cookiecutter.project_name }})
```

## Usage

## Issue Report
If you find any issues on this project, please [report it on GitHub](https://github.com/{{ cookiecutter.github_username }}/{{ cookiecutter.repo_name }}/issues).

## Acknowledgements
- This project utilizes OSS (Open Source Software)
    See [NOTICE.md](NOTICE.md)
