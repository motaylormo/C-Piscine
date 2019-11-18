#include "Account.class.hpp"
#include <iostream>
#include <ctime>

#define SUMMARY "\e[1m"
#define CREATE "\e[32m"
#define CLOSE "\e[31m"
#define STATUS ""
#define DEPOSIT "\e[92m"
#define WITHDRAW "\e[91m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


// ************************************************************************** //
// 			printing thingies
// ************************************************************************** //
#define P_index	"index:"       << this->_accountIndex
#define P_amt	"amount:"      << this->_amount
#define P_dep	"deposits:"    << this->_nbDeposits
#define P_wdl	"withdrawals:" << this->_nbWithdrawals

void	Account::_displayTimestamp(void)
{
	time_t timestamp;
	struct tm *t;
	char buf[32];

	time(&timestamp);
	t = localtime(&timestamp);
	strftime(buf, 32, "[%Y%m%d_%H%M%S] ", t);
	std::cout << buf;
}

// ************************************************************************** //
// 			ctor dtor
// ************************************************************************** //
Account::Account(int initial_deposit):
	_accountIndex(getNbAccounts()),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	//	printy thingy
	std::cout << CREATE;
	Account::_displayTimestamp();
	std::cout << P_index << ";" << P_amt << ";" << "created";
	std::cout << "\e[0m" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= this->_amount;

	//	printy thingy
	std::cout << CLOSE;
	Account::_displayTimestamp();
	std::cout << P_index << ";" << P_amt << ";" << "closed";
	std::cout << "\e[0m" << std::endl;
	return ;
}

// ************************************************************************** //
// 			non-static vars
// ************************************************************************** //
int			Account::checkAmount( void ) const	{ return (this->_amount); }

void		Account::displayStatus( void ) const
{
	std::cout << STATUS;
	Account::_displayTimestamp();
	std::cout << P_index << ";" << P_amt << ";" << P_dep << ";" << P_wdl;
	std::cout << "\e[0m" << std::endl;
}

void		Account::makeDeposit( int deposit )
{
	int	p_amount = this->_amount;

	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;

	//	printy thingy
	std::cout << DEPOSIT;
	Account::_displayTimestamp();
	std::cout << P_index << ";"
					<< "p_amount:" << p_amount << ";" << "deposit:" << deposit << ";"
					<< P_amt << ";" << "nb_" << P_dep;
	std::cout << "\e[0m" << std::endl;
}

bool		Account::makeWithdrawal( int withdrawal )
{
	std::cout << WITHDRAW;
	Account::_displayTimestamp();
	std::cout << P_index << ";" << "p_" << P_amt << ";";

	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused";
		std::cout << "\e[0m" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		//	printy thingy
		std::cout << "withdrawal:" << withdrawal << ";" << P_amt << ";" << "nb_" << P_wdl;
		std::cout << "\e[0m" << std::endl;
		return (true);
	}
}

// ************************************************************************** //
// 			static vars
// ************************************************************************** //
int		Account::getNbAccounts(void)	{ return (Account::_nbAccounts); }
int		Account::getTotalAmount(void)	{ return (Account::_totalAmount); }
int		Account::getNbDeposits(void)	{ return (Account::_totalNbDeposits); }
int		Account::getNbWithdrawals(void)	{ return (Account::_totalNbWithdrawals); }

void	Account::displayAccountsInfos(void)
{
	std::cout << SUMMARY;
	Account::_displayTimestamp();
	std::cout	<< "accounts:"    << Account::getNbAccounts()    << ";"
				<< "total:"       << Account::getTotalAmount()   << ";"
				<< "deposits:"    << Account::getNbDeposits()    << ";"
				<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
	std::cout << "\e[0m";
}