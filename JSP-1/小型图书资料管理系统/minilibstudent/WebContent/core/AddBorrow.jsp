<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="minilib.vo.*" import="java.util.ArrayList"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>添加借阅</title>
</head>
<body  background="../images/背景3.jpg">
<center>
<%
if(request.getAttribute("message")==null){
	out.print("");
}
else{
	out.print(request.getAttribute("message"));
}
ArrayList<User> alluserid = (ArrayList<User>)request.getAttribute("alluserid"); 
ArrayList<Title> allbookid = (ArrayList<Title>)request.getAttribute("allbookid"); 
 %>
<form method="post" action="addBorrowManageTAction.action">
<h3>借阅图书</h3>
<table width="50%" border="0" cellspacing="1" cellpadding="0" class="">
			                      <tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												用户ID
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<select name="record.userid" id="typeid">
													<%
													for(int i=0;i<alluserid.size();i++)
													{
													%>
														<option value="<%=alluserid.get(i).getUserid() %>"><%=alluserid.get(i).getUserid() %> </option>
													<%
													}
													%>
													</select>
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												图书ID
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<select name="record.bookid" id="typeid">
													<%
													for(int i=0;i<allbookid.size();i++)
													{
													%>
														<option value="<%=allbookid.get(i).getBookid() %>"><%=allbookid.get(i).getBookid() %> </option>
													<%
													}
													%>
													</select>
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												借阅日期
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="record.borrowdate" value="请输入借阅日期">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												还书日期
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="record.returndate" value="请输入还书日期">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									</table>

<br>
<input type="submit" name = "sumbit" value = "借阅">
</form>
 </center>
</body>
</html>