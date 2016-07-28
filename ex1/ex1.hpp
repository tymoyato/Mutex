//
// ex1.hpp for  in /home/arce_c/TEK_2/C++_2/cpp_plazza/TP/plazza/Tp_c++
// 
// Made by Chris Arce
// Login   <arce_c@epitech.net>
// 
// Started on  Fri Apr 15 17:02:28 2016 Chris Arce
// Last update Fri Apr 15 17:13:52 2016 Chris Arce
//

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class	tmutex
{
public:
  tmutex();
  ~tmutex();
  static void	*increment_counter(void *param);
  void	Run();
};
