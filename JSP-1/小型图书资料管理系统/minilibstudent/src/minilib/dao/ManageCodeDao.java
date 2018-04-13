package minilib.dao;

import java.sql.SQLException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.opensymphony.xwork2.ActionSupport;

import minilib.vo.Press;
import minilib.vo.BookType;
import minilib.util.DBUtil;

public class ManageCodeDao  extends ActionSupport{
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private Press press;
    private BookType booktype;

	public void setPress(Press press) {
		this.press = press;
	}
	
	public void setBooktype(BookType booktype) {
		this.booktype = booktype;
	}

	public ManageCodeDao() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	//添加press
	public boolean pressAddInsert()  throws Exception{
		try {
			pst= con.prepareStatement("insert into code_press (codeid,codename,codetype)  values(?,?,?)");
			pst.setString(1, press.getCodeid());
			pst.setString(2, press.getCodename());
			pst.setString(3, press.getCodetype());
			if(pst.executeUpdate()==1){
				pst.close();
				con.close();
				return true;
			}else{
				pst.close();
				con.close();
				return false;
			}
			
		} catch (SQLException e) {
			System.out.print("增加出版社失败");
			return false;
		}
		
	}
	
	//查找press
	public Press pressQuery(String name) throws Exception{
		Press press1 = new Press();
		String codename;
		try{
			st=con.createStatement();
			rs=st.executeQuery("select * from code_press where codename ='"+name+"'");
			if(rs.next()) {
				String codeid = rs.getString(1);
				codename = rs.getString(2);
				String codetype = rs.getString(3);
				press1.setCodeid(codeid);
				press1.setCodename(codename);
				press1.setCodetype(codetype);
			}
			rs.close();
			st.close();
			con.close();
			
		}catch(SQLException e){
			System.out.println("出版社查询失败");
		}
		return press1;
	}
	//查找allpress
		public ArrayList<Press> allpressQuery() throws Exception{
			ArrayList<Press> allpress = new ArrayList<Press>();
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from code_press");
				while(rs.next()) {
					String codeid = rs.getString(1);
					String codename = rs.getString(2);
					String codetype = rs.getString(3);
					Press press1 = new Press();
					press1.setCodeid(codeid);
					press1.setCodename(codename);
					press1.setCodetype(codetype);
					allpress.add(press1);
				}
				rs.close();
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("出版社查询失败");
			}
			return allpress;
		}
	//添加booktype
		public boolean bookTypeAddInsert()  throws Exception{
			try {
				pst= con.prepareStatement("insert into code_booktype (codeid,codename,codetype)  values(?,?,?)");
				pst.setString(1, booktype.getCodeid());
				pst.setString(2, booktype.getCodename());
				pst.setString(3, booktype.getCodetype());
				if(pst.executeUpdate()==1){
					pst.close();
					con.close();
					return true;
				}else{
					pst.close();
					con.close();
					return false;
				}
				
			} catch (SQLException e) {
				System.out.print("增加图书类型失败");
				return false;
			}
			
		}
	//查找booktype
		public BookType bookTypeQuery(String name) throws Exception{
			BookType booktype1 = new BookType();
			String codename;
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from code_booktype where codename ='"+name+"'");
				if(rs.next()) {
					String codeid = rs.getString(1);
					codename = rs.getString(2);
					String codetype = rs.getString(3);
					booktype1.setCodeid(codeid);
					booktype1.setCodename(codename);
					booktype1.setCodetype(codetype);
				}
				rs.close();
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("图书类型查询失败");
			}
			return booktype1;
		}
	//查找所有booktype
				public ArrayList<BookType> findBookType() throws Exception{
					ArrayList<BookType> list = new ArrayList<BookType>();
					try{
						st=con.createStatement();
						rs=st.executeQuery("select * from code_booktype");
						while(rs.next()) {
							String codeid = rs.getString(1);
							String codename = rs.getString(2);
							String codetype = rs.getString(3);
							BookType booktype1 = new BookType();
							booktype1.setCodeid(codeid);
							booktype1.setCodename(codename);
							booktype1.setCodetype(codetype);
							list.add(booktype1);
						}
						rs.close();
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("图书类型查询失败");
					}
					return list;
				}

}
