package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import mybean.*;

/**
 * Servlet implementation class UserLoginAction
 */
@WebServlet("/UserLoginAction")
public class UserLoginAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UserLoginAction() {
        super();
        // TODO Auto-generated constructor stub
    }
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//String username = request.getParameter("username");
		String username = new String(request.getParameter("username").getBytes("ISO-8859-1"),"UTF-8");
		String password = request.getParameter("password");
		
		UserDAO userdao = new UserDAO();
		UserVO uservo = userdao.userLoginFind(username);
		if(password.equals(uservo.getPassword())) {
			HttpSession session = request.getSession(true);
			session.setAttribute("username", username);
			request.getRequestDispatcher("order.jsp").forward(request, response);
		}
		else
			request.getRequestDispatcher("login.jsp").forward(request, response);
		
	}

}
