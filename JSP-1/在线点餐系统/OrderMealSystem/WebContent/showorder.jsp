<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="mybean.OrderDAO" import="mybean.OrderVO" import="java.util.ArrayList"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>订单列表</title>
</head>
<body background="images/背景3.jpg">
<%
ArrayList<OrderVO> allorder = (ArrayList<OrderVO>)request.getAttribute("allorder");
%>
<center>
<form action="CalculaterAction" method="post">
<h2>订单列表</h2>
<table width="100%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td bgcolor= "#fba661">
			<div align="center">
				订单号
			</div>
		</td>
		<td bgcolor="#fba661">
			<div align="center">
				订单详情
			</div>
		</td>
		<td bgcolor="#fba661">
			<div align="center">
				总价
			</div>
		</td>
		<td bgcolor="#fba661">
			<div align="center">
				备注
			</div>
		</td>
		<td bgcolor="#fba661">
			<div align="center">
				用户名
			</div>
		</td>
		<td bgcolor="#fba661">
			<div align="center">
				电话
			</div>
		</td>
		<td bgcolor="#fba661">
			<div align="center">
				地址
			</div>
		</td>	
		<td bgcolor="#fba661">
			<div align="center">
				订单状态
			</div>
		</td>							
	</tr>			                      
<%
    for(int i=0;i<allorder.size();i++)
    {
%>
	
		<tr bgcolor="#f3f3f3">
		    <td>
		        <div align="center">
		            <%=allorder.get(i).getOrdernum() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%=allorder.get(i).getFoodimformation() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%=allorder.get(i).getTotal() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%=allorder.get(i).getRemark() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%=allorder.get(i).getUsername() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%=allorder.get(i).getTelephone() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%=allorder.get(i).getAddress() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%=allorder.get(i).getState() %>
		        </div>
		    </td>
		</tr>
<%	
    }
%>
</table>
<p><input type="button" value="返回功能界面" onclick="window.open('ownerfunction.jsp')">
</form>
</center>
</body>
</html>