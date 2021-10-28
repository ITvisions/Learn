const Koa = require('koa');
const router = require("koa-router")();
const bodyParser = require("koa-bodyparser");
const app = new Koa();
router.get('/',async(ctx,next)=> {
    ctx.response.body = `<h1>login</h1>
    <form action="/loginin" method="post">
    <p>name: <input name="name" value="koa"></input></p>
    <p>password: <input type="password" name="password"></input></p>
    <p><input type="submit" value="submit"></input> </p>
    </form>`
})
router.post('/loginin',async(ctx,next) => {
    var name = ctx.request.body.name || '',
        password = ctx.request.body.password || '';
    if(name == "koa" && password == "123") {
        ctx.response.body = `<h1>hello,${name}</h1>`
    } else {
        ctx.response.body = `<h1>login fail</h1>
        <p><a href="/">try again</a> </p>`
    }
})

app.use(bodyParser());
app.use(router.routes());

app.listen(3000)
console.log('app started at port 3000 ...');
