//
// Commande.cpp for  in /home/renard_e/2/C++/cpp_nanotekspice/lib
//
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
//
// Started on  Tue Feb 28 09:43:12 2017 Gregoire Renard
// Last update Sun Mar  5 16:15:44 2017 Gregoire Renard
//

#include <iostream>
#include <csignal>
#include "cpp_nanotekspice_parser.hpp"
#include "Parser.hpp"

int					sig;

void					Parser::displayFunc(nts::t_ast_node &root)
{
  (void)root;
  _cmpt->display();
}

int					Parser::inversClock(nts::t_ast_node &root)
{
  ITERATOR_S				itSection;
  ITERATOR_S				itClock;

  if ((itSection = searchInTree(root, ".chipsets", "clock", itClock))
      == root.children->end())
    return (-1);
  while (itClock != (*itSection)->children->end())
    {
      if ((*itClock)->value == "1")
	(*itClock)->value = "0";
      else
	(*itClock)->value = "1";
      itClock++;
    }
  return (0);
}

void					Parser::simulateFunc(nts::t_ast_node &root)
{
  (void)root;
  _cmpt->simulate();
  
}

static void				sigInt(int sign)
{
  sig = sign;
}

void					Parser::loopFunc(nts::t_ast_node &root)
{
  sig = 0;
  std::signal(SIGINT, sigInt);
  while (sig != SIGINT)
    simulateFunc(root);
}

void					Parser::dumpFunc(nts::t_ast_node &root)
{
  (void)root;
  _cmpt->dump();
}

int					Parser::isInputValue(std::string &line)
{
  int					cpt;

  cpt = 0;
  while (line[cpt] != '=' && line[cpt] != '\0')
    cpt++;
  if (line[cpt] == '\0')
    return (-1);
  return (1);
}
