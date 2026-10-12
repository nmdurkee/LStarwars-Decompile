/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f72b0; label: FUN_004f72b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f72b0(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined8 uVar5;
  
  piVar1 = DAT_0091eeb0;
  if (param_2 != 0) {
    iVar2 = 0;
    piVar3 = DAT_0091eeb0;
    if (0 < DAT_0091ce64) {
      do {
        if (*piVar3 == param_2) break;
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 4;
      } while (iVar2 < DAT_0091ce64);
    }
    iVar4 = DAT_0091ce64;
    if (DAT_0091eea8 <= iVar2) {
      uVar5 = FUN_004ef790();
      iVar4 = (int)((ulonglong)uVar5 >> 0x20);
      iVar2 = (int)uVar5;
    }
    if (iVar2 == iVar4) {
      DAT_0091ce64 = iVar4 + 1;
    }
    piVar1[iVar2 * 4] = param_2;
    uVar5 = FUN_004f6d10(param_1);
    piVar1 = DAT_0091eeb0;
    DAT_0091eeb0[iVar2 * 4 + 2] = (int)uVar5;
    piVar1[iVar2 * 4 + 3] = (int)((ulonglong)uVar5 >> 0x20);
  }
  return;
}

