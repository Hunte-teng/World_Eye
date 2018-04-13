package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import mybean.*;
import java.util.ArrayList;
import java.lang.StringBuffer;
import java.util.Random;

/**
 * Servlet implementation class OrderAction
 */
@WebServlet("/OrderAction")
public class OrderAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public OrderAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		HttpSession session = request.getSession(true);
		//String remark = request.getParameter("remark");//备注
		String remark = new String(request.getParameter("remark").getBytes("ISO-8859-1"),"UTF-8");
		//session.setAttribute("remark", remark);
		UserVO uservo = (UserVO)session.getAttribute("uservo");//用户名、电话、地址
		ArrayList<FoodVO> myfood = (ArrayList<FoodVO>)session.getAttribute("myfood");//食物名称、食物类型、食物价格、食物数量
		//总价、备注、状态、订单号
		OrderDAO orderdao = new OrderDAO();
		OrderVO ordervo = new OrderVO();
		StringBuffer sb1 = new StringBuffer();//存储食物信息
		sb1.append("");
		for(int i=0;i<myfood.size();i++)
		{
			
			sb1.insert(i, myfood.get(i).getName()+"*"+myfood.get(i).getNumber());//食物信息
		}
		Random r = new Random();//随机生成订单号
		String rr = Integer.toString(r.nextInt());
		session.setAttribute("rr",rr);
		int total = (int)session.getAttribute("total");
		String sb2 = sb1.toString();
		ordervo.setOrdernum(rr);
		ordervo.setFoodimformation(sb2);
		ordervo.setTotal(Integer.toString(total));
		ordervo.setRemark(remark);
		ordervo.setUsername(uservo.getUsername());
		ordervo.setTelephone(uservo.getTelephone());
		ordervo.setAddress(uservo.getAddress());
		ordervo.setState("等待商家接单");
		orderdao.setOrdervo(ordervo);
		orderdao.orderInsert();
		
		//显示订单
		request.setAttribute("ordervo", ordervo);
		request.getRequestDispatcher("checkout.jsp").forward(request, response);
		
	}

}
