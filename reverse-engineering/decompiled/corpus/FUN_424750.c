/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x424750; label: FUN_00424750
 */

undefined4 FUN_00424750(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = FUN_0062df80((int)*(short *)(param_1 + 0x6c));
    if ((iVar1 != 0) &&
       ((*(short *)(param_1 + 0x1b2) == 0xbe || (*(short *)(param_1 + 0x1b2) == 99)))) {
      iVar1 = FUN_0062df80((int)*(short *)(param_1 + 0x6e));
      if ((iVar1 != 0) &&
         ((*(short *)(param_1 + 0x1fa) == 0xbe || (*(short *)(param_1 + 0x1fa) == 99)))) {
        return 1;
      }
    }
  }
  return 0;
}

