<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>注册</title>
</head>
<body background="images/背景.jpg">
<br>
<center>
<h3><font size=10 color=#fba661 style="华为行楷">欢迎注册考试系统</font></h3>
<form action="studentregister.jsp" method="post">
<div style="background:url(images/登录1.png);width:300px;height:200px">
<h3><font size="5">学生注册</font></h3>
<p>用户名：<input type="text" name="studentname">
<p>学&nbsp;&nbsp;&nbsp;号：<input type="text" name="number">
<p>密&nbsp;&nbsp;&nbsp;码：<input type="password" name="studentpass">
<p><input type="submit" value="学生注册">
</div>
</form>
<form action="teacherregister.jsp" method="post">
<div style="background:url(images/登录1.png);width:300px;height:180px">
<h3><font size="5">教师注册</font></h3>
<p>用户名：<input type="text" name="teachername">
<p>密&nbsp;&nbsp;&nbsp;码：<input type="password" name="teacherpass">
<p><input type="submit" value="教师注册">
</div>
</form>
<p><a href="login.jsp">返回登录</a>
</center>
</body>
</html>