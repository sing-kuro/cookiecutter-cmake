cmake_minimum_required(VERSION 3.21)

project({{ cookiecutter.project_name }} VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_{{ cookiecutter.project_upper }} "Build the executable" ON)
option(ENABLE_TESTING_{{ cookiecutter.project_upper }} "Enable testing" OFF)
option(BUILD_{{ cookiecutter.project_upper }}_DOCS "Build documentation" OFF)

if (ENABLE_TESTING_{{ cookiecutter.project_upper }})
    enable_testing()
    add_subdirectory(tests)
endif()

if (BUILD_{{ cookiecutter.project_upper }}_DOCS)
    add_subdirectory(docs)
endif()

if (BUILD_{{ cookiecutter.project_upper }} OR ENABLE_TESTING_{{ cookiecutter.project_upper }})
    add_subdirectory(src)

    # Install headers
    install(DIRECTORY include/ DESTINATION include)

    # Export config files for find_package
    include(CMakePackageConfigHelpers)

    # Generate version file
    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}ConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    # Install the export set
    install(EXPORT {{ cookiecutter.project_name }}Targets
        FILE {{ cookiecutter.project_name }}Targets.cmake
        NAMESPACE {{ cookiecutter.project_name }}::
        DESTINATION lib/cmake/{{ cookiecutter.project_name }}
    )

    # Generate the config file
    configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/{{ cookiecutter.project_name }}Config.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}Config.cmake"
        INSTALL_DESTINATION lib/cmake/{{ cookiecutter.project_name }}
    )

    # Install config and version files
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}ConfigVersion.cmake"
        DESTINATION lib/cmake/{{ cookiecutter.project_name }}
    )

    # Export build-tree package config
    export(EXPORT {{ cookiecutter.project_name }}Targets
        FILE "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}Targets.cmake"
        NAMESPACE {{ cookiecutter.project_name }}::
    )

    #Add the build tree as a package registry entry
    set({{ cookiecutter.project_upper }}_DIR "${CMAKE_CURRENT_BINARY_DIR}")

endif()
