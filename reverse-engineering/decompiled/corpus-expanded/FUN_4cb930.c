/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cb930; label: FUN_004cb930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cb930(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(byte *)(*(int *)(*(int *)(*param_2 + 0x54) + 0x24) + 0x90) & 0x40) != 0) {
    iVar1 = *(int *)(*param_2 + 0xcd0);
    if (iVar1 != 0) {
      iVar2 = (uint)*(byte *)((*(char *)(param_1 + 0x160) == '\0') + 0x10 +
                             *(int *)(param_1 + 0x15c)) * 0x5c +
              *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
      FUN_004882d0(iVar1,1);
      FUN_00561e20(iVar1,iVar2 + 4,0,0x3f000000,0x3f800000,0);
      FUN_0043cbb0(iVar1,iVar2,0,3);
    }
    return 1;
  }
  return 0;
}

