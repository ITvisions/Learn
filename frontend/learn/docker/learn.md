### 13. 初识dockerfile
第三种获得镜像的方法，通过docerfile来diy制作镜像
通过dockerfile构建镜像是最常见的一种方式
> 什么是dockerfile
> 
dockerfile是一个包含用于组合景象的命令的文本文档，可以在命令行调用任何命令。  
dockerfile通过读取dockerfile中的指令自动生成影像
总结为：
* dockerfile是用于构建镜像的文件
* dockerfile里包含了构建镜像所需的“指令”
* dockerfile有其特定的语法规则（重点学习）
> demo-执行python程序
需求： 制作一个镜像，镜像的操作系统是`Ubuntu`最新版，然后在系统上运行`test.py`程序。python程序只需要打印出`hello docker`即可
>
第一步,安装一个Ubuntu环境
第二步，下载安装python环境
```
apt-get update && \
DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends -y python3.9 python3-pip python3.9-dev
```
第三步,准备`test.py`文件，这个可以在`D盘`新建一个`test.py`文件，然后编写文件
```
print("hello docker")
```
第四步，运行`test.py`
```
python test.py
```
以上是我们拆解的步骤，有了步骤之后，看如何写一个Dockerfile文件（建议把Dockerfile文件和test.py文件放在一个文件夹下）
```
FROM ubuntu:latest
RUN apt-get update && \ DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends -y python3.9 python3-pip python3.9-dev
ADD test.py /
CMD ["python3", "test.py"]
```
这算是最简单的一个Dockerfile文件的编写了，有了这个文件之后，下面就可以通过Dockerfile来构建一个镜像了
### 14. 通过Dockerfile构建镜像
> Dockerfile构建镜像
> 
当有了`Dockerfile`和`test.py`文件以后，通过`powershell`进入到两个文件的文件夹。通过Docker命令就可以完成构建
```
docker image build -t <Name:tag> <file path>
```
例如现在通过已经写好的Dockerfile,构建一个`test`的镜像，就可以使用下面的命令构建
```
docker image build -t test .
```
（注意命令最后是有一个`.`的），如果你是第一次执行打包，这个过程需要几分钟，当出现`FINISHED`后，说明打包完成了  
打包完成后，通过`docker image ls`命令查看现在拥有的镜像列表。如果一切正常，可以看到名字为test的镜像已经存在  
可以执行容器，验证自己diy的镜像是否可用
```
docker run test
```
镜像如果正常，应该出现`hello docker`字样，然后就直接退出容器了。这是跟我们写的Dockerfile有关的
### 15. 把镜像分享到Dockerhub
把镜像push到dockerhub上去，这样就可以让所有人进行使用了
> 符合dockerhub的命名规范
>
如果你想要上传属于自己的镜像，就需要遵守社区规则，就是`用户ID/镜像名称`。可以最简单的方法就好似重新build一个镜像，镜像名称符合社区规则就行
```
docker image build -t aitvision/test .
```
这时候就会生成一个新的镜像，但是image ID是一样的
也可以通过`docker image tag`命令，具体语法如下：
```
docker image tag <old image name><new image name>
```
例如吧`test`这个镜像改为`aitvision/test`镜像，可以使用如下命令：
```
docker image tag test aitvision/test
```
> 推送到Dockerhub上
>
在推送前，需要先登陆Dockerhub账号，登陆命令如下：
```
docker login
```
执行命令后，会要求输入`Username`,也就是你的Dockerhub ID,还需要输入密码，如果输入正确，会出现`Login Succeeded`就证明登陆成功
```
docker image push aitvision/test
```
输入完命令后，就会给我们push到Dockerhub上去，这时候到Dockerhub的profile页面刷新就会看到刚刚push上去的镜像,这样所有人都可以使用你的镜像了
### 16. FROM语法和镜像选择

