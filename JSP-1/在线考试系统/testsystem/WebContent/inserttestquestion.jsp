<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<%request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>添加试题</title>
</head>
<body background="images/背景.jpg"><center>
<form action="inserttestquestionmanage.jsp" method="post">
	<p>题号：<input type="text" name="id">
	<p>题目：<input type="text" name="question">
	<p>选项A：<input type="text" name="A">
	<p>选项B：<input type="text" name="B">
	<p>选项C：<input type="text" name="C">
	<p>选项D：<input type="text" name="D">
	<p>正确答案：<input type="text" name="answer">
	<p><input type="submit" value="提交">
</form>
<p><a href="makeoutatestpaper.jsp">返回</a></center>
</body>
</html>