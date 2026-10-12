/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x440df0; label: FUN_00440df0
 */

/* WARNING: Removing unreachable block (ram,0x00440e10) */

float10 FUN_00440df0(undefined4 param_1,undefined4 param_2,int param_3)

{
  float10 fVar1;
  
  if (param_3 == 0) {
    fVar1 = (float10)0;
  }
  else {
    fVar1 = (float10)(*(uint *)(param_3 + 0x1e8) >> 0xb & 1);
  }
  return fVar1;
}

