/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5eabb0; label: FUN_005eabb0
 */

void FUN_005eabb0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    if (((byte)DAT_009738c4 & 2) == 0) {
      iVar1 = *(int *)(param_1 + 0x40) + 4;
    }
    else {
      iVar1 = 0;
    }
    FUN_005d10e0(iVar1,param_1,param_2,param_3,param_4);
  }
  return;
}

