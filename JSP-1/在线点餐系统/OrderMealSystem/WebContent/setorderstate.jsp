<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.OrderVO" import="java.util.ArrayList"%>
    <%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>设置订单状态</title>
</head>
<body background="images/背景3.jpg">
<%
ArrayList<OrderVO> allorder = (ArrayList<OrderVO>)request.getAttribute("allorder");
%>
<center>
<form action="SetOrderStateAction" method="post">
<h2>修改订单状态</h2>
<table width="60%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661" width="50%">
			<div align="center">
				请输入需要设置的订单号
			</div>
		</td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				<select name="ordernumber">
				<%
				    for(int i=0;i<allorder.size();i++){
				%>
				    <option value="<%=allorder.get(i).getOrdernum() %>"><%=allorder.get(i).getOrdernum() %></option>
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
				请输入需要设置的订单状态
			</div>
		</td>
		<td bgcolor="#f3f3f3">
			<div align="center">
				 <select name="state">
				    <option value="接单">接单</option>
				    <option value="配餐中">配餐中</option>
				    <option value="送货中">送货中</option>
				    <option value="送达">送达</option>
                 </select>
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