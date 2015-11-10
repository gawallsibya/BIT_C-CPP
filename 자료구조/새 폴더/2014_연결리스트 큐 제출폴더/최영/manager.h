//manager.h

void ma_init();

void ma_makeaccount();
void ma_deposit();		
void ma_withdraw();			
void ma_inquire();	
void ma_information();	

ACCOUNT* idtoaccount(LIST *parr, int id);