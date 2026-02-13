#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("Zaphod Beeblebrox", false, 25,5), target("criminal")
{

}
PresidentialPardonForm::PresidentialPardonForm(const std::string _target):AForm("Zaphod Beeblebrox", false, 25,5), target(_target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        target = other.target;
    return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
    return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
    }
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}