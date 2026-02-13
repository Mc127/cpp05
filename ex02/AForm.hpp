#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int recquiredgrade;
        const int executegrade;
    public:
        AForm();
        AForm(const AForm& other);
        AForm(const std::string name, bool isSigned, const int recquiredgrade, const int executegrade);
        AForm& operator=(const AForm& other);
        std::string getname() const;
        bool  getisSigned() const;
        int getrecquiredgrade() const;
        int getexecutegrade() const;
        void beSigned(Bureaucrat& em);
        virtual void execute(Bureaucrat const & executor) const = 0;
        virtual ~AForm();
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
std::ostream& operator<<(std::ostream& os, AForm& form);