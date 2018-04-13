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
 * Servlet implementation class UpdateFoodAction
 */
@WebServlet("/UpdateFoodAction")
public class UpdateFoodAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UpdateFoodAction() {
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
		
		String foodname = new String(request.getParameter("foodname").getBytes("ISO-8859-1"),"UTF-8");
		String update = request.getParameter("update");
		String updatetext = new String(request.getParameter("updatetext").getBytes("ISO-8859-1"),"UTF-8");
		System.out.println(foodname);
		FoodDAO fooddao = new FoodDAO();
		if(update!=null && updatetext!=null) {
		if(update.equals("foodname")) {
			boolean f = fooddao.updatefoodname(foodname, updatetext);
			if(f) {
				request.setAttribute("message", "修改食物名称成功请继续修改");
			}
			else {
				request.setAttribute("message", "修改食物名称失败请继续修改");
			}
			request.getRequestDispatcher("FindAllFoodNameAction").forward(request, response);
		}
		if(update.equals("foodtype")) {
			boolean f = fooddao.updatefoodtype(foodname, updatetext);
			if(f) {
				request.setAttribute("message", "修改食物类型成功请继续修改");
			}
			else {
				request.setAttribute("message", "修改食物类型失败请继续修改");
			}
			request.getRequestDispatcher("FindAllFoodNameAction").forward(request, response);
		}
		if(update.equals("foodimg")) {
			boolean f = fooddao.updatefoodimg(foodname, updatetext);
			if(f) {
				request.setAttribute("message", "修改食物图片成功请继续修改");
			}
			else {
				request.setAttribute("message", "修改食物图片失败请继续修改");
			}
			request.getRequestDispatcher("FindAllFoodNameAction").forward(request, response);
		}
		if(update.equals("foodprice")) {
			boolean f = fooddao.updatefoodprice(foodname, updatetext);
			if(f) {
				request.setAttribute("message", "修改食物价格成功请继续修改");
			}
			else {
				request.setAttribute("message", "修改食物价格失败请继续修改");
			}
			request.getRequestDispatcher("FindAllFoodNameAction").forward(request, response);
		}
		}
		else {
			request.setAttribute("message", "有选项未填写！请重新填写");
			request.getRequestDispatcher("FindAllFoodNameAction").forward(request, response);
		}
		
	}

}
