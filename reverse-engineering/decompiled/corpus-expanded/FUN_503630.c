/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x503630; label: FUN_00503630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00503630(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  if (*(int *)(in_EAX + 0x24) != 0) {
    piVar6 = (int *)(*(int *)(in_EAX + 0x24) + param_1);
    *(int **)(in_EAX + 0x24) = piVar6;
    if (piVar6[1] == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = piVar6[1] + param_1;
    }
    piVar6[1] = iVar1;
    if ((iVar1 != 0) && (iVar1 = 0, 0 < *piVar6)) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(piVar6[1] + 4 + iVar4);
        iVar5 = piVar6[1] + iVar4;
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = iVar2 + param_1;
        }
        *(int *)(iVar5 + 4) = iVar2;
        uVar3 = FUN_005da600(*(undefined4 *)(iVar5 + 8),param_1);
        iVar1 = iVar1 + 1;
        *(undefined4 *)(iVar5 + 8) = uVar3;
        iVar4 = iVar4 + 0xc;
      } while (iVar1 < *piVar6);
    }
  }
  return;
}

