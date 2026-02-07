#include <iostream>
#include <{{ cookiecutter.include_dir }}/{{ cookiecutter.project_name }}.hpp>

int main()
{
    std::cout << {{ cookiecutter.name_space }}::hello() << std::endl;
    return 0;
}
