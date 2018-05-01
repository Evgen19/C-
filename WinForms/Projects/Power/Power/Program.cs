//Вычислить целые степени числа 2.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Power
{
    class Program
    {
        static void Main(string[] args)
        {
            int e;
            int result;

            for(int i=0; i<10; i++)
            {
                result = 1;
                e = i;

                while(e>0)
                {
                    result *= 2;
                    e--;
                }
                Console.WriteLine("2 в степени " + i + " равно " + result);
            }
            Console.Read();
            
        }
    }
}
