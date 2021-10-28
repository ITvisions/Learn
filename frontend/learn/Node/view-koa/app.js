const Koa = require('koa');
const router = require("koa-router")();
const bodyParser = require("koa-bodyparser");
const app = new Koa(); 
app.use(bodyParser());
app.use(router.routes());


// 导入controller middleware:
const controller = require('./controller');

// 使用middleware:
app.use(controller());



app.listen(3002)
console.log('app started at port 3000 ...');
