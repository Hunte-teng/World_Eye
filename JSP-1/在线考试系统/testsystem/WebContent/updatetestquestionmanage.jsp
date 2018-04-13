<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.*"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>修改</title>
</head>
<body background="images/背景.jpg"><center>
<%
int id = Integer.parseInt(request.getParameter("id"));
String update = request.getParameter("update");
String updatetext = request.getParameter("updatetext");
TestDAO testdao = new TestDAO();
if(update.equals("question")){
	testdao.updateQuestion(id, updatetext);
}
if(update.equals("choiceA")){
	testdao.updateChoiceA(id, updatetext);
}
if(update.equals("choiceB")){
	testdao.updateChoiceB(id, updatetext);
}
if(update.equals("choiceC")){

	testdao.updateChoiceC(id, updatetext);
}
if(update.equals("choiceD")){
	testdao.updateChoiceD(id, updatetext);
}
if(update.equals("answer")){
	testdao.updateAnswer(id, updatetext);
}
out.print("修改成功！");%>
<p><a href="makeoutatestpaper.jsp">返回</a></center>
</body>
</html>