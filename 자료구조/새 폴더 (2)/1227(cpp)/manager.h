#ifndef _MANAGER_H_
#define _MANAGER_H_

class Manager
{
	Arr		m_arr;
	List	m_list;
public:
	Manager() {}
	void ma_reserve();
	void ma_check();		
	void ma_cancel();			
	void ma_info();	
	Member* numtores(int id);
};

#endif /*_MANAGER_H_*/