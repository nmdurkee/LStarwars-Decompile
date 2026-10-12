/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x6083d0; label: FUN_006083d0
 */

void FUN_006083d0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00741620((int)*(short *)(param_1 + 0x1f6));
  if (iVar1 != 0) {
    DAT_02854c20 = param_1;
    if (((*(uint *)(param_1 + 0x1f0) & 0x300000) == 0) && (*(int *)(param_1 + 0x3c) != 0)) {
      FUN_00742730(iVar1,param_1);
      FUN_00741640(iVar1);
      FUN_006e56c0(*(undefined4 *)(param_1 + 700));
    }
    if ((*(uint *)(param_1 + 0x40) & 0xc000) == 0x4000) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40);
    }
    FUN_00601360(param_1);
    FUN_006e5340(0x1b,0);
  }
  return;
}

