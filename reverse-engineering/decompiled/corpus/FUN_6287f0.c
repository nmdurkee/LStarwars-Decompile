/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x6287f0; label: FUN_006287f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006287f0(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0xc) + 0x50);
  if (iVar1 != 0) {
    if (*(int *)(param_2 + 8) == 7) {
      _DAT_02912e98 = *(undefined4 *)(iVar1 + 0x10);
      _DAT_02912e9c = *(undefined4 *)(iVar1 + 0x14);
      _DAT_02912ea0 = *(undefined4 *)(iVar1 + 0x18);
    }
    if (*(int *)(param_2 + 8) == 8) {
      _DAT_02912ea4 = *(undefined4 *)(iVar1 + 0x18);
    }
    pcVar2 = *(code **)(*(int *)(param_2 + 0xc) + 100);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(param_1,param_2,param_3);
    }
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

