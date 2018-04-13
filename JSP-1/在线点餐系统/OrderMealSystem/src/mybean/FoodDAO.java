package mybean;

import java.sql.Connection;
import mybean.FoodVO;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class FoodDAO {
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private FoodVO foodvo; // 实体bean
	
	public void setFoodvo(FoodVO foodvo) {
		this.foodvo = foodvo;
	}
	
	public FoodDAO() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	//查询食物列表
		public ArrayList<FoodVO> getAllFood(){
			ArrayList<FoodVO> allfood=new ArrayList<FoodVO>();
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from food");
				while(rs.next()){
					String foodname=rs.getString(2);
					String type=rs.getString(3);
					String img=rs.getString(4);
					String price=rs.getString(5);
					FoodVO food=new FoodVO();
					food.setName(foodname);
					food.setType(type);
					food.setImg(img);
					food.setPrice(price);
					allfood.add(food);
				}
				rs.close();
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("查询失败");
			}
			
			return allfood;
		}
		//查询食物单价
				public ArrayList<String> getFoodprice(){
					ArrayList<String> foodprice = new ArrayList<String>();
					try{
						st=con.createStatement();
						rs=st.executeQuery("select foodprice from food");
						while(rs.next()){
							String price=rs.getString(1);
							foodprice.add(price);
						}
						rs.close();
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("单价查询失败");
					}
					
					return foodprice;
				}
		//根据食物名称查询食物类型、单价
				public FoodVO getAFood(String foodname){
					FoodVO foodvo = new FoodVO();
					String name,type,price,img;
					try{
						st=con.createStatement();
						rs=st.executeQuery("select * from food where foodname = '"+foodname+"'");
						if(rs.next()) {
							name=rs.getString(2);
							type=rs.getString(3);
							img=rs.getString(4);
							price=rs.getString(5);
							
							foodvo.setName(name);
							foodvo.setType(type);
							foodvo.setImg(img);
							foodvo.setPrice(price);
						}
						else 
						{
							name="**";
							type="**";
							img="**";
							price="0";
							foodvo.setName(name);
							foodvo.setType(type);
							foodvo.setImg(img);
							foodvo.setPrice(price);
						}
						rs.close();
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("查询失败");
					}
					
					return foodvo;
				}
		//根据食物价格查询食物类型、单价
				public FoodVO getBFood(String foodprice){
					FoodVO foodvo = new FoodVO();
					String name,type,price;
					try{
						st=con.createStatement();
						rs=st.executeQuery("select * from food where foodname = '"+foodprice+"'");
						if(rs.next()) {
							name=rs.getString(2);
							type=rs.getString(3);
							price=rs.getString(5);
							
							foodvo.setName(name);
							foodvo.setType(type);
							foodvo.setPrice(price);
						}
						else 
						{
							name="**";
							type="**";
							price="0";
							foodvo.setName(name);
							foodvo.setType(type);
							foodvo.setPrice(price);
						}
						rs.close();
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("查询失败");
					}
					
					return foodvo;
				}
	//模糊查询
				public ArrayList<FoodVO> fuzzyQueryFood(String context){
					ArrayList<FoodVO> allfood=new ArrayList<FoodVO>();
					try{
						st=con.createStatement();
						String strsql = "select ";
						strsql = strsql + "*";
						strsql = strsql + " from food where ";
						strsql = strsql + " foodname like '%" + context + "%'" ;
						rs=st.executeQuery(strsql);
						while(rs.next()){
							String foodname=rs.getString(2);
							String type=rs.getString(3);
							String img=rs.getString(4);
							String price=rs.getString(5);
							FoodVO food=new FoodVO();
							food.setName(foodname);
							food.setType(type);
							food.setImg(img);
							food.setPrice(price);
							allfood.add(food);
						}
						rs.close();
						st.close();
						con.close();
						
					}catch(SQLException e){
						System.out.println("模糊查询失败");
					}
					
					return allfood;
				}
	//添加食物
				public boolean addfood() {
					try {
						pst= con.prepareStatement("insert into food values(?,?,?,?,?)");
						pst.setString(1, foodvo.getId());
						pst.setString(2, foodvo.getName());
						pst.setString(3, foodvo.getType());
						pst.setString(4, foodvo.getImg());
						pst.setString(5, foodvo.getPrice());
						if(pst.executeUpdate()==1){
							pst.close();
							con.close();
							return true;
						}else{
							con.close();
							return false;
						}
						
					} catch (SQLException e) {
						System.out.print("食物插入操作失败");
						System.out.println(e.getMessage());
						return false;
					}
					
				}
	//删除食物
				public boolean deletefood(String name) {
					try {
						st=con.createStatement();
						String deleteString = "delete from food where foodname='"+name+"'";
						st.executeUpdate(deleteString);
						st.close();
						con.close();
						return true;
					}catch(SQLException e) {
						System.out.print("食物删除操作失败");
						return false;
					}
				}
	//修改食物名称
				public boolean updatefoodname(String foodname,String update){
					try{
						st=con.createStatement();
						String updateString = "update food set foodname='"+update+"' where foodname='"+foodname+"'";
						st.executeUpdate(updateString);
						st.close();
						con.close();
						return true;
					}catch(SQLException e){
						System.out.println("食物名称修改失败");
						return false;
					}
				}
	//修改食物类别
				public boolean updatefoodtype(String foodname,String update){
					System.out.println(foodname+update);
					try{
						st=con.createStatement();
						String updateString = "update food set foodtype='"+update+"' where foodname='"+foodname+"'";
						st.executeUpdate(updateString);
						st.close();
						con.close();
						return true;
					}catch(SQLException e){
						System.out.println("食物类别修改失败");
						System.out.println(e.getMessage());
						return false;
					}
				}
	//修改食物图片编号
				public boolean updatefoodimg(String foodname,String update){
					System.out.println(foodname+update);
					try{
						st=con.createStatement();
						String updateString = "update food set foodimg='"+update+"' where foodname='"+foodname+"'";
						st.executeUpdate(updateString);
						st.close();
						con.close();
						return true;
					}catch(SQLException e){
						System.out.println("食物图片修改失败");
						System.out.println(e.getMessage());
						return false;
					}
				}
	//修改食物价格
				public boolean updatefoodprice(String foodname,String update){
					System.out.println(foodname+update);
					try{
						st=con.createStatement();
						String updateString = "update food set foodprice='"+update+"' where foodname='"+foodname+"'";
						st.executeUpdate(updateString);
						st.close();
						con.close();
						return true;
					}catch(SQLException e){
						System.out.println("食物价格修改失败");
						System.out.println(e.getMessage());
						return false;
					}
				}
				
}
