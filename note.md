1. 为什么使用spdlog这个数据库，为什么不选择别的数据库

a：任何一个项目都需要打印日志，在文件或者console中打印详细的信息或者一些错误日志，方便开发者定位问题，掌握程序运行的状态等。

2. 数据库为什么使用这个

a：使用数据库做持久化操作。
客户端几乎都是使用sqlite数据库，正常使用sqlite数据库，比如增删改查，都需要写对应的sql语句才可以。
正常客户端使用sqlite，都会直接使用链接sqlite C开源库，然后写一堆sql语句，在调用一堆C语句，没有RAII，使用起来很不方便，比如每次start transtion，都需要在所有的if else分支调用transtion commit或者transtion rollback才行。
基于以上的麻烦，这里选择基于sqlite封装的一个ORM开源库，只需要定义某些struct，调用相关的函数就可以实现增删改查等能力，使用起来特别方便。

3. 日志系统

a：构造多个logger对象，让不同的logger对象往不同的目录写入日志

![alt text](./BuriedPoint/photo/spdlog日志.jpeg)

写日志流程

1. 写入一行日志
2. Formatter，为日志做格式化，比如写入的日志是abc，经过Formatter，会自动拼接信息，such as 线程id，进程id，当前时间等等，我们可以自定义
3. sinks，控制日志写入的目的地，比如console sink，会将日志写入到控制台，file sink会将日志写入文件，我们海口可以自定义sink。每行日志，不一定会只经过一个sink，可以经过多个sink，可以写入控制台，又可以写入文件


# 在header——only方式下，会有很多源文件的include spdlog 的头文件，相当于每个源文件都需要定义很多spdlog函数，所以我这一使用链接
# 的方式。

# 这种方式下需要在CMakeLists.txt中做一些配置:
# 1.把spdlog的头文件目录添加到整个项目的头文件搜索目录中
# 2.add subdirectory spdlog，相当于编译spdlog
# 3.项目的库依赖spdlog