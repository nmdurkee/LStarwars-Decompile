/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x548640; label: FUN_00548640
 */

void FUN_00548640(int param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((((param_2 != 0) && (param_3 != (int *)0x0)) && (iVar1 = *param_3, iVar1 < param_4)) &&
     (param_1 != -1)) {
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(param_2 + iVar2 * 4) == param_1) {
          return;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    *(int *)(param_2 + iVar1 * 4) = param_1;
    *param_3 = *param_3 + 1;
  }
  return;
}

