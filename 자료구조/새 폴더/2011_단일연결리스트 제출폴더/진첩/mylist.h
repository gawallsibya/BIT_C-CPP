#ifndef _MYLIST_H_
#define _MYLIST_H_ 
 typedef struct tagNODE NODE;
            struct tagNODE
            {
		char data;
 		struct tagNODE *next;
            };

            typedef struct tagLIST LIST;
            struct tagLIST
             {
		NODE * head;		// start
		int    count;		// 저장개수
	};
	LIST    list;
#endif 

	   