class WordDictionary {
    private children: WordDictionary[];
    private isEnd: boolean;

    constructor() {
        this.children = Array(26).fill(null);
        this.isEnd = false;
    }

    addWord(word: string): void {
        let cur: WordDictionary = this;
        for(let elem of word) {
            let index: number = elem.charCodeAt(0) - 'a'.charCodeAt(0);
            if(cur.children[index] === null) {
                cur.children[index] = new WordDictionary();
            }
            cur = cur.children[index];
        }
        cur.isEnd = true;
    }

    search(word: string): boolean {
        return this.searchRecursive(word, 0);
    }

    private searchRecursive(val: string, start: number): boolean {
        if(start === val.length) return this.isEnd;
        let elem: string = val[start];
        if(elem === '.') {
            for(let j = 0; j < 26; j++) {
                if(this.children[j] !== null && this.children[j].searchRecursive(val, start + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            let index: number = elem.charCodeAt(0) - 'a'.charCodeAt(0);
            if(this.children[index] === null) return false;
            return this.children[index].searchRecursive(val, start + 1);
        }
    }
}
