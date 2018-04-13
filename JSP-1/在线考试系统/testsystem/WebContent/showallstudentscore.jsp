<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList" import="mybean.StudentVO" import="mybean.StudentDAO"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>所有学生成绩</title>
</head>
<body background="images/背景.jpg">
<%
ArrayList<StudentVO> alllist = new ArrayList<StudentVO>();
StudentDAO studentdao = new StudentDAO();
alllist = studentdao.studentAllScore();
/* StudentVO stu = new StudentVO();
for(int j=0;j<alllist.size()-1;j++)
{
	for(int i=0;i<alllist.size()-1-j;i++)
	{
		if(alllist.get(i).getTotal()<alllist.get(i+1).getTotal())
		{
			stu = alllist.get(i);
			alllist.get(i) = alllist.get(i+1);
		}
	}
} */
%>
<center>
<h3>学生成绩单</h3>
<table border="2">
   <tr>
       <th>学生学号</th>
       <th>学生姓名</th>
       <th>所选选项</th>
       <th>每题得分</th>
       <th>总分</th>
   </tr>
<%
for(int i=0;i<alllist.size();i++)
{
%>   
   <tr>
       <td><%=alllist.get(i).getNumber() %></td>
       <td><%=alllist.get(i).getStudentname() %></td>
       <td><%=alllist.get(i).getEverychoice() %></td>
       <td><%=alllist.get(i).getEveryscore() %></td>
       <td><%=alllist.get(i).getTotal() %></td>
   </tr>
<%
}
%>
</table>
<a href="makeoutatestpaper.jsp">返回</a>
</center>
</body>
</html>