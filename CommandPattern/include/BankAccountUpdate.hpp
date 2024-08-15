

class BankAccountUpdate { 

	long accountNumber; 

	public: 
	BankAccountUpdate(){};
	virtual ~BankAccountUpdate(){};

	void addMoneytoAccount(long accountNumber,long money);

	void deductMoneyfromAccount(long accountNumber,long money);

    void transferMoneyFromAccount(long accountNumber,long money);

};