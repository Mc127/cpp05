#include "Form.hpp"

Form::Form():name(""), isSigned(false), recquiredgrade(1), executegrade(1)
{
}
Form::Form(const Form& other):name(other.name),isSigned(other.isSigned),
            recquiredgrade(other.recquiredgrade),
            executegrade(other.executegrade)
{
}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::Form(const std::string name, bool isSigned, const int recquiredgrade, const int executegrade):
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
const char* Form::GradeTooHighException::what() const throw()
{
    return "[Form] grade too hight";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "[Form] grade too low";
}

std::string Form::getname() const
{
    return name;
}
bool  Form::getisSigned()
{
    return isSigned;
}
int Form::getrecquiredgrade() const
{   
    return recquiredgrade; 
}
int Form::getexecutegrade() const
{
    return executegrade;
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
    os << "my name is " << form.getname() << " ";
    os << " my required grade is " << form.getrecquiredgrade() << " ";
    os << " , excuted grade " << form.getexecutegrade() << " ";
    os << " the form is signed as " << form.getisSigned() << "\n";
    return os;
}

void Form::beSigned(Bureaucrat& em)
{
    if (em.getGrade() > recquiredgrade)
        throw Form::GradeTooLowException();
    else
        isSigned = true;
}
Form::~Form()
{
}