import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleCalculator {
    JFrame frame;
    JTextField tf1, tf2;
    JButton addButton, subButton;
    JLabel resultLabel;

    public SimpleCalculator() {
        frame = new JFrame("Simple Calculator");
        frame.setSize(300, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        tf1 = new JTextField(10);
        tf2 = new JTextField(10);
        addButton = new JButton("Add");
        subButton = new JButton("Subtract");
        resultLabel = new JLabel("Result: ");

        frame.add(new JLabel("Number 1:"));
        frame.add(tf1);
        frame.add(new JLabel("Number 2:"));
        frame.add(tf2);
        frame.add(addButton);
        frame.add(subButton);
        frame.add(resultLabel);

        addButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    double num1 = Double.parseDouble(tf1.getText());
                    double num2 = Double.parseDouble(tf2.getText());
                    resultLabel.setText("Result: " + (num1 + num2));
                } catch (NumberFormatException ex) {
                    resultLabel.setText("Please enter valid numbers");
                }
            }
        });

        subButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    double num1 = Double.parseDouble(tf1.getText());
                    double num2 = Double.parseDouble(tf2.getText());
                    resultLabel.setText("Result: " + (num1 - num2));
                } catch (NumberFormatException ex) {
                    resultLabel.setText("Please enter valid numbers");
                }
            }
        });

        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new SimpleCalculator();
            }
        });
    }
}
