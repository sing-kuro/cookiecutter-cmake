cmake_minimum_required(VERSION 3.21)

project({{ cookiecutter.project_name }} VERSION 0.1.0 LANGUAGES CXX)

option(ENABLE_TESTING_{{ cookiecutter.project_upper }} "Enable testing" OFF)
option(BUILD_{{ cookiecutter.project_upper }}_DOCS "Build documentation" OFF)

if (ENABLE_TESTING_{{ cookiecutter.project_upper }})
    enable_testing()
    add_subdirectory(tests)
endif()

if (BUILD_{{ cookiecutter.project_upper }}_DOCS)
    add_subdirectory(docs)
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library({{ cookiecutter.project_name }} INTERFACE)
target_include_directories({{ cookiecutter.project_name }}
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# C++ standard
target_compile_features({{ cookiecutter.project_name }} INTERFACE cxx_std_23)

#Export + Install rules
install(TARGETS {{ cookiecutter.project_name }}
    EXPORT {{ cookiecutter.project_name}}Targets
)

# Install headers
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT {{ cookiecutter.project_name }}Targets
    FILE {{ cookiecutter.project_name }}Targets.cmake
    NAMESPACE {{ cookiecutter.project_name }}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/{{ cookiecutter.project_name }}
)

# Generate config files
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/{{ cookiecutter.project_name }}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/{{ cookiecutter.project_name }}
)

# Generate version file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Install config and version files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/{{ cookiecutter.project_name }}
)

# Export build-tree package config
export(EXPORT {{ cookiecutter.project_name }}Targets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/{{ cookiecutter.project_name }}Targets.cmake"
    NAMESPACE {{ cookiecutter.project_name }}::
)

#Add the build tree as a package registry entry
set({{ cookiecutter.project_upper }}_DIR "${CMAKE_CURRENT_BINARY_DIR}")
