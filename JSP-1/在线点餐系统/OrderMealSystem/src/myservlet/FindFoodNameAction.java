package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import mybean.FoodDAO;
import mybean.FoodVO;

/**
 * Servlet implementation class FindFoodNameAction
 */
@WebServlet("/FindFoodNameAction")
public class FindFoodNameAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FindFoodNameAction() {
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
		//String foodname = request.getParameter("foodname");
		String foodname = new String(request.getParameter("foodname").getBytes("ISO-8859-1"),"UTF-8");
		FoodDAO fooddao = new FoodDAO();
		FoodVO foodnamevo = new FoodVO();
		foodnamevo = fooddao.getAFood(foodname);
		HttpSession session = request.getSession(true);
		session.setAttribute("foodnamevo", foodnamevo);
		request.getRequestDispatcher("type-3.jsp").forward(request, response);
		
	}

}
