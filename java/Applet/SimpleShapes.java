import java.applet.*;
import java.awt.*;

public class SimpleShapes extends Applet {

    public void paint(Graphics g) {
        g.drawLine(10, 10, 20, 20);
        g.drawRect(50, 50, 150, 100);
        g.drawArc(200, 200, 100, 100, 0, 180);
    }
}
