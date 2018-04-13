package minilib.action;

import javax.servlet.ServletRequest;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import org.apache.struts2.ServletActionContext;
import com.opensymphony.xwork2.ActionSupport;
import minilib.vo.User;
import minilib.dao.ManageUserDao;;

public class LoginAction extends ActionSupport {
	private User user;
	
	public User getUser() {
		return user;
	}
	public void setUser(User user) {
		this.user = user;
	}
	public String execute()throws Exception{
		/*if(user.getName().equals("admin")&&user.getPassword().equals("123456")){
			HttpServletRequest request=ServletActionContext.getRequest();
			HttpSession session=request.getSession();
			session.setAttribute("username", user.getName());
			return "menu";
		}else{
			return "login";
		}*/
		ManageUserDao userdao = new ManageUserDao();
		User user1 = userdao.userLogin(user.getName());
		if(user1.getPassword().equals(user.getPassword())){
			HttpServletRequest request=ServletActionContext.getRequest();
			HttpSession session=request.getSession();
			session.setAttribute("username", user.getName());
			return "menu";
		}else{
			return "login";
		}
	}

}
