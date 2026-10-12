/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500a90; label: FUN_00500a90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00500a90(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x58) + 0x18);
  iVar5 = 0;
  if ((short)piVar1[1] != 0) {
    iVar4 = 0;
    do {
      iVar2 = *piVar1;
      iVar3 = FUN_004f8b10(param_2,*(undefined4 *)(iVar2 + 0x40 + iVar4));
      if (iVar3 == 0) {
        puVar6 = (undefined4 *)(iVar2 + iVar4);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *param_3 = *puVar6;
          puVar6 = puVar6 + 1;
          param_3 = param_3 + 1;
        }
        return 1;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 100;
    } while (iVar5 < (int)(uint)*(ushort *)(piVar1 + 1));
  }
  return 0;
}

