#include <gtest/gtest.h>
#include <{{ cookiecutter.include_dir }}/{{ cookiecutter.project_name }}.hpp>

TEST({{ cookiecutter.project_name.replace('-', '_') }}_test, Hello)
{
    EXPECT_EQ({{ cookiecutter.name_space }}::hello(), "Hello from {{ cookiecutter.project_name }}!");
}
