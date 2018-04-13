<!-- 
/***********************************************************
*													
*														
*	项目名称：				
*	子系统名：			
*	功能名称：	
*	完成人员：					
*	完成时间：					
*								
*									
************************************************************/
-->
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <title>小型图书资料管理系统登录页面</title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
  </head>
  <body background="../images/背景1.jpg">   
   	<center>
   	<br>
   	<br>
   	<br>
   	<br>
   	<h3><font size=7 color=#fba661>欢迎登录小型图书资料管理系统</font></h3>
   	
	<form method="post" action="login.action" name="frm">
	<div style="background:url(../images/登录2.png);width:500px;height:400px">
    <br>
	<font color=#f3f3f3 size=4 face=华为行楷><b>
	 <p>小型图书资料管理系统-版本_0.1.0 2017年10月7日<br/>
	 <p><img src="../images/小黄人.gif" width=40>用户账户： <input type="text" size="30" name="user.name" value="admin">
	     <img src="../images/笔.gif" width=60><br/>
	    <p><img src="../images/小黄人.gif" width=40>登录密码： <input type="password" size="30" name="user.password" value="123456">
	    <img src="../images/笔.gif" width=60><br/><br/>
	  <p><input type="submit" value="登录系统" name="login">
	  <input type="reset" value="重新填写" name="reset"><br/>
      <p>Copyright@ 2009-2017 版权所有 辽宁师范大学
      </b></font>
	</div>
	</form>
	
	</center>
  </body>
</html>
