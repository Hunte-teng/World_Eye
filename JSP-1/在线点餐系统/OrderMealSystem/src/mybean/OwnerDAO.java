package mybean;

import java.sql.Connection;
import mybean.OwnerVO;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class OwnerDAO {
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private OwnerVO ownervo; // 实体bean

	
	public void setOwnervo(OwnerVO ownervo) {
		this.ownervo = ownervo;
	}

	public OwnerDAO() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	
	//注册
			public boolean ownerRegisterInsert() {
				try {
					pst= con.prepareStatement("insert into owner  values(?,?,?,?,?)");
					pst.setString(1, ownervo.getOwnernumber());
					pst.setString(2, ownervo.getOwnername());
					pst.setString(3, ownervo.getOwnerpass());
					pst.setString(4, ownervo.getTelephone());
					pst.setString(5, ownervo.getAddress());
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
			public OwnerVO ownerLoginFind(String name){
				OwnerVO ownervo = new OwnerVO();
				String ownername;
				String ownerpass;
				try{
					st=con.createStatement();
					rs=st.executeQuery("select * from owner where ownername ='"+name+"'");
					if(rs.next()) {
						ownername=rs.getString(2);
						ownerpass=rs.getString(3);
						ownervo.setOwnername(ownername);
						ownervo.setOwnerpass(ownerpass);
					}
					else {
						ownername = "**";
						ownerpass = "**";
						ownervo.setOwnername(ownername);
						ownervo.setOwnerpass(ownerpass);
					}
					rs.close();
					st.close();
					con.close();
					
				}catch(SQLException e){
					System.out.println("登录失败");
				}
				return ownervo;
			}

}
