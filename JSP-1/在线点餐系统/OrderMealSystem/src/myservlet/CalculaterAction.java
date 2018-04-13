package myservlet;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import mybean.FoodDAO;
import mybean.FoodVO;
import mybean.UserVO;
import mybean.UserDAO;
/**
 * Servlet implementation class CalculaterAction
 */
@WebServlet("/CalculaterAction")
public class CalculaterAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CalculaterAction() {
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
		String[] number = (String[])session.getAttribute("number");//数量
		ArrayList<String> mycart = (ArrayList<String>)session.getAttribute("mycart");//名称
		ArrayList<FoodVO> myfood = new ArrayList<FoodVO>();//订单
		int total = 0;
		
		for(int i=0;i<mycart.size();i++)
		{
			String value = request.getParameter(number[i]);
			//System.out.println(value);
			if(value.equals("0"))
			{
				//mycart.remove(i);
				continue;
			}
			else
			{
				FoodDAO fooddao = new FoodDAO();
				FoodVO foodvo = new FoodVO();
				//foodvo = fooddao.getAFood(mycart.get(i));//根据食物名称查找相关信息
				foodvo = fooddao.getAFood(new String(mycart.get(i).getBytes("ISO-8859-1"),"UTF-8"));//根据食物名称查找相关信息
				foodvo.setNumber(value);
				myfood.add(foodvo);
				total = total + Integer.parseInt(foodvo.getPrice())*Integer.parseInt(value);
				//total += 10;
			}
		}
		session.setAttribute("myfood", myfood);//食物名称、类型、价格、数量
		session.setAttribute("total", total);//总价
		UserDAO userdao = new UserDAO();
		UserVO uservo = new UserVO();
		String username = (String)session.getAttribute("username");
		uservo = userdao.getUser(username);
		session.setAttribute("uservo", uservo);//用户名、电话、地址
		
		request.getRequestDispatcher("calculate.jsp").forward(request, response);
	}

}
