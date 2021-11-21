# 《Data Structure》-Wandao
《Data Structure》- Wandao

# 1.初始化仓库

## 		(1)设置用户信息

​		git config --global user.name "Junk Chen"
​		git config --global user.email junkchen@vip.qq.com

##     	(2)初始化仓库

​		git init

##     	(3)克隆现有的仓库

​		git clone https://github.com/libgit2/libgit2

# 2.提交更改

## 		(1)添加到暂存区里面去

​		git add .

##     	(2)把文件提交到仓库。引号内为提交说明

​		git commit -m 'first commit'

##     	(3)当前分支master推送到远程

​		git push

​		git config --global http.sslVerify "false" （网络不稳定，连接超时导致的，打开Git命令页面，执行git命令脚本：修改设置，解除ssl验证）

# 3.删除操作

##     	(1)删除文件夹

​		git rm -r "CH2 用C语言编写程序1" 

##     	(2)删除文件

​		git rm "text.txt"

# 4....