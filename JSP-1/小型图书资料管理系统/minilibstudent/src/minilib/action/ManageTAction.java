package minilib.action;

import javax.servlet.http.HttpServletRequest;
import org.apache.struts2.ServletActionContext;
import com.opensymphony.xwork2.ActionSupport;
import java.util.ArrayList;
import minilib.vo.*;
import minilib.dao.*;

public class ManageTAction extends ActionSupport{
	private Record record;

	public Record getRecord() {
		return record;
	}

	public void setRecord(Record record) {
		this.record = record;
	}
	
	//添加借书记录
		public String addBorrow() throws Exception{
			String restadd = INPUT;
			HttpServletRequest req = ServletActionContext.getRequest();
			ManageTDao tadd = new ManageTDao();
			tadd.setRecord(record);
			boolean f = tadd.addBorrow();
			if(f) {
				req.setAttribute("message", "借书成功!请继续添加");
			}
			else {
				req.setAttribute("message", "借书失败!请重新添加");
			}		
			restadd = "addborrow";
			return restadd;		
		}
	//查询所有userid和bookid
		public String findub() throws Exception{
			String restadd = INPUT;
			
			ManageUserDao userdao = new ManageUserDao();
			ManageTitlesDao titledao = new ManageTitlesDao();
			ArrayList<User> alluserid = new ArrayList<User>();
			ArrayList<Title> allbookid = new ArrayList<Title>();
			alluserid = userdao.userID();
			allbookid = titledao.allBookid();
			HttpServletRequest req = ServletActionContext.getRequest();
			req.setAttribute("alluserid", alluserid);
			req.setAttribute("allbookid", allbookid);
		
			restadd = "findub";
			return restadd;	
		}
	//查询借书记录
				public String findBorrow() throws Exception{
					String restadd = INPUT;
					HttpServletRequest req = ServletActionContext.getRequest();
					ManageTDao t = new ManageTDao();
					ArrayList<Record> list = new ArrayList<Record>();
					list = t.findAllBorrow();
					req.setAttribute("list", list);
		
					restadd = "findborrow";
					return restadd;		
				}

}
