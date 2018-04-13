<%@ page language="java" contentType="text/html; charset=UTF-8"
	import = "java.util.*" import="minilib.vo.Title"
    pageEncoding="UTF-8"%>
<%@ taglib prefix = "c" uri="http://java.sun.com/jstl/core_rt" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>图书列表</title>
</head>
<body>
<%
String flag;
String pages;
int pn = 18;
if(request.getParameter("flag")!=null){
	flag = request.getParameter("flag");
}
else{
	flag = "1";
}
ArrayList<Title> allTitlelist = new ArrayList<Title>();
if(request.getAttribute("allTitlelist")!=null){
	allTitlelist = (ArrayList<Title>)request.getAttribute("allTitlelist");
	session.setAttribute("allTitlelist", allTitlelist);
}
else{
	allTitlelist = (ArrayList<Title>)session.getAttribute("allTitlelist");
}
if(allTitlelist.size()==0) {
	out.print("<center>"+"查到0条结果"+"</center>");
}
else{
	//flag=1表示向下翻页
	if(flag.equals("1")){
%>
		<form action="QueryBookResults.jsp" method="post">
		<table width="100%" border="0" cellspacing="1" cellpadding="0" class="">
			<tr bgcolor="#fba661" height="25">
				<td width="10%" bgcolor= "#fba661">
					<div align="center">
						ISBN
					</div>
				</td>
				<td width="13%" bgcolor="#fba661">
					<div align="center">
						书名
					</div>
				</td>
				<td width="12%" bgcolor="#fba661">
					<div align="center">
						作者
					</div>
				</td>
				<td width="13%" bgcolor="#fba661">
					<div align="center">
						出版社
					</div>
				</td>
			</tr>	
		<%
		pages = (String)session.getAttribute("pages");
		int n = Integer.parseInt(pages);
		for(int i=n;i<n+18;i++)
		{
			
		%>
			<tr bgcolor="#f3f3f3" height="25">
				<td width="10%">
					<div align="center">
					     <%=allTitlelist.get(i).getIsbn() %>
					</div>
				</td>
				<td width="12%">
					<div align="center">
					    <%=allTitlelist.get(i).getTitle() %>
					</div>
				</td>
				<td width="12%">
					<div align="center">
					    <%=allTitlelist.get(i).getAuthors() %>
					</div>
				</td>
				<td width="12%">
					<div align="center">
					    <%=allTitlelist.get(i).getPressid() %>
					</div>
				</td>
			</tr>
        <%
        }
        %>						
        </table>
        <%
        pn = n+18;
        session.setAttribute("pages", String.valueOf(n+18));
	}
    
	//flag=-1表示向上翻页
	else{
		%>
		<form action="QueryBookResults.jsp" method="post">
		<table width="100%" border="0" cellspacing="1" cellpadding="0" class="">
			<tr bgcolor="#fba661" height="25">
				<td width="10%" bgcolor= "#fba661">
					<div align="center">
						ISBN
					</div>
				</td>
				<td width="13%" bgcolor="#fba661">
					<div align="center">
						书名
					</div>
				</td>
				<td width="12%" bgcolor="#fba661">
					<div align="center">
						作者
					</div>
				</td>
				<td width="13%" bgcolor="#fba661">
					<div align="center">
						出版社
					</div>
				</td>
			</tr>	
		<%
		pages = (String)session.getAttribute("pages");
		int n = Integer.parseInt(pages);
		//if(n-18>0){
		for(int i=n-36;i<n-18;i++)
		{
			
		%>
			<tr bgcolor="#f3f3f3" height="25">
				<td width="10%">
					<div align="center">
					     <%=allTitlelist.get(i).getIsbn() %>
					</div>
				</td>
				<td width="12%">
					<div align="center">
					    <%=allTitlelist.get(i).getTitle() %>
					</div>
				</td>
				<td width="12%">
					<div align="center">
					    <%=allTitlelist.get(i).getAuthors() %>
					</div>
				</td>
				<td width="12%">
					<div align="center">
					    <%=allTitlelist.get(i).getPressid() %>
					</div>
				</td>
			</tr>
		<%
		}
		%>						
		</table>
		<%
		pn = n-18;
		session.setAttribute("pages", String.valueOf(n-18));
		}
	//}
}
%>
<p><center><a href="QueryBookResults.jsp?flag=-1">上一页</a><%out.print("   第"+pn/18+"页         "); %><a href="QueryBookResults.jsp?flag=1">下一页</a></center>
</form>
</body>
</html>






<%-- <c:forEach items = "${requestScope.allTitleslist }" var = "title" varStatus="status"> 	
	<tr bgcolor="#f3f3f3" height="25">
			    <td width="10%">
			        <div align="center">
			            ${title.isbn}
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            ${title.title}
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            ${title.authors}
			        </div>
			    </td>
			    <td width="12%">
			        <div align="center">
			            ${title.pressid}
			        </div>
			    </td>
			</tr>		
		
		
		</c:forEach> --%>