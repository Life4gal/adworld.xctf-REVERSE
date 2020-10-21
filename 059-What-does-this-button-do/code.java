public class code{
public static void main(String[] args){
    String var3 = "";
    for(int var2 = 0; var2 < 22; ++var2){
        var3 = var3.concat(String.valueOf((char)(new int[]{102, 108, 97, 103, 123, 119, 52, 110, 110, 52, 95, 106, 52, 114, 95, 109, 121, 95, 100, 51, 120, 125})[var2]));
    }
    System.out.println(var3);
}
}
