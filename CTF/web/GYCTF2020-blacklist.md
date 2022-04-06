​		重启CTF刷题第一道=。=，每周刷几道题，稍微简单随意的学一点安全知识，期待以后有机会从事安全行业……

​		这道题基本上是看题解做的，随便记录点东西。

​		输入1、2正常回显，3及以上的数字没有回显。

​		输入select会发现黑名单：

```php
return preg_match("/set|prepare|alter|rename|select|update|delete|drop|insert|where|\./i",$inject);
```

​		然后看别人经验，可以用show查表。

```
1';show tables;#
1';show columns from flaghere;#
```

​		这里的flaghere必须用给出的格式，不能不区分大小写。原因吗？可能是后台经过PHP，被处理过一次，所以数据库不认？我也不是很明白=。=

​		总之发现表了之后，然后可以学习别人的技巧，就是使用Mysql特有的Handler查表方式，下面我学习一下，然后记录点内容。



​		handler是mysql专有的语句，并没有被包含到sql标准内。handler提供通往表的直接通道的存储引擎接口，可以用于MyISAM和InnoDB。

​		似乎类似于编程语言打开文件的方式啊，先用handler指定表名打开，然后按行读取，最后再关闭。	

```
HANDLER tbl_name OPEN;
HANDLER tbl_name READ { FIRST | NEXT }
    [ WHERE where_condition ] [LIMIT ... ]
HANDLER tbl_name close;
```

​		payload:

```
1';handler FlagHere open;handler FlagHere read first;
```

​		另外，关于sql注入中常见的三种注释，#，--和--+，之所以会有差异，是因为使用的时候会被转码。甚么意思呢？比如get请求时注入，会发现#和+号被url转义了，分别代表网页锚点和空格，因而都需要url转码后，在后端才能被解析成正确的内容。

​		具体怎样或者说细节如何，只能以后再看了。说不太清楚，因为我编码知识还没学清楚，以后再补，现在就先不挖了。