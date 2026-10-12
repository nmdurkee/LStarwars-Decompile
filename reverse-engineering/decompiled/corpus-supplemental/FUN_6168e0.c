/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x6168e0; label: FUN_006168e0
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

void FUN_006168e0(int param_1)

{
  int in_ECX;
  int *piVar1;
  int local_4;
  
  if ((*(char *)(param_1 + 0xc) == '\0') &&
     ((*(int *)(DAT_028572e0 + 4) == 4 || (*(int *)(DAT_028572e0 + 4) == 3)))) {
    if (param_1 == *(int *)(in_ECX + 0x20)) {
      *(undefined4 *)(in_ECX + 0x20) = 0;
    }
    if (param_1 == *(int *)(in_ECX + 0x24)) {
      *(undefined4 *)(in_ECX + 0x24) = 0;
    }
    piVar1 = (int *)(in_ECX + 0x38);
    local_4 = 0x800;
    do {
      if (((*(short *)((int)piVar1 + -6) != 0) && (*piVar1 == param_1)) && (piVar1 != (int *)0x8)) {
        *piVar1 = *(int *)(DAT_028572e0 + 0x84);
        FUN_00612ac0(piVar1 + -2);
        FUN_006157f0(*(undefined2 *)((int)piVar1 + -6));
        FUN_0060e4c0(piVar1 + -2,*piVar1);
      }
      piVar1 = piVar1 + 6;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  if ((*(int *)(in_ECX + 0xd838) != 0) && (*(int *)(in_ECX + 0xd838) == param_1)) {
    *(undefined4 *)(in_ECX + 0xd838) = 0;
    *(undefined4 *)(in_ECX + 0xd848) = 0;
    *(undefined4 *)(in_ECX + 0xd844) = 0;
  }
  if ((*(int *)(in_ECX + 0xd84c) != 0) && (*(int *)(in_ECX + 0xd84c) == param_1)) {
    *(undefined4 *)(in_ECX + 0xd84c) = 0;
    *(undefined4 *)(in_ECX + 0xd85c) = 0;
    *(undefined4 *)(in_ECX + 0xd858) = 0;
  }
  if ((*(int *)(in_ECX + 0xd860) != 0) && (*(int *)(in_ECX + 0xd860) == param_1)) {
    *(undefined4 *)(in_ECX + 0xd860) = 0;
    *(undefined4 *)(in_ECX + 0xd870) = 0;
    *(undefined4 *)(in_ECX + 0xd86c) = 0;
  }
  if ((*(int *)(in_ECX + 0xd874) != 0) && (*(int *)(in_ECX + 0xd874) == param_1)) {
    *(undefined4 *)(in_ECX + 0xd874) = 0;
    *(undefined4 *)(in_ECX + 0xd884) = 0;
    *(undefined4 *)(in_ECX + 0xd880) = 0;
  }
  if ((*(int *)(in_ECX + 0xd888) != 0) && (*(int *)(in_ECX + 0xd888) == param_1)) {
    *(undefined4 *)(in_ECX + 0xd888) = 0;
    *(undefined4 *)(in_ECX + 0xd898) = 0;
    *(undefined4 *)(in_ECX + 0xd894) = 0;
  }
  if ((*(int *)(in_ECX + 0xd89c) != 0) && (*(int *)(in_ECX + 0xd89c) == param_1)) {
    *(undefined4 *)(in_ECX + 0xd89c) = 0;
    *(undefined4 *)(in_ECX + 0xd8ac) = 0;
    *(undefined4 *)(in_ECX + 0xd8a8) = 0;
  }
  if ((*(int *)(in_ECX + 0xd8b0) != 0) && (*(int *)(in_ECX + 0xd8b0) == param_1)) {
    *(undefined4 *)(in_ECX + 0xd8b0) = 0;
    *(undefined4 *)(in_ECX + 0xd8c0) = 0;
    *(undefined4 *)(in_ECX + 0xd8bc) = 0;
  }
  if ((*(int *)(in_ECX + 0xd8c4) != 0) && (*(int *)(in_ECX + 0xd8c4) == param_1)) {
    *(undefined4 *)(in_ECX + 0xd8c4) = 0;
    *(undefined4 *)(in_ECX + 0xd8d4) = 0;
    *(undefined4 *)(in_ECX + 0xd8d0) = 0;
  }
  return;
}

