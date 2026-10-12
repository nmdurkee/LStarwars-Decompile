/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68cd30; label: FUN_0068cd30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068cd30(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = &DAT_02924b60;
  do {
    if ((piVar3[-1] == -1) && (*piVar3 != -1)) {
      if (*piVar3 != 99999) {
        FUN_00684400(piVar3);
      }
      DAT_02962a2c = DAT_02962a2c + -1;
      *piVar3 = -1;
    }
    piVar3 = piVar3 + 0x16;
  } while ((int)piVar3 < 0x292fb60);
  DAT_02962a3c = 0;
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  if (iVar1 != 0) {
    FUN_006279f0(param_1);
    iVar2 = iVar1;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,iVar2);
  }
  return;
}

