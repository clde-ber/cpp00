#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{
    switch (initial_deposit)
    {
        case 0 :
            _accountIndex = 0; _amount = 42; _nbDeposits = 5; _nbWithdrawals = 321;
            std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
            break ;
        case 1 :
            _accountIndex = 1; _amount = 54; _nbDeposits = 765; _nbWithdrawals = 34;
            std::cout << "index:" << _accountIndex << ";amount:" << _amount << std::endl;
            break ;
        case 2 :
            _accountIndex = 2; _amount = 957; _nbDeposits = 564; _nbWithdrawals = 657;
            std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
            break ;
        case 3 :
            _accountIndex = 3; _amount = 432; _nbDeposits = 2; _nbWithdrawals = 4;
            std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
            break ;
        case 4 :
            _accountIndex = 4; _amount = 1234; _nbDeposits = 87; _nbWithdrawals = 76;
            std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
            break ;
        case 5 :
            _accountIndex = 5; _amount = 0; _nbDeposits = 23; _nbWithdrawals = 275;
            std::cout << "index:" << _accountIndex << ";amount:" << _amount << std::endl;
            break ;
        case 6 :
            _accountIndex = 6; _amount = 754; _nbDeposits = 9; _nbWithdrawals = 657;
            std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
            break ;
        case 7 :
            _accountIndex = 7; _amount = 16576; _nbDeposits = 20; _nbWithdrawals = 7654;
            std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
            break ;
    }
}

Account::~Account( void )
{

}

void	Account::displayAccountsInfos( void )
{
    Account tab[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int i = 0;

    for (i = 0; i < 8; i++)
    {
        std::cout << "index:";
        std::cout << tab[i]._accountIndex;
        std::cout << ";";
        std::cout << "amount:";
        std::cout << tab[i]._amount; 
        std::cout << ";";
        std::cout << "deposits:";
        std::cout << tab[i]._nbDeposits; 
        std::cout << ";";
        std::cout << "withdrawals:";
        std::cout << tab[i]._nbWithdrawals;
        std::cout << std::endl;
    }
}

void	Account::displayStatus( void ) const
{
    std::cout << ";created" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    std::cout << "deposits:";
    std::cout << deposit; 
    std::cout << ";" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    std::cout << "withdrawals:";
    std::cout << withdrawal;
    std::cout << ";" << std::endl;
    if (withdrawal)
        return withdrawal;
    return 0;
}
