package minilib.action;

import javax.servlet.http.HttpServletRequest;

import org.apache.struts2.ServletActionContext;

import com.opensymphony.xwork2.ActionSupport;

import minilib.dao.ManageUserDao;
import java.util.ArrayList;
import minilib.vo.User;

public class ManageUserAction  extends ActionSupport{
	private User user;

	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}
	//添加User
		public String addUser() throws Exception{
			String restadd = "";
			ManageUserDao useradd = new ManageUserDao();
			useradd.setUser(user);
			useradd.userAddInsert();
			HttpServletRequest req = ServletActionContext.getRequest();
			req.setAttribute("message", "用户添加成功！请继续添加");
			restadd = "useradd";
			return restadd;
			
		}
	//查找user
		public String findUser() throws Exception{
			String refind = "";
			ManageUserDao userfind = new ManageUserDao();
			User user1 = new User();
			user1 = userfind.userFind(user.getName());
			HttpServletRequest req = ServletActionContext.getRequest();
			req.setAttribute("user1", user1);
			refind = "userfind";
			return refind;
			
		}

}
