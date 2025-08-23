interface ITrieNode {
    keys : { [key : string] : TrieNode },
    isEnd : boolean
}

class TrieNode implements ITrieNode {
    keys : {[key : string] : TrieNode};
    isEnd : boolean;
    
    constructor(){
        this.keys = {};
        this.isEnd = false;
    }
}

interface ITrie {
    insert(word : string) : void;
    search(word : string) : boolean;
    startswith(prefix : string) : boolean;
}

class Trie implements ITrie{
    root : TrieNode
    constructor(){
        this.root = new TrieNode()
    }
    insert(word : string) : void {
        let node = this.root;
        for(let ch of word){
            if(!node.keys[ch]){
                node.keys[ch] = new TrieNode();
            }
            node = node.keys[ch];
        }
        node.isEnd = true;
    }
    search(word : string) : boolean{
        let node = this.root;
        for(let ch of word){
            if(!node.keys[ch]){
                return false;
            }
            node = node.keys[ch];
        }
        return node.isEnd;
    }
    startswith(prefix : string) : boolean{
        let node = this.root;
        for(let ch of prefix){
            if(!node.keys[ch]){
                return false;
            }
            node = node.keys[ch];
        }
        return true;
    }
}

// Test code
const dict : ITrie = new Trie()

dict.insert("apple")
dict.insert("app")
dict.insert("dog")

console.log(dict.search("apple"))
console.log(dict.startswith("appl"))
console.log(dict.search("app"))
console.log(dict.startswith("cat"))
console.log(dict.search("apples"))