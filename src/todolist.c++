#include <print>
#include <iostream>
#include <format>
#include <cstdlib>
#include "todolist.hpp"

auto td_list = ToDoList{};

void ToDoList::OutputElement(TODOElement element)
{
  if (element.description.empty())
  {
    std::cout << "- TODO: " << element.title << std::endl;
  }
  else
  {
    std::cout << "- TODO: " << element.title << " - " << element.description << std::endl;
  }
}

void ToDoList::OutputCommand(std::string title, std::string description)
{
  auto message = std::format("- {}: {}", title, description);
  std::cout << message << "\n";
}

void ToDoList::OutputList()
{
  for (TODOElement i : td_list.list)
  {
    td_list.OutputElement(TODOElement(i.title, i.description));
  }
}

void ToDoList::Add(TODOElement element)
{
  if (element.description.empty())
  {
    td_list.list.push_back(TODOElement(element.title));
  }
  else
  {
    td_list.list.push_back(TODOElement(element.title, element.description));
  }
}

void ToDoList::Remove(std::string title)
{
  td_list.list.erase(std::remove(
                         td_list.list.begin(),
                         td_list.list.end(),
                         TODOElement(title)),
                     td_list.list.end());
}

void ToDoList::Help()
{
  OutputCommand("add", "Adds TODO element to list.");
  OutputCommand("remove", "Removes TODO element from list.");
  OutputCommand("show-list", "Shows TODO elements.");
  OutputCommand("clear", "Clears previous history of commands.");
}

void ToDoList::Clear()
{
  int clear = system("clear");
}

void RunLoop()
{

  while (true)
  {
    std::println("Type `help` for commands.");
    std::print(">>> ");

    std::string command;
    std::getline(std::cin, command);

    if (command == "help")
    {
      td_list.Help();
    }
    else if (command == "show-list")
    {
      td_list.OutputList();
    }
    else if (command == "add")
    {
      std::print("Title: ");

      std::string inputTitle;
      std::getline(std::cin, inputTitle);

      std::print("Description (Optional): ");

      std::string inputDescription;
      std::getline(std::cin, inputDescription);

      td_list.Add(TODOElement(inputTitle, inputDescription));
    }
    else if (command == "remove")
    {
      std::print("Type element's title, which you want to remove: ");

      std::string inputTitle;
      std::getline(std::cin, inputTitle);

      td_list.Remove(inputTitle);
    }
    else if (command == "clear")
    {
      td_list.Clear();
    }
    else
    {
      std::cout << "Wrong command: " << command << std::endl;
    }
  }
}

void Color::Red(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[31m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[31m" << message << "\033[0m";
  }
}

void Color::Green(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[32m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[32m" << message << "\033[0m";
  }
}

void Color::Yellow(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[33m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[33m" << message << "\033[0m";
  }
}

void Color::Blue(std::string message, bool isWithNewLine)
{
  if (isWithNewLine)
  {
    std::cout << "\033[34m" << message << "\033[0m" << std::endl;
  }
  else
  {
    std::cout << "\033[34m" << message << "\033[0m";
  }
}

void Terminal::Error(std::string message)
{
  Color color;
  color.Red("ERROR: ", false);
  std::cout << message << std::endl;
}

void Terminal::Warning(std::string message)
{
  Color color;
  color.Yellow("WARNING: ", false);
  std::cout << message << std::endl;
}

void Terminal::Info(std::string message)
{
  Color color;
  color.Blue("INFO: ", false);
  std::cout << message << std::endl;
}

void Terminal::Success(std::string message)
{
  Color color;
  color.Green("SUCCESS: ", false);
  std::cout << message << std::endl;
}

int main()
{
  RunLoop();
  return 0;
}