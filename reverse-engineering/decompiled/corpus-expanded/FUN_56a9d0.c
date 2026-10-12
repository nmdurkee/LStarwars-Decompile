/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56a9d0; label: FUN_0056a9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056a9d0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  if (0 < DAT_009507a8) {
    puVar3 = &DAT_009507b0;
    do {
      iVar1 = FUN_004f8b10(puVar3,param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 0x20;
    } while (iVar2 < DAT_009507a8);
  }
  if (DAT_009507a8 < 0x20) {
    FUN_004f1f40(&DAT_009507b0 + DAT_009507a8 * 0x20,param_1,0x20);
    iVar2 = DAT_009507a8;
    DAT_009507a8 = DAT_009507a8 + 1;
    return iVar2;
  }
  return -1;
}

