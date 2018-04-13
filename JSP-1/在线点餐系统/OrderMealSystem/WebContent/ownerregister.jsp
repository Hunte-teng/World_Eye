<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>店家注册</title>
</head>
<body background="images/背景1.jpg">
<center>
<form action="OwnerRegisterAction" method="post">
<%
if(request.getAttribute("message")==null){
	out.print("");
}
else{
	out.print(request.getAttribute("message"));
}
%>
<h3><font size="5">店家注册</font></h3>
<p>店号：<input type="text" name="ownernumber"><img src="images/笔.gif" width=30>
<p>店名：<input type="text" name="ownername"><img src="images/笔.gif" width=30>
<p>密码：<input type="password" name="password"><img src="images/笔.gif" width=30>
<p>电话：<input type="text" name="telephone"><img src="images/笔.gif" width=30>
<p>地址：<input type="text" name="address"><img src="images/笔.gif" width=30>
<p><input type="submit" value="注册">
</form>
<p><a href="login.jsp">返回登录</a>
</center>
</body>
</html>