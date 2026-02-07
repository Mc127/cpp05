#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    // ---------- CASE 1: Successful signing ----------
    try
    {
        Bureaucrat boss("Ahmed", 10);
        Form f1("Certificate", false, 10, 50); 
        boss.signForm(f1);
        std::cout << f1 << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    std::cout << "-----------1--------------\n";

    // ---------- CASE 2: Fail signing (grade too low) ----------
    try
    {
        Bureaucrat junior("Mohamed", 50);
        Form f2("SecretDoc", false, 20, 100);  
        junior.signForm(f2); 
        std::cout << f2 << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    std::cout << "------------2-------------\n";

    // ---------- CASE 3: Fail Form construction (grade too high) ----------
    try
    {
        Form f3("ImpossibleForm", false, 0, 10);
        std::cout << f3 << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Form construction failed: " << e.what() << "\n";
    }

    std::cout << "------------3-------------\n";

    // ---------- CASE 4: Fail Form construction (grade too low) ----------
    try
    {
        Form f4("ImpossibleForm2", false, 10, 151);
        std::cout << f4 << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Form construction failed: " << e.what() << "\n";
    }
    std::cout << "------------4-------------\n";
    return 0;
}