/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x437390; label: FUN_00437390
 */

undefined4 FUN_00437390(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x28b) != '\0') {
    return 0;
  }
  if (param_3 == 0) {
    if (0.0 < *(float *)(param_1 + 0x1000)) {
      return 0;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1000) = 0;
  }
  if (DAT_0093b324 != 0) {
    uVar2 = 0;
    if (*(char *)(param_1 + 0x280) == '\0') {
      iVar1 = 1;
    }
    else {
      if (*(char *)(param_1 + 0x280) != '\x01') goto LAB_00437406;
      iVar1 = 0;
    }
    if (((&DAT_0093d7f0)[iVar1] != 0) &&
       ((*(uint *)((&DAT_0093d7f0)[iVar1] + 0x1f8) & 0x40000) != 0)) {
      uVar2 = 1;
    }
    FUN_00475fb0(iVar1,uVar2);
  }
LAB_00437406:
  uVar2 = FUN_004364e0(param_1,param_2,0);
  return uVar2;
}

