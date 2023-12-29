var canConstruct = function(ransomNote, magazine) {
    let magazineMap = new Map();

    // 定义一个自定义的函数，用于将字符插入或设置计数
    const insertOrSet = (map, key) => {
        if (map.has(key)) {
            map.set(key, map.get(key) + 1);
        } else {
            map.set(key, 1); // 如果键不存在，则初始化为1
        }
    };

    // 遍历杂志中的字符，并插入或设置计数
    for (let char of magazine) {
        insertOrSet(magazineMap, char);
    }

    // 检查是否可以从杂志中构建勒索信
    for (let char of ransomNote) {
        if (!magazineMap.has(char) || magazineMap.get(char) <= 0) {
            console.log(false);
            return false;
        }
        magazineMap.set(char, magazineMap.get(char) - 1); // 减少杂志中相应字符的计数
    }

    console.log(true);
    return true;
};

canConstruct('a', 'b');
