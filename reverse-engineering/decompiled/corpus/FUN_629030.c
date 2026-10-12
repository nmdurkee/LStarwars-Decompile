/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x629030; label: FUN_00629030
 */

undefined4 FUN_00629030(int param_1,int param_2)

{
  int iVar1;
  int extraout_EDX;
  int iVar2;
  
  if ((param_2 != 0) && ((*(byte *)(param_2 + 0x78) & 0x10) != 0)) {
    iVar1 = *(int *)(param_1 + 0x40);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
    if ((DAT_02912f30 == 0) && (iVar1 != 0)) {
      FUN_006279f0(param_1);
      param_1 = extraout_EDX;
    }
    if (*(code **)(param_1 + 0x30) != (code *)0x0) {
      (**(code **)(param_1 + 0x30))(param_1,iVar2);
    }
    return 1;
  }
  return 0;
}

