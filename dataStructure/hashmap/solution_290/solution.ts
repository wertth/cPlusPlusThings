/*
 * @lc app=leetcode.cn id=290 lang=typescript
 * @lcpr version=30112
 *
 * [290] 单词规律
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
// function wordPattern(pattern: string, s: string): boolean {
//     const map = new Map<string, string>();

//     const wordArr = s.split(' ');
//     if(wordArr.length !== pattern.length) return false;
//     for(const index in wordArr) {
//         const word = wordArr[index]
//         if(map.has(pattern[index]+'-') && map.get(pattern[index]+'-') !== word) return false;
//         if(map.has(word) && map.get(word) !== pattern[index]+'-') return false;
//         else {
//             map.set(word, pattern[index]+'-');
//             map.set(pattern[index]+'-', word);
//         }
//     }

//     return true;
// };


function wordPattern(pattern: string, s: string): boolean {
    const arr = new Array(26).fill("");
    const wordArr = s.split(' ');
    if(wordArr.length !== pattern.length) return false;
    for(const index in wordArr) {
        const patternChar = pattern[index]
        const needPlacePos = patternChar.charCodeAt(0) - 'a'.charCodeAt(0);
        const word = wordArr[index];

        if(arr[needPlacePos] === "") arr[needPlacePos] = word;
        if(arr[needPlacePos] !== word) return false;
        if(arr.findIndex(item => item === word) !== needPlacePos) return false;
    }

    return true;

};
// @lc code=end



/*
// @lcpr case=start
// "abba"\n"dog cat cat dog"\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n"dog cat cat fish"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"dog cat cat dog"\n
// @lcpr case=end

 */

