<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="minilib.vo.Record" import="java.util.ArrayList"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>查询借阅</title>
</head>
<body background="../images/背景3.jpg">
<center>
<%
ArrayList<Record> list = (ArrayList<Record>)request.getAttribute("list"); 
 %>
<form method="post" action="addBorrowManageTAction.action">
<h3>借阅记录</h3>
<table width="100%" border="0" cellspacing="1" cellpadding="0" class="">
	<tr bgcolor="#fba661" height="25">
		<td width="25%" bgcolor= "#fba661">
			<div align="center">
				用户ID
			</div>
		</td>
		<td width="25%" bgcolor= "#fba661">
			<div align="center">
				图书ID
			</div>
		</td>
		<td width="25%" bgcolor= "#fba661">
			<div align="center">
				借书日期
			</div>
		</td>
		<td width="25%" bgcolor= "#fba661">
			<div align="center">
				还书日期
			</div>
		</td>
	</tr>
<%
for(int i=0;i<list.size();i++){
%>
    <tr bgcolor="#fba661" height="25">
        <td width="25%" bgcolor= "#f3f3f3">
		    <div align="center">
			    <%=list.get(i).getUserid() %>
		    </div>
	    </td>
	    <td width="25%" bgcolor= "#f3f3f3">
		    <div align="center">
			    <%=list.get(i).getBookid() %>
		    </div>
	    </td>
	    <td width="25%" bgcolor= "#f3f3f3">
		    <div align="center">
			    <%=list.get(i).getBorrowdate() %>
		    </div>
	    </td>
	    <td width="25%" bgcolor= "#f3f3f3">
		    <div align="center">
			    <%=list.get(i).getReturndate() %>
		    </div>
	    </td>
	</tr>
<%
}
%>
</table>
</form>
 </center>
</body>
</html>