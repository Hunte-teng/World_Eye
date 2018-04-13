package minilib.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.opensymphony.xwork2.ActionSupport;

import minilib.vo.Title;
import minilib.vo.BookType;
import minilib.util.DBUtil;

public class ManageTitlesDao  extends ActionSupport{
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private Title title;
	

	public void setTitle(Title title) {
		this.title = title;
	}

	public ManageTitlesDao() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	
	//添加Title
		public boolean addBook() throws Exception{
			//System.out.print(title.getBookid()+title.getTypeid()+title.getTitle()+title.getAuthors()+title.getPressid());
			try {
				//pst= con.prepareStatement("insert into t_book (typeid,title,authors) values('" + title.getTypeid()+ "','" + title.getTitle()+ "','" + title.getAuthors()+ "')");
				pst= con.prepareStatement("insert into t_book (typeid,isbn,title,authors,pressid) values(?,?,?,?,?)");
				pst.setString(1, title.getTypeid());
				pst.setString(2, title.getIsbn());
				pst.setString(3, title.getTitle());
				pst.setString(4, title.getAuthors());
				pst.setString(5, title.getPressid());
				if(pst.executeUpdate()==1){
					con.close();
					return true;
				}else{
					con.close();
					return false;
				}
				
			} catch (SQLException e) {
				System.out.print("增加图书失败");
				System.out.print(e.getMessage());
				return false;
			}
			
		}
	    //查找t_book所有
		public ArrayList<Title> findAllBooks() throws Exception{
			ArrayList<Title> list = new ArrayList<Title>();
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from t_book order by t_book.bookid");
				while(rs.next()) {
					Title title = new Title();
					title.setBookid(rs.getString(1));
					title.setTypeid(rs.getString(2));
					title.setIsbn(rs.getString(3));
					title.setTitle(rs.getString(5));
					title.setAuthors(rs.getString(6));
					title.setPressid(rs.getString(8));
					list.add(title);
				}
				
				con.close();
				
			}catch(SQLException e){
				System.out.println("查找失败");
			}
			return list;
		}
	    //查找code_booktype
		public ArrayList<BookType> findBookType() throws InstantiationException,IllegalAccessException,ClassNotFoundException,SQLException{
			ArrayList<BookType> list = new ArrayList<BookType>();
			//Connection conn = DBUtil.connectDB();
			//Statement stmt = conn.createStatement();
			//定义查询图书类别语句
			String strsql = "select codeid,codename from code_booktype order by codeid";
			//获取查询图书类别结果
			ResultSet rs = st.executeQuery(strsql);
			while(rs.next()) {
				BookType booktype = new BookType();
				booktype.setCodeid(rs.getString(1));
				booktype.setCodename(rs.getString(2));
				list.add(booktype);
			}
			rs.close();
			st.close();
			con.close();
			
			return list;
		}
	//模糊查询t_book
				public ArrayList<Title> fuzzyQuery(String context) throws Exception{
					ArrayList<Title> list = new ArrayList<Title>();
					try{
						st=con.createStatement();
						String strsql = "select ";
						strsql = strsql + "*";
						strsql = strsql + " from t_book where ";
						strsql = strsql + " typeid like '%" + context + "%'" ;
						strsql = strsql + " or isbn like '%" +context+ "%'" ;
						strsql = strsql + " or placeid like '%" +context+ "%'" ;
						strsql = strsql + " or title like '%" +context+ "%'" ;
						strsql = strsql + " or authors like '%" +context+ "%'" ;
						strsql = strsql + " or pressid like '%" +context+ "%'" ;
						rs=st.executeQuery(strsql);
						while(rs.next()) {
							Title title = new Title();
							title.setBookid(rs.getString(1));
							title.setTypeid(rs.getString(2));
							title.setIsbn(rs.getString(3));
							title.setTitle(rs.getString(5));
							title.setAuthors(rs.getString(6));
							title.setPressid(rs.getString(8));
							list.add(title);
						}
						
						con.close();
						
					}catch(SQLException e){
						System.out.println("查找失败");
						System.out.println(e.getMessage());
					}
					return list;
				}	
		//查找所有bookid
				public ArrayList<Title> allBookid() throws Exception{
					ArrayList<Title> allbookid = new ArrayList<Title>();
					try{
						st=con.createStatement();
						rs=st.executeQuery("select bookid from t_book order by t_book.bookid");
						while(rs.next()) {
							Title title = new Title();
							title.setBookid(rs.getString(1));
							allbookid.add(title);
						}
						
						con.close();
						
					}catch(SQLException e){
						System.out.println("查找失败");
					}
					return allbookid;
				}
}
