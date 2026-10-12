/* Ghidra pseudocode, not original source.
 * ev_65926145281a5167c739b8e4818ebc57eef5737a43bcd750b332aefff6a63eb2
 * Entry: 0x441180; label: FUN_00441180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441180(void)

{
  float fVar1;
  short sVar2;
  undefined4 *puVar3;
  int in_stack_00000014;
  
  if ((((in_stack_00000014 != 0) && (DAT_0093d810 != 0)) &&
      ((*(char *)(DAT_0093d810 + 0x281) != '\0' || (*(char *)(DAT_0093d810 + 0x282) != '\0')))) &&
     ((sVar2 = *(short *)(DAT_0093d810 + 0x27e), sVar2 != -1 &&
      (fVar1 = *(float *)(*(int *)(sVar2 * 0x6c + 0x40 + *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
      fVar1 < *(float *)(DAT_0093d810 + 0x60) != (fVar1 == *(float *)(DAT_0093d810 + 0x60)))))) {
    for (puVar3 = *(undefined4 **)(*(int *)(in_stack_00000014 + 0x28) + 0x18);
        puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
      if (sVar2 == *(short *)(puVar3[9] + 2)) {
        return (float10)1;
      }
    }
  }
  return (float10)0;
}

