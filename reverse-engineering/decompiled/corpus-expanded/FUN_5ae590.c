/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae590; label: FUN_005ae590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005ae590(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = param_2;
  iVar6 = 0;
  iVar7 = 0;
  if ((param_2 != 0) && (piVar3 = *(int **)(param_2 + 0x5108), *piVar3 != 0)) {
    if (0 < piVar3[1]) {
      param_2 = 0;
      do {
        iVar1 = *piVar3 + param_2;
        if (*(int *)(*piVar3 + 0x20 + param_2) != 0) {
          iVar4 = FUN_004f8b10(param_4,iVar1);
          if (iVar4 == 0) {
            uVar5 = FUN_0055a020(*(undefined4 *)(iVar2 + 0x2ac8),0xffffffff,iVar1);
            *(undefined4 *)(param_1 + iVar7 * 4) = uVar5;
            iVar7 = iVar7 + 1;
            if (iVar7 == param_3) {
              return -1;
            }
          }
        }
        piVar3 = *(int **)(iVar2 + 0x5108);
        param_2 = param_2 + 0x28;
        iVar6 = iVar6 + 1;
      } while (iVar6 < piVar3[1]);
    }
    return iVar7;
  }
  return 0;
}

