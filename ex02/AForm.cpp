#include "AForm.hpp"

AForm::AForm():name(""), isSigned(false), recquiredgrade(1), executegrade(1)
{
}
AForm::AForm(const AForm& other):name(other.name),isSigned(other.isSigned),
            recquiredgrade(other.recquiredgrade),
            executegrade(other.executegrade)
{
}
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::AForm(const std::string name, bool isSigned, const int recquiredgrade, const int executegrade):
                    name(name), isSigned(isSigned), recquiredgrade(recquiredgrade),executegrade(executegrade)
{
    if (recquiredgrade > 150 || executegrade > 150)
    {
        throw GradeTooLowException();
    }
    if (recquiredgrade < 1 || executegrade < 1)
    {
        throw GradeTooHighException();
    }
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return "[AForm] grade too hight";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "[AForm] grade too low";
}

std::string AForm::getname() const
{
    return name;
}
bool  AForm::getisSigned() const
{
    return isSigned;
}
int AForm::getrecquiredgrade() const
{   
    return recquiredgrade; 
}
int AForm::getexecutegrade() const
{
    return executegrade;
}

std::ostream& operator<<(std::ostream& os, AForm& form)
{
    os << "my name is " << form.getname() << " ";
    os << " my required grade is " << form.getrecquiredgrade() << " ";
    os << " , excuted grade " << form.getexecutegrade() << " ";
    os << " the form is signed as " << form.getisSigned() << "\n";
    return os;
}

void AForm::beSigned(Bureaucrat& em)
{
    if (em.getGrade() > recquiredgrade)
        throw AForm::GradeTooLowException();
    else
        isSigned = true;
}
AForm::~AForm()
{
}