### 18. [Dockerfile]Dockerfile中的文件操作
制作镜像时，经常需要向镜像里添加文件。在Dockerfile中有两个命令可以向镜像中添加文件`COPY`和`ADD`
> 用COPY命令构建镜像
> 
`COPY`和`ADD`命令，在复制普通文件时，没有太大的不同，两个命令都可以吧本地文件，复制到镜像里（如果复制的路径不存在，则会自动创建）  
现在我们写一个Dockerfile,里面的内容时用基础镜像，然后拷贝一个`index.js` 文件进去
Dockerfile.copy内容如下：
```
FROM node:alpine3.14
COPY index.js /app/index.js
```
引用node3.14版本，然后把`index.js`文件，拷贝到`app`目录下面
index.js文件如下，代码是3000端口上，开启一个简单的web服务，然后返回`hello nodejs`
```
// 导入http模块
const http = require('http')
// 创建服务器对象
const server = http.createServer()
// 开启服务器
server.listen(3000, () => {
  console.log('Server is running...')
})
// 监听浏览器请求并进行处理
server.on('request', (req, res) => {
  // end方法能够将数据返回给浏览器，浏览器将会显示该字符串
  res.end('hello nodejs')
})
```
两个文件准备好以后，使用`build`命令进行构建
```
docker image build -f Dockerfile.copy -t hello-copy .
```
构建完成后，使用`docker image ls`命令进行查询。生成成功后，可以启用交互模式，加上映射端口的形式，运行容器
```
docker container run -it -p 3000:3000 hello-copy sh
```
这里映射了3000端口，这样就可以使用127.0.0.1:3000端口进行访问
> 用ADD构建镜像
> 
`ADD`构建镜像和`COPY`最直观的一点不同，是ADD命令可以直接解压`gzip`压缩文件，当我们需要上传很多文件时，这样就会变的简单很多
Dockerfile.add文件内容
```
FROM node:alpine3.14
ADD  index.tar /app/
```
使用`ADD`命令进行打包镜像
```
docker image build -f Dockerfile.add -t hello-gzip .
```
打包好后进入交互模式，开启容器
```
docker container run -it -p 3000:3000 hello-gzip sh
```
再进入`app`路径下面，可以看到下面自动给我们解压了`index.tar`文件
> 切换工作目录WORKDIR
> 
在写Dockerfile文件时，默认的操作目录，时镜像的根目录。但有时候需要拷贝很多内容到二级目录，就可以使用WORKDIR命令。把工作的目录切换到二级，`WORKDIR`命令像我们操作linux下的`cd`命令  
比如刚刚的Dockerfile.add文件，我们可以使用`WORKDIR`命令，改成下面的形式
```
FROM node:alpine3.14
WORKDIR /app
ADD index.tar index.js
```
这时候进入系统后的工作目录，就是在`/app`下面了
### 19. [Dockerfile]Dockerfile中的ARG和ENV
`ARG`和`ENV`是经常容易被混淆的两个Dockerfile语法，它们都可以用来设置一个“变量”
> ENV定义变量
> 
在`Dockerfile.good`这个文件中，内容如下
```
FROM ubuntu:latest
RUN apt-get update && \
    apt-get install -y wget && \
    wget https://github.com/ipinfo/cli/releases/download/ipinfo-2.0.1/ipinfo_2.0.1_linux_amd64.tar.gz && \
    tar zxf ipinfo_2.0.1_linux_amd64.tar.gz && \
    mv ipinfo_2.0.1_linux_amd64 /usr/bin/ipinfo && \
    rm -rf ipinfo_2.0.1_linux_amd64.tar.gz
```
这段文件里有ipinfo的版本是`ipinfo-2.0.1`，这个版本是可能改变的。文件里一共出现了5次`2.0.1`。修改起来是比较麻烦的，如果出现更多次，几乎变的不可维护。所以这时候就需要定义一个变量，方便日后的维护  
先用`ENV`的形式来修改变量，把上面的Dockerfile.good文件修改为下面的形式,并将其保存名为`Dockerfile.ENV`文件
```
FROM ubuntu:latest
ENV VERSION=2.0.1
RUN apt-get update && \
    apt-get install -y wget && \
    wget https://github.com/ipinfo/cli/releases/download/ipinfo-${VERSION}/ipinfo_${VERSION}_linux_amd64.tar.gz && \
    tar zxf ipinfo_${VERSION}_linux_amd64.tar.gz && \
    mv ipinfo_${VERSION}_linux_amd64 /user/bin/ipinfo && \
    rm -rf ipinfo_${VERSION}_linux_amd64.tar.gz
```
这样写了之后，以后如果版本改变了，就还需要改变`VERSION`对应的版本号就行了
现在我们来构建这个ENV的镜像
```
docker image build -f Dockerfile.ENV -t ipinfo-env .
```
打包后，先把打包的镜像放在哪，看一下ARG的用法和打包
> ARG定义变量
>
跟上面的方法一样用ARG定义变量效果是一样的，只是把`ENV`换成`ARG`
文件名为Dockerfile.ARG,内容如下
```
FROM ubuntu:latest
ARG VERSION=2.0.1
RUN apt-get update && \
    apt-get install -y wget && \
    wget https://github.com/ipinfo/cli/releases/download/ipinfo-${VERSION}/ipinfo_${VERSION}_linux_amd64.tar.gz && \
    tar zxf ipinfo_${VERSION}_linux_amd64.tar.gz && \
    mv ipinfo_${VERSION}_linux_amd64 /usr/bin/ipinfo && \
    rm -rf ipinfo_${VERSION}_linux_amd64.tar.gz
```
使用一下命令来构建一个ARG镜像
```
docker image build -f Dockerfile.ARG -t ipinfo-arg .
```
两个打包完后，用`docker image ls`查看两个镜像，可以看到镜像的大小是一样的
> ARG和ENV的不同点
> 
总的来说`ARG`和`ENV`有亮点不同，第一点是声明变量的作用域不同，第二点是`ARG`声明后，可以在构建时修改变量
1. ARG是构建环境，ENV可带到镜像中
用交互模式进入到`ipconfig-env`镜像中,然后输入`env`可以看到当前镜像的信息
```
docker container run -it ipinfo-env
```
然后输入`env`，可以看到里面是会有`VERSION`变量的
2. ARG可以在构建镜像时改变变量值
在构建时，可以使用`-build-arg`参数来改变变量的值，例如现在要把变量`VERSION`的值进行修改，可以使用一下命令
```
docker image build -f Dockerfile.ARG -t ipinfo-arg-2.0.0 --build-arg VERSION=2.0.0 .
```
这时候我们在使用交互模式，开启`ipinfo-arg-2.0.0`容器
```
docker container run -it ipinfo-arg-2.0.0
```
然后再通过shell命令 ，`ipinfo version`查看ipinfo的版本，可以看到版本已经变成了2.0.0
### 20. [Dockerfile]CMD容器启动命令
当设置好基础环境，安装完成对应软件，处理完文件后。有时候需要启动某个默认命令，`CMD`用来设置容器启动时默认会执行的命令
> 批量清理容器和镜像
> 
批量删除不再使用的容器，注意这个批量删除是已经退出的容器（Exited state）
```
docker system prune -f
```
同样可以使用以下命令，删除没有使用的所有镜像
```
docker image prune -a
```
这个命令输入后，会提示确认，确认后才会真正删除。
> CMD命令的三个特性，有三个基本原则需要我们遵守
> 
* 容器在启动时默认执行的命令
* 如果`docker container run`启动容器时指定了其他命令，则CMD命令会被忽略
* 如果定义了多个CMD,只有最有一个CMD执行
新建一个Dockerfile.base文件，拷贝上面`Dockerfile.ENV`内容到新文件中，进行构建镜像
```
FROM ubuntu:latest
ENV VERSION=2.0.1
RUN apt-get update && \
    apt-get install -y wget && \
    wget https://github.com/ipinfo/cli/releases/download/ipinfo-${VERSION}/ipinfo_${VERSION}_linux_amd64.tar.gz && \
    tar zxf ipinfo_${VERSION}_linux_amd64.tar.gz && \
    mv ipinfo_${VERSION}_linux_amd64 /usr/bin/ipinfo && \
    rm -rf ipinfo_${VERSION}_linux_amd64.tar.gz
```
有了文件后，构建这个镜像
```
docker image build -f Dockerfile.base -t ipinfo-base .
```
构建完成后，用交互模式启动镜像
```
docker container run -it ipinfo-base
```
启动后，就进入了shell模式，这是因为ubuntu里面有定义CMD命令
> 启动容器时指定命令
> 
在用shell命令启动容器时，是可以指定香港的CMD命令的。比如我们在创建容器的时候，就启动`ipinfo`命令
```
docker container run -it ipinfo-base ipinfo version
```
输入完上面的命令后，就可以看到控制台打印出了`2.0.1`也就是ipinfo的版本号
> CMD的写法
>
现在我们向Dockerfile.base文件里，加入一个CMD命令
```
FROM ubuntu:latest
ENV VERSION=2.0.1
RUN apt-get update && \
    apt-get install -y wget && \
    wget https://github.com/ipinfo/cli/releases/download/ipinfo-${VERSION}/ipinfo_${VERSION}_linux_amd64.tar.gz && \
    tar zxf ipinfo_${VERSION}_linux_amd64.tar.gz && \
    mv ipinfo_${VERSION}_linux_amd64 /usr/bin/ipinfo && \
    rm -rf ipinfo_${VERSION}_linux_amd64.tar.gz
CMD ["ipinfo","version"]
```
CMD的写法
```
CMD ["inpinfo", "version"]
```
先删除已有的镜像，然后构建新的对象
```
docker image build -f Dockerfile.base -t ipinfo-base .
```
然后开启交互模式，启动容器
```
docker container run -it ipinfo-base
```
### 21. [Dockerfile]ENTRYPOINT命令的使用
`ENTRYPOINT`命令很容易和`CMD`命令混淆。`ENTRYPOINT`也可以设置容器启动时要执行的命令
> ENTRYPOINT和CMD的区别
> 
* `CMD`设置的命令，可以在`docker container run`时传入其他命令，覆盖掉`CMD`的命令，但是`ENTRYPOINT`所设置的命令是一定会被执行的
* `ENTRYPOINT`和`CMD`可以联合使用，`ENTRYPOINT`设置执行的命令，CMD传递参数
> 三种镜像Dockerfile说明
> 
便携三个Dockerfile文件，`Dockerfile-cmd`, `Dockerfile-entrypoint`和`Dockerfile`
`Dockerfile-cmd`内容
```
FROM ubuntu:21.04
CMD ["echo", "hello docker"]
```
`Dockerfile-entrypoint`内容
```
FROM ubuntu:21.04
ENTRYPOINT ["echo", "hello docker"]
```
`Dockerfile`内容
```
FROM ubuntu:21.04
ENTRYPOINT ["echo"]
CMD []
```
对于三个`Dockerfile`文件分别打包为`demo-cmd`, `demo-entrypoint`, `demo-both`
> 使用的区别和方法
> 
#### demo-cmd镜像的使用
```
docker container run --rm -it demo-cmd
```
输出`hello docker`，这时候如果我们在`docker container run`里直接加入命令，就会覆盖掉现在显示出的`hello docker`
```
docker container run --rm -it demo-cmd echo "hello world"
```
输出`hello world`，覆盖了`hello docker`这个原来的输出，只执行了`docker contaienr run`中后面输入的命令
#### demo-entrypoint镜像的使用
启用demo-entrypoint镜像的容器，会直接输出`hello docker`,说明`entrypoint`定义的命令也被执行了
```
docker container run --rm -t demo-entrypoint
```
输出`hello docker`,在`docker container run`命令后面，加入一个`echo "hello world"`
```
docker container run --rm -t demo-entrypoint echo "hello world"
```
输出`hello docker echo hello world`，说明它不是执行了两条命令，而是把`docker container run`后面的命令作为了参数进行传递
#### demo-both的使用
```
FROM ubuntu:21.04
ENTRYPOINT ["echo"]
CMD []
```
意思是用`ENTRYPOINT`执行`echo`命令，但最终打印出的结果，由`CMD`来决定。实现了`ENTRYPOINT`和`CMD`的配合使用
```
docker container run --rm -t demo-both "hello world !!!"
```
输出`hello world !!!`
### [数据持久化]VOLUME让数据持久化-1
容器删除后，里面的数据也会跟着删除。数据的保存和重复可用是最基本的要求，也即数据的持久化。在写`Dockerfile`的时候可以使用`VOLUME`命令，指定数据持久化
> 不能持久化的实例
> 
```
docker container run -d nginx
```

