/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x4447a0; label: FUN_004447a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004447a0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (iVar2 = *piVar1, param_6 != 0)) {
    iVar4 = 0;
    *(uint *)(iVar2 + 0xeec) = *(uint *)(iVar2 + 0xeec) & 0xffdfffff | 0x100000;
    if (0 < param_5) {
      do {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"origin");
        if (iVar3 == 0) {
          *(uint *)(iVar2 + 0xeec) = *(uint *)(iVar2 + 0xeec) | 0x200000;
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"false");
          if (iVar3 == 0) {
            *(uint *)(iVar2 + 0xeec) = *(uint *)(iVar2 + 0xeec) & 0xffefffff;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
  }
  return 1;
}

