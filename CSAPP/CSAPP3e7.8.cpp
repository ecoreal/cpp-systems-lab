A.    /* Module 1 */            /* Module 2 */

      int main()                static int main=1;

      {                         int p2()

      }                         {

                                }

    (a) REF(main.1) ¡ú DEF(main.1)
    (b) REF(main.2) ¡ú DEF(main.2)

B.    /* Module 1 */            /* Module 2 */

      int x;                    double x;

      void main()               int p2()

      {                         {

      }                         }

    (a) REF(x.1) ¡ú Î´Öª 
    (b) REF(x.2) ¡ú Î´Öª 

C.    /* Module 1 */            /* Module 2 */

      int x=1;                  double x=1.0;

      void main()               int p2()

      {                         {

      }                         }

    (a) REF(x.1) ¡ú ´íÎó 
    (b) REF(x.2) ¡ú ´íÎó 
