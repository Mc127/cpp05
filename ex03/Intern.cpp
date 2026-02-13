#include "Intern.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
        return *this;
    return *this;
}

AForm* Intern::ShrubberyFunction(std::string target)
{
    ShrubberyCreationForm* a = new ShrubberyCreationForm(target);
    return a;
}
AForm* Intern::RobotomyRequestFunction(std::string target)
{
    RobotomyRequestForm* a = new RobotomyRequestForm(target);
    return a;
}
AForm* Intern::PresidentialPardonFunction(std::string target)
{
    PresidentialPardonForm* a = new PresidentialPardonForm(target);
    return a;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = {"shrubbery form", "robotomy request", "presidential pardon"};
    AForm* (Intern::*ptr[3])(std::string);
    ptr[0] = &Intern::ShrubberyFunction;
    ptr[1] = &Intern::RobotomyRequestFunction;
    ptr[2] = &Intern::PresidentialPardonFunction;
    for (int i = 0; i < 3; i++)
    {
        if(forms[i] == name)
        {
            std::cout << "Intern creates " << target << "\n"; 
            return (this->*ptr[i])(target);
        }
    }
    std::cerr << "no mutched form name\n";
    return (NULL);
}

Intern::~Intern()
{
}