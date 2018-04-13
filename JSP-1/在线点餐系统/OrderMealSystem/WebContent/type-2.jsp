<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList" import="mybean.FoodVO" import="mybean.FoodDAO"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>饮品</title>
</head>
<body background="images/背景3.jpg">
<%
    ArrayList<FoodVO> allfood = (ArrayList<FoodVO>)request.getAttribute("allfood");
    int n = allfood.size();//食物个数
    ArrayList<FoodVO> type2 = new ArrayList<FoodVO>();
    for(int i=0;i<n;i++)
    {
	    if(allfood.get(i).getType().equals("饮品") || allfood.get(i).getType().equals("yp"))
	    	type2.add(allfood.get(i));
    }
    int n1 = type2.size();
%>
<center>
<form action="CartManageAction" method="post">
<table width="70%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td width="50%" bgcolor= "#fba661">
			<div align="center">
				食物类型
			</div>
		</td>
	    <td width="50%" bgcolor="#fba661">
			<div align="center">
				食物名称
			</div>
		</td>								
	</tr>			                      
<%
    for(int i=0;i<n1;i+=2)
    {
%>
	
		<tr bgcolor="#f3f3f3">
		    <td>
		        <div align="center">
		            <br>
		            <img src="images/<%=type2.get(i).getImg() %>.jpg"  width=200><br>
		            <input type="checkbox" name="food" value="<%=type2.get(i).getName() %>"><%=type2.get(i).getName() %>
		            &nbsp;&nbsp;<%=type2.get(i).getPrice() %>/杯
		            <br><br>
		        </div>
		    </td>
		    <td>
		        <div align="center">
		            <br><br>
		            <%
			        if(i+1==n1 && n1%2!=0){
			        	out.print("");
			        }
			        else{
			        %>
			            <img src="images/<%=type2.get(i+1).getImg() %>.jpg" width=200><br>
			            <input type="checkbox" name="food" value="<%=type2.get(i+1).getName() %>"><%=type2.get(i+1).getName() %>
			            &nbsp;&nbsp;<%=type2.get(i+1).getPrice() %>/杯
			        <%
			        }
			        %>
		            <br>
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