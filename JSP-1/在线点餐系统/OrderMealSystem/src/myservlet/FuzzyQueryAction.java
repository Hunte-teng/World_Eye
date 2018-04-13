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
import java.util.ArrayList;

/**
 * Servlet implementation class FuzzyQueryAction
 */
@WebServlet("/FuzzyQueryAction")
public class FuzzyQueryAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FuzzyQueryAction() {
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
		//String keyword = request.getParameter("keyword");
		String keyword = new String(request.getParameter("keyword").getBytes("ISO-8859-1"),"UTF-8");
		FoodDAO fooddao = new FoodDAO();
		ArrayList<FoodVO> list = new ArrayList<FoodVO>();
		list = fooddao.fuzzyQueryFood(keyword);
		HttpSession session = request.getSession(true);
		session.setAttribute("list", list);
		request.getRequestDispatcher("type-5.jsp").forward(request, response);
		
	}

}
