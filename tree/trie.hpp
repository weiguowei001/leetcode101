#pragma once

#include "trie.hpp"
#include <string>

using namespace std;

namespace algorithm {
namespace tree {
namespace trie {

class TrieNode {
public:
	TrieNode *childNode[26];
	bool isVal;
	TrieNode()
		: isVal(false)
	{
		for (int i = 0; i < 26; ++i) {
			childNode[i] = nullptr;
		}
	}
};


class Trie {
	TrieNode *root;

public:
	Trie()
		: root(new TrieNode())
	{
	}

	// 向字典树插入一个词
	void
	insert(string word)
	{
		TrieNode *temp = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!temp->childNode[word[i] - 'a']) {
				temp->childNode[word[i] - 'a'] = new TrieNode();
			}
			temp = temp->childNode[word[i] - 'a'];
		}
		temp->isVal = true;
	}

	// 判断字典树里是否有一个词
	bool
	search(string word)
	{
		TrieNode *temp = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!temp) {
				break;
			}
			temp = temp->childNode[word[i] - 'a'];
		}
		return temp ? temp->isVal : false;
	}
	// 判断字典树是否有一个以词开始的前缀
	bool
	startsWith(string prefix)
	{
		TrieNode *temp = root;
		for (int i = 0; i < prefix.size(); ++i) {
			if (!temp) {
				break;
			}
			temp = temp->childNode[prefix[i] - 'a'];
		}
		return temp;
	}
};

} // namespace trie
} // namespace tree
} // namespace algorithm