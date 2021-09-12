originial artical address:https://www.digitalocean.com/community/tutorials/ubuntu-and-debian-package-management-essentials



### Ubuntu和Debian包管理概要

By [Justin Ellingwood](https://www.digitalocean.com/community/users/jellingwood)

Published onNovember 3, 2014

##### 简介

​        包管理是Linux系统提供的若干根本优势之一。打包格式和包管理工具因发行版而异，但最常见的是两个通用系列。基于RHEL（red hat enterprise linux)的发行版，最常用的是RPM打包格式和rpm与yum包管理工具。而Ubuntu、Debian以及相关发行版，用.deb打包格式和apt与dpkg打包工具。后者就是我们这个教程所要谈论的内容。

​        在这篇教程中，我们会涉及一些系统管理员在Debian和Ubuntu上最常使用的包管理工具。如果你需要在这些系统上完成包管理任务，这也可以作为一篇简短的参考。

#### 如何使用本教程

​		本教程会涉及用户最常在Debian和Ubuntu上使用的包管理工具。