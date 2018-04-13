<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>出卷</title>
</head>
<body background="images/背景.jpg">
<center><p><h3>开始出题</h3>
<p>出题人：<%=session.getAttribute("teachername") %>
<p><a href="inserttestquestion.jsp">添加试题</a>
<p><a href="updatetestquestion.jsp">修改试题</a>
<p><a href="deletetestquestion.jsp">删除试题</a>
<p><a href="showpaper.jsp">查询试题</a>
<p><a href="studentscore.jsp">查看学生成绩单</a>
<p><a href="login.jsp">返回登录</a></center>
</body>
</html>