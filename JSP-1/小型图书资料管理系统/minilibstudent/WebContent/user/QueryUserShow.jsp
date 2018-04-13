<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="minilib.vo.User"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>用户查询结果</title>
</head>
<body>
<%
User user = (User)request.getAttribute("user1");
%>
<table width="100%" border="0" cellspacing="1" cellpadding="0" class="">
			                      <tr bgcolor="#fba661" height="25">
				                        <td width="10%" bgcolor= "#fba661">
											<div align="center">
												用户ID
											</div>
										</td>
										<td width="13%" bgcolor="#fba661">
											<div align="center">
												用户名
											</div>
										</td>
										<td width="12%" bgcolor="#fba661">
											<div align="center">
												性别
											</div>
										</td>
										<td width="13%" bgcolor="#fba661">
											<div align="center">
												年级
											</div>
									
										</td>
										<td width="13%" bgcolor="#fba661">
											<div align="center">
												身份
											</div>
									
										</td>
									
									</tr>	
	<tr bgcolor="#f3f3f3" height="25">
			    <td width="10%">
			        <div align="center">
			            <%=user.getUserid() %>
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            <%=user.getName() %>
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            <%=user.getSexid() %>
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            <%=user.getDeptid() %>
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            <%=user.getTypeid() %>
			        </div>
			    </td>
			</tr>	
</table>
</body>
</html>