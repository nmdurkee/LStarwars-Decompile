/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414bb0; label: FUN_00414bb0
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

