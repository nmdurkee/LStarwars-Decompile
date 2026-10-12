/* Ghidra pseudocode, not original source.
 * ev_77aeb2367ed99f8a41c442dae19643b7a9da5543c353c848e7914996f03c14a2
 * Entry: 0x6fa007; label: __handle_qnan2
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __handle_qnan2
   
   Library: Visual Studio 2005 Release */

float10 __handle_qnan2(undefined4 param_1,double param_2,double param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  float10 fVar2;
  
  if (DAT_0082a740 == 0) {
    fVar2 = (float10)__umatherr(1,param_1,param_2,param_3,param_2 + param_3,param_4);
    return fVar2;
  }
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 0x21;
  __ctrlfp();
  return (float10)(param_2 + param_3);
}

