/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x4432e0; label: FUN_004432e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004432e0(int param_1,int param_2)

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

