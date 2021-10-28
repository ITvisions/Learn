const path = require('path')
const mime = require('mime')
const fs = require('fs');
const { dir } = require('console');

function staticFiles(url,fir) {
    return async(ctx,next) => {
        let rpath = ctx.request.path;
        if(rpath.startsWith(url)) {
            let fp = path.join(dir,rpath.substring(url.length));
            if(await fs.exists(fs)) {
                ctx.response.type = mime.lookup(rpath);
                ctx.response = await fs.readFile(fp);
            } else {
                ctx.response.status = 404
            }
        } else {
            await next();
        }
    }
}

module.exports = staticFiles;
