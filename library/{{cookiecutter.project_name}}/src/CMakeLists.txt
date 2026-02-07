add_library({{ cookiecutter.project_name }} {{ cookiecutter.project_name }}.cpp)

target_include_directories({{ cookiecutter.project_name }} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Install the library
install(TARGETS {{ cookiecutter.project_name }}
    EXPORT {{ cookiecutter.project_name }}Targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
