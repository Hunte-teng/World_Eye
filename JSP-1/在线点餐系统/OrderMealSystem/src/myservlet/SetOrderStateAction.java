package myservlet;

import java.io.IOException;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.ArrayList;
import mybean.OrderDAO;
import mybean.OrderVO;

/**
 * Servlet implementation class SetOrderState
 */
@WebServlet("/SetOrderStateAction")
public class SetOrderStateAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SetOrderStateAction() {
        super();
        // TODO Auto-generated constructor stub
    }
    
    public void init(ServletConfig config) throws ServletException {
		super.init(config);
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
		String ordernumber = request.getParameter("ordernumber");
		//String state = request.getParameter("state");
		
		request.setCharacterEncoding("utf-8");
		
		String state = new String(request.getParameter("state").getBytes("ISO-8859-1"),"UTF-8");
		OrderDAO orderdao = new OrderDAO();
		
		boolean f = orderdao.updatestate(ordernumber, state);
		if(f) {
			request.setAttribute("message", "设置成功请继续设置");
		}
		else {
			request.setAttribute("message", "设置失败请重新设置");
		}
		request.getRequestDispatcher("FindAllOrderNumberAction").forward(request, response);
		
	}

}
