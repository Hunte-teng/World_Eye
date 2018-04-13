<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%><%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>添加食物</title>
</head>
<body background="images/背景3.jpg">
<center>
<form action="AddFoodAction" method="post">
<h2>添加食物</h2>
<table width="60%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661" width=50%>
			<div align="center">
				食物编号
			</div>
		</td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				<input type="text" name="foodid">
			</div>
		</td>						
	</tr>
	<tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				食物名称
			</div>
		</td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				<input type="text" name="foodname">
			</div>
		</td>						
	</tr>
	<tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				食物类型
			</div>
	    </td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				<input type="text" name="foodtype">
			</div>
		</td>	
	</tr>
	<tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				食物图片id
			</div>
		</td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				<input type="text" name="foodimg">
			</div>
		</td>						
	</tr>
	<tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				食物价格
			</div>
		</td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				<input type="text" name="foodprice">
			</div>
		</td>						
	</tr>								                      
</table>
<p><input type="submit" value="添加">&nbsp;&nbsp;&nbsp;<input type="button" value="返回功能界面" onclick="window.open('ownerfunction.jsp')">
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