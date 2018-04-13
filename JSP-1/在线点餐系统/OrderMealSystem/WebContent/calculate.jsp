<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"  import="java.util.ArrayList" import="mybean.FoodVO" import="mybean.UserVO"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>结账</title>
</head>
<body background="images/背景3.jpg">
<%
ArrayList<FoodVO> myfood = (ArrayList<FoodVO>)session.getAttribute("myfood");//食物名称、类型、价格、数量
int total= Integer.parseInt(session.getAttribute("total").toString());//总价
//String total= (String)session.getAttribute("total");//总价
UserVO uservo = new UserVO();
uservo = (UserVO)session.getAttribute("uservo");
%>
<center>
<form action="OrderAction" method="post">
<h2>尊敬的<%=uservo.getUsername() %>用户，您的订单如下：</h2>
<table width="70%" border="0" cellspacing="1" cellpadding="0" class="">
    <tr bgcolor="#fba661" height="25">
		<td width="34%" bgcolor= "#fba661">
			<div align="center">
				食物名称
			</div>
		</td>
		<td width="33%" bgcolor="#fba661">
			<div align="center">
				单价
			</div>
		</td>
		<td width="33%" bgcolor="#fba661">
			<div align="center">
				数量
			</div>
		</td>								
	</tr>			                      
<%
    for(int i=0;i<myfood.size();i++)
    {
%>
	
		<tr bgcolor="#f3f3f3">
		    <td>
		        <div align="center">
		            <%=myfood.get(i).getName() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%=myfood.get(i).getPrice() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">	
		            <%="*"+myfood.get(i).getNumber() %>
		        </div>
		    </td>
		</tr>
<%		
    }

%>
        <tr>
            <td>
		        <div align="center">
		                                          订餐电话：<%=uservo.getTelephone() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">
		                                          订餐地址：<%=uservo.getAddress() %>
		        </div>
		    </td>
		    <td>
		        <div align="center">
		                                          总价：<%=session.getAttribute("total") %>元
		        </div>
		    </td>
        </tr>
</table>
<p>备注：<input type="text" name="remark">
<p><input type="submit" value="提交订单">&nbsp;&nbsp;<input type="button" value="取消订单" onclick="window.open('order.jsp')">
</form>
</center>
</body>
</html>