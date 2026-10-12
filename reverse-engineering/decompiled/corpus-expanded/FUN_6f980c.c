/* Ghidra pseudocode, not original source.
 * ev_77aeb2367ed99f8a41c442dae19643b7a9da5543c353c848e7914996f03c14a2
 * Entry: 0x6f980c; label: __set_exp
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __set_exp
   
   Library: Visual Studio 2005 Release */

float10 __set_exp(undefined8 param_1,short param_2)

{
  undefined8 local_c;
  
  local_c = (double)CONCAT26((param_2 + 0x3fe) * 0x10 | param_1._6_2_ & 0x800f,(undefined6)param_1);
  return (float10)local_c;
}

