<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.FoodVO" import="java.util.ArrayList"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>查询结果</title>
</head>
<body background="images/背景3.jpg">
<%
	ArrayList<FoodVO> list = (ArrayList<FoodVO>)session.getAttribute("list");
%>
<center>
<form action="CartManageAction" method="post">
<table width="70%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td width="50%" bgcolor= "#fba661">
			<div align="center">
				查询结果
			</div>
		</td>								
	</tr>			                      
<%
    for(int i=0;i<list.size();i++)
    {
%>
	
		<tr bgcolor="#f3f3f3">
		    <td>
		        <div align="center">
		            <br>
		            <img src="images/<%=list.get(i).getImg() %>.jpg" width=200><br>
		            <input type="checkbox" name="food" value="<%=list.get(i).getName() %>"><%=list.get(i).getName() %>
		            &nbsp;&nbsp;<%=list.get(i).getPrice() %>/份
		            <br><br>
		        </div>
		    </td>
		</tr>
<%		
    }

%>
</table>
<p><input type="submit" value="加入购物车">&nbsp;&nbsp;<input type="button" value="查看购物车" onclick="window.open('cart.jsp')">
&nbsp;&nbsp;<input type="button" value="返回" onclick="window.open('order.jsp')">
</form>
</center>
</body>
</html>