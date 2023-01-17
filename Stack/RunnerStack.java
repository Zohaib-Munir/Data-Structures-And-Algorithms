public class RunnerStack {
    public static void main(String[] args) {
        StackJava s1 = new StackJava();
        s1.push(20);
        s1.push(59);
        s1.push(67);
        System.out.println("Capacity is "+s1.getCapacity());
        s1.push(78);
        s1.push(39);
        System.out.println("Capacity is "+s1.getCapacity());
        System.out.println("Top is "+s1.top());
        s1.display();
    }
}
