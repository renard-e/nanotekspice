//
// Setfct.cpp for  in /home/renard_e/2/C++/cpp_nanotekspice/lib
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Wed Feb 15 00:24:11 2017 Gregoire Renard
// Last update Sun Mar  5 16:22:57 2017 Gregoire Renard
//

#include <iostream>
#include <string>
#include "Parser.hpp"

void					Parser::setIt(std::string wanted, ITERATOR_S &it,
						      nts::t_ast_node &root, int &tour)
{
  while (it != root.children->end() && (*it)->type == nts::ASTNodeType::SECTION
	 && (*it)->lexeme != wanted)
    it++;
  if (it == root.children->end())
    {
      initChild(root, wanted);
      it = root.children->begin();
      setIt(wanted, it, root, tour);
    }
  tour++;
}

void					Parser::setLine(std::string &line)
{
  char					car;
  
  line = "";
  car = 2;
  while (car != '\n' && car != EOF)
    {
      car = std::getc(stdin);
      line += car;
    }
  line += '\0';
}

int					Parser::setValue(std::string &line,
							 nts::t_ast_node &root)
{
  std::vector<std::string>		params;
  ITERATOR_S				component;
  ITERATOR_S				section;
  ITERATOR_S				ssection;

  if (line.length() >= 2)
    line[line.length() - 2] = '\0';
  getInput(line.c_str(), params);
  if (((*(params.begin() + 1))[0] != '1' && (*(params.begin() + 1))[0] != '0')
      || (*(params.begin() + 1))[1] != '\0')
    return (-1);
  if ((searchSection(root, ".chipsets", component, section)) == -1)
    return (-1);
  while (component != (*section)->children->end())
    {
      ssection = (*component)->children->begin();
      while (ssection != (*component)->children->end())
	{
	  if ((*ssection)->lexeme == (*(params.begin())))
	    {
	      if ((*component)->lexeme == "input" || (*component)->lexeme == "clock")
		{
		  (*ssection)->value = (*(params.begin() + 1));
		  std::get<2>(dynamic_cast<nts::Processor *>(_cmpt->devices.find((*ssection)->lexeme)->second)->_listPin[1]) = (nts::Tristate)(std::stoi((*ssection)->value));
		  return (0);
		}
	      return (-1);
	    }
	  ssection++;
	}
      component++;
    }
  return (-1);
}

int					Parser::setValueChild(nts::t_ast_node &child)
{
  std::vector<std::string>		params;
  int					cpt;

  cpt = 2;
  while (_argv[cpt] != NULL)
    {
      if ((getInput(_argv[cpt], params)) == -1)
	return (-1);
      if (params.size() != 2)
	{
	  std::cout << "Error : invalid input in command line \"" << _argv[cpt]
		    << "\"" << std::endl;
	  return (-1);
	}
      if (child.lexeme == (*params.begin()))
	{
	  child.value = (*(params.begin() + 1));
	  if (child.value != "1" && child.value != "0")
	    return (-1);
	  return (0);
	}
      params.clear();
      cpt++;
    }
  return (-1);
}

void					Parser::setNext(std::string &line, int &cpt)
{
  while (line[cpt] != '\0' && (line[cpt] == ' ' || line[cpt] == '\t'))
    cpt++;
}
