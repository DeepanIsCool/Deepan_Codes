package Day5;

// Define the Resizable interface with methods to resize width and height
interface Resizable {
    void resizeWidth(int width);

    void resizeHeight(int height);
}

// Implement the Rectangle class that implements the Resizable interface
class Rectangle implements Resizable {
    private int width;
    private int height;

    // Constructor to initialize width and height
    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    // Implement the resizeWidth method
    @Override
    public void resizeWidth(int width) {
        this.width = width;
    }

    // Implement the resizeHeight method
    @Override
    public void resizeHeight(int height) {
        this.height = height;
    }

    // Method to display the dimensions of the rectangle
    public void displayDimensions() {
        System.out.println("Width: " + this.width);
        System.out.println("Height: " + this.height);
    }

    public static void main(String[] args) {
        // Create a Rectangle object
        Rectangle rectangle = new Rectangle(10, 20);

        // Display the initial dimensions
        System.out.println("Initial Dimensions:");
        rectangle.displayDimensions();

        // Resize the rectangle
        rectangle.resizeWidth(15);
        rectangle.resizeHeight(25);

        // Display the resized dimensions
        System.out.println("Resized Dimensions:");
        rectangle.displayDimensions();
    }
}