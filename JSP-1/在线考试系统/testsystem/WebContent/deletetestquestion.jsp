<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>删除题目</title>
</head>
<body background="images/背景.jpg"><center>
<form action="deletetestquestionmanage.jsp" method="post">
<p>请输入要删除的题目的题号：<input type="text" name="id">
<p><input type="submit" value="删除"> 
<p><a href="makeoutatestpaper.jsp">返回</a>
</form></center>
</body>
</html>