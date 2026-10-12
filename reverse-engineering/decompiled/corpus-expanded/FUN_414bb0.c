/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414bb0; label: FUN_00414bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00414bb0(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xcd0) != 0) {
      if ((*(uint *)(param_1 + 0x1f8) & 0x4000) == 0) {
        FUN_004364e0(*(int *)(param_1 + 0xcd0),4,0);
      }
      else {
        FUN_004882d0(param_1,1);
      }
    }
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xffffefff;
    if (*(char *)(param_1 + 0x400) != -1) {
      iVar1 = FUN_0052c790(param_1 + 0x2c8,"InActive");
      if (iVar1 != 0) {
        *(undefined1 *)(param_1 + 0x406) = 0;
        *(undefined1 *)
         ((uint)*(byte *)(param_1 + 0x400) * 0xa4 + 0x87 +
         *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x18)) = 2;
        return;
      }
    }
    *(undefined1 *)(param_1 + 0x406) = 4;
  }
  return;
}

