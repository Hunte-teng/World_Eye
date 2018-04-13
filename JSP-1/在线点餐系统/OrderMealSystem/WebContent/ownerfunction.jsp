<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%><%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>开始管理你的店吧</title>
</head>
<body background="images/背景3.jpg">
<center>
<h2>开始管理你的店吧</h2>
<table width="50%" border="0" cellspacing="1" cellpadding="0" class="">
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
				<form action="FindOrderAction" method="post">
				<input type="submit" value="查看订单">
				</form>
			</div>
		</td>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
			    <form action="FindAllOrderNumberAction" method="post">
				<input type="submit" value="设置订单状态">
				</form>
			</div>
		</td>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
				<form action="SelectFoodListAction" method="post">
				<input type="submit" value="查看店内食物">
				</form>
			</div>
		</td>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
				<input type="button" value="增加食物" onclick="window.open('addfood.jsp')">
			</div>
		</td>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
			    <form action="FindAllFoodNameAction" method="post">
			    <input type="hidden" name="hidden" value="deletefood">
				<input type="submit" value="删除食物">
				</form>
			</div>
		</td>						
	</tr>
	<tr bgcolor="#f3f3f3" height="25">
		<td bgcolor= "#f3f3f3">
			<div align="center">
				<form action="FindAllFoodNameAction" method="post">
			    <input type="hidden" name="hidden" value="updatefood">
				<input type="submit" value="修改食物">
				</form>
			</div>
		</td>						
	</tr>							                      
</table>
<p><a href="ownerlogin.jsp">返回登录</a>
</center>
</body>
</html>