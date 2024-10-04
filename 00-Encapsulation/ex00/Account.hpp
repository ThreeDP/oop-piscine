#ifndef __ACCOUNT_HPP__
# define __ACCOUNT_HPP__

# include <iostream>

class Account {
    int _id;
    int _value;

    public:
        const int GetAccountNumber(void) const;
        const int GetAccountValue(void) const;

    private:
        Account() : _id(-1), _value(0) {}
};

std::ostream& operator << (std::ostream &os, const Account& account);

#endif