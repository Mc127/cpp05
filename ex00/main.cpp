#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat em1("ahmed", 150);
        // em1.DecrementGrade();
        std::cout << em1 << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "======================================\n";
    try
    {
        Bureaucrat em1("karim", 2);
        std::cout << em1 << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "======================================\n";
    try
    {
        Bureaucrat em1("salma", 0);
        std::cout << em1 << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}