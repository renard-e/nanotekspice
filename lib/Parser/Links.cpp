//
// Links.cpp for  in /home/renard_e/2/C++/cpp_nanotekspice/lib
// 
// Made by Gregoire Renard
// Login   <renard_e@epitech.net>
// 
// Started on  Wed Feb 15 00:17:51 2017 Gregoire Renard
// Last update Thu Mar  2 14:42:25 2017 Gregoire Renard
//

#include <iostream>
#include <string>
#include "Parser.hpp"

int					Parser::extractInfo(std::string &params,
							    std::vector<std::string> &line)
{
  int					lim;
  int					cpt;
  std::string				info;

  cpt = 0;
  lim = 0;
  info = "";
  while (params[lim] != '\0' && params[lim] != ':')
    lim++;
  if (params[lim] == '\0')
    return (-1);
  while (cpt != lim)
    {
      info += params[cpt];
      cpt++;
    }
  line.push_back(info);
  info = "";
  cpt++;
  while (params[cpt] != '\0')
    {
      info += params[cpt];
      cpt++;
    }
  line.push_back(info);
  return (0);
}

int					Parser::pushLink(std::vector<std::string> &params,
							 ITERATOR_S &it)
{
  std::vector<nts::t_ast_node *>	*tab = new std::vector<nts::t_ast_node*>;
  nts::t_ast_node			*child = new nts::t_ast_node(tab);
  nts::t_ast_node			*link = new nts::t_ast_node(NULL);
  std::vector<std::string>		line;
  auto					itParams = params.begin();
  auto					itLine = line.begin();
  int					tour;

  child->type = nts::ASTNodeType::LINK;
  link->type = nts::ASTNodeType::LINK_END;
  tour = 0;
  while (itParams != params.end())
    {
      if ((extractInfo(*itParams, line)) == -1)
  	return (-1);
      itLine = line.begin();
      if (tour == 0)
  	{
	  child->lexeme = *itLine;
	  itLine++;
	  child->value = *itLine;
  	}
      else
  	{
	  link->lexeme = *itLine;
	  itLine++;
	  link->value = *itLine;
  	}
      line.clear();
      itParams++;
      tour++;
    }
  _cmpt->devices.find(child->lexeme)->second->SetLink((size_t)(std::stoi(child->value)), *_cmpt->devices.find(link->lexeme)->second, (size_t)(std::stoi(link->value)));
  child->children->push_back(link);
  (*it)->children->push_back(child);
  return (0);
}

int					Parser::rempLinks(std::string &line,
							  nts::t_ast_node &root)
{
  std::vector<std::string>		params;
  static auto				it = root.children->begin();
  static int				tour = 0;

  if (tour == 0)
    setIt(".links", it, root, tour);
  getParams(line, params);
  if ((checkParams(params)) == -1 || (checkNameLink(params, root)) == -1 || (pushLink(params, it)) == -1)
    {
      std::cout << "Error : bad synthax at line \"" << line << "\"" << std::endl;
      return (-1);
    }
  return (0);
}
