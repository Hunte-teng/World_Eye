<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>查询图书</title>
</head>
<body background="../images/背景3.jpg">
<center>
<h3>查询图书</h3>
<table width="50%" border="0" cellspacing="1" cellpadding="0" class="">
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												输入关键字查询
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
											    <form action="fuzzyQueryTitleManageTitlesAction.action" method="post">
												<input type="text" name="context" value="请输入关键字">
												<img src="../images/笔.gif" width=40>
												<input type="submit" name="submit" value="查询">
												</form>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												查询所有图书
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
											    <form method="post" action="queryTitleManageTitlesAction.action">
												<input type="submit" name="submit" value="查询所有图书">
												<img src="../images/笔.gif" width=40>
												</form>
											</div>
										</td>
									</tr>
									</table>
</center>
<%
session.setAttribute("pages", "0");
%>
</body>
</html>