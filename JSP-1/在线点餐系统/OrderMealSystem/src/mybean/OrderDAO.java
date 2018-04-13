package mybean;

import java.sql.Connection;
import mybean.OrderVO;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class OrderDAO {
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private OrderVO ordervo;
	
	
	public void setOrdervo(OrderVO ordervo) {
		this.ordervo = ordervo;
	}
	public OrderDAO() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}
	//生成订单
	public boolean orderInsert() {
		System.out.print(ordervo.getOrdernum());
		try {
			pst= con.prepareStatement("insert into orders values(?,?,?,?,?,?,?,?)");
			/*pst= con.prepareStatement("insert into order values('" + ordervo.getOrdernum() + "'," + ""
					+ "'" + ordervo.getFoodimformation() + "'," + ""
							+ "'" + ordervo.getTotal() + "'," + ""
									+ "'" + ordervo.getRemark() + "'," + ""
											+ "'" + ordervo.getUsername() + "'," + ""
													+ "'" + ordervo.getTelephone() + "'," + ""
															+ "'" + ordervo.getAddress() + "'," + ""
																	+ "'" + ordervo.getState() + "')");*/
			pst.setString(1, ordervo.getOrdernum());
			pst.setString(2, ordervo.getFoodimformation());
			pst.setString(3, ordervo.getTotal());
			pst.setString(4, ordervo.getRemark());
			pst.setString(5, ordervo.getUsername());
			pst.setString(6, ordervo.getTelephone());
			pst.setString(7, ordervo.getAddress());
			pst.setString(8, ordervo.getState());
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
			System.out.print("订单生成失败");
			System.out.println(e.getMessage());
			return false;
		}
		
	}
	//查询订单
	public ArrayList<OrderVO> getAllOrder(){
		ArrayList<OrderVO> allorder=new ArrayList<OrderVO>();
		try{
			st=con.createStatement();
			rs=st.executeQuery("select * from orders");
			while(rs.next()){
				String ordernumber=rs.getString(1);
				String foodimformation=rs.getString(2);
				String total=rs.getString(3);
				String remark=rs.getString(4);
				String username=rs.getString(5);
				String telephone=rs.getString(6);
				String address=rs.getString(7);
				String state=rs.getString(8);
				OrderVO ordervo=new OrderVO();
				ordervo.setOrdernum(ordernumber);
				ordervo.setFoodimformation(foodimformation);
				ordervo.setTotal(total);
				ordervo.setRemark(remark);
				ordervo.setUsername(username);
				ordervo.setTelephone(telephone);
				ordervo.setAddress(address);
				ordervo.setState(state);
				allorder.add(ordervo);
			}
			rs.close();
			st.close();
			con.close();
			
		}catch(SQLException e){
			System.out.println("订单查询失败");
			System.out.println(e.getMessage());
		}
		
		return allorder;
	}
	//查询单个订单
		public OrderVO getAOrder(String number){
			OrderVO ordervo=new OrderVO();
			String foodimformation;
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from orders where ordernumber = '"+number+"'");
				if(rs.next()){
					String ordernumber=rs.getString(1);
					       foodimformation=rs.getString(2);
					String total=rs.getString(3);
					String remark=rs.getString(4);
					String username=rs.getString(5);
					String telephone=rs.getString(6);
					String address=rs.getString(7);
					String state=rs.getString(8);
					
					ordervo.setOrdernum(ordernumber);
					ordervo.setFoodimformation(foodimformation);
					ordervo.setTotal(total);
					ordervo.setRemark(remark);
					ordervo.setUsername(username);
					ordervo.setTelephone(telephone);
					ordervo.setAddress(address);
					ordervo.setState(state);
				}
				else {
					foodimformation="**";
				}
				rs.close();
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("订单查询失败");
			}
			
			return ordervo;
		}
	//设置订单状态
				public boolean updatestate(String number,String update){
					try{
						st=con.createStatement();
						String updateString = "update orders set state='"+update+"' where ordernumber='"+number+"'";
						st.executeUpdate(updateString);
						st.close();
						con.close();
						return true;
					}catch(SQLException e){
						System.out.println("订单状态修改失败");
						return false;
					}
				}
}
