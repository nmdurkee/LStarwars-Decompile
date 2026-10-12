/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x607820; label: FUN_00607820
 */

void FUN_00607820(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 != 0) && (*(int *)(*(int *)(param_1 + 8) + 0x20) != *(int *)(param_2 + 0x20))) {
    if (*(short *)(*(int *)(param_1 + 8) + 0x30) != *(short *)(param_2 + 0x30)) {
      iVar1 = FUN_005fcfd0(param_2);
      if (iVar1 != 0) {
        FUN_006034b0(param_1,0xa9,iVar1);
      }
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x30) = *(undefined2 *)(param_2 + 0x30);
    }
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x20) = *(undefined4 *)(param_2 + 0x20);
  }
  return;
}

