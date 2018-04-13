package mybean;

import java.sql.Connection;
import mybean.TeacherVO;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class TeacherDAO {
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private TeacherVO teachervo; // 实体bean

	

	public void setTeachervo(TeacherVO teachervo) {
		this.teachervo = teachervo;
	}

	public TeacherDAO() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	
	//注册
		public boolean tescherLoginInsert() {
			try {
				pst= con.prepareStatement("insert into teacherlogin values(?,?)");
				pst.setString(1, teachervo.getTeachername());
				pst.setString(2, teachervo.getTeacherpass());
				if(pst.executeUpdate()==1){
					con.close();
					return true;
				}else{
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
		public TeacherVO teacherLoginFind(String name){
			TeacherVO tea = new TeacherVO();
			String teaname;
			String teapass;
			try{
				st=con.createStatement();
				rs=st.executeQuery("select teachername,password from teacherlogin where teachername ='"+name+"'");
				if(rs.next()) {
					teaname=rs.getString(1);
					teapass=rs.getString(2);
					tea.setTeachername(teaname);
					tea.setTeacherpass(teapass);
				}
				else {
					teaname = "**";
					teapass = "**";
					tea.setTeachername(teaname);
					tea.setTeacherpass(teapass);
				}
				
				con.close();
				
			}catch(SQLException e){
				System.out.println("登录失败");
			}
			return tea;
		}

}
