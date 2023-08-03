import java.io.*;
class SymTab
{
    public static void main(String args[])throws Exception
    {
        FileReader FP = new FileReader(args[0]);
        BufferedReader br = new BufferedReader(FP);
        String line = null;
        int line_count = 0, LC = 0, symTabLine = 0, opTabLine = 0, litTabLine = 0, poolTabLine = 0;
        final int MAX = 100;
        String SymbolTable[][] = new String[MAX][3];
        String OpTable[][] = new String[MAX][3];
        String LitTable[][] = new String[MAX][2];
        int PoolTable[] = new int[MAX];
        int litTabAddress = 0;
        System.out.println("___________________________________________________");

        while((line = BufferedReader.readLine()) != null)
        {
            String[] tokens = line.split("\t");
            if(line_count == 0)
            {
                LC = Integer.parseInt(tokens[2]);
                for(int i = 0; i < tokens.length; i++)
                    System.out.print(tokens[i] + "\t");
                System.out.println("");
            }
            else
            {
                for(int i = 0; i < tokens.length; i++)
                    System.out.print(tokens[i] + "\t");
                System.out.println();
                if(!tokens[0].equals(""))
                {
                    SymbolTable[symTabLine][0] = token[0];
                    SymbolTable[symTabLine][1] = Integer.toString(LC);
                    SymbolTable[symTabLine][2] = Integer.toString(1);
                    symTabLine++;
                }
                else if(tokens[1].equalsIgnoreCase("DS") || tokens[1].equalsIgnoreCase("DC"))
                {
                    SymbolTable[symTabLine][0] = token[0];
                    SymbolTable[symTabLine][1] = Integer.toString(LC);
                    SymbolTable[symTabLine][2] = Integer.toString(1);
                    symTabLine++;
                }
                if(tokens.length == 3 && tokens[2].charAt(0) == '=')
                {
                    LitTable[litTabLine][0] = tokens[2];
                    LitTable[litTabLine][1] = Integer.toString(LC);
                    litTabLine++;
                }
                else if(tokens[1] != NULL)
                {
                    OpTable[opTabLine][0] = tokens[1];
                    
                    if(tokens[1].equalsIgnoreCase("START") || tokens[1].equalsIgnoreCase("END") || tokens[1].equalsIgnoreCase("ORIGIN") || tokens[1].equalsIgnoreCase("EQU") || tokens[1].equalsIgnoreCase("LTORG"))
                    {
                        OpTable[opTabLine][1] = "AD";
                        OpTable[opTabLine][2] = "R11";
                    }
                    else if(tokens[1].equalsIgnoreCase("DS") || tokens[1].equalsIgnoreCase("DC"))
                    {
                        OpTable[opTabLine][1] = "DL";
                        OpTable[opTabLine][2] = "R7";
                    }
                    else
                    {
                        OpTable[opTabLine][1] = "IS";
                        OpTable[opTabLine][2] = "(04, 1)";
                    }
                    opTabLine++;
                }
            }
            line_count++;
            LC++;            
        }
        System.out.println("___________________________________________________");  

        System.out.println("\n\n	SYMBOL TABLE		");
        System.out.println("--------------------------");
        System.out.println("SYMBOL\tADDRESS\tLENGTH");
        System.out.println("--------------------------");
        for(int i = 0; i < symTabLine; i++)
        {
            System.out.println(SymbolTable[i][0] + "\t" + SymbolTable[i][1] + "\t" + SymbolTable[i][2]);
        }
        System.out.println("--------------------------");

        System.out.println("\n\n	OPCODE TABLE		");
		System.out.println("----------------------------");	
        System.out.println("MNEMONIC\tCLASS\tINFO");
        for(int i = 0; i < opTabLine; i++)
        {
            System.out.println(OpTable[i][0] + "\t" + OpTable[i][1] + "\t" + OpTable[i][2]);
        }
        System.out.println("--------------------------");

        System.out.println("\n\n   LITERAL TABLE		");
        System.out.println("-----------------");
        System.out.println("LITERAL\tADDRESS");
        System.out.println("-----------------");	
        for(int )
    }
}