package minilib.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import com.opensymphony.xwork2.ActionSupport;

import minilib.vo.User;
import minilib.util.DBUtil;

public class ManageUserDao   extends ActionSupport{
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private User user;
	
	
	public void setUser(User user) {
		this.user = user;
	}

	public ManageUserDao() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	//注册
			public boolean userAddInsert()  throws Exception{
				System.out.print(user.getUserid()+user.getName()+user.getDeptid());
				try {
					/*pst= con.prepareStatement("insert into t_user (userid,name,password)  values('"+Integer.parseInt(user.getUserid())+"',"
							+ "'"+user.getName()+"',"
									+ "'"+user.getPassword()+"')");*/
					pst= con.prepareStatement("insert into t_user (userid,name,sexid,typeid,password) values(?,?,?,?,?)");
					pst.setString(1, user.getUserid());
					pst.setString(2, user.getName());
					pst.setString(3, user.getSexid());
					pst.setString(4, user.getTypeid());
					pst.setString(5, user.getPassword());
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
					System.out.print("注册失败");
					System.out.println(e.getMessage());
					return false;
				}
				
			}
	//user登录
			public User userLogin(String name) throws Exception{
				User user1 = new User();
				String username;
				try{
					st=con.createStatement();
					rs=st.executeQuery("select userid,password from t_user where name ='"+name+"'");
					if(rs.next()) {
						String userid = rs.getString(1);
						String password = rs.getString(2);
						user1.setUserid(userid);
						user1.setPassword(password);
					}
					else {
						String password = "**";//密码不能设置为**
						user1.setPassword(password);
					}
					rs.close();
					st.close();
					con.close();
					
				}catch(SQLException e){
					System.out.println("登录失败");
				}
				return user1;
			}
	//查找user
			public User userFind(String name) throws Exception{
				User user1 = new User();
				String username;
				try{
					st=con.createStatement();
					rs=st.executeQuery("select * from t_user where name ='"+name+"'");
					if(rs.next()) {
						int userid = rs.getInt(1);
						username = rs.getString(3);
						String sexid = rs.getString(4);
						String deptid = rs.getString(6);
						String typeid = rs.getString(8);
						user1.setUserid(Integer.toString(userid));
						user1.setName(username);				
						user1.setSexid(sexid);
						user1.setDeptid(deptid);
						user1.setTypeid(typeid);
					}
					else {
						int userid = 0000;
						username = "**";
						String sexid = "**";
						String deptid = "**";
						String typeid = "**";
						user1.setUserid(Integer.toString(userid));
						user1.setName(username);				
						user1.setSexid(sexid);
						user1.setDeptid(deptid);
						user1.setTypeid(typeid);
					}
					rs.close();
					st.close();
					con.close();
					
				}catch(SQLException e){
					System.out.println("登录失败");
				}
				return user1;
			}
	//查找userID
			public ArrayList<User> userID() throws Exception{
				ArrayList<User> alluserid = new ArrayList<User>();
				try{
					st=con.createStatement();
					rs=st.executeQuery("select userid from t_user where typeid=2");
					while(rs.next()) {
						int userid = rs.getInt(1);
						User user1 = new User();
						user1.setUserid(Integer.toString(userid));
						alluserid.add(user1);
					}
					rs.close();
					st.close();
					con.close();
					
				}catch(SQLException e){
					System.out.println("查询用户ID失败");
				}
				return alluserid;
			}

}
