/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x423fa0; label: FUN_00423fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00423fa0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_0093b338 == 0) {
    if (((*(ushort *)(param_1 + 0x12) & 0x180) != 0) && (iVar1 = FUN_0055c880(), iVar1 == 0)) {
      return 0;
    }
    if (*(short *)(param_1 + 4) != -1) {
      iVar1 = FUN_00594250((int)*(short *)(param_1 + 4),0,0);
      if (iVar1 == -1) {
        return 1;
      }
      iVar1 = FUN_00594960((int)*(short *)(param_1 + 4));
      if (iVar1 == 0) {
        return 0;
      }
    }
    uVar2 = *(uint *)(param_1 + 0x14) & 0xc;
    if ((uVar2 != 0) && (iVar1 = FUN_00594a00(0xffffffff,uVar2), iVar1 == 0)) {
      return 0;
    }
    if ((*(char *)(param_1 + 0x11) != -1) &&
       (iVar1 = FUN_00594a00((int)*(char *)(param_1 + 0x11),0), iVar1 == 0)) {
      return 0;
    }
  }
  else if ((*(byte *)(param_1 + 0x12) & 0x10) != 0) {
    return 0;
  }
  return 1;
}

