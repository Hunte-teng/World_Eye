<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"  import="mybean.*" import="java.util.*"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>试卷</title>
</head>
<body background="images/背景.jpg"><center>
<%
TestDAO testdao = new TestDAO();
ArrayList<QuestionVO> questions = testdao.getAll();
%>
<table border="2">
   <tr>
       <th bgcolor="#fba661">题号</th>
       <th bgcolor="#fba661">试题内容</th>
       <th bgcolor="#fba661">选项A</th>
       <th bgcolor="#fba661">选项B</th>
       <th bgcolor="#fba661">选项C</th>
       <th bgcolor="#fba661">选项D</th>
       <th bgcolor="#fba661">答案</th>
   </tr>
<%
	for(int i=0;i<questions.size();i++)
	{
%>
   <tr>
       <td bgcolor="#f3f3f3"><%=questions.get(i).getId() %></td>
       <td bgcolor="#f3f3f3"><%=questions.get(i).getQuestion() %></td>
       <td bgcolor="#f3f3f3"><%=questions.get(i).getA() %></td>
       <td bgcolor="#f3f3f3"><%=questions.get(i).getB() %></td>
       <td bgcolor="#f3f3f3"><%=questions.get(i).getC() %></td>
       <td bgcolor="#f3f3f3"><%=questions.get(i).getD() %></td>
       <td bgcolor="#f3f3f3"><%=questions.get(i).getAnswer() %></td>
   </tr>
<%
	}
%>
</table>
<p><a href="makeoutatestpaper.jsp">返回</a></center>
</body>
</html>