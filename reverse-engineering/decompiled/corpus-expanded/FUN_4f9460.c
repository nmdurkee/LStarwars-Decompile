/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f9460; label: FUN_004f9460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f9460(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = DAT_0091ef14;
  for (piVar2 = DAT_0091ef18; (0 < iVar3 && (*piVar2 != 0)); piVar2 = piVar2 + 1) {
    iVar1 = FUN_004f8b10(*piVar2,"PADRECORD");
    if (iVar1 == 0) {
      piVar2 = piVar2 + 1;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        FUN_004ef790();
      }
      DAT_0297dc1c = *piVar2;
      DAT_0297dc08 = 1;
    }
    else {
      iVar1 = FUN_004f8b10(*piVar2,"PADPLAY");
      if (iVar1 == 0) {
        piVar2 = piVar2 + 1;
        iVar3 = iVar3 + -1;
        if (iVar3 == 0) {
          FUN_004ef790();
        }
        DAT_0297dc1c = *piVar2;
        DAT_0297dc08 = 2;
      }
    }
    iVar3 = iVar3 + -1;
  }
  DAT_0091ef14 = iVar3;
  DAT_0091ef18 = piVar2;
  return;
}

