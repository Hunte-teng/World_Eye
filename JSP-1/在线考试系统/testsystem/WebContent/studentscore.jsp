<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>查看学生成绩单</title>
</head>
<body background="images/背景.jpg"><center>
<form action="showstudentscore.jsp" method="post">
<p>请输入要查看的学生姓名：<input type="text" name="studentname">
<p><input type="submit" value="查看">
</form>
<!-- <form action="showallstudentscore.jsp" method="post"> -->
<p><input type="button" value="查询所有学生成绩" onclick="window.open('showallstudentscore.jsp')">
<!-- </form> -->

</center>
</body>
</html>