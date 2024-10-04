# include "Account.hpp"

const int Account::GetAccountNumber(void) const {
    return _id;
}

const int Account::GetAccountValue(void) const {
    return _value;
}

std::ostream& operator << (std::ostream &os, const Account& account) {
    os << "[ " << account.GetAccountNumber() << " ]: " << account.GetAccountValue() << std::endl; 
    return (os);
}