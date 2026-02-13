#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#include <ctime>

int main()
{
    try
    {
        srand(time(NULL));
        Bureaucrat a("karim", 7);
        PresidentialPardonForm Cert("malas");
        a.signForm(Cert);
        a.executeForm(Cert);
        // Cert.execute(a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}