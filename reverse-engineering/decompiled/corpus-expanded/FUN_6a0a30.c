/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a0a30; label: FUN_006a0a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a0a30(void)

{
  int *piVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  
  piVar1 = *(int **)(in_EAX + 0x1c);
  if (piVar1 != (int *)0x0) {
    FUN_006a3570();
    iVar3 = 6;
    do {
      iVar3 = iVar3 + -1;
      FUN_006a3570();
    } while (iVar3 != 0);
    FUN_006a3570();
    FUN_006a3570();
    FUN_006a3570();
    FUN_006a3570();
    FUN_006a3570();
    FUN_006a3570();
    if (*piVar1 != 0) {
      for (uVar2 = *piVar1 - 1; uVar2 != 0; uVar2 = uVar2 >> 1) {
      }
    }
    FUN_006a3570();
    if (piVar1[1] != 0) {
      for (uVar2 = piVar1[1] - 1; uVar2 != 0; uVar2 = uVar2 >> 1) {
      }
    }
    FUN_006a3570();
    FUN_006a3570();
    return 0;
  }
  return 0xffffff7f;
}

