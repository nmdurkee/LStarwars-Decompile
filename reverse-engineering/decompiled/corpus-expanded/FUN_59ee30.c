/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59ee30; label: FUN_0059ee30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0059ee30(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_00956414 != (int *)0x0) {
    iVar2 = *DAT_00956414;
    piVar3 = DAT_00956414;
    while (iVar2 != 0) {
      iVar2 = FUN_004f8b10();
      if (iVar2 == 0) {
        return piVar3;
      }
      piVar1 = piVar3 + 2;
      piVar3 = piVar3 + 2;
      iVar2 = *piVar1;
    }
  }
  return (int *)0x0;
}

