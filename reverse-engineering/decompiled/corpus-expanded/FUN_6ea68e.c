/* Ghidra pseudocode, not original source.
 * ev_7917d444e56ee151ebe44b68491c815c9234e24f7023aa905c57d397c47edbbf
 * Entry: 0x6ea68e; label: __chgsign
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

