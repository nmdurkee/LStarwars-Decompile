/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x424750; label: FUN_00424750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

