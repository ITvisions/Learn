var index = async(ctx,next) => {
    ctx.response.body = `<h1>login</h1>
    <form action="/signin" method="post">
    <p>name: <input name="name" value="koa"></input></p>
    <p>password: <input type="password" name="password"></input></p>
    <p><input type="submit" value="submit"></input> </p>
    </form>`;
}

// var siginin = async(ctx,next) => {
//     var name = ctx.request.body.name || '',
//         password = ctx.request.body.password || '';
//     if(name == "koa" && password == "123") {
//         ctx.response.body = `<h1>hello,${name}</h1>`
//     } else {
//         ctx.response.body = `<h1>login fail</h1>
//         <p><a href="/">try again</a> </p>`
//     }
// }

var fn_signin = async (ctx, next) => {
    // ctx.response.body = `<h1>123</h1>`
    var
        name = ctx.request.body.name || '',
        password = ctx.request.body.password || '';
    console.log(`signin with name: ${name}, password: ${password}`);
    if (name === 'koa' && password === '12345') {
        ctx.response.body = `<h1>Welcome, ${name}!</h1>`;
    } else {
        ctx.response.body = `<h1>Login failed!</h1>
        <p><a href="/">Try again</a></p>`;
    }
};
module.exports = {
    'GET /': index,
    'POST /signin': fn_signin
}
