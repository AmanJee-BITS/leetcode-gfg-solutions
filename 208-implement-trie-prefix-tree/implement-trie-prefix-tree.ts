// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

class TrieNode {
    child: Map<string, TrieNode>;
    isEnd: boolean;

    constructor() {
        this.child = new Map<string, TrieNode>();
        this.isEnd = false;
    }
}

// Implement the Trie class:
class Trie {
    node: TrieNode;

    // Trie() Initializes the trie object.
    constructor() {
        this.node = new TrieNode();
    }

    // void insert(String word) Inserts the string word into the trie.
    insert(word: string): void {
        let currNode = this.node;

        for (const char of word) {
            if (!currNode.child.has(char)) {
                currNode.child.set(char, new TrieNode());
            }
            currNode = currNode.child.get(char);
        }

        currNode.isEnd = true;
    }

    // boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    search(word: string): boolean {
        let currNode = this.node;

        for (const char of word) {
            if (currNode.child.has(char)) {
                currNode = currNode.child.get(char);
            } else {
                return false;
            }
        }

        return currNode.isEnd;
    }

    // boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
    startsWith(word: string): boolean {
        let currNode = this.node;

        for (const char of word) {
            if (currNode.child.has(char)) {
                currNode = currNode.child.get(char);
            } else {
                return false;
            }
        }

        return true;
    }
}