/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a2db0; label: FUN_006a2db0
 */

int FUN_006a2db0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((-1 < *(int *)(param_1 + 0x18)) && (*(int *)(param_1 + 0x18) < *(int *)(param_1 + 0x14))) {
    if (param_2 != (undefined4 *)0x0) {
      iVar2 = 0;
      if (0 < *(int *)(iVar1 + 4)) {
        do {
          *(int *)(*(int *)(param_1 + 0xc) + iVar2 * 4) =
               *(int *)(*(int *)(param_1 + 8) + iVar2 * 4) + *(int *)(param_1 + 0x18) * 4;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar1 + 4));
      }
      *param_2 = *(undefined4 *)(param_1 + 0xc);
    }
    return *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x18);
  }
  return 0;
}

