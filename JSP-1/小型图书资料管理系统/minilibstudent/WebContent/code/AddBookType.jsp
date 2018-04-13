<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>增加图书分类</title>
</head>
<body background="../images/背景3.jpg">
<center>
<%
if(request.getAttribute("message")==null){
	out.print("");
}
else{
	out.print(request.getAttribute("message"));
}
%>
<form action="addBookTypeManageCodeAction.action" method="post">

<h3>增加图书分类</h3>
<table width="50%" border="0" cellspacing="1" cellpadding="0" class="">
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												图书类型ID
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="booktype.codeid">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												图书类型名称
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="booktype.codename">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												图书类型
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="booktype.codetype">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									</table>
<p><input type="submit"	value="添加">
</form>
</center>
</body>
</html>