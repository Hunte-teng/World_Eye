<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="minilib.vo.Press"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>出版社查询结果</title>
</head>
<body>
<%
Press press = (Press)request.getAttribute("press1");
%>
<table width="100%" border="0" cellspacing="1" cellpadding="0" class="">
			                      <tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												出版社编号
											</div>
										</td>
										<td width="13%" bgcolor="#fba661">
											<div align="center">
												出版社书名
											</div>
										</td>
										<td width="12%" bgcolor="#fba661">
											<div align="center">
												出版社类别
											</div>
										</td>
									
									</tr>	
	<tr bgcolor="#f3f3f3" height="25">
			    <td width="10%">
			        <div align="center">
			            <%=press.getCodeid() %>
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            <%=press.getCodename() %>
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            <%=press.getCodetype() %>
			        </div>
			    </td>
			</tr>	
</table>
</body>
</html>