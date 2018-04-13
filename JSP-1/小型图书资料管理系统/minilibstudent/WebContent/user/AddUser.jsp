<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body background="../images/背景3.jpg">
<center>
<form action="addUserManageUserAction.action" method="post">
<!-- <h3><font size="5">增加用户</font></h3>
<p>用户ID：<input type="text" name="user.userid">
<p>用户名：<input type="text" name="user.name">
<p>性&nbsp;&nbsp;&nbsp;别：<input type="text" name="user.sexid">
<p>年&nbsp;&nbsp;&nbsp;级：<input type="text" name="user.deptid">
<p>身&nbsp;&nbsp;&nbsp;份：<input type="text" name="user.typeid">
<p>密&nbsp;&nbsp;&nbsp;码：<input type="password" name="user.password">
<p><input type="submit" value="注册">
</form> -->
<%
if(request.getAttribute("message")==null){
	out.print("");
}
else{
	out.print(request.getAttribute("message"));
}
%>
 <h3>增加用户</h3>
<table width="50%" border="0" cellspacing="1" cellpadding="0" class="">
			                      <tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												用户ID
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="user.userid">
													<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												用户名
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="user.name">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												密码
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="password" name="user.password">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												性别
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<select name="user.sexid">
														<option value="1">男</option>
														<option value="2">女</option>
													</select>
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												身份
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<select name="user.typeid">
														<option value="1">管理员</option>
														<option value="2">读者</option>
													</select>
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									</table>
<br>
<input type="submit" name = "sumbit" value = "注册">


</form>
</center>
</body>
</html>