/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x437390; label: FUN_00437390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

