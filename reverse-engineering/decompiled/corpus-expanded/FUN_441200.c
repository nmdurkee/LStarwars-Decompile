/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x441200; label: FUN_00441200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441200(void)

{
  float fVar1;
  int *piVar2;
  uint uVar3;
  int in_stack_00000014;
  
  if ((in_stack_00000014 != 0) && (DAT_0093d810 != 0)) {
    uVar3 = 0;
    if (((*(char *)(DAT_0093d810 + 0x281) != '\0') || (*(char *)(DAT_0093d810 + 0x282) != '\0')) &&
       ((*(short *)(DAT_0093d810 + 0x27e) != -1 &&
        (fVar1 = *(float *)(*(int *)(*(short *)(DAT_0093d810 + 0x27e) * 0x6c + 0x40 +
                                    *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
        fVar1 < *(float *)(DAT_0093d810 + 0x60) != (fVar1 == *(float *)(DAT_0093d810 + 0x60)))))) {
      uVar3 = 1;
    }
    if ((DAT_0093d814 != 0) &&
       ((((*(char *)(DAT_0093d814 + 0x281) != '\0' || (*(char *)(DAT_0093d814 + 0x282) != '\0')) &&
         (*(short *)(DAT_0093d814 + 0x27e) != -1)) &&
        (fVar1 = *(float *)(*(int *)(*(short *)(DAT_0093d814 + 0x27e) * 0x6c + 0x40 +
                                    *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
        fVar1 < *(float *)(DAT_0093d814 + 0x60) != (fVar1 == *(float *)(DAT_0093d814 + 0x60)))))) {
      uVar3 = uVar3 | 2;
    }
    if ((uVar3 != 0) &&
       (piVar2 = *(int **)(*(int *)(in_stack_00000014 + 0x28) + 0x18), piVar2 != (int *)0x0)) {
      do {
        if ((((uVar3 & 1) != 0) && (*(short *)(DAT_0093d810 + 0x27e) == *(short *)(piVar2[9] + 2)))
           || (((uVar3 & 2) != 0 && (*(short *)(DAT_0093d814 + 0x27e) == *(short *)(piVar2[9] + 2)))
              )) {
          return (float10)1;
        }
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)0x0);
    }
  }
  return (float10)0;
}

