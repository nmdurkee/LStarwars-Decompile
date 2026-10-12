/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53f7e0; label: FUN_0053f7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0053f7e0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    iVar3 = 0;
    do {
      if (*(char *)(iVar2 + 0x32) != '\0') {
        iVar1 = FUN_004f8b10(param_2,iVar2 + 0xe4);
        if (iVar1 == 0) {
          return iVar2;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x13c;
    } while (iVar3 < 0x40);
  }
  return 0;
}

