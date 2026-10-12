/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x470e10; label: FUN_00470e10
 */

void FUN_00470e10(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = *(int *)(param_1 + 0x46ec);
    if (iVar1 != 0) {
      *(undefined4 *)(param_2 + 0x2810) = *(undefined4 *)(iVar1 + 0x48c);
      *(undefined4 *)(param_2 + 0x2814) = *(undefined4 *)(iVar1 + 0x484);
      *(undefined4 *)(param_2 + 0x2818) = *(undefined4 *)(iVar1 + 0x494);
      return;
    }
    *(undefined4 *)(param_2 + 0x2814) = 0x49f42400;
  }
  return;
}

