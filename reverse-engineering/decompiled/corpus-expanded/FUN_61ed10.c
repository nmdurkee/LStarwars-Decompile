/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61ed10; label: FUN_0061ed10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061ed10(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (((byte)DAT_02912ec8 & 0x40) != 0) {
    if (*(code **)(iVar1 + 0x68) != (code *)0x0) {
      (**(code **)(iVar1 + 0x68))(*(undefined4 *)(param_1 + 0x10),iVar1,0);
    }
    iVar2 = FUN_0061ec40();
    if ((iVar2 != 0) && (*(int *)(iVar1 + 0x4c) != 0)) {
      if ((*(byte *)(iVar1 + 0x54) & 1) != 0) {
        FUN_0061eb60(iVar1);
        return 0;
      }
      FUN_0061eb20();
    }
  }
  return 0;
}

