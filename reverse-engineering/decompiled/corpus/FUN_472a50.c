/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x472a50; label: FUN_00472a50
 */

undefined4 FUN_00472a50(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x5074) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xeb) != '\0') {
    uVar2 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x5074) = uVar2;
    puVar1 = *(undefined4 **)(param_1 + 0x5074);
    *(uint *)(param_1 + 0x104) = uVar2 + 0x10;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    uVar2 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x104) = uVar2;
    *(uint *)(*(int *)(param_1 + 0x5074) + 0xc) = uVar2;
    *(int *)(param_1 + 0x104) =
         *(int *)(param_1 + 0x104) + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xfd) * 0xa0;
    _memset(*(void **)(*(int *)(param_1 + 0x5074) + 0xc),0,
            (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xfd) * 0xa0);
  }
  return *(undefined4 *)(param_1 + 0x5074);
}

