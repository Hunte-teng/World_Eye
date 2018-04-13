<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>欢迎登录用户系统</title>
</head>
<body background="images/背景1.jpg">
<br><br><br><br><br>
<center><h2><font size=20 color=#fba661>欢迎用户登录</font></h2>
<%
	ArrayList<String> mycart = new ArrayList<String>();
	session.setAttribute("mycart",mycart);
	if(request.getAttribute("message")==null){
		out.print("");
	}
	else{
		out.print(request.getAttribute("message"));
	}
%>
<form action="UserLoginAction" method="post">
<div style="background:url(images/登录.png);width:300px;height:200px">
<h4><font size="5" color=#ffffff><b>用户登录</b></font></h4>
<p>用户名：<input type="text" name="username"><img src="images/笔.gif" width=30>
<p>密&nbsp;&nbsp;&nbsp;码：<input type="password" name="password"><img src="images/笔.gif" width=30>
<p><input type="submit" value="登录"> &nbsp;&nbsp;&nbsp;<input type="button" value="注册" onclick="window.open('userregister.jsp')">
</div>
</form>
</center>
</body>
</html>