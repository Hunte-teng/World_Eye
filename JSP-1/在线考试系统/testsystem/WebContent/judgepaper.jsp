<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.*" import="java.util.ArrayList" import="java.lang.StringBuffer"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>得分</title>
</head>
<body  background="images/背景.jpg"><center>
<%
TestDAO testdao = new TestDAO();
ArrayList<String> ans = new ArrayList<String>();
ans = testdao.getAllAnswer();//标准答案
TestDAO testdao1 = new TestDAO();
ArrayList<String> questions = new ArrayList<String>();
questions = testdao1.getAllQuestion();
String[] answeri = (String[])session.getAttribute("answeri");//学生所选答案
int score = 0,total = 0;
int n = ((Integer)session.getAttribute("n")).intValue();

StringBuffer sb1 = new StringBuffer();//存储学生所选答案
StringBuffer sb2 = new StringBuffer();//存储标准答案
sb1.append("");
sb2.append("");

%>
<h3>成绩单</h3>
<h4>考生姓名：<%=session.getAttribute("studentname") %>&nbsp;&nbsp;考生学号：<%=session.getAttribute("number") %></h4>
<table border="2">
   <tr>
       <th>题号</th>
       <th>试题题干</th>
       <th>标准答案</th>
       <th>所选选项</th>
       <th>得分</th>
   </tr>
<%
    for(int i=0;i<n;i++)//循环接收答案
    {
    	String choice = request.getParameter(answeri[i]);
        if(choice.equals(ans.get(i))){
        	score = 2;
        	total += score;
        	
        }
        else
        	score = 0;
%>
<tr>
       <td><%=i+1 %></td>
       <td><%=questions.get(i) %></td>
       <td><%=ans.get(i) %></td>
       <td><%=choice %></td>
       <td><%=score %></td>
   </tr>
<%
        sb1.insert(i, choice);//所选答案
        sb2.insert(i, score);//标准答案
    }
%>
   <tr><td colspan="4"><center>总分：<%=total %></center></td></tr>
</table>
<%
    StudentDAO studao = new StudentDAO();
    String studentname = (String)session.getAttribute("studentname");
    String everychoice = sb1.toString();
    String everyscore = sb2.toString();
    studao.updateStudentScore(studentname, everychoice, everyscore, total);
%>
<p><input type="button" value="返回试题" onclick="window.open('paper.jsp')">&nbsp;&nbsp;&nbsp;<input type="button" value="结束考试" onclick="window.open('login.jsp')">
</center>
</body>
</html>