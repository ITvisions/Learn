async(ctx,next) => {
    ctx.render('index.html',{
        title: 'Welcome'
    });
}

async(ctx,next) => {
    var email = ctx.request.body.email || '',
        password = ctx.request.body.password || '';
    if(email === '1' && password === '123') {
        ctx.render('signin-ok.html',{
            title: 'Sign in ok',
            name: 'mr node'
        })
    } else {
        ctx.render('signin-failed.html',{
            title: 'Sign in failed'
        })
    }
}
