#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{

}

Account::~Account( void )
{

}

void	Account::displayAccountsInfos( void )
{

}

void	Account::displayStatus( void ) const
{

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
