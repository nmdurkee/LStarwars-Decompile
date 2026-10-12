/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x515ba0; label: FUN_00515ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00515ba0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (param_6 != 0)) &&
     ((param_5 != 0 && (iVar2 = 0, 0 < param_5)))) {
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"Clockwise");
      if (iVar1 == 0) {
        *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x200;
      }
      else {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"AntiClockwise");
        if (iVar1 == 0) {
LAB_00515c75:
          *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffdff;
        }
        else {
          iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"Reverse");
          if (iVar1 == 0) {
            *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) ^ 0x200;
          }
          else {
            iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"Random");
            if (iVar1 == 0) {
              fVar3 = (float10)FUN_005b9dd0();
              if (fVar3 <= (float10)0.5) goto LAB_00515c75;
              *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x200;
            }
          }
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_5);
  }
  return 1;
}

