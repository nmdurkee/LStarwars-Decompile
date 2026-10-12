/* Ghidra pseudocode, not original source.
 * ev_77aeb2367ed99f8a41c442dae19643b7a9da5543c353c848e7914996f03c14a2
 * Entry: 0x6f9ea1; label: __set_errno_from_matherr
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __set_errno_from_matherr
   
   Library: Visual Studio 2005 Release */

void __set_errno_from_matherr(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 1) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x21;
  }
  else if ((1 < param_1) && (param_1 < 4)) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x22;
    return;
  }
  return;
}

