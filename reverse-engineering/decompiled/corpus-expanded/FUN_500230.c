/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x500230; label: FUN_00500230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00500230(int param_1)

{
  int *piVar1;
  float fVar2;
  float10 fVar3;
  
  fVar3 = (float10)0;
  if ((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x58), piVar1 != (int *)0x0)) {
    if (*piVar1 < 10) {
      if (((1 < *piVar1) && ((*(byte *)(piVar1 + 0xe) & 1) != 0)) && ((char)piVar1[0x10] != '\0'))
      goto LAB_0050026b;
      fVar2 = (float)piVar1[2] - 1.0;
    }
    else {
      fVar2 = (float)*(ushort *)((int)piVar1 + 0x42);
    }
    fVar2 = fVar2 - *(float *)(param_1 + 0x90);
    if (fVar3 < (float10)fVar2) {
      if (fVar3 != (float10)*(float *)(param_1 + 0x98)) {
        fVar3 = (float10)FUN_004fff50(fVar2,*(undefined4 *)(param_1 + 0x98));
        return fVar3;
      }
LAB_0050026b:
      return (float10)3.4028235e+38;
    }
  }
  return fVar3;
}

