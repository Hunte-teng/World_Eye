<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.FoodVO" import="java.util.ArrayList"%><%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>修改食物信息</title>
</head>
<body background="images/背景3.jpg">
<center>
<%
ArrayList<FoodVO> allfood = (ArrayList<FoodVO>)request.getAttribute("allfood");
%>
<form action="UpdateFoodAction" method="post" name="updatefood">
<input type="hidden" name="hidden" value="updatefood">
<h2>修改食物信息</h2>
<table width="80%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				需要修改的食物名称
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
	<tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				修改选项
			</div>
		</td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				 <p><input type="radio" name="update" value="foodname">食物名称
                 <p><input type="radio" name="update" value="foodtype">食物类型
                 <p><input type="radio" name="update" value="foodimg">食物图片
                 <p><input type="radio" name="update" value="foodprice">食物价格
			</div>
		</td>						
	</tr>
	<tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				修改内容
			</div>
	    </td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				<input type="text" name="updatetext">
			</div>
		</td>	
	</tr>						                      
</table>
<p><input type="submit" value="修改">&nbsp;&nbsp;&nbsp;<input type="button" value="返回功能界面" onclick="window.open('ownerfunction.jsp')">
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