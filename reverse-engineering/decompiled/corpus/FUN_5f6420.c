/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f6420; label: FUN_005f6420
 */

undefined4 FUN_005f6420(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    if (*(int *)(param_1 + 4) < 0x414e4935) {
      uVar1 = FUN_005f3140(param_2,&param_1);
    }
    else {
      uVar1 = FUN_004f4f40(param_1);
    }
    return uVar1;
  }
  return 0;
}

