/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x441020; label: FUN_00441020
 */

float10 FUN_00441020(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_004678f0(**(undefined4 **)(param_3 + 0xd0),param_5);
  if (iVar1 != 0) {
    return (float10)1;
  }
  return (float10)0;
}

