<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.FoodVO" import="java.util.ArrayList"%><%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>删除食物</title>
</head>
<body background="images/背景3.jpg">
<center>
<%
ArrayList<FoodVO> allfood = (ArrayList<FoodVO>)request.getAttribute("allfood");
%>
<form action="DeleteFoodAction" method="post" name="deletefood">
<input type="hidden" name="hidden" value="deletefood">
<h2>删除食物</h2>
<table width="60%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661"  width="50%">
			<div align="center">
				需要删除食物的名称
			</div>
		</td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				<select name="foodname">
				<%
				    for(int i=0;i<allfood.size();i++){
				%>
				    <option value="<%=allfood.get(i).getName() %>"><%=allfood.get(i).getName() %></option>
				<% 
				    }
				%>	    
				</select>
			</div>
		</td>						
	</tr>							                      
</table>
<p><input type="submit" value="删除">&nbsp;&nbsp;&nbsp;<input type="button" value="返回功能界面" onclick="window.open('ownerfunction.jsp')">
</form>
<%
if(request.getAttribute("message")==null){
	out.print("");
}
else{
	out.print(request.getAttribute("message"));
}

%>
</center>
</body>
</html>