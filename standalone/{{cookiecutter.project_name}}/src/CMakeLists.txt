add_library(lib{{ cookiecutter.project_name }} {{ cookiecutter.project_name }}.cpp)

target_include_directories(lib{{ cookiecutter.project_name }} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Install the library
install(TARGETS lib{{ cookiecutter.project_name }}
    EXPORT {{ cookiecutter.project_name }}Targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

add_executable({{ cookiecutter.project_name }} main.cpp)
target_link_libraries({{ cookiecutter.project_name }} PRIVATE lib{{ cookiecutter.project_name }})

install(TARGETS {{ cookiecutter.project_name }}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
