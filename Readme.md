#### NT内核导出以及未导出函数-全局变量偏移速查

###### System目录下有已经完成的偏移 可以在线速查

###### https://github.com/DragonQuestHero/WindowsSyscallsEx/blob/master/System

<h1 align="center">
	<img src="0.png" >
	<br>
	<br>
</h1>

#### 使用说明:

###### 解压文件 2个DLL和exe以及nt pdb文件放置同一个目录 运行exe即可

###### 使用kernel base+偏移可以快速定位未导出函数 不必每个版本都用特征码搜索 也不必使用环3上传符号地址

<h1 align="center">
	<img src="1.png" >
	<br>
	<br>
</h1>

###### (详情:https://github.com/DragonQuestHero/WindowsSyscallsEx/blob/master/GetKernelBase/Main.cc#L290)
