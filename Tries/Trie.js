var TrieNode = /** @class */ (function () {
    function TrieNode() {
        this.keys = {};
        this.isEnd = false;
    }
    return TrieNode;
}());
var Trie = /** @class */ (function () {
    function Trie() {
        this.root = new TrieNode();
    }
    Trie.prototype.insert = function (word) {
        var node = this.root;
        for (var _i = 0, word_1 = word; _i < word_1.length; _i++) {
            var ch = word_1[_i];
            if (!node.keys[ch]) {
                node.keys[ch] = new TrieNode();
            }
            node = node.keys[ch];
        }
        node.isEnd = true;
    };
    Trie.prototype.search = function (word) {
        var node = this.root;
        for (var _i = 0, word_2 = word; _i < word_2.length; _i++) {
            var ch = word_2[_i];
            if (!node.keys[ch]) {
                return false;
            }
            node = node.keys[ch];
        }
        return node.isEnd;
    };
    Trie.prototype.startswith = function (prefix) {
        var node = this.root;
        for (var _i = 0, prefix_1 = prefix; _i < prefix_1.length; _i++) {
            var ch = prefix_1[_i];
            if (!node.keys[ch]) {
                return false;
            }
            node = node.keys[ch];
        }
        return true;
    };
    return Trie;
}());
// Test code
var dict = new Trie();
dict.insert("apple");
dict.insert("app");
dict.insert("dog");
console.log(dict.search("apple"));
console.log(dict.startswith("appl"));
console.log(dict.search("app"));
console.log(dict.startswith("cat"));
console.log(dict.search("apples"));
