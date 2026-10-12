/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b44f0; label: FUN_006b44f0
 */

undefined4
FUN_006b44f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_5) {
    puVar1 = param_3;
    do {
      if (*(int *)((param_4 - (int)param_3) + (int)puVar1) != 0) {
        param_3[iVar3] = *puVar1;
        iVar3 = iVar3 + 1;
      }
      puVar1 = puVar1 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    if (iVar3 != 0) {
      uVar2 = FUN_006b3960(param_2,param_3,iVar3);
      return uVar2;
    }
  }
  return 0;
}

