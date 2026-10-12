/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x4707a0; label: FUN_004707a0
 */

int FUN_004707a0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((*(int *)(param_1 + 0x4b0) != 0) && ((*(byte *)(param_1 + 0x559) & 1) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0x4b0) + 0x14) != 0)) {
    if (param_2 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)(param_1 + 0x40);
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_2 = *puVar2;
        puVar2 = puVar2 + 1;
        param_2 = param_2 + 1;
      }
    }
    return param_1 + 0x70;
  }
  if (param_2 != (undefined4 *)0x0) {
    puVar2 = &DAT_00806680;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
  }
  return param_1 + 0x48c;
}