### 24.[数据持久化]Bind Mount实现数据持久
数据持久化除了`Date Volume`外，还有一种叫做`Bind Mount`，也就是`数据绑定`。简单来说就是把容器中持久化的数据，绑定到本机的一个自定义位置
> Bind Mount的优势
> 
1. `Data Volume`在windows环境中很难使用，因为路径是虚拟机的路径不容易找到
2. `Bind Mount`设置更简单，可以和开发环境更好的融合
建议在开发时，更多地使用Bind Mount实现数据持久化
> Bind Mount命令的使用
> 
使用`Bind Mount`进行数据持久化的方法，和`Data Volume`类似，也需要在启动容器时用到`-v`参数，只是参数的编写结构不同  
比如在windows进入`PowerShell`，运行一个Node的容器，然后把`/app`作为目录，把本机的当前目录作为绑定目录，意思是容器中的app目录和本机的当前目录绑定到了一起
```
docker container run -it -v ${pwd}:/app node
```
上面命令的意思是，用`Bind Mount`的形式，开启一个node容器，然后进入交互模式
其实这是时候就实现了`Bind Mount`的数据持久化，而且你可以在本季新建和操作内容，然后在容器中运行
> 本机编写index.js插件
> 
比如在本机的绑定目录新建一个`index.js`文件，然后每秒显示一下时间
```
console.log("show time")
setInterval(() => {
  console.log(Date())
}, 1000)
```
写完之后，在`powershell`里是可以看到这个文件的。这样就算没有`Node`环境，可以在容器中进行使用
进入容器的`/app`目录，运行`node index.js`命令，就可以显示时间了
### 25. [网络]容器的端口转发
如果你在外网的linux服务器上启动了一个wordpress的容器，然后想通过本季访问，这时候就需要使用端口映射了。如果不进行端口映射，容器相当于一个私域IP，外网是访问不到的，所以要使用端口转发的形式，才可以正常访问。
> linux主机安装wordpress
> 
先安装和启动容器，并映射80端口
```
docker container run -d -p 80:80 wordpress
```
第一个`80`是要映射的端口号，后面的`80`是镜像提供的端口号
> 如何查看容器提供的端口
> 
如果不知道容器提供的端口就需要使用下面的命令查看容器提供的端口
```
docker container inspect --format '{{.Config.ExposedPorts}}' <ContainerID>
```
`--format`是格式化过滤的意思，后面的`{{}...}`中是要查看的选项
如果镜像提供了这样的端口配置就可以查看到了。如果不知道有什么具体项，可以使用以下命令查看所有详细信息
```
docker container inspect <Container ID>
```
### 26. [docker-compose]介绍和安装
> 什么是Docker-compose
> 
熟悉linux应该知道我们可以把很多想的命令写成`xxx.sh`文件，而且这些步骤也是相对固定的  
这样直接运行sh文件，就可以逐一执行很多相关的docker命令。这中形式可以减少出错和解决复用问题。docker也为我们准备了一个专门的工具`docker-compose`,实现类似`sh`文件的功能，让我们可以可以更加轻松的实现多docker命令的操作  
你也可以把很多docker命令写入一个专属的文件`docker-compose.yml`,然后执行这个文件，就可以直接启动我们的容器。`docker-compose`也为我么提供了相应的操作命令
```
docker-compose up
docker-compose stop
```
操作docker-compose会有两个大的部分需要操作
* 第一部分是`docker-compose.yml`文件
* 输入命令执行构建容器
> docker-comopse的安装
> 
如果是windows或者mac安装docker桌面版本(desktip）以后，就默认安装了docker-compose工具了，可以直接使用  
查看安装的版本，在powershell中输入以下命令
```
docker-compose --version
```
弱安装好了，就会显示对应的版本
> Linux官方推荐安装方法
> 
Linux系统默认是没有安装`docker-compose`工具的，可以在[https://docs.docker.com/desktop/](https://docs.docker.com/desktop/)进行安装，选择`Product Manuals` -> `Docker compose` -> `Liunx`,可以看到三条命令，依次执行命令就可以安装  
```
sudo curl -L "https://github.com/docker/compose/releases/download/1.29.2/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose  
sudo chmod +x /usr/local/bin/docker-compose  
sudo ln -s /usr/local/bin/docker-compose /usr/bin/docker-compose
```
> linux用pip进行安装
> 
如果linux系统上没有安装pip工具，可以通过下面命令进行安装`pip`和`docker-conpose`
1. 查看是否安装依赖包
```
sudo yum install epel-release
```
2. 更新文件库
```
sudo yum -y update
```
3. 安装pip
```
sudo yum -y install python-pip
```
4. 安装docker-compose
```
sudo pip install -U docker-compose
```
### 27. [docker-compose]文件的结构和版本
> yaml文件的基础结构讲解
> 
`yaml`文件里是对启动镜像相关设置的所有描述
基本的`yaml`格式`docker-compose.yml`
```
version: "3.8"

services: # 容器
  servicename: # 服务名字，这个名字也是内部 bridge网络可以使用的 DNS name
    image: # 镜像的名字
    command: # 可选，如果设置，则会覆盖默认镜像里的 CMD命令
    environment: # 可选，相当于 docker run里的 --env
    volumes: # 可选，相当于docker run里的 -v
    networks: # 可选，相当于 docker run里的 --network
    ports: # 可选，相当于 docker run里的 -p
  servicename2:

volumes: # 可选，相当于 docker volume create

networks: # 可选，相当于 docker network create
```
以一个wordpress的镜像为例，制作`yaml`文件
> wordpress的yaml写法
> 
用命令的写法
```
docker container run -d -p 80:80 wordpress
```
yaml文件的写法
```
version: "3.8"
service: 
  my-wordpress:
    image: wordpress:latest
    ports:
     - 80:80
```
> docker-compose版本说明
> 

> docker-compose语法版本：https://docs.docker.com/compose/compose-file/(https://docs.docker.com/compose/compose-file/)
>
网页中可以看到`compose`和`docker`版本的兼容关系表
可以使用以下命令查看当前电脑的版本
```
docker --version
```
### 28. [docker-compose]基础命令的使用
> docker compose 的yaml文件
> 
上面的`yaml`文件
```
version: "3.8"

services:
  my-wordpress:
    image: wordpress:latest
    ports:
      - 80:80
```
有了这个文件后，打开`vscode`，然后在终端中输入`docker compose`命令
> 开启容器的命令
> 
要学的第一个命令是用来开启容器的`docker compose up`，当然`docker compose`有很多命令,输入`docker compose`然后回车就可以看到相关的命令  
在终端中输入以下命令，就可以开启`compose`容器了
```
docker compose up
```
但这时候的容器开启方式是又日志输出的，并且窗口被占用了。没办法进行其他操作，加入`-d`参数启动后台运行模式，就可以继续操作终端了
```
docker compose up -d
```
如果想要看`service`运行情况，可以使用以下命令
```
docker-compose ps
```
> docker compose的停止和清理
> 
当你不再使用这个`service`时，可以使用`stop`命令停止
```
docker compose stop
```
停止后，容器处于`Exited`模式。容器停止后，就可以进行清理了
```
docker compose rm
```
命令会删除由`docker compose`所建立的容器，但是docker命令创建的容器不回被删除，对应的网络也不会被删除
> 命名规则
> 
用`docker compose`创建的容器，名字都会加入一个对应文件，例如现在的文件夹为`test`，在`yaml`文件中的名字为`my-wordpress`,那么最终的容器名字就是`test_my-wordpress_1`
这个前缀可以更改，例如前缀加上`hello`，可以使用`-p`参数
```
docker-compose -p hello up -d
```
也可以在`yaml`文件中指定这个名字，方法是使用`container_name:xxx`但是这样就会完全省略前缀和后缀
```
version: "3.8"

services:
  my-wordpress:
        container_name: hello
    image: wordpress:latest
    ports:
      - 80:80
```
