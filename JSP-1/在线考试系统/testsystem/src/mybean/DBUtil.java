package mybean;

import java.sql.Connection;
import java.sql.DriverManager;


public class DBUtil {
	//private static String sDBDriver = "sun.jdbc.odbc.JdbcOdbcDriver";
	//private static String sConnStr = "jdbc:odbc:mydb";
	private static String sDBDriver = "com.mysql.jdbc.Driver";
	private static Connection con;

	
	public static Connection connectDB(){
		try{
			Class.forName(sDBDriver);
			//con=DriverManager.getConnection(sConnStr);
			con=DriverManager.getConnection("jdbc:mysql://localhost:3306/testsystem","root","60121431");
		}catch(Exception e){
			System.out.println("连接数据库失败");
		}
		return con;
	}
}
