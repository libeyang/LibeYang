import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.*;
import java.awt.event.*;
public class Translate {
public static void main(String[] args) {
JFrame Form = new JFrame("Unknown Window");
Form.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
Form.setEnabled(true);
Form.setVisible(true);
JButton button0 = new JButton();
JLabel label0 = new JLabel();
JTextField edit0 = new JTextField();
JTextArea memo0 = new JTextArea();
JLabel label1 = new JLabel();
Form.setTitle("작업창");
Form.setPreferredSize(new Dimension(800, 628));
Form.setLocation(889, 73);
button0.setText("앙?");
button0.setSize(new Dimension(100, 40));
button0.setLocation(100, 160);
label0.setText("글씨0");
label0.setSize(new Dimension(151, 28));
label0.setLocation(100, 210);
edit0.setText("입력");
edit0.setSize(new Dimension(100, 36));
edit0.setLocation(100, 100);
memo0.setText(memo0.getText() + "큰\n");
memo0.setSize(new Dimension(100, 100));
memo0.setLocation(500, 260);
label1.setText("글씨1");
label1.setSize(new Dimension(151, 28));
label1.setLocation(400, 220);
button0.addMouseListener(new MouseAdapter(){
@Override
public void mouseClicked(MouseEvent e){
JOptionPane.showMessageDialog(null, "기모띠?!");
}
});
Form.getContentPane().setLayout(null);
button0.setFont(new Font("맑은 고딕", Font.PLAIN, 15));
Form.getContentPane().add(button0);
label0.setFont(new Font("맑은 고딕", Font.PLAIN, 15));
Form.getContentPane().add(label0);
edit0.setFont(new Font("맑은 고딕", Font.PLAIN, 15));
Form.getContentPane().add(edit0);
memo0.setFont(new Font("맑은 고딕", Font.PLAIN, 15));
Form.getContentPane().add(memo0);
label1.setFont(new Font("맑은 고딕", Font.PLAIN, 15));
Form.getContentPane().add(label1);
Form.pack();
Form.repaint();
}
}
