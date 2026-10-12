/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bcf00; label: FUN_004bcf00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004bcf00(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x50b4) != 0) {
    return 0;
  }
  FUN_006217e0();
  iVar2 = FUN_006217e0();
  iVar3 = 0;
  *(int *)(param_1 + 0x50b4) = iVar2;
  if (0 < iVar2) {
    iVar2 = *(int *)(param_1 + 0x50b0) + 0x90;
    do {
      FUN_006216f0(iVar2 + -0x10,0x10);
      FUN_00621900(iVar2);
      uVar1 = FUN_00621860();
      *(undefined2 *)(iVar2 + 0x10) = uVar1;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc0;
    } while (iVar3 < *(int *)(param_1 + 0x50b4));
  }
  return 1;
}

