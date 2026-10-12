/* Ghidra pseudocode, not original source.
 * ev_52b1dbacad98807a86fda1d7285f00f4b35f02131457f245004edfced337e57f
 * Entry: 0x441910; label: FUN_00441910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00441910(void)

{
  float fVar1;
  int in_stack_00000014;
  
  if ((((DAT_0093d810 != 0) && (in_stack_00000014 != -1)) &&
      ((*(char *)(DAT_0093d810 + 0x281) != '\0' || (*(char *)(DAT_0093d810 + 0x282) != '\0')))) &&
     ((*(short *)(DAT_0093d810 + 0x27e) == in_stack_00000014 &&
      (fVar1 = *(float *)(*(int *)(*(short *)(DAT_0093d810 + 0x27e) * 0x6c + 0x40 +
                                  *(int *)(DAT_0292fc68 + 0x68)) + 0x34),
      fVar1 < *(float *)(DAT_0093d810 + 0x60) != (fVar1 == *(float *)(DAT_0093d810 + 0x60)))))) {
    return (float10)1;
  }
  return (float10)0;
}

