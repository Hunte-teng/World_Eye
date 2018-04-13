package mybean;

import java.sql.Connection;
import mybean.UserVO;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class UserDAO {
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private UserVO uservo; // 实体bean

	public void setUservo(UserVO uservo) {
		this.uservo = uservo;
	}

	public UserDAO() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	
	//注册
		public boolean userRegisterInsert() {
			try {
				pst= con.prepareStatement("insert into user  values(?,?,?,?)");
				pst.setString(1, uservo.getUsername());
				pst.setString(2, uservo.getPassword());
				pst.setString(3, uservo.getTelephone());
				pst.setString(4, uservo.getAddress());
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
				return false;
			}
			
		}
		//登录检测
		public UserVO userLoginFind(String name){
			UserVO uservo = new UserVO();
			String username;
			String password;
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from user where username ='"+name+"'");
				if(rs.next()) {
					username=rs.getString(1);
					password=rs.getString(2);
					uservo.setUsername(username);
					uservo.setPassword(password);
				}
				else {
					username = "**";
					password = "**";
					uservo.setUsername(username);
					uservo.setPassword(password);
				}
				rs.close();
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("登录失败");
			}
			return uservo;
		}
		//教师查询学生成绩单
		public UserVO getUser(String name){
			UserVO user = new UserVO();
			String username;
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from user where username ='"+name+"'");
				if(rs.next()) {
					username=rs.getString(1);
					String telephone=rs.getString(3);
					String address=rs.getString(4);
					user.setUsername(username);
					user.setTelephone(telephone);
					user.setAddress(address);
				}
				else {
					username = "**";
					user.setUsername(username);
				}
				rs.close();
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("成绩单查询失败");
			}
			return user;
		}
		/*//更新学生成绩单
				public void updateStudentScore(String studentname,String everychoice,String everyscore,int total){
					try{
						st=con.createStatement();
						String updateString = "update student set everychoice ='"+everychoice+"',everyscore ='"+everyscore+"',total ='"+total+"'  where studentname='"+studentname+"'";
						st.executeUpdate(updateString);
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("成绩单修改失败");
					}
				}
		//教师查询学生成绩单
				public StudentVO studentScore(String name){
					StudentVO stu = new StudentVO();
					String stuname;
					try{
						st=con.createStatement();
						rs=st.executeQuery("select * from student where studentname ='"+name+"'");
						if(rs.next()) {
							stuname=rs.getString(1);
							String stueverychoice=rs.getString(3);
							String stueveryscore=rs.getString(4);
							int stutotal=rs.getInt(5);
							stu.setStudentname(stuname);
							stu.setEverychoice(stueverychoice);
							stu.setEveryscore(stueveryscore);
							stu.setTotal(stutotal);
						}
						else {
							stuname = "**";
							stu.setStudentname(stuname);
						}
						rs.close();
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("成绩单查询失败");
					}
					return stu;
				}*/
}
