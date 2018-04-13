<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.StudentVO" import="mybean.StudentDAO"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>学生注册</title>
</head>
<body background="images/背景.jpg"><center>
<%
String studentname = request.getParameter("studentname");
String number = request.getParameter("number");
String studentpass = request.getParameter("studentpass");
StudentDAO studao = new StudentDAO();
StudentVO stu = new StudentVO();
stu.setNumber(number);
stu.setStudentname(studentname);
stu.setStudentpass(studentpass);
studao.setStudentvo(stu);
studao.studentLoginInsert();
out.print("注册成功！");
%>
<p><a href="login.jsp">登录</a></center>
</body>
</html>