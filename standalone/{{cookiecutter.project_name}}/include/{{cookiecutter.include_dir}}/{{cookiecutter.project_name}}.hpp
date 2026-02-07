///
/// @file {{ cookiecutter.project_name }}.hpp
///

#ifndef {{ cookiecutter.include_dir.upper() }}_{{ cookiecutter.project_upper }}_HPP
#define {{ cookiecutter.include_dir.upper() }}_{{ cookiecutter.project_upper }}_HPP

#include <string>

namespace {{ cookiecutter.name_space }}
{

///
/// @brief Returns a greeting message.
/// @return A greeting message.
///
std::string hello();

}

#endif // {{ cookiecutter.include_dir.upper() }}_{{ cookiecutter.project_upper }}_HPP
