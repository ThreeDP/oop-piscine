# include "Bank.hpp"

int Bank::_orderIdBank = 0;

Bank::Bank(std::string bankName, double liquidity)
    : _bankId(++_orderIdBank), _orderIdAccount(100000), _bankName(bankName), _liquidity(0)
{
    if (liquidity > 0)
        _liquidity = liquidity;
    std::cout << "Bank: [" << _bankName << " with value of " << _liquidity << "] Created" << std::endl;
}

Bank::~Bank(void) {
    this->CloseAccounts();
    std::cout << "Bank: [" << _bankName << " with value of " << _liquidity << "] Destroyed" << std::endl;
}

void Bank::CloseAccounts(void) {
    std::map<int, Account *>::iterator it = _clientAccounts.begin();
    for ( ; it != _clientAccounts.end(); ++it) {
        delete it->second;
    }
}

double Bank::ApplyTax(double value) {
    if (value <= 0)
        return 0;
    int newValue = value - (value * 5) / 100;
    _liquidity += (value - newValue);
    return newValue; 
}

const int Bank::OpenAccount(std::string userName, double value) {
    (void)userName;
    ApplyTax(value);
    return ++_orderIdAccount; 
}

const int Bank::OpenAccount(std::string userName)
{
    return this->OpenAccount(userName, 0);
}

const int Bank::GetBankId(void) const {
    return _bankId;
}

const std::string Bank::GetBankName(void) const {
    return _bankName;
}

const double Bank::GetBankLiquidity(void) const {
    return _liquidity;
}

const int Bank::GetAmountClients(void) const  {
    return _clientAccounts.size();
}

std::ostream& operator << (std::ostream& os, const Bank bank) {
    os << "Bank: [ " << bank.GetBankName() << " | liquidity: " << bank.GetBankLiquidity() << " ]" << std::endl;
    return os;
}