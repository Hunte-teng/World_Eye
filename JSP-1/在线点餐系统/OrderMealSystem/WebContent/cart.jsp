<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList"%>
<%request.setCharacterEncoding("UTF-8"); %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>购物车</title>
</head>
<body background="images/背景3.jpg">
<%
ArrayList<String> mycart = (ArrayList<String>)session.getAttribute("mycart");
String []number = new String[mycart.size()];
%>
<center>
<form action="CalculaterAction" method="post">
<h2>购物车</h2>
<table width="70%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td width="34%" bgcolor= "#fba661">
			<div align="center">
				食物名称
			</div>
		</td>
		<td width="33%" bgcolor="#fba661">
			<div align="center">
				数量
			</div>
		</td>								
	</tr>			                      
<%
    for(int i=0;i<mycart.size();i++)
    {
%>
	
		<tr bgcolor="#f3f3f3">
		    <td>
		        <div align="center">
		            <%=new String(mycart.get(i).getBytes("ISO-8859-1"),"UTF-8")%>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		        <%="*" %>	      
		            <select name="<%=i %>">
		            <option value="0"> 0</option>
		            <option value="1" selected> 1</option>
		            <option value="2"> 2</option>
		            <option value="3"> 3</option>
		            <option value="4"> 4</option>
		            <option value="5"> 5</option>
		            <option value="6"> 6</option>
		            <option value="7"> 7</option>
		            <option value="8"> 8</option>
		            <option value="9"> 9</option>
		            <option value="10"> 10</option>
		            </select>
		        </div>
		    </td>
		</tr>
<%	
	number[i] = Integer.toString(i);
    }

	session.setAttribute("number", number);
%>
</table>
<p><input type="submit" value="去结算">&nbsp;&nbsp;<input type="button" value="继续添加" onclick="window.open('order.jsp')">
</form>

</center>
</body>
</html>