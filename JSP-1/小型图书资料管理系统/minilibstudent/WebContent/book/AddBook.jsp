<%@ page language="java" contentType="text/html; charset=UTF-8"
	import="java.util.*" import="java.util.ArrayList" import="minilib.vo.BookType" import="minilib.vo.Press"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>增加图书</title>
</head>
<body background="../images/背景3.jpg">
<%
ArrayList<BookType> booktypelist = (ArrayList<BookType>)request.getAttribute("booktypelist"); 
ArrayList<Press> presslist = (ArrayList<Press>)request.getAttribute("presslist"); 
%>
<center>
<form method="post" action="addTitleManageTitlesAction.action">
<h3>增加图书</h3>
<table width="50%" border="0" cellspacing="1" cellpadding="0" class="">
			                      <tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												图书类型
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<select name="book.typeid" id="typeid">
													<%
													for(int i=0;i<booktypelist.size();i++)
													{
													%>
														<option value="<%=booktypelist.get(i).getCodeid() %>"><%=booktypelist.get(i).getCodename() %> </option>
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
												ISBN
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="book.isbn" value="ISBN">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												书名
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="book.title" value="书名">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												作者
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<input type="text" name="book.authors" value="作者">
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									<tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												出版社
											</div>
										</td>
										<td width="10%" bgcolor= "#f3f3f3">
											<div align="center">
												<select name="book.pressid" id="pressid">
													<%
													for(int i=0;i<presslist.size();i++)
													{
													%>
														<option value="<%=presslist.get(i).getCodeid() %>"><%=presslist.get(i).getCodename() %> </option>
													<%
													}
													%>
													</select>
												<img src="../images/笔.gif" width=40>
											</div>
										</td>
									</tr>
									</table>

<br>
<input type="submit" name = "sumbit" value = "增加图书">
</form>
<%
if(request.getAttribute("message")==null){
	out.print("");
}
else{
	out.print(request.getAttribute("message"));
}
 %>
 </center>
</body>
</html>