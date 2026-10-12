/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x628860; label: FUN_00628860
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00628860(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0xc);
  if (*(int *)(iVar1 + 0x50) != 0) {
    if (*(int *)(param_2 + 8) == 7) {
      FUN_0061a670(*(int *)(iVar1 + 0x50),_DAT_02912e98,_DAT_02912e9c,_DAT_02912ea0);
    }
    if (*(int *)(param_2 + 8) == 8) {
      FUN_0061a670(*(undefined4 *)(iVar1 + 0x50),0,0,_DAT_02912ea4);
    }
    if (*(code **)(iVar1 + 0x68) != (code *)0x0) {
      (**(code **)(iVar1 + 0x68))(param_1,param_2,param_3);
    }
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

