#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name(""), grade(1)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error grade too hight";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error grade too low";
}

std::string Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::DecrementGrade()
{
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::IncrementGrade()
{
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}