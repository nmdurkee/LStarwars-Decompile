/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4f9de0; label: FUN_004f9de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f9de0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  piVar2 = param_1;
  uVar4 = 0;
  DAT_0091eeb8 = 0;
  if (*param_1 == 0x12345678) {
    param_1 = param_1 + 3;
  }
  else if (*param_1 == 0x1234567a) {
    param_1 = param_1 + 6;
  }
  else {
    param_1 = param_1 + 5;
  }
  uVar1 = piVar2[1];
  piVar5 = param_1;
  if (uVar1 != 0) {
    do {
      iVar3 = FUN_004f8b10(*piVar5 + (int)piVar2,param_2);
      if (iVar3 == 0) {
        if ((*(byte *)(param_1 + uVar4 * 7 + 4) & 2) != 0) {
          return 0;
        }
        return uVar4 + 1;
      }
      uVar4 = uVar4 + 1;
      piVar5 = piVar5 + 7;
    } while (uVar4 < uVar1);
  }
  return 0;
}

