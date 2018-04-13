package myservlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import mybean.OwnerDAO;
import mybean.OwnerVO;

/**
 * Servlet implementation class OwnerRegisterAction
 */
@WebServlet("/OwnerRegisterAction")
public class OwnerRegisterAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public OwnerRegisterAction() {
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
		String ownernumber = request.getParameter("ownernumber");
		String ownername = new String(request.getParameter("ownername").getBytes("ISO-8859-1"),"UTF-8");
		String password = request.getParameter("password");
		String telephone = request.getParameter("telephone");
		//String address = request.getParameter("address");
		String address = new String(request.getParameter("address").getBytes("ISO-8859-1"),"UTF-8");
		OwnerVO ownervo = new OwnerVO();
		ownervo.setOwnernumber(ownernumber);
		ownervo.setOwnername(ownername);
		ownervo.setOwnerpass(password);
		ownervo.setTelephone(telephone);
		ownervo.setAddress(address);
		OwnerDAO ownerdao = new OwnerDAO();
		ownerdao.setOwnervo(ownervo);
		if(ownerdao.ownerRegisterInsert()==true) {
			request.setAttribute("message", "注册成功！请登陆");
			request.getRequestDispatcher("ownerlogin.jsp").forward(request, response);
		}
		else {
			request.setAttribute("message", "注册失败！请重新注册");
			request.getRequestDispatcher("ownerregister.jsp").forward(request, response);
		}
			
	}

}
