/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e8380; label: FUN_004e8380
 */

undefined4 FUN_004e8380(int param_1,int param_2,int param_3)

{
  float10 fVar1;
  
  if (((((*(byte *)(param_1 + 0xef4) & 2) != 0) && (DAT_0088a54c != 0)) &&
      (*(int *)(param_1 + 0xcd0) == 0)) &&
     ((param_2 != 0 && ((*(byte *)(param_2 + 0x1fc) & 0x80) != 0)))) {
    fVar1 = (float10)FUN_005b3c50(param_1 + 0x5c,param_2 + 0x5c,param_3);
    if (fVar1 < (float10)0.4899999797344208) {
      FUN_005b3620(param_3,param_3,-(uint)*(ushort *)(param_2 + 0x27a));
      if (0.0 < *(float *)(param_3 + 8)) {
        return 1;
      }
    }
  }
  return 0;
}

