/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8da0; label: FUN_004f8da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f8da0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar3 = param_1;
  puVar5 = &param_1;
  do {
    piVar1 = puVar5 + 1;
    uVar2 = puVar5[2];
    puVar5 = puVar5 + 2;
    if (*piVar1 == 0) {
      return uVar2;
    }
    iVar4 = FUN_004f8b10(uVar3,*piVar1);
  } while (iVar4 != 0);
  return uVar2;
}

