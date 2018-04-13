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
 * Servlet implementation class FindFoodPriceAction
 */
@WebServlet("/FindFoodPriceAction")
public class FindFoodPriceAction extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FindFoodPriceAction() {
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
		String foodprice1 = request.getParameter("foodprice1");
		String foodprice2 = request.getParameter("foodprice2");
	    int	foodprice11 = Integer.parseInt(foodprice1);
	    int	foodprice22 = Integer.parseInt(foodprice2);
		FoodDAO fooddao = new FoodDAO();
		ArrayList<FoodVO> foodresult2 = new ArrayList<FoodVO>();
		ArrayList<FoodVO> foodresult1 = new ArrayList<FoodVO>();
		foodresult2 = fooddao.getAllFood();
		for(int i=0;i<foodresult2.size();i++)
		{
			if(Integer.parseInt(foodresult2.get(i).getPrice())>=foodprice11 && Integer.parseInt(foodresult2.get(i).getPrice())<=foodprice22)
			{
				foodresult1.add(foodresult2.get(i));
			}
		}
		HttpSession session = request.getSession(true);
		session.setAttribute("foodresult1", foodresult1);
		request.getRequestDispatcher("type-4.jsp").forward(request, response);
		
	}

}
