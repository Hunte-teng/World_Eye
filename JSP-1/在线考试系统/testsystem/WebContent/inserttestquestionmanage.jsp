<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.*" %>
<%request.setCharacterEncoding("utf-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body background="images/背景.jpg"><center>
<%
int id = Integer.parseInt(request.getParameter("id"));
String question = request.getParameter("question");
String a = request.getParameter("A");
String b = request.getParameter("B");
String c = request.getParameter("C");
String d = request.getParameter("D");
String answer = request.getParameter("answer");

QuestionVO ques = new QuestionVO();
ques.setId(id);
ques.setQuestion(question);
ques.setA(a);
ques.setB(b);
ques.setC(c);
ques.setD(d);
ques.setAnswer(answer);
TestDAO testdao = new TestDAO();
testdao.setQuestionvo(ques);
testdao.insert();
out.print("插入成功！");%>
<p><a href="makeoutatestpaper.jsp">返回</a></center>
</body>
</html>