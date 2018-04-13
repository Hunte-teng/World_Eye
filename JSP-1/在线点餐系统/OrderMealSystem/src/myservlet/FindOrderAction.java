package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.ArrayList;
import mybean.OrderDAO;
import mybean.OrderVO;

/**
 * Servlet implementation class FindOrderAction
 */
@WebServlet("/FindOrderAction")
public class FindOrderAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FindOrderAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		OrderDAO orderdao = new OrderDAO();
		OrderVO ordervo = new OrderVO();
		ArrayList<OrderVO> allorder = new ArrayList<OrderVO>();
		allorder = orderdao.getAllOrder();
		request.setAttribute("allorder", allorder);
		request.getRequestDispatcher("showorder.jsp").forward(request, response);
		
		
	}

}
