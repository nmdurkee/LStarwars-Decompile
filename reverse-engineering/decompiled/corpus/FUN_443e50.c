/* Ghidra analysis pseudocode, not original source.
 * ev_6b8c5160150a0b0a722ba8204210d6d18ff1e44325cd9d4d6103efb3bbacbc6b
 * Entry: 0x443e50; label: FUN_00443e50
 */

float10 FUN_00443e50(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  float10 fVar3;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar2 = *piVar1;
    piVar1 = *(int **)(iVar2 + 0x3ac);
    if (((piVar1 != (int *)0x0) && (*piVar1 != 0)) &&
       (((*(uint *)(iVar2 + 0x4b0) & 0x800) != 0 &&
        (fVar3 = (float10)1, (float10)*(float *)(iVar2 + 0x3b0) < fVar3)))) {
      if (*(short *)(*piVar1 + 0x1064) == DAT_007f18c0) {
        return fVar3;
      }
      if (*(short *)(*piVar1 + 0x1064) == DAT_007f18bc) {
        return fVar3;
      }
    }
  }
  return (float10)0;
}

