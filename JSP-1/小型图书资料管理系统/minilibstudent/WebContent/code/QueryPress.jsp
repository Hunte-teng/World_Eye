<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>查询出版社</title>
</head>
<body background="../images/背景3.jpg">
<center>
<form action="queryPressManageCodeAction.action" method="post">
<h3>查询出版社</h3>
<table width="50%" border="0" cellspacing="1" cellpadding="0" class="">
			                      <tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												请输入要查询的出版社名字
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="press.codename">
													<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									</table>
<input type="submit" name = "sumbit" value = "查询">
</form>
</center>
</body>
</html>