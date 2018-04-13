<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.TeacherDAO" import="mybean.TeacherVO"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
String teachername = request.getParameter("teachername");
String teacherpass = request.getParameter("teacherpass");
TeacherDAO teadao = new TeacherDAO();
TeacherVO tea = teadao.teacherLoginFind(teachername);

if(tea.getTeacherpass().equals(teacherpass)){
	session.setAttribute("teachername", teachername);
%>
    <jsp:forward page="makeoutatestpaper.jsp"></jsp:forward>
<%
}
else{
%>
	<jsp:forward page="login.jsp"></jsp:forward>
<%
}
%>
</body>
</html>