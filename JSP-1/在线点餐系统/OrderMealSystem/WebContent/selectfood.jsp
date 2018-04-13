<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.util.ArrayList" import="mybean.FoodVO" import="mybean.FoodDAO"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>食物清单</title>
</head>
<body>
<body background="images/背景3.jpg">
<%
    ArrayList<FoodVO> allfood = (ArrayList<FoodVO>)request.getAttribute("allfood");
    int n = allfood.size();//食物个数
    session.setAttribute("n",new Integer(n));
%>
<center>
<h3>食物清单</h3>
<table width="70%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td width="50%" bgcolor= "#fba661">
			<div align="center">
				招牌披萨
			</div>
		</td>
	    <td width="50%" bgcolor="#fba661">
			<div align="center">
				特色披萨
			</div>
		</td>								
	</tr>			                      
<%
    for(int i=0;i<n;i+=2)
    {
%>
	
		<tr bgcolor="#f3f3f3">
		    <td>
		        <div align="center">
		            <br>
		            <img src="images/<%=allfood.get(i).getImg() %>.jpg" width=200><br>
		            <%=allfood.get(i).getName() %>
		            &nbsp;&nbsp;<%=allfood.get(i).getPrice() %>/份
		            <br><br>
		        </div>
		    </td>
		    <td>
		        <div align="center">
		            <%
			        if(i+1==n && n%2!=0){
			        	out.print("");
			        }
			        else{
			        %>
			            <img src="images/<%=allfood.get(i+1).getImg() %>.jpg" width=200><br>
			            <input type="checkbox" name="food" value="<%=allfood.get(i+1).getName() %>"><%=allfood.get(i+1).getName() %>
			            &nbsp;&nbsp;<%=allfood.get(i+1).getPrice() %>/份
			        <%
			        }
			        %>
		        </div>
		    </td>
		</tr>
<%		
    }

%>
</table>
<p><input type="button" value="返回功能菜单" onclick="window.open('ownerfunction.jsp')">
</center>
</body>
</html>