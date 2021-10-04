#include "Account.hpp"
#include "ctime"
#include <iostream>

int Account::_nbAccounts = 8;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp(void)
{
    time_t time;
    tm *timeinfo;

    std::time_t result = std::time(&time);
    timeinfo = localtime(&time);
    timeinfo->tm_year += 1900;
    timeinfo->tm_mon += 1;
    std::cout << "[" << timeinfo->tm_year;
    if (timeinfo->tm_mon < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mon;
    if (timeinfo->tm_mday < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_mday;
    std::cout << "_";
    if (timeinfo->tm_hour < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_hour;
    if (timeinfo->tm_min < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_min;
    if (timeinfo->tm_sec < 10)
        std::cout << "0";
    std::cout << timeinfo->tm_sec << "] ";
}

Account::Account( int initial_deposit ) : _amount(initial_deposit), \
_accountIndex(0), _nbDeposits(0), _nbWithdrawals(0)
{
    switch(initial_deposit)
    {
        case 42:    this->_accountIndex = 0;
                    break;
        case 54:    this->_accountIndex = 1;
                    break;
        case 957:   this->_accountIndex = 2;
                    break;
        case 432:   this->_accountIndex = 3;
                    break;
        case 1234:  this->_accountIndex = 4;
                    break;
        case 0:     this->_accountIndex = 5;
                    break;
        case 754:   this->_accountIndex = 6;
                    break;
        case 16576: this->_accountIndex = 7;
                    break;
    }
    _displayTimestamp();
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";amount:";
    std::cout << this->_amount; 
    std::cout << ";created";
    std::cout << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:";
    std::cout << this->_accountIndex;
    std::cout << ";amount:";
    std::cout << this->_amount; 
    std::cout << ";closed";
    std::cout << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
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
    _displayTimestamp();
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
    _displayTimestamp();
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
