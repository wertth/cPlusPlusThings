function letterCombinations(digits: string): string[] {
    if (digits.length === 0) return [];

    let map = new Map([
        ['2', ['a', 'b', 'c']],
        ['3', ['d', 'e', 'f']],
        ['4', ['g', 'h', 'i']],
        ['5', ['j', 'k', 'l']],
        ['6', ['m', 'n', 'o']],
        ['7', ['p', 'q', 'r', 's']],
        ['8', ['t', 'u', 'v']],
        ['9', ['w', 'x', 'y', 'z']]
    ]);

    let res = [''];

    for (let i = 0; i < digits.length; i++) {
        let digit = digits[i];
        let alternatives = map.get(digit);
        if (!alternatives) continue;

        let currentLength = res.length;
        for (let j = 0; j < currentLength; j++) {
            let prefix = res.shift();
            for (let alternative of alternatives) {
                res.push(prefix + alternative);
            }
        }
    }

    return res;
};
