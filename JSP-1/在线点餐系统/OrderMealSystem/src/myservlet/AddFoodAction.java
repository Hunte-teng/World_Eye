package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import mybean.FoodDAO;
import mybean.FoodVO;

/**
 * Servlet implementation class AddFoodAction
 */
@WebServlet("/AddFoodAction")
public class AddFoodAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddFoodAction() {
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
		String foodid = request.getParameter("foodid");
		String foodname = new String(request.getParameter("foodname").getBytes("ISO-8859-1"),"UTF-8");
		String foodtype = new String(request.getParameter("foodtype").getBytes("ISO-8859-1"),"UTF-8");
		String foodimg = request.getParameter("foodimg");
		String foodprice = request.getParameter("foodprice");
		FoodDAO fooddao = new FoodDAO();
		FoodVO foodvo = new FoodVO();
		foodvo.setId(foodid);
		foodvo.setName(foodname);
		foodvo.setType(foodtype);
		foodvo.setImg(foodimg);
		foodvo.setPrice(foodprice);
		fooddao.setFoodvo(foodvo);
		boolean f = fooddao.addfood();
		if(f) {
			request.setAttribute("message", "添加成功请继续添加");
		}
		else {
			request.setAttribute("message", "添加失败请继续添加");
		}
		request.getRequestDispatcher("addfood.jsp").forward(request, response);
	}

}
