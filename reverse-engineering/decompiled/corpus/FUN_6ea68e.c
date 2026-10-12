/* Ghidra analysis pseudocode, not original source.
 * ev_9ad7a170f646401050a4bdb160dd6a58b6970b37c021c3b7525074b06431e013
 * Entry: 0x6ea68e; label: __chgsign
 */

/* Library Function - Single Match
    __chgsign
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release,
   Visual Studio 2012 Release */

double __cdecl __chgsign(double _X)

{
  undefined8 local_c;
  
  local_c = (double)(CONCAT44(~_X._4_4_,SUB84(_X,0)) ^ 0x7fffffff00000000);
  return local_c;
}

