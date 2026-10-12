/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45e1b0; label: FUN_0045e1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045e1b0(int param_1,int param_2,float param_3)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0xb9) == '\x03') {
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      if (((((*(uint *)(param_2 + 0xb0) & 0x400) == 0) && (*(char *)(param_2 + 0xba) == '\0')) &&
          ((*(uint *)(param_2 + 0xb0) & 0x40) == 0)) &&
         ((*(char *)(param_2 + 0xa7) == '\0' && (*(char *)(param_2 + 0xa6) == '\0')))) {
        FUN_00486940(0);
        return;
      }
      FUN_004838f0(param_2);
      return;
    }
  }
  else if (*(char *)(param_2 + 0xb9) == '\0') {
    *(undefined1 *)(param_2 + 0xb9) = 1;
    FUN_004cf4b0();
    iVar1 = FUN_0050c000();
    if (iVar1 == 0) {
      *(undefined1 *)(param_2 + 0xb9) = 3;
      FUN_00509830();
      return;
    }
  }
  else if (DAT_00921df8 == 0) {
    *(undefined1 *)(param_2 + 0xb9) = 3;
  }
  return;
}

