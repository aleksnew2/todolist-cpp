#include <vector>
#include <string>

void RunLoop();

class TODOElement
{
public:
  std::string title;
  std::string description;

  TODOElement(std::string title, std::string description = "")
  {
    this->title = title;
    this->description = description;
  }

  bool operator==(const TODOElement &other) const
  {
    return title == other.title;
  }
};

struct ToDoList
{
public:
  std::vector<TODOElement> list;

  void OutputElement(TODOElement element);
  void OutputCommand(std::string title, std::string decription);
  void OutputList();
  void Add(TODOElement element);
  void Remove(std::string title);
  void Help();
  void Clear();
};

class Color
{
public:
  void Red(std::string message);
  void Green(std::string message);
  void Yellow(std::string message);
  void Blue(std::string message);
};