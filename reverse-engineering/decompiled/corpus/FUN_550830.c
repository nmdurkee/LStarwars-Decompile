/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x550830; label: FUN_00550830
 */

float10 FUN_00550830(undefined4 param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float10 fVar2;
  float local_c;
  float local_8;
  float local_4;
  
  if (0.0 < param_4) {
    FUN_005b3800(&local_c,param_1,DAT_00925164 + 0x30);
    fVar1 = local_4 * local_4 + local_c * local_c + local_8 * local_8;
    if (fVar1 < param_3 * param_3) {
      if (fVar1 <= param_2 * param_2) {
        return (float10)param_4;
      }
      fVar2 = (float10)FUN_005c0240(fVar1);
      return (float10)(float)(((float10)1 -
                              (fVar2 - (float10)param_2) / ((float10)param_3 - (float10)param_2)) *
                             (float10)param_4);
    }
  }
  return (float10)0;
}

