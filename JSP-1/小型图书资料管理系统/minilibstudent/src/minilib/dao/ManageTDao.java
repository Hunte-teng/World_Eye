package minilib.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import com.opensymphony.xwork2.ActionSupport;
import minilib.vo.Record;
import minilib.vo.Title;
import minilib.util.DBUtil;

public class ManageTDao extends ActionSupport{
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private Record record;

	public void setRecord(Record record) {
		this.record = record;
	}
	public ManageTDao() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	//添加借阅
	public boolean addBorrow()  throws Exception{
		try {
			pst= con.prepareStatement("insert into t_record (userid,bookid,borrowdate,returndate) values(?,?,?,?)");
			pst.setString(1, record.getUserid());
			pst.setString(2, record.getBookid());
			pst.setString(3, record.getBorrowdate());
			pst.setString(4, record.getReturndate());
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
			System.out.print("借阅添加失败");
			System.out.println(e.getMessage());
			return false;
		}
		
	}
	//查询所有借书记录
			public ArrayList<Record> findAllBorrow() throws Exception{
				ArrayList<Record> list = new ArrayList<Record>();
				try{
					st=con.createStatement();
					rs=st.executeQuery("select * from t_record");
					while(rs.next()) {
						Record record = new Record();
						record.setUserid(rs.getString(2));
						record.setBookid(rs.getString(3));
						record.setBorrowdate(rs.getString(4));
						record.setReturndate(rs.getString(4));

						list.add(record);
					}
					
					con.close();
					
				}catch(SQLException e){
					System.out.println("查找借书记录失败");
					System.out.println(e.getMessage());
				}
				return list;
			}

}
