package minilib.util;

import java.sql.Connection;
import java.sql.DriverManager;


public class DBUtil {
	//数据库的用户名和密码
	//private static String rootname = "root";
	//private static String rootpass = "60121431";
	//数据库的位置
	//private static String url = "jdbc:mysql://localhost:3306/book";
	//MySql的驱动程序
		private static String sDBDriver = "com.mysql.jdbc.Driver";
	private static Connection con;

	
	public static Connection connectDB(){
		try{
			Class.forName(sDBDriver);
			//con=DriverManager.getConnection(sConnStr);
			con=DriverManager.getConnection("jdbc:mysql://localhost:3306/book?characterEncoding=utf8&useSSL=true","root","60121431");
		}catch(Exception e){
			System.out.println("连接数据库失败");
		}
		return con;
	}
}
