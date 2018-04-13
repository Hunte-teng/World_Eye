<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>用户注册</title>
</head>
<body background="images/背景1.jpg">
<center>
<%
if(request.getAttribute("message")==null){
	out.print("");
}
else{
	String message = (String)request.getAttribute("message");
	out.print(message);
}
%>
<form action="UserRegisterAction" method="post">
<h3><font size="5">用户注册</font></h3>
<p>用户名：<input type="text" name="username"><img src="images/笔.gif" width=30>
<p>密&nbsp;&nbsp;&nbsp;码：<input type="password" name="password"><img src="images/笔.gif" width=30>
<p>电&nbsp;&nbsp;&nbsp;话：<input type="text" name="telephone"><img src="images/笔.gif" width=30>
<p>地&nbsp;&nbsp;&nbsp;址：<input type="text" name="address"><img src="images/笔.gif" width=30>
<p><input type="submit" value="注册">
</form>
<p><a href="login.jsp">返回登录</a>
</center>
</body>
</html>