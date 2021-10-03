#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 8;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit), _accountIndex(0), _nbDeposits(0), _nbWithdrawals(0)
{
}

Account::~Account( void )
{

}

void	Account::displayAccountsInfos( void )
{
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";amount:";
    std::cout << this->_amount; 
    std::cout << ";deposits:";
    std::cout << this->_totalNbDeposits; 
    std::cout << ";withdrawals:";
    std::cout << this->_totalNbWithdrawals;
    std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _totalNbDeposits = 1;
    this->_nbDeposits = deposit;
    this->_amount = this->_amount + deposit;
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";p_amount:";
    std::cout << this->_amount; 
    std::cout << ";deposit:";
    std::cout << this->_nbDeposits; 
    std::cout << ";amount:";
    std::cout << this->_amount + this->_nbDeposits;
    std::cout << ";nb_deposits:";
    std::cout << this->_totalNbDeposits;
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _totalNbWithdrawals = 1;
    this->_nbWithdrawals = withdrawal;
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";p_amount:";
    std::cout << this->_amount;
    if (this->_amount - withdrawal < 0)
        std::cout << ";withdrawal:refused";
    else
    {
        std::cout << ";withdrawal:";
        std::cout << this->_nbDeposits; 
        std::cout << ";amount:";
        this->_amount = this->_amount - withdrawal;
        std::cout << this->_amount;
        std::cout << ";nb_withdrawals:";
        std::cout << this->_totalNbWithdrawals;
    }
    std::cout << std::endl;
    if (withdrawal)
        return 1;
    return 0;
}
