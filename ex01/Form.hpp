#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int recquiredgrade;
        const int executegrade;
    public:
        Form();
        Form(const Form& other);
        Form(const std::string name, bool isSigned, const int recquiredgrade, const int executegrade);
        Form& operator=(const Form& other);
        std::string getname() const;
        bool  getisSigned();
        int getrecquiredgrade() const;
        int getexecutegrade() const;
        void beSigned(Bureaucrat& em);
        ~Form();
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& os, Form& form);