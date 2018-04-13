package mybean;

import java.sql.Connection;
import mybean.QuestionVO;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class TestDAO {
	private PreparedStatement pst;
	private Statement st;
	private ResultSet rs;
	private Connection con;
	private QuestionVO questionvo; // 实体bean

	public QuestionVO getQuestion() {
		return questionvo;
	}

	public void setQuestionvo(QuestionVO questionvo) {
		this.questionvo = questionvo;
	}

	public TestDAO() { // 利用构造函数连接数据库
		con = DBUtil.connectDB();
	}

	//插入
	public boolean insert() {
		try {
			pst= con.prepareStatement("insert into testquestions values(?,?,?,?,?,?,?)");
			pst.setInt(1, questionvo.getId());
			pst.setString(2, questionvo.getQuestion());
			pst.setString(3, questionvo.getA());
			pst.setString(4, questionvo.getB());
			pst.setString(5, questionvo.getC());
			pst.setString(6, questionvo.getD());
			pst.setString(7, questionvo.getAnswer());
			if(pst.executeUpdate()==1){
				pst.close();
				con.close();
				return true;
			}else{
				con.close();
				return false;
			}
			
		} catch (SQLException e) {
			System.out.print("插入操作失败");
			return false;
		}
		
	}
	
	//删除
	public void delete(int id) {
		try {
			st=con.createStatement();
			String deleteString = "delete from testquestions where id='"+id+"'";
			st.executeUpdate(deleteString);
			st.close();
			con.close();
		}catch(SQLException e) {
			System.out.print("删除操作失败");
		}
	}
	
	//更新题目内容
		public void updateQuestion(int id,String update){
			try{
				st=con.createStatement();
				String updateString = "update testquestions set question='"+update+"' where id='"+id+"'";
				st.executeUpdate(updateString);
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("题目内容修改失败");
			}
		}
		
		//更新choiceA
		public void updateChoiceA(int id,String update){
			try{
				st=con.createStatement();
				String updateString = "update testquestions set choiceA='"+update+"' where id='"+id+"'";
				st.executeUpdate(updateString);
				st.close();
				con.close();
						
			}catch(SQLException e){
				System.out.println("选项A修改失败");
			}
		}
		
		//更新choiceB
		public void updateChoiceB(int id,String update){
			try{
				st=con.createStatement();
				String updateString = "update testquestions set choiceB='"+update+"' where id='"+id+"'";
				st.executeUpdate(updateString);
				st.close();
				con.close();
								
			}catch(SQLException e){
				System.out.println("选项B修改失败");
			}
		}
		
		//更新choiceC
		public void updateChoiceC(int id,String update){
			try{
				st=con.createStatement();
				String updateString = "update testquestions set choiceC='"+update+"' where id='"+id+"'";
				st.executeUpdate(updateString);
				st.close();
				con.close();
										
			}catch(SQLException e){
				System.out.println("选项C修改失败");
			}
		}
		//更新choiceD
		public void updateChoiceD(int id,String update){
			try{
				st=con.createStatement();
				String updateString = "update testquestions set choiceD='"+update+"' where id='"+id+"'";
				st.executeUpdate(updateString);
				st.close();
				con.close();
										
			}catch(SQLException e){
				System.out.println("选项D修改失败");
			}
		}
		
		//更新标准答案
	    public void updateAnswer(int id,String update){
			try{
				st=con.createStatement();
				String updateString = "update testquestions set answer='"+update+"' where id='"+id+"'";
				st.executeUpdate(updateString);
				st.close();
				con.close();
										
			}catch(SQLException e){
				System.out.println("标准答案修改失败");
			}
		}
		
	//查询单个题目
	public ArrayList<QuestionVO> find(int id){
		ArrayList<QuestionVO> allQuestions=new ArrayList<QuestionVO>();
		try{
			st=con.createStatement();
			rs=st.executeQuery("select * from testquestions where id='"+id+"'");
			while(rs.next()){
				int quesId=rs.getInt(1);
				String quesQuestion=rs.getString(2);
				String quesA=rs.getString(3);
				String quesB=rs.getString(4);
				String quesC=rs.getString(5);
				String quesD=rs.getString(6);
				String quesAnswer=rs.getString(7);
				QuestionVO ques=new QuestionVO();
				ques.setId(quesId);
				ques.setQuestion(quesQuestion);
				ques.setA(quesA);
				ques.setB(quesB);
				ques.setC(quesC);
				ques.setD(quesD);
				ques.setAnswer(quesAnswer);
				allQuestions.add(ques);
			}
			rs.close();
			st.close();
			con.close();
			
		}catch(SQLException e){
			System.out.println("查询失败");
		}
		
		return allQuestions;
	}
	
	//查询所有题目
	public ArrayList<QuestionVO> getAll(){
		ArrayList<QuestionVO> allQuestions=new ArrayList<QuestionVO>();
		try{
			st=con.createStatement();
			rs=st.executeQuery("select * from testquestions");
			while(rs.next()){
				int quesId=rs.getInt(1);
				String quesQuestion=rs.getString(2);
				String quesA=rs.getString(3);
				String quesB=rs.getString(4);
				String quesC=rs.getString(5);
				String quesD=rs.getString(6);
				String quesAnswer=rs.getString(7);
				QuestionVO ques=new QuestionVO();
				ques.setId(quesId);
				ques.setQuestion(quesQuestion);
				ques.setA(quesA);
				ques.setB(quesB);
				ques.setC(quesC);
				ques.setD(quesD);
				ques.setAnswer(quesAnswer);
				allQuestions.add(ques);
			}
			rs.close();
			st.close();
			con.close();
			
		}catch(SQLException e){
			System.out.println("查询失败");
		}
		
		return allQuestions;
	}
	
	//查询所有题目答案
	public ArrayList<String> getAllAnswer(){
		ArrayList<String> ans = new ArrayList<String>();
		try{
			st=con.createStatement();
			rs=st.executeQuery("select * from testquestions");
			while(rs.next()){
				ans.add(rs.getString(7));
			}
			rs.close();
			st.close();
			con.close();
			
		}catch(SQLException e){
			System.out.println("答案查询失败");
		}
		
		return ans;
	}
	
	//查询所有题目内容
		public ArrayList<String> getAllQuestion(){
			ArrayList<String> que = new ArrayList<String>();
			try{
				st=con.createStatement();
				rs=st.executeQuery("select * from testquestions");
				while(rs.next()){
					que.add(rs.getString(2));
				}
				rs.close();
				st.close();
				con.close();
				
			}catch(SQLException e){
				System.out.println("题目查询失败");
			}
			
			return que;
		}
}

