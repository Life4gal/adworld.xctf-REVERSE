import java.math.BigInteger;

/*
 * 原题见: https://adworld.xctf.org.cn/task/answer?type=reverse&number=4&grade=1&id=4908&page=1
 * 原题为同目录下的 Guess-the-Number.jar , 从中提取出来的字节码文件为 Guess.class
 */

public class Code {
    static String XOR(String _str_one, String _str_two) 
    {
        BigInteger i1 = new BigInteger(_str_one, 16);
        BigInteger i2 = new BigInteger(_str_two, 16);
        BigInteger res = i1.xor(i2);
        return res.toString(16);
    }

    public static void main(String[] args) 
    {
        String str_one = "4b64ca12ace755516c178f72d05d7061";
        String str_two = "ecd44646cfe5994ebeb35bf922e25dba";
        String answer = XOR(str_one, str_two);
        System.out.println("your flag is: " + answer);
    }
}
