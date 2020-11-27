#ifndef _HISTORY_TRANSACTION_CPP_
#define _HISTORY_TRANSACTION_CPP_

#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"



////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////

// Constructor
Transaction::Transaction(std::string ticker_symbol, unsigned int day_date, unsigned int month_date, unsigned year_date,
						bool buy_sell_trans, unsigned int number_shares, double trans_amount){
	symbol = ticker_symbol;
	day = day_date;
	month = month_date;
	year = year_date;
	shares = number_shares;
	amount = trans_amount;
	trans_id = assigned_trans_id++;
	if(buy_sell_trans){
		trans_type = "Buy";
	}else{
		trans_type = "Sell";
	}
	p_next = nullptr;
	cgl = 0;
	share_balance = 0;
	acb_per_share = 0;
	acb = 0;
}

// Destructor
Transaction::~Transaction(){
	//yeet
}

// Overloaded < operator.
bool Transaction::operator<(Transaction const &other){
	if(this->year > other.year){
		return false;
	}else if(this->year < other.year){
		return true;

	}else if(this->month > other.month){
		return false;
	}else if(this->month < other.month){
		return true;

	}else if(this->day > other.day){
		return false;
	}else if(this->day < other.day){
		return true;

	}else if(this->trans_id > other.trans_id){
		return false;
	}else{
		return true;
	}
}

// GIVEN
// Member functions to get values.
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";

  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}



////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////

// Constructor
History::History(){
	p_head = nullptr;
}

// Destructor
History::~History(){
	Transaction *p_temp{p_head};
	while(p_head != nullptr){
		p_head = p_head->get_next();
		delete p_temp;
		p_temp = p_head;
	}
}

// read_transaction(...): Read the transaction history from file.
void History::read_history(){
	ece150::open_file();

	while(ece150::next_trans_entry()){
		Transaction *new_trans{new Transaction{ece150::get_trans_symbol(), ece150::get_trans_day(),ece150::get_trans_month(),
		ece150::get_trans_year(), ece150::get_trans_type(), ece150::get_trans_shares(), ece150::get_trans_amount()}};
		insert(new_trans);
	}

	ece150::close_file();
}

// insert(...): Insert transaction into linked list.
void History::insert(Transaction *p_new_trans){
	if(p_head == nullptr){
		p_head = p_new_trans;
		return;
	}

	Transaction *p_temp{p_head};
	while(p_temp->get_next() != nullptr){
		p_temp = p_temp->get_next();
	}
	p_temp->set_next(p_new_trans);
	p_temp = nullptr;
}

//recursive sorting algorithm <3
Transaction* sort(Transaction *p_head){
	//base case: list size = 0 or 1
	if(p_head == nullptr || p_head->get_next() == nullptr){
		return p_head;
	}
	//base case: list size = 2
	Transaction *p_temp{p_head};
	if(p_head->get_next()->get_next() == nullptr){
		if(*p_head->get_next() < *p_head){
			p_head->get_next()->set_next(p_head);
			p_temp = p_head->get_next();
			p_head->set_next(nullptr);
			p_head = p_temp;
		}
		p_temp = nullptr;
		return p_head;
	}
	//recursive case: list size = 3+
	p_head = sort(p_head->get_next());
	if(*p_temp < *p_head){
		//insert front
		p_temp->set_next(p_head);
		p_head = p_temp;
	}else{
		Transaction *p_i{p_head};
		while(p_i->get_next() != nullptr && *p_i->get_next() < *p_temp){
			p_i = p_i->get_next();
		}
		//insert middle/end
		p_temp->set_next(p_i->get_next());
		p_i->set_next(p_temp);
	}
	p_temp = nullptr;
	return p_head;
}

// sort_by_date(): Sort the linked list by trade date.
void History::sort_by_date(){
	//RECURSE
	p_head = sort(p_head);
}

// update_acb_cgl(): Updates the ACB and CGL values.
void History::update_acb_cgl(){
	Transaction *p_temp{p_head};
	unsigned int shares{0};
	double acb{0}, cgl{0};
	while(p_temp != nullptr){
		//if buy
		if(p_temp->get_trans_type()){
			acb += p_temp->get_amount();
			shares += p_temp->get_shares();

			p_temp->set_acb(acb);
			p_temp->set_share_balance(shares);
			p_temp->set_acb_per_share(acb/shares);
		//if sell
		}else{
			cgl = p_temp->get_amount() - p_temp->get_shares()*(acb/shares);
			acb -= p_temp->get_shares()*(acb/shares);
			shares -= p_temp->get_shares();

			p_temp->set_acb(acb);
			p_temp->set_share_balance(shares);
			p_temp->set_acb_per_share(acb/shares);
			p_temp->set_cgl(cgl);
		}
		p_temp = p_temp->get_next();
	}
	p_temp = nullptr;
}

// compute_cgl(): )Compute the ACB, and CGL.
double History::compute_cgl(unsigned int year){
	Transaction *p_temp{p_head};
	double cgl{0};
	while(p_temp != nullptr){
		if(p_temp->get_year() == year){
			cgl += p_temp->get_cgl();
		}
		p_temp = p_temp->get_next();
	}
	p_temp = nullptr;
	return cgl;
}

// print() Print the transaction history.
void History::print(){
	Transaction *p_temp{p_head};
	std::cout << "BEGIN TRANSACTION HISTORY" << std::endl;
	while(p_temp != nullptr){
		p_temp->print();
		p_temp = p_temp->get_next();
	}
	std::cout << "END TRANSACTION HISTORY" << std::endl;
}

// GIVEN
// get_p_head(): Full access to the linked list.
Transaction *History::get_p_head() { return p_head; }

#endif
