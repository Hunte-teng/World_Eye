<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList" import="mybean.FoodVO" import="mybean.FoodDAO"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>查询食物</title>
</head>
<body  background="images/背景3.jpg">
<%
ArrayList<FoodVO> allfood = (ArrayList<FoodVO>)request.getAttribute("allfood");
int n = allfood.size();//食物个数
session.setAttribute("n",new Integer(n));
%>
<center>
<h1>查询</h1>

<table width="50%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				输入关键字查询
			</div>
		</td>
		<td bgcolor= "#f3f3f3">
		        <div align="center">
		            <form action="FuzzyQueryAction" method="post">
					<input type="text" name="keyword" value="请输入关键字">
					<p><input type="submit" value="查询">
					</form>
		        </div>
		    </td>
	</tr>
	<tr>
		<td bgcolor="#fba661">
			<div align="center">
				按食物名称查询
			</div>
		</td>
		<td bgcolor= "#f3f3f3">
		        <div align="center">	
		            <form action="FindFoodNameAction" method="post">
					<select name= foodname >
					<%
					for(int i=0;i<n;i++)
					{
					%>
					    <option value="<%=allfood.get(i).getName() %>"><%=allfood.get(i).getName() %></option>
					<%
					}
					%>
					</select>
					<p><input type="submit" value="查询">
					</form>
		        </div>
		    </td>
	</tr>
	<tr>
		<td bgcolor="#fba661">
			<div align="center">
				按食物价格查询
			</div>
		</td>
		<td bgcolor= "#f3f3f3">
		<div align="center">	
		     <form action="FindFoodPriceAction" method="post">
			
			<select name= foodprice1 >
			<%
			for(int i=0;i<100;i++)
			{
			%>
			    <option value="<%=i %>"><%=i %></option>
			<%
			}
			%>
			</select>
			-
			<select name= foodprice2>
			<%
			for(int i=0;i<100;i++)
			{
			%>
			    <option value="<%=i %>"><%=i %></option>
			<%
			}
			%>
			</select>
			<p><input type="submit" value="查询">
		</div>
		</td>
    </tr>			                      
</table>
<p><a href="order.jsp">返回功能菜单</a>
</center>
</body>
</html>