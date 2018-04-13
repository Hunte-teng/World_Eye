package minilib.action;

import javax.servlet.http.HttpServletRequest;
import org.apache.struts2.ServletActionContext;
import com.opensymphony.xwork2.ActionSupport;
import minilib.dao.ManageTitlesDao;
import java.util.ArrayList;
import minilib.vo.Title;
import minilib.vo.BookType;

public class ManageTitlesAction extends ActionSupport {
	private Title book;
	
	
	public Title getBook() {
		return book;
	}
	public void setBook(Title book) {
		this.book = book;
	}
	//添加Title
	public String addTitle() throws Exception{
		String restadd = INPUT;
		ManageTitlesDao mtadd = new ManageTitlesDao();
		mtadd.setTitle(book);
		mtadd.addBook();
		HttpServletRequest req = ServletActionContext.getRequest();
		req.setAttribute("message", "添加成功请继续添加");
		restadd = "addbook";
		return restadd;
		
	}
	//查找Title
	public String queryTitle() throws Exception{
		String restType = INPUT;
		ManageTitlesDao mttype = new ManageTitlesDao();
		ArrayList<Title> allTitlelist = mttype.findAllBooks();
		HttpServletRequest req = ServletActionContext.getRequest();
		req.setAttribute("allTitlelist",allTitlelist);
		
		restType = "querybook";
		
		return restType;
	}
	/*public String findBookType() throws Exception{
		String restType = INPUT;
		ManageTitlesDao mttype = new ManageTitlesDao();
		ArrayList<BookType> allTypelist = mttype.findBookType();
		
		HttpServletRequest req = ServletActionContext.getRequest();
		req.setAttribute("alltypelist",allTypelist);
		
		restType = "booktype";
		
		
		return restType;
	}*/
	//模糊查找Title
		public String fuzzyQueryTitle() throws Exception{
			String restType = INPUT;
			HttpServletRequest req = ServletActionContext.getRequest();
			String context = req.getParameter("context");
			ManageTitlesDao fmttype = new ManageTitlesDao();
			ArrayList<Title> allTitlelist = fmttype.fuzzyQuery(context);

			req.setAttribute("allTitlelist",allTitlelist);			
			restType = "fuzzyquerybook";
			
			return restType;
		}

}
