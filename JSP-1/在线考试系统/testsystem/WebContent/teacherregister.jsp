<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.TeacherVO" import="mybean.TeacherDAO"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body background="images/背景.jpg"><center>
<%
String teachername = request.getParameter("teachername");
String teacherpass = request.getParameter("teacherpass");
TeacherDAO teadao = new TeacherDAO();
TeacherVO tea = new TeacherVO();
tea.setTeachername(teachername);
tea.setTeacherpass(teacherpass);
teadao.setTeachervo(tea);
teadao.tescherLoginInsert();
out.print("注册成功！");
%>
<p><a href="login.jsp">登录</a></center>
</body>
</html>