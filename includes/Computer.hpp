//
// Computer.hpp for nanotekspice in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/C++/cpp_nanotekspice/includes
//
// Made by Rodrigue René
// Login   <rodrigue.rene@epitech.eu>
//
// Started on  Sun Feb 12 16:45:08 2017 Rodrigue René
// Last update Sun Mar  5 20:28:55 2017 Rodrigue René
//

#ifndef COMPUTER_HPP_
# define COMPUTER_HPP_

#include <vector>
#include <tuple>
#include <string>
#include <functional>
#include "Component.hpp"
#include "Component.hpp"
#include "Processor.hpp"

class Computer;

typedef std::tuple<std::function<nts::IComponent*(const std::string&)>, int > T_TUPLECOMP;

//typedef std::get<2>(piece->_listPin[_1]) getpin;

typedef nts::IComponent *(Computer::*func)(const std::string &value) const;

//typedef std::tuple<func, int > T_TUPLECOMP;AVANT
//typedef std::tuple< std::function<nts::IComponent*(const std::string&) const >, int,char > T_TUPLECOMP;

class Computer
{
public:
  std::map<std::string, nts::IComponent *>	devices;
  Computer();
  ~Computer();

  nts::IComponent		*createComponent(const std::string &type, const std::string &value);
  //CREEEEEATE
  nts::IComponent		*create4001(const std::string &value) const;
  nts::IComponent		*create4008(const std::string &value) const;
  nts::IComponent		*create4011(const std::string &value) const;
  nts::IComponent		*create4013(const std::string &value) const;
  nts::IComponent		*create4017(const std::string &value) const;
  nts::IComponent		*create4030(const std::string &value) const;
  nts::IComponent		*create4040(const std::string &value) const;
  nts::IComponent		*create4069(const std::string &value) const;
  nts::IComponent		*create4071(const std::string &value) const;
  nts::IComponent		*create4081(const std::string &value) const;
  nts::IComponent		*create4094(const std::string &value) const;
  nts::IComponent		*create4503(const std::string &value) const;
  nts::IComponent		*create4514(const std::string &value) const;
  nts::IComponent		*createInput(const std::string &value) const;
  nts::IComponent		*createTrue(const std::string &value) const;
  nts::IComponent		*createFalse(const std::string &value) const;
  nts::IComponent		*createClock(const std::string &value) const;
  nts::IComponent		*createOutput(const std::string &value) const;
  //CREEEEEATE
  void				addComponent(nts::IComponent *, std::string const &);
  std::map<std::string, int>	getListCompenentValable(std::string &type);
  //FIIIIIIIILLER
  void				filler(nts::Processor *, int , int , int , int ) const;
  void				filler4001(nts::Processor *, int , int , int , int ) const;
  //  void				fillerxor(nts::Processor *, int , int , int , int ) const;
  void				filler4008(nts::Processor *, int , int , int , int, int, int)const;
  void				filler4011(nts::Processor *, int , int , int , int ) const;
  void				filler4017(nts::Processor *, int , int , int , int ) const;
  void				filler4030(nts::Processor *, int , int , int , int ) const;
  void				filler4040(nts::Processor *, int , int , int , int ) const;
  void				filler4069(nts::Processor *, int , int , int) const;
  void				filler4071(nts::Processor *, int , int , int , int ) const;
  void				filler4094(nts::Processor *, int , int , int , int,int ,int ) const;
  void				filler4514(nts::Processor *, int , int, int, int, int, int ) const;
  void				fillerflipflop(nts::Processor *, int , int , int , int, int, int, int ,int) const;
  void				filler(nts::Processor *, int , int ) const;
  //FIIIIIIIILLER
  std::map<std::string, T_TUPLECOMP>	listComponentValable;//(value, pointersurfonction, nb pin)

  //  T_TUPLECOMP     filltuple(int nb_pin, std::function<nts::IComponent *(const std::string &)> &func);
  T_TUPLECOMP			filltuple(int nb_pin, func function);
  void			        dump();
  void			        simulate();
  void			        display();
  //  T_TUPLECOMP			filltuple(int nb_pin, nts::IComponent* (Computer::*func)(const std::string &)const);
  //  T_TUPLECOMPfilltuple(int nb_pin,
  //std::function<nts::IComponent* (Computer::*)(const std::string&)const >);

  //  ...
};

#endif /* !COMPUTER_HPP_ */
