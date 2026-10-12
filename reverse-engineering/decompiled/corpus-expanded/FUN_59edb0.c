/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59edb0; label: FUN_0059edb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059edb0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  FUN_004f7fb0(param_1);
  if (DAT_00805538 != -1) {
    puVar3 = &DAT_00805540;
    do {
      if (DAT_00956344 != -1) {
        return;
      }
      iVar2 = FUN_004f8b10(puVar3[-1],*(undefined4 *)(param_1 + 0x510));
      if ((iVar2 == 0) && (DAT_00956344 = iVar4, (code *)*puVar3 != (code *)0x0)) {
        (*(code *)*puVar3)(param_1);
      }
      iVar4 = iVar4 + 1;
      piVar1 = puVar3 + 1;
      puVar3 = puVar3 + 3;
    } while (*piVar1 != -1);
  }
  return;
}

