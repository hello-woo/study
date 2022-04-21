#include <iostream>
#include <string>
#include <queue>
using namespace std;

class MapADT {
public:
  MapADT();
  MapADT(string filename);

  string find(const string& key);  
  void insert(const string& key, const string& value);
  string remove(const string& key);

  void print();
protected:
  unsigned int hash(const string& key);

  int find_index(const string& key, bool override_duplicated_key);

  const static unsigned int size_max = 100;
  string keys[size_max];
  string values[size_max];
};

MapADT::MapADT() {
  for (int i = 0; i < size_max; i++) {
    keys[i] = string();
    values[i] = string();
  }
}

unsigned int MapADT::hash(const string& k)
{
  unsigned int value = 0 ;
  for (int i = 0; i < k.length(); i++)
    value = 37*value + k[i];
  return value;
}

void MapADT::print() {
  cout << "{";
  for (int i = 0; i < size_max; i++)
    if (!keys[i].empty())
      cout << keys[i] << ":" << values[i] << ", ";
  cout << "}" << endl;
}

//override_duplicate_key为true说明覆盖重复的值，false为开放定址法，找一个没用过的
int MapADT::find_index(const string& key, bool override_duplicate_key = true) {     
  unsigned int h = hash(key) % size_max, offset = 0, index;
  
  while (offset < size_max) {
    index = (h + offset) % size_max;

    // empty index for new entry with key `key`
    // or find the index of key `key` in hash table
    // if `override_duplicate_key` is `false`, return a new, unused index, used in DictionaryADT
    if (keys[index].empty() ||
        (override_duplicate_key && keys[index] == key))
      return index;

    offset++;
  }
  return -1;
}

void MapADT::insert(const string& key, const string& value) {
  int index = find_index(key);
  if (index == -1) {
    cerr << "Table is full!" << endl;
    return;
  }

  keys[index] = key;
  values[index] = value;
}

string MapADT::find(const string& key) {
  int index = find_index(key);
  if (index != -1)
    return values[index];

  return "";
}

string MapADT::remove(const string& key) {
  int index = find_index(key);
  if (index == -1) return "";

  string value = values[index];
  keys[index].clear();
  values[index].clear();

  return value;
}

class DictionaryADT : public MapADT {
public:
  DictionaryADT() : MapADT() {}
  DictionaryADT(string filename);

  void insert(const string& key, const string& value);
  queue<string> find_all(const string& key);
  queue<string> remove(const string& key);
};

void DictionaryADT::insert(const string& key, const string& value) {
  int index = find_index(key, false);
  if (index == -1) {
    cerr << "Table is full!" << endl;
    return;
  }

  keys[index] = key;
  values[index] = value;
}

queue<string> DictionaryADT::find_all(const string& key) {
  queue<string> result;
  for (int i = 0; i < size_max; i++)
    if (keys[i] == key)
      result.push(values[i]);
  return result;
}

queue<string> DictionaryADT::remove(const string& key) {
  queue<string> result;
  for (int i = 0; i < size_max; i++)
    if (keys[i] == key) {
      result.push(values[i]);
      keys[i].clear();
      values[i].clear();
    }
  return result;
}

int main() {
  MapADT map;
  map.print();
  map.insert("k1", "v1");
  map.insert("k2", "v2");
  map.print();

  map.insert("k1", "v1b");
  map.print();

  cout << "k2: " << map.find("k2") << endl;
  cout << "k3: " << map.find("k3") << endl;

  cout << "k2: " << map.remove("k2") << endl;
  map.print();
  cout << "---" << endl;

  DictionaryADT d;
  d.insert("k1", "v1a");
  d.insert("k1", "v1b");
  d.insert("k2", "v2");
  d.print();

  cout << "k1: " << d.find("k1") << endl;
  queue<string> k1v = d.find_all("k1");
  cout << "k1: ";
  while (!k1v.empty()) {
    cout << k1v.front() << ", ";
    k1v.pop();
  }
  cout << endl;
  d.print();

  k1v = d.remove("k1");
  cout << "k1: ";
  while (!k1v.empty()) {
    cout << k1v.front() << ", ";
    k1v.pop();
  }
  cout << endl;
  d.print();

  d.remove("k2");
  d.print();

  return 0;
}