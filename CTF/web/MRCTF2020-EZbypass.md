```php
if(isset($_GET['gg'])&&isset($_GET['id'])) 
{ 
	$id=$_GET['id']; 
	$gg=$_GET['gg']; 
	if (md5($id) === md5($gg) && $id !== $gg) 
	{
		echo 'You got the first step'; 
		if(isset($_POST['passwd'])) 
		{ 
			$passwd=$_POST['passwd']; 
			if (!is_numeric($passwd)) 
				if($passwd==1234567) 
				{ 
					echo 'Good Job!'; 
					highlight_file('flag.php'); 
					die('By Retr_0'); 
				} 
				else
					echo "can you think twice??";  
			else
				echo 'You can not get it !';  
		}
		else
			die('only one way to get the flag'); 
	}
	else
		echo "You are not a real hacker!"; 
}
else
{ 
	die('Please input first'); 
}

```

​		可以看见，就是一层又一层的符合条件，然后隐藏着答案的flag.php会被显示出来。我们一层层的扒开

​		第一层：用get方法设置id和gg。

​		第二层：传入的两个参数md5碰撞一致；

​		第三层：传入一个passwd；

​		第四层：passwd是非数字类型

​		第五层：弱比较与1234567相等。

​		大概就是这些内容了。第一层和第三层传参即可。可以看得出来主要复习两个知识点，当然也不算是知识=。=

​		一个是md5碰撞，这个网上一找一大把。另一个就是类型比较，php的类型比较有着各种各样奇怪的特性，因而很容易产生漏洞被人绕过。这里就是要传入一个非数字型，然后和数字比较相等。具体是怎样的我不记得了，但是网上应该也有不少的资料。

​		没看仔细……第一个md5还是强比较。弱比较的话，资料比较多，就是说md5的结果如果以0e开头，会被视为科学计数法从而判定相等。

> ​		因为处理hash字符串时，PHP会将每一个以 0E开头的哈希值解释为0，那么只要传入的不同字符串经过哈希以后是以 0E开头的，那么PHP会认为它们相同

​		但是===不行，强比较需要其它绕过方法。强比较在PHP8.0以前，都只能通过数组进行绕过，也就是说，两个不同参数都定义为数组，然后md5函数计算不会报错，只会返回null，然后两个null比较，可以通过判定。

```
id[]=1&gg[]=2
```

​		然后就是处理非数字类型和数字类型的比较了。

​		没想到这么简单。。。用1234567abcde就过了。。。似乎字符串和数字类型进行比较，PHP会自动把字符串类型截断？然后只保留一部分的数字，不然不应该就这么通过了啊……

​		大概不知道咋总结，但大概好像就那么过了=。=，PHP一堆胡乱特性，过了就过了吧。。。遇到更深的再详细了解