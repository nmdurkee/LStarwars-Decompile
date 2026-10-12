/* Ghidra pseudocode, not original source.
 * ev_7917d444e56ee151ebe44b68491c815c9234e24f7023aa905c57d397c47edbbf
 * Entry: 0x6ea668; label: __copysign
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __copysign
   
   Library: Visual Studio 2005 Release */

double __cdecl __copysign(double _Number,double _Sign)

{
  return (double)CONCAT44((_Sign._4_4_ ^ _Number._4_4_) & 0x7fffffff ^ _Sign._4_4_,SUB84(_Number,0))
  ;
}

