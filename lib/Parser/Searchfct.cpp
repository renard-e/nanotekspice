//
// Searchfct.cpp for  in /home/renard_e/2/C++/cpp_nanotekspice/lib/Parser
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Wed Mar  1 19:41:47 2017 Gregoire Renard
// Last update Fri Mar  3 11:13:07 2017 Gregoire Renard
//

#include "Parser.hpp"

int					Parser::searchSection(nts::t_ast_node &root,
							      std::string section,
							      ITERATOR_S &it,
							      ITERATOR_S &itRoot)
{
  itRoot = root.children->begin();
  while ((*itRoot)->lexeme != section && itRoot != root.children->end())
    itRoot++;
  if (itRoot == root.children->end())
    return (-1);
  it = (*itRoot)->children->begin();
  return (0);
}

int					Parser::searchNameInChipsets(nts::t_ast_node &root,
								     std::string &name,
								     std::string &pin,
								     std::vector<std::string> &tabType)
{
  ITERATOR_S				component;
  ITERATOR_S				section;
  ITERATOR_S				itComponent;
  int					realPin;

  if ((searchSection(root, ".chipsets", component, section)) == -1)
    return (-1);
  while (component != (*section)->children->end())
    {
      itComponent = (*component)->children->begin();
      while (itComponent != (*component)->children->end())
	{
	  if ((*itComponent)->lexeme == name)
	    {
	      if ((*component)->lexeme == "process")
	      	realPin = std::get<1>(_cmpt->listComponentValable.find
	      			      ((*itComponent)->value)->second);
	      else
	      	realPin = std::get<1>(_cmpt->listComponentValable.find
	      			      ((*component)->lexeme)->second);
	      if (realPin < (std::stoi(pin)))
	      	return (-1);
	      tabType.push_back((*component)->lexeme);
	      if ((*component)->lexeme == "output")
		_outputLink.push_back(name);
	      return (0);
	    }
	  itComponent++;
	}
      component++;
    }
  return (-1);
}


ITERATOR_S				Parser::searchInTree(nts::t_ast_node &root,
							     std::string section1,
							     std::string section2,
							     ITERATOR_S &itNeeded)
{
  ITERATOR_S				it = root.children->begin();
  ITERATOR_S				itChild;

  while ((*it)->lexeme != section1 && it != root.children->end())
    it++;
  itChild = (*it)->children->begin();
  while ((*itChild)->lexeme != section2 && itChild != (*it)->children->end())
    itChild++;
  itNeeded = (*itChild)->children->begin();
  return (itChild);
}
