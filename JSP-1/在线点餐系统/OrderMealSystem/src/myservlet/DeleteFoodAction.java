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
 * Servlet implementation class DeleteFoodAction
 */
@WebServlet("/DeleteFoodAction")
public class DeleteFoodAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DeleteFoodAction() {
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
		// TODO Auto-generated method stub
		String foodname = new String(request.getParameter("foodname").getBytes("ISO-8859-1"),"UTF-8");
		FoodDAO fooddao = new FoodDAO();
		boolean f = fooddao.deletefood(foodname);
		if(f) {
			request.setAttribute("message", "删除成功!请继续删除");
		}
		else {
			request.setAttribute("message", "删除失败!请重新删除");
		}
		request.getRequestDispatcher("FindAllFoodNameAction").forward(request, response);
	}

}
