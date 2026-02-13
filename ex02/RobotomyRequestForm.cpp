#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("Robot", false, 72, 45), target("robot")
{

}
RobotomyRequestForm::RobotomyRequestForm(const std::string& _target):AForm("Robot", false, 72, 45), target(_target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other), target(other.target)
{

}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        this->target = other.target;
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
        std::cout << "briiiiiizzzzz gghhfsdjfgs Noise ......\n";
        int r = rand();
        if (r % 2 != 0)
            std::cout << this->getTarget() << " has been robotomized successfull\n";
        else
            std::cout << this->getTarget() << " robotomy failed\n";
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}