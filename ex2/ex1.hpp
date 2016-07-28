//
// ex1.hpp for  in /home/arce_c/TEK_2/C++_2/cpp_plazza/TP/plazza/Tp_c++
// 
// Made by Chris Arce
// Login   <arce_c@epitech.net>
// 
// Started on  Fri Apr 15 17:02:28 2016 Chris Arce
// Last update Sat Apr 16 16:25:50 2016 Duttoo Ervin
//

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class	IMutex
{
public:
  virtual	~IMutex(void);
  virtual	void	lock(void) = 0;
  virtual	void	unlock(void) = 0;
  //virtual	bool	trylock(void) = 0;
};

class	Thread: public IMutex
{
public:
  Thread();
  ~Thread();
  static void	*increment_counter(void *param);
  void	Run();
  void	lock(void);
  void	unlock(void);
};
