package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import java.util.ArrayList;

/**
 * Servlet implementation class CartManageAction
 */
@WebServlet("/CartManageAction")
public class CartManageAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CartManageAction() {
        super();
        // TODO Auto-generated constructor stub
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String food[] = request.getParameterValues("food");
		HttpSession session = request.getSession(true);
		ArrayList<String> mycart = (ArrayList<String>)session.getAttribute("mycart");
		for(int i=0;i<food.length;i++)
		{
			mycart.add(food[i]);
		}
		
		session.setAttribute("mycart", mycart);
		request.getRequestDispatcher("cart.jsp").forward(request, response);
		
	}

}
