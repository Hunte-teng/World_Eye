<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>修改</title>
</head>
<body background="images/背景.jpg"><center>
<form action="updatetestquestionmanage.jsp" method="post">
<p>请输入要修改的题目的题号：<input type="text" name="id">
<p>请选择要修改的对象：
                 <p><input type="radio" name="update" value="question">试题内容
                 <p><input type="radio" name="update" value="choiceA">选项A
                 <p><input type="radio" name="update" value="choiceB">选项B
                 <p><input type="radio" name="update" value="choiceC">选项C
                 <p><input type="radio" name="update" value="choiceD">选项D
                 <p><input type="radio" name="update" value="answer">标准答案
<p>请输入要修改的内容：<input type="text" name="updatetext">
<p><input type="submit" value="修改"> 
<p><a href="makeoutatestpaper.jsp">返回</a>
</form></center>
</body>
</html>