package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.ArrayList;
import mybean.FoodDAO;
import mybean.FoodVO;

/**
 * Servlet implementation class FoodListAction
 */
@WebServlet("/FoodListAction")
public class FoodListAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FoodListAction() {
        super();
        // TODO Auto-generated constructor stub
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//查询所有食物然后在网页输出
		String type = request.getParameter("type");
		//int ty = Integer.parseInt(type);
		FoodDAO fooddao = new FoodDAO();
		ArrayList<FoodVO> allfood = new ArrayList<FoodVO>();
		allfood = fooddao.getAllFood();
		request.setAttribute("allfood", allfood);
		if(type.equals("1")) {
			request.getRequestDispatcher("type-1.jsp").forward(request, response);
		}
		else if(type.equals("2")){
			request.getRequestDispatcher("type-2.jsp").forward(request, response);
		}
		else {
			request.getRequestDispatcher("find.jsp").forward(request, response);
		}
		
	}

}
