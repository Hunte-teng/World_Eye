<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.*"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>学生成绩单</title>
</head>
<body background="images/背景.jpg"><center>
<%
    String stuname = request.getParameter("studentname");
    StudentDAO studao = new StudentDAO();
    StudentVO stu = studao.studentScore(stuname);
%>
<table border="2">
   <tr>
       <th>学生学号</th>
       <th>学生姓名</th>
       <th>所选选项</th>
       <th>每题得分</th>
       <th>总分</th>
   </tr>
   <tr>
       <td><%=stu.getNumber() %></td>
       <td><%=stu.getStudentname() %></td>
       <td><%=stu.getEverychoice() %></td>
       <td><%=stu.getEveryscore() %></td>
       <td><%=stu.getTotal() %></td>
   </tr>
</table>
<a href="makeoutatestpaper.jsp">返回</a>
</center>
</body>
</html>