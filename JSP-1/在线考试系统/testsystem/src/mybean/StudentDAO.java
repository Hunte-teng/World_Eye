package mybean;

import java.sql.Connection;
import mybean.StudentVO;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class StudentDAO {
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private StudentVO studentvo; // 实体bean

	public void setStudentvo(StudentVO studentvo) {
		this.studentvo = studentvo;
	}

	public StudentDAO() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	
	//注册
		public boolean studentLoginInsert() {
			try {
				pst= con.prepareStatement("insert into student (number,studentname,studentpass) values(?,?,?)");
				pst.setString(1, studentvo.getNumber());
				pst.setString(2, studentvo.getStudentname());
				pst.setString(3, studentvo.getStudentpass());
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
	//查找
		//查找
		public StudentVO studentLoginFind(String name){
			StudentVO stu = new StudentVO();
			String stuname;
			String stupass;
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from student where studentname ='"+name+"'");
				if(rs.next()) {
					stuname=rs.getString(2);
					stupass=rs.getString(3);
					stu.setStudentname(stuname);
					stu.setStudentpass(stupass);
				}
				else {
					stuname = "**";
					stupass = "**";
					stu.setStudentname(stuname);
					stu.setStudentpass(stupass);
				}
				rs.close();
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("登录失败");
			}
			return stu;
		}
		//更新学生成绩单
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
		//教师查询单个学生成绩单
				public StudentVO studentScore(String name){
					StudentVO stu = new StudentVO();
					String stuname;
					try{
						st=con.createStatement();
						rs=st.executeQuery("select * from student where studentname ='"+name+"'");
						if(rs.next()) {
							String number =rs.getString(1);
							stuname=rs.getString(2);
							String stueverychoice=rs.getString(4);
							String stueveryscore=rs.getString(5);
							int stutotal=rs.getInt(6);
							stu.setNumber(number);
							stu.setStudentname(stuname);
							stu.setEverychoice(stueverychoice);
							stu.setEveryscore(stueveryscore);
							stu.setTotal(stutotal);
						}
						/*else {
							stuname = "**";
							stu.setStudentname(stuname);
						}*/
						rs.close();
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("成绩单查询失败");
					}
					return stu;
				}
		//教师查询学生成绩单
				public ArrayList<StudentVO> studentAllScore(){
					ArrayList<StudentVO> alllist = new ArrayList<StudentVO>();
					try{
						st=con.createStatement();
						rs=st.executeQuery("select * from student");
						while(rs.next()) {
							String number =rs.getString(1);
							String stuname=rs.getString(2);
							String stueverychoice=rs.getString(4);
							String stueveryscore=rs.getString(5);
							int stutotal=rs.getInt(6);
							StudentVO stu = new StudentVO();
							stu.setNumber(number);
							stu.setStudentname(stuname);
							stu.setEverychoice(stueverychoice);
							stu.setEveryscore(stueveryscore);
							stu.setTotal(stutotal);
							alllist.add(stu);
						}
						/*else {
							stuname = "**";
							stu.setStudentname(stuname);
						}*/
						rs.close();
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("成绩单查询失败");
					}
					return alllist;
				}
}
