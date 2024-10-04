#ifndef __BANK_HPP__
# define __BANK_HPP__

# include <map>
# include "Account.hpp"

class Bank {
    const static int            _tax = 5; 
    static int                  _orderIdBank;
    int                         _orderIdAccount;
    const int                   _bankId;
    const std::string           _bankName;
    double                      _liquidity;
    std::map<int, Account *>    _clientAccounts;

    public:
        Bank(std::string bankName, double liquidity);
        ~Bank(void);

        const int           GetBankId(void) const;
        const std::string   GetBankName(void) const;
        const double        GetBankLiquidity(void) const;
        const int           GetAmountClients(void) const;

        const int           OpenAccount(std::string userName, double value);
        const int           OpenAccount(std::string userName);
        double              ApplyTax(double value);

    private:
        void                CloseAccounts(void);
        Bank(void) : _bankId(-1), _orderIdAccount(100000), _bankName(""), _liquidity(0) {}
};

std::ostream& operator << (std::ostream& os, const Bank bank);

#endif