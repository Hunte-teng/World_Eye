<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.StudentDAO" import="mybean.StudentVO"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
String number = request.getParameter("number");
String studentname = request.getParameter("studentname");
String studentpass = request.getParameter("studentpass");
StudentDAO studao = new StudentDAO();
StudentVO stu = studao.studentLoginFind(studentname);

if(stu.getStudentpass().equals(studentpass)){
	session.setAttribute("number", number);
	session.setAttribute("studentname", studentname);
%>
    <jsp:forward page="paper.jsp"></jsp:forward>
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