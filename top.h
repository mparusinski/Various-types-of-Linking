#ifndef _TOP_MOST_LIBRARY_H
#define _TOP_MOST_LIBRARY_H

class ClassWithNonTrivialDtor
	{
	public:
		ClassWithNonTrivialDtor(int initValue);
		~ClassWithNonTrivialDtor();

	private:
		int * m_heapInt;
	};

class ClassWithStaticVar
	{
	public:
		ClassWithStaticVar(int initValue);
		~ClassWithStaticVar();
	
	private:
        // Left intentionally uninistantiated
		static ClassWithStaticVar instance;
        ClassWithNonTrivialDtor* m_nastyObject;
	};	

#endif  // _TOP_MOST_LIBRARY_H