<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList" import="mybean.FoodVO"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>开始点餐</title>
</head>
<body background="images/背景3.jpg">
<center>
<br><br><br><br><br><br>
<h2>开始点餐吧</h2>
<table width="40%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<th bgcolor= "#fba661">
			<div align="center">
				功能选项
			</div>
		</th>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
				<a href="FoodListAction?type=3">查询食物</a>
			</div>
		</td>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
			    <a href="FoodListAction?type=1">披萨</a>
			</div>
		</td>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
				<a href="FoodListAction?type=2">饮品</a>
			</div>
		</td>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
			    <a href="ViewOrderAction">查看订单</a>
			</div>
		</td>						
	</tr>			                      
</table>
<p><a href="login.jsp">返回登录</a>
</center>
</body>
</html>