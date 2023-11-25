const fs = require("fs")
const fileNameList = ['random1','random2','random3','random4','random5','random6','random7','random8','random9','random10']


/**
 *
 * @param content {string}
 * @param writeStream {WriteStream}
 */

function writeToFile(content, writeStream) {
    return new Promise((resolve, reject) => {
        writeStream.write(content,(err) => {
            if(err) {
                console.error(err?.message)
                reject(err)
            } else resolve(1)
        })
    })
}



async function genRandFile(fileName) {
    let writer = fs.createWriteStream(`./${fileName}`,{flags:'a'})
    let temp = []
    for(let i = 0 ; i < 5000_000 ; i++) {
        temp.push((Math.floor(Math.random() * 1000) % 1000).toString())
        if(i%1000 === 0){
            await writeToFile(temp.join(','),writer)
            temp = []
        }
    }
    temp.length > 0 ? await writeToFile(temp.join(','),writer) : undefined ;
    writer.end()
}

(async () => {
    const start = new Date()
    for(const name of fileNameList) {
        const startDate = new Date()
        console.log(`start to gen ${name}`)
        try {
            await fs.promises.access(`./${name}`,fs.constants.F_OK)
            await fs.promises.unlink(`./${name}`)
        } catch (err) {
            if (err.code !== 'ENOENT') {
                // If the error is something other than 'file not found', log the error
                console.error(err.message);
            }
        }
        await genRandFile(name)
        const endDate = new Date()
        console.log(`total spend ${(endDate-startDate) /1000}s`)
    }
    console.log(`total used ${(new Date() - start) / 1000} s`)
}) ()

