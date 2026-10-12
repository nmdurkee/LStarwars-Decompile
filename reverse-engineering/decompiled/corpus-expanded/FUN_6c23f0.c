/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c23f0; label: FUN_006c23f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c23f0(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)*in_ECX;
  while (piVar1 != (int *)0x0) {
    if (*piVar1 == 0) {
      in_ECX[1] = piVar1[1];
    }
    else {
      *(int *)(*piVar1 + 4) = piVar1[1];
    }
    if ((int *)piVar1[1] == (int *)0x0) {
      *in_ECX = *piVar1;
    }
    else {
      *(int *)piVar1[1] = *piVar1;
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    in_ECX[2] = in_ECX[2] + -1;
    FUN_006334d0(piVar1,0x50);
    piVar1 = (int *)*in_ECX;
  }
  return;
}

