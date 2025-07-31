/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victoire <victoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:04:36 by vicperri          #+#    #+#             */
/*   Updated: 2025/07/31 17:20:52 by victoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    std::cout << "["
        << (1900 + ltm->tm_year)
        << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon)
        << std::setfill('0') << std::setw(2) << ltm->tm_mday
        << "_"
        << std::setfill('0') << std::setw(2) << ltm->tm_hour
        << std::setfill('0') << std::setw(2) << ltm->tm_min
        << std::setfill('0') << std::setw(2) << ltm->tm_sec
        << "] ";
}

Account::Account(int initial_deposit)  {
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _accountIndex =  _nbAccounts - 1;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

int	Account::getNbAccounts( void ) {
    return(_nbAccounts);
}

int	Account::getTotalAmount( void ) {
    return(_totalAmount);
}

int	Account::getNbDeposits( void ) {
    return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
    return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals()
    << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount  += deposit;
    _nbDeposits++;
    _displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount - deposit
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
     _displayTimestamp();
     if ( _amount  - withdrawal < 0)
     {
             std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount
			  << ";withdrawal:refused"  
              << std::endl;
              return(false);
     }
     else
     {
        _amount  -= withdrawal;
         _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
	        std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount + withdrawal
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
     }
     return(true);
}

int		Account::checkAmount( void ) const {
    return (_amount);
}

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex
    << ";amount:" <<  _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" <<  _nbWithdrawals
    << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}