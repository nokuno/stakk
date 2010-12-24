#include "../utrie.h"
using namespace stakk;

Ustring UTrie::u;

int main(int argc, char *argv[]) {
  string filename = "test/dictionary.txt";
  UTrie trie;
  int result = trie.load(filename, 0, '\t');

  assert(result == true);
  
  string value = "わたし	1	1	10	私";

  { // search
    vector<string> *result = trie.search("わたし");
    assert(result != NULL);
    assert((*result)[0] == value);
  }
  { // common prefix search
    UTrie::Entries results;
    trie.common_prefix_search("わたしのなまえ", results);
    assert(results.size() != 0);
    assert(results[0].key == "わたし");
    assert(results[0].values.size() != 0);
    assert(results[0].values[0] == value);
  }
  /*
  { // predictive search
    UTrie::Entries results;
    trie.predictive_search("わた", "", results);
    assert(results.size() != 0);
    assert(results[0].key == "わたし");
    assert(results[0].values.size() != 0);
    assert(results[0].values[0] == value);
  }

  { // fuzzy search
    UTrie::Entries results;
    trie.fuzzy_search_ex("わあし", 1, results);
    assert(results.size() != 0);
    assert(results[0].key == "わたし");
    assert(results[0].values.size() != 0);
    assert(results[0].values[0] == value);
  }
  */
  return 0;
}