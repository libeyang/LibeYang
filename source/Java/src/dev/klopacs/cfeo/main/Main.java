package dev.klopacs.cfeo.main;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Date;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	
	/*
	 * Program Made By Moon Seok Khang °­¹®¼®
	 * 
	 * Code4Every1 Data File Translator
	 * 
	 */
	
	
	public static Scanner sc;
	public static Vector<String> readData = new Vector<String>();
	public static Vector<String> writeData = new Vector<String>();
	public static Vector<String> componentNames = new Vector<String>();
	public static HashMap<String, Vector<String>> events = new HashMap<String, Vector<String>>();
	public static int cn = 0;
	
	//public static HashMap<String, JButton> buttons = new HashMap<String, JButton>();
	//public static HashMap<String, JLabel> labels = new HashMap<String, JLabel>();
	//public static HashMap<String, JTextArea> memos = new HashMap<String, JTextArea>();
	//public static HashMap<String, JCheckBox> checkboxes = new HashMap<String, JCheckBox>();
	//public static HashMap<String, JComboBox> comboboxes = new HashMap<String, JComboBox>();
	//public static HashMap<String, JTextField> edits = new HashMap<String, JTextField>();
	//public static JFrame Form;
	
	
	public static void main(String args[]){
		new Main(args[0]);
		//new Main("C:\\Code4Every1\\Translate.cfeo");
	}
	
	public Main(String filename){
		
		int cutpoint = 0;
	    char[] chars = filename.replace(".cfeo", ".java").toCharArray();
	    
	    for (int i = 0; i < filename.replace(".cfeo", ".java").length(); i++){
	    	if (chars[i] == '\\')
	    		cutpoint = i;
	    }
		
		
		String[] forecode = {
				"import javax.swing.*;",
				"import java.awt.*;",
				"import java.io.*;",
				"import java.util.*;",
				"import java.awt.event.*;",
				"public class Translate {",
				"public static void main(String[] args) {",
				"JFrame Form = new JFrame(\"Unknown Window\");",
				"Form.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);",
				"Form.setEnabled(true);",
				"Form.setVisible(true);"
		};
		
		printConsole("Finished Inserting Forecode...");
		
		
		for (int i = 0; i < forecode.length; i++){
			writeData.add(forecode[i]);
			printConsole("Writing Line : " + forecode[i]);
		}
		
		
		try {
			
			sc = new Scanner(new File(filename));
			
			
			while(sc.hasNext()) {
				readData.add(sc.nextLine());	
			}
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		
		for (int i = 0; i < readData.size(); i++){
				
			String kstr = readData.get(i);
			
			try {
				kstr = new String(readData.get(i).getBytes("x-windows-949"), "ksc5601");
			} catch (UnsupportedEncodingException e) {
				e.printStackTrace();
			}
			
			String command[] = kstr.split(" ");
			
			if (command[0].equals("new")) {
				
				registerComponent(command[1]);
				
			} else if (command[0].equals("event")) {
				
				addEvent(command[1], command[2]);
				
			} else {
				
				setProperty(command[0], command[1], command[2]);
				
			}

		}

		
			
		
		for (int y = 0; y < componentNames.size(); y++){
			
			if (events.containsKey(componentNames.get(y))) {
				
				writeData.add(componentNames.get(y) + ".addMouseListener(new MouseAdapter(){");
				writeData.add("@Override");
				writeData.add("public void mouseClicked(MouseEvent e){");
				
				
				for (int z = 0; z < events.get(componentNames.get(y)).size(); z++) {
					writeData.add(events.get(componentNames.get(y)).get(z));
				}
				
				writeData.add("}");
				writeData.add("});");
				
			}
			
		}
		
		writeData.add("Form.getContentPane().setLayout(null);");
		
		for (int a = 0; a < componentNames.size(); a++){
			writeData.add(componentNames.get(a) + ".setFont(new Font(\"¸¼Àº °íµñ\", Font.PLAIN, 15));");
			writeData.add("Form.getContentPane().add(" + componentNames.get(a) + ");");
			
		}
		
		writeData.add("Form.pack();");
		writeData.add("Form.repaint();");
		
		writeData.add("}");
		writeData.add("}");
		
		try {
			
			PrintWriter pw = new PrintWriter(new File(filename.replace(".cfeo", ".java")), "UTF-8");
				
			for (int i = 0; i < writeData.size(); i++){
				
				
				
				pw.println(new String(writeData.get(i).getBytes("x-windows-949"), "ksc5601"));
				printConsole(writeData.get(i));
					
			}
			
				
			pw.close();
			
			Process pro0 = Runtime.getRuntime().exec("javac -encoding UTF-8 C:\\Code4Every1\\Translate.java");
			pro0.waitFor();
			printConsole("Compile Completed With Exit Code : " + pro0.exitValue());

		    for (int i = 0; i < filename.replace(".cfeo", ".java").length(); i++){
		    	if (chars[i] == '\\')
		    		cutpoint = i;
		    }
		    
			Process pro = Runtime.getRuntime().exec("java -Dfile.encoding=UTF-8 -cp C:\\Code4Every1\\ Translate");
			pro.waitFor();
			printConsole("Open Completed With Exit Code : " + pro.exitValue());
	
			printConsole("Exit.");
			
		} catch (Exception e) {
				
			e.printStackTrace();
				
		}
		
		
		
		
		
		
	}
	
	
	
	
	
	
	public static void setProperty(String componentName, String property, String value){

		
		int values[];
		
		if (componentName.contains("button") || componentName.contains("edit") || componentName.contains("label")){
			if (property.equals("text")) {
				writeData.add(componentName + ".setText(\"" + convertString(value) + "\");");
			} if (property.equals("size")) {
				values = getDimension(value);
				writeData.add(componentName + ".setSize(new Dimension(" + values[0] + ", " + values[1] + "));");
			} if (property.equals("position")) {
				values = getDimension(value);
				writeData.add(componentName + ".setLocation(" + values[0] + ", " + values[1] + ");");
				cn++;
			}
		} if (componentName.contains("memo")) {
			if (property.equals("lines")) {
				String str[] = getStringVector(value);
				for (int i = 0; i < str.length; i++){
					writeData.add(componentName + ".setText(" + componentName + ".getText() + \"" + str[i].replace("_", " ") + "\\n\");");
				}
			} if (property.equals("size")) {
				values = getDimension(value);
				writeData.add(componentName + ".setSize(new Dimension(" + values[0] + ", " + values[1] + "));");
			} if (property.equals("position")) {
				values = getDimension(value);
				writeData.add(componentName + ".setLocation(" + values[0] + ", " + values[1] + ");");
				cn++;
			}
		} if (componentName.contains("combobox")) {
			if (property.equals("items")) {
				String str[] = getStringVector(value);
				for (int j = 0; j < str.length; j++){
					writeData.add(componentName + ".addItem(\"" + str[j].replace("_", " ") + "\");");
				}
			} if (property.equals("size")) {
				values = getDimension(value);
				writeData.add(componentName + ".setSize(new Dimension(" + values[0] + ", " + values[1] + "));");
			} if (property.equals("position")) {
				values = getDimension(value);
				writeData.add(componentName + ".setLocation(" + values[0] + ", " + values[1] + ");");
				cn++;
			}
		} if (componentName.contains("checkbox")) {
			if (property.equals("text")) {
				writeData.add(componentName + ".setText(\"" + convertString(value) + "\");");
			} if (property.equals("size")) {
				values = getDimension(value);
				writeData.add(componentName + ".setSize(new Dimension(" + values[0] + ", " + values[1] + "));");
			} if (property.equals("position")) {
				values = getDimension(value);
				writeData.add(componentName + ".setLocation(" + values[0] + ", " + values[1] + ");");
				cn++;
			} if (property.equals("checked")) {
				writeData.add(componentName + ".setSelected(" + value + ");");
			}
		} if (componentName.contains("form")) {
			if (property.equals("text")) {
				writeData.add("Form.setTitle(\"" + convertString(value) + "\");");
			} if (property.equals("size")) {
				values = getDimension(value);
				writeData.add("Form.setPreferredSize(new Dimension(" + values[0] + ", " + values[1] + "));");
			} if (property.equals("position")) {
				values = getDimension(value);
				writeData.add("Form.setLocation(" + values[0] + ", " + values[1] + ");");
				cn++;
			}
		}
		
	}
	
	

	
	public static String convertString(String str){
		String convertstr = "";
		convertstr = str.replace('_', ' ').replace("\"", "");
		return convertstr;
	}

	public static void registerComponent(String componentName){
		
		if (componentName.contains("button")){
			writeData.add(String.valueOf("JButton " + componentName + " = new JButton();"));
			componentNames.add(componentName);
		}
		if (componentName.contains("label")){
			writeData.add(String.valueOf("JLabel " + componentName + " = new JLabel();"));
			componentNames.add(componentName);
		}
		if (componentName.contains("memo")){
			writeData.add(String.valueOf("JTextArea " + componentName + " = new JTextArea();"));
			componentNames.add(componentName);
		}
		if (componentName.contains("checkbox")){
			writeData.add(String.valueOf("JCheckBox " + componentName + " = new JCheckBox();"));
			componentNames.add(componentName);
		}
		if (componentName.contains("combobox")){
			writeData.add(String.valueOf("JComboBox<String> " + componentName + " = new JComboBox<String>();"));
			componentNames.add(componentName);
		}
		if (componentName.contains("edit")){
			writeData.add(String.valueOf("JTextField " + componentName + " = new JTextField();"));
			componentNames.add(componentName);
		}
		
	}
	
	public static int[] getDimension(String source){
		
		String parts[] = source.split(";");
		
		for (int i = 0; i < parts.length; i++){
			parts[i] = String.valueOf(parts[i]);
		}
		
		int value[] = new int[parts.length];
		
		for (int i = 0; i < parts.length; i++){
			value[i] = Integer.parseInt(parts[i]);
		}
		
		return value;
		
	}
	
	public static String[] getStringVector(String source){
		
		String str = "";
		
		str = source.replace('_', ' ');
		
		String parts[] = str.split(";");
		
		for (int i = 0; i < parts.length; i++){
			parts[i] = String.valueOf(parts[i]);
			parts[i] = parts[i].replace("\"", "");
		}
		
		return parts;
		
	}
	
	public static void addEvent(String componentName, String eventvalue) {
		if (!events.containsKey(componentName)) {
			events.put(componentName, new Vector<String>());
		}
		
		String returnString = "";
		String parts[] = eventvalue.split("#");
		
		if (parts[0].equals("pop")) {
			if (parts[2].equals("_")){
				returnString = "JOptionPane.showMessageDialog(null, " + parts[1].replace("_", " ") + ");";	
			} else {
				if (parts[3].equals("text")) {
					returnString = "JOptionPane.showMessageDialog(null, " + parts[2] + ".getText());";
				}
				if (parts[3].equals("selected")) {
					returnString = "JOptionPane.showMessageDialog(null, " + parts[2] + ".getSelectedItem());";
				}
			}		
		} else {
			if (!parts[3].equals("_")){
				if (parts[1].equals("text")) {
					if (parts[3].equals("selected")) {
						returnString = parts[0] + ".setText(" + parts[2] + ".getSelectedItem().toString());";
					} else {
						returnString = parts[0] + ".setText(" + parts[2] + ".getText());";
					}
				}
				if (parts[1].equals("size")) {
					if (parts[3].equals("position"))
						returnString = parts[0] + ".setSize(" + parts[2] + ".getX(), " + parts[2] + ".getY());";
					else
						returnString = parts[0] + ".setSize(" + parts[2] + ".getWidth(), " + parts[2] + ".getWidth());";
				}
				if (parts[1].equals("position")) {
					returnString = parts[0] + ".setLocation(" + parts[2] + ".getX(), " + parts[2] + ".getY());";
				}
				if (parts[1].equals("checked")) {
					returnString = parts[0] + ".setSelected(" + parts[2] + ".isSelected());";
				}
				
			} else {
				if (eventvalue.contains("text")) {
					returnString = parts[0] + ".setText(" + parts[2].replace("_", " ") + ");";
				}
				if (eventvalue.contains("size")) {
					int values[] = getDimension(parts[2]);
					returnString = parts[0] + ".setSize(" + values[0] + ", " + values[1] + ");";
				}
				if (eventvalue.contains("position")) {
					int values[] = getDimension(parts[2]);
					returnString = parts[0] + ".setLocation(" + values[0] + ", " + values[1] + ");";
				}
				if (eventvalue.contains("checked")) {
					returnString = parts[0] + ".setSelected(" + parts[2] + ");";
				}
			}
		}
		
		events.get(componentName).add(returnString);
			
			
			
		
		

	}
	

	
	
	public static void printConsole(String str) {
		System.out.println("[" + new Date().toString() + "] Code4Every1 Translator Console >>> " + str);
	}
	

	
	public static String toKSC5601(String s){ 
		if(s == null){ 
			return null; 
		} 
		try { 
			return new String(s.getBytes("8859_1"),"KSC5601"); 
		} catch(Exception e){
			return s;
		} 
	}
	
}
