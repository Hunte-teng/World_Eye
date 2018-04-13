package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import mybean.*;

/**
 * Servlet implementation class UserRegisterAction
 */
@WebServlet("/UserRegisterAction")
public class UserRegisterAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UserRegisterAction() {
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
		//String username = request.getParameter("username");
		String username = new String(request.getParameter("username").getBytes("ISO-8859-1"),"UTF-8");
		String password = request.getParameter("password");
		String telephone = request.getParameter("telephone");
		//String address = request.getParameter("address");
		String address = new String(request.getParameter("address").getBytes("ISO-8859-1"),"UTF-8");
		UserVO uservo = new UserVO();
		uservo.setUsername(username);
		uservo.setPassword(password);
		uservo.setTelephone(telephone);
		uservo.setAddress(address);
		UserDAO userdao = new UserDAO();
		userdao.setUservo(uservo);
		if(userdao.userRegisterInsert()==true) {
			request.setAttribute("message", "注册成功！请登录");
			request.getRequestDispatcher("login.jsp").forward(request, response);
		}
		else
			request.setAttribute("message", "注册失败！请重新注册");
			request.getRequestDispatcher("userregister.jsp").forward(request, response);
		
	}

}
