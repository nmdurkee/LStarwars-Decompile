/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x440d60; label: FUN_00440d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00440d60(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_2 != 0) && (param_1 != 0)) && (iVar2 = 0, 0 < DAT_0093b278)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0xc + DAT_0093b274),param_2);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x4c;
    } while (iVar2 < DAT_0093b278);
  }
  return -1;
}

