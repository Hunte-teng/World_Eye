package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import mybean.OwnerDAO;
import mybean.OwnerVO;

/**
 * Servlet implementation class OwnerLoginAction
 */
@WebServlet("/OwnerLoginAction")
public class OwnerLoginAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public OwnerLoginAction() {
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
		//String ownername = request.getParameter("ownername");
		String ownername = new String(request.getParameter("ownername").getBytes("ISO-8859-1"),"UTF-8");
		String ownerpass = request.getParameter("ownerpass");
		OwnerDAO ownerdao = new OwnerDAO();
		OwnerVO ownervo = ownerdao.ownerLoginFind(ownername);
		if(ownerpass.equals(ownervo.getOwnerpass())) {
			HttpSession session = request.getSession(true);
			session.setAttribute("ownername", ownername);
			request.getRequestDispatcher("ownerfunction.jsp").forward(request, response);
		}
		else
			request.getRequestDispatcher("ownerlogin.jsp").forward(request, response);
	}

}
