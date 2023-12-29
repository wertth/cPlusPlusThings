/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

const hasValue = (map, value) => {
    return Array.from(map.values()).includes(value)
}

var isIsomorphic = function(s, t) {
    let map = new Map();
    if(s.length !== t.length) return false;
    for(let i = 0; i < s.length; i++) {
        let source_key = s[i], target_key = t[i]

        if(map.has(source_key)) {
            if(map.get(source_key) !== target_key) return false;
            //if(map.get(target_key) !== source_key) return false;
        } else if(hasValue(map,target_key)) {
            const saved_source_key = 
            Array
            .from(map.entries())
            .filter((e) => e[1] === target_key)[0][0]
            if(saved_source_key !== source_key) return false;
        } else {
            map.set(source_key, target_key)
            // map.set(target_key, source_key)
        }

    }
    return true;
};

// /**
//  * @param {string} s
//  * @param {string} t
//  * @return {boolean}
//  */

// const hasValue = (map, value) => {
//     return Array.from(map.values()).includes(value);
// };

// var isIsomorphic = function(s, t) {
//     let sToT = new Map();
//     let tToS = new Map(); // 添加一个反向映射

//     if (s.length !== t.length) return false;

//     for (let i = 0; i < s.length; i++) {
//         let source_char = s[i];
//         let target_char = t[i];

//         if (sToT.has(source_char)) {
//             if (sToT.get(source_char) !== target_char) return false;
//         } else {
//             sToT.set(source_char, target_char);
//         }

//         if (tToS.has(target_char)) {
//             if (tToS.get(target_char) !== source_char) return false;
//         } else {
//             tToS.set(target_char, source_char);
//         }
//     }

//     return true;
// };
