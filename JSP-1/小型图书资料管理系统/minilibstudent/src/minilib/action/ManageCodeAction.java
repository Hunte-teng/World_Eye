package minilib.action;

import javax.servlet.http.HttpServletRequest;
import org.apache.struts2.ServletActionContext;
import com.opensymphony.xwork2.ActionSupport;
import minilib.dao.ManageCodeDao;
import java.util.ArrayList;
import minilib.vo.Press;
import minilib.vo.BookType;

public class ManageCodeAction  extends ActionSupport{
	private Press press;
	private BookType booktype;

	public Press getPress() {
		return press;
	}

	public void setPress(Press press) {
		this.press = press;
	}
	
	

	public BookType getBooktype() {
		return booktype;
	}

	public void setBooktype(BookType booktype) {
		this.booktype = booktype;
	}

	//添加press
			public String addPress() throws Exception{
				String repressadd = "";
				System.out.print(press.getCodename());
				ManageCodeDao pressadd = new ManageCodeDao();
				pressadd.setPress(press);
				pressadd.pressAddInsert();
				HttpServletRequest req = ServletActionContext.getRequest();
				req.setAttribute("message", "出版社添加成功请继续添加");
				repressadd = "pressadd";
				return repressadd;
				
			}
	//查找press
			public String queryPress() throws Exception{
				String requery = "";
				System.out.print(press.getCodename());
				ManageCodeDao pressquery = new ManageCodeDao();
				Press press1 = new Press();
				press1 = pressquery.pressQuery(press.getCodename());
				HttpServletRequest req = ServletActionContext.getRequest();
				req.setAttribute("press1", press1);
				requery = "pressquery";
				return requery;
				
			}
	//添加booktype
			public String addBookType() throws Exception{
				String rebooktypeadd = "";
				System.out.print(booktype.getCodename());
				ManageCodeDao booktypeadd = new ManageCodeDao();
				booktypeadd.setBooktype(booktype);
				booktypeadd.bookTypeAddInsert();
				HttpServletRequest req = ServletActionContext.getRequest();
				req.setAttribute("message", "图书类型添加成功请继续添加");
				rebooktypeadd = "booktypeadd";
				return rebooktypeadd;
				
			}
	//查找booktype
			public String queryBookType() throws Exception{
				String requery = "";
				
				ManageCodeDao booktypequery = new ManageCodeDao();
				BookType booktype1 = new BookType();
				booktype1 = booktypequery.bookTypeQuery(booktype.getCodename());
				//booktype1 = booktypequery.bookTypeQuery("教育");
				HttpServletRequest req = ServletActionContext.getRequest();
				req.setAttribute("booktype1", booktype1);
				requery = "booktypequery";
				return requery;
				
			}
	//查找所有booktype
			public String findBookType() throws Exception{
				String requery = "";
				ManageCodeDao booktypequery = new ManageCodeDao();
				ArrayList<BookType> booktypelist = new ArrayList<BookType>();
				booktypelist = booktypequery.findBookType();
				
				ManageCodeDao pressequery = new ManageCodeDao();
				ArrayList<Press> presslist = new ArrayList<Press>();
				presslist = pressequery.allpressQuery();
				HttpServletRequest req = ServletActionContext.getRequest();
				req.setAttribute("booktypelist", booktypelist);
				req.setAttribute("presslist", presslist);
				requery = "booktype";
				return requery;
				
			}
	//
}
