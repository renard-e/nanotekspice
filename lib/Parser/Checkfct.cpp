//
// Checkfct.cpp for  in /home/renard_e/2/C++/cpp_nanotekspice/lib
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Wed Feb 15 00:25:00 2017 Gregoire Renard
// Last update Tue Mar  7 10:58:05 2017 Gregoire Renard
//

#include <iostream>
#include <string>
#include "Parser.hpp"

int					Parser::checkAllLink(nts::t_ast_node &root)
{
  ITERATOR_S				section;
  ITERATOR_S				output;
  
  section = searchInTree(root, ".chipsets", "output", output);
  while (output != (*section)->children->end())
    {
      if ((std::find(_outputLink.begin(), _outputLink.end(), (*output)->lexeme))
	  == _outputLink.end())
	{
	  std::cout << "Output '" << (*output)->lexeme << "' is not linked to anything."
		    << std::endl;
	  return (-1);
	}
      output++;
    }
  return (0);
}

int					Parser::checkValid(std::vector<std::string> &params)
{
  auto					it = params.begin();
  int					cpt;
  int					idx;
  
  cpt = 0;
  idx = 0;
  while (it != params.end())
    {
      while((*it)[idx] != '\0')
	{
	  if ((*it)[idx] == ':')
	    cpt++;
	  idx++;
	}
      it++;
      idx = 0;
    }
  if (cpt != 2)
    return (-1);
  return (0);
}

int					Parser::checkNameLink(std::vector<std::string> &params,
							      nts::t_ast_node &root)
{
  auto					it = params.begin();
  std::vector<std::string>		tabType;
  std::vector<std::string>		line;

  if ((checkValid(params)) == -1)
    return (-1);
  while (it != params.end())
    {
      if ((extractInfo(*it, line)) == -1)
	return (-1);
      if ((searchNameInChipsets(root, (*(line.begin())), (*(line.begin() + 1)), tabType))
	  == -1)
	return (-1);
      it++;
      line.clear();
    }
  // if ((std::find(tabType.begin(), tabType.end(), "process")) == tabType.end())
  //   return (-1);
  return (0);
}

int					Parser::checkProcess(std::vector<std::string> &params)
{
  if ((_cmpt->listComponentValable.find((*(params.begin()))))
      == _cmpt->listComponentValable.end())
    return (-1);
  return (0);
}

int					Parser::checkDouble(std::string &name,
							    ITERATOR_S &it)
{
  ITERATOR_S				itChild = (*it)->children->begin();
  ITERATOR_S				itCompare;
  
  while (itChild != (*it)->children->end())
    {
      itCompare = (*itChild)->children->begin();
      while (itCompare != (*itChild)->children->end())
	{
	  if ((*itCompare)->lexeme == name)
	    return (-1);
	  itCompare++;
	}
      itChild++;
    }
  return (0);
}

void					Parser::checkDot()
{
  auto					it = _checkDot.begin();

  while (it != _checkDot.end())
    {
      if ((*it) == 0)
	_next = -1;
      it++;
    }
  if (_next == -1)
    std::cout << "Error : Missing .chipsets or .links" << std::endl;
}

std::string				Parser::checkSection(std::string &line)
{
  std::string				tmp;
  int					cpt;

  cpt = 0;
  setNext(line, cpt);
  while (line[cpt] != '\0' && line[cpt] != ' ' && line[cpt] != '\t')
    {
      tmp += line[cpt];
      cpt++;
      if (line[cpt - 1] == ':')
	break;
    }
  setNext(line, cpt);
  if (line[cpt] != '#' && line[cpt] != '\n' && line[cpt] != '\0')
    tmp = "none";
  if (tmp == ".chipsets:")
    {
      _checkDot[0] = 1;
      return ("chipsets");
    }
  if (tmp == ".links:")
    {
      _checkDot[1] = 1;
      return ("links");
    }
  std::cout << "Error : section .* must be chipsets or links" << std::endl;
  return ("null");
}

