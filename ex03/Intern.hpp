#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        AForm* ShrubberyFunction(std::string target);
        AForm* RobotomyRequestFunction(std::string target);
        AForm* PresidentialPardonFunction(std::string target);
        AForm* makeForm(std::string name, std::string target);
};

