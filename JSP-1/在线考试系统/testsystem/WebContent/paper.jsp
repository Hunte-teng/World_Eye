<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.*" import="java.util.*"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>考试</title>
</head>
<body background="images/背景.jpg">
<%
TestDAO testdao = new TestDAO();
ArrayList<QuestionVO> questions = testdao.getAll();
int n = questions.size();//题目个数
session.setAttribute("n",new Integer(n));
String []answeri = new String[n];
%>
<center>
<form action="judgepaper.jsp" method="post">
<table border="2">
  <tr>
      <td align="center" bgcolor="#f3f3f3"><h2>Java Web 模拟考试</h2></td>
  </tr>
  <tr>
      <th  bgcolor="#f3f3f3">考生姓名：<%=session.getAttribute("studentname") %>&nbsp;&nbsp;&nbsp;
                                  考生学号：<%=session.getAttribute("number") %>
      </th>
  </tr>
<%
	for(int i=0;i<questions.size();i++)
	{
%>
  <tr>
    <td bgcolor="#f3f3f3">
<%
		out.print(i+1+"、"+questions.get(i).getQuestion()+"<br>");
%>
  
        <input type="radio" name="<%=i %>" value="A"><%=questions.get(i).getA() %>
        <input type="radio" name="<%=i %>" value="B"><%=questions.get(i).getB() %>
        <input type="radio" name="<%=i %>" value="C"><%=questions.get(i).getC() %>
        <input type="radio" name="<%=i %>" value="D"><%=questions.get(i).getD() %>

<%
        answeri[i] = Integer.toString(i);
	}
    session.setAttribute("answeri", answeri);
%>
    </td>
  </tr>
  <tr>
    <td align="center">
<input type="submit" value="提交">&nbsp;&nbsp;&nbsp;<input type="button" value="返回登录" onclick="window.open('login.jsp')">
    </td>
  </tr>
</table>

</form>
</center>
</body>
</html>