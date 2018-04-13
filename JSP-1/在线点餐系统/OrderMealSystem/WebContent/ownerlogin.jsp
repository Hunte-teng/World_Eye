<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>欢迎登录店家系统</title>
</head>
<body background="images/背景1.jpg">
<br><br><br><br><br>
<h2><font size=20 color=#fba661>欢迎店家登录</font></h2>
<%
if(request.getAttribute("message")==null){
	out.print("");
}
else{
	out.print(request.getAttribute("message"));
}
%>
<form action="OwnerLoginAction" method="post">

<div style="background:url(images/动图4.gif);width:316px;height:240px" align="center">
<br><br>
<font size="5"><b>店家登录</b></font>
<p>用户名：<input type="text" name="ownername" size=13><br>
<p>密&nbsp;&nbsp;&nbsp;码：<input type="password" name="ownerpass" size=13><br>
<p><input type="submit" value="登录"  OnClick=check()>&nbsp;&nbsp;&nbsp; <input type="button" value="注册" onclick="window.open('ownerregister.jsp')">
</div>
</form>

</body>
</html>