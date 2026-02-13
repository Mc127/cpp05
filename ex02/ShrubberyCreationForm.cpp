#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("Shrubbery", false, 145, 137),target("shrut")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other),target(other.target)
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        target = other.target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target):AForm("Shrubbery", false, 145, 137), target(_target)
{

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getisSigned() != true)
    {
        throw GradeTooLowException();
    }
    else if (this->getexecutegrade() < executor.getGrade())
    {
        throw GradeTooLowException();
    }
    else
    {
        std::string tar = this->target + "_shrubbery";
        std::ofstream file(tar.c_str());
        if (!file.is_open())
        {
            std::cout << "Error opening file\n";
            return  ;
        }
        for (int i = 0 ; i < 3; i++)
        {
            file << "   ^\n";
            file << "  ^^^\n";
            file << " ^^^^^\n";
            file << "   |\n";
            file << "\n";
        }
        file.close();
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}