/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6bf0e0; label: FUN_006bf0e0
 */

void FUN_006bf0e0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_c [12];
  
  if (DAT_02973ae4 != 0) {
    if (*(int *)(param_2 + 0xc) == -1) {
      FUN_005d0480(local_c);
      puVar2 = local_c;
    }
    else {
      puVar2 = (undefined1 *)(*(int *)(param_2 + 0xc) + 0x18);
      iVar1 = FUN_005cfa50(puVar2);
      if (iVar1 != 0) {
        FUN_0061e530(*(undefined4 *)(DAT_02973ae4 + 4),iVar1);
      }
    }
    (**(code **)(**(int **)(DAT_02973ae4 + 8) + 8))
              (*(undefined4 *)(DAT_02973ae4 + 0xc),DAT_02973acc,puVar2,0,0);
  }
  return;
}

