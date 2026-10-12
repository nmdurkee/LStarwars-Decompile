/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x481950; label: FUN_00481950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00481950(int param_1)

{
  bool bVar1;
  int *piVar2;
  float10 fVar3;
  float10 fVar4;
  
  bVar1 = false;
  if ((DAT_0087a908 != 0) && ((*(byte *)(*(int *)(DAT_0087a908 + 0x34) + 10) & 1) != 0)) {
    FUN_00541bc0(*(undefined4 *)(param_1 + 0x2988),DAT_0087a908 + 0x28,(int)DAT_0087a0d5,
                 (int)DAT_0087a0d6,&DAT_0087a0d4);
    fVar3 = (float10)FUN_0053f7a0(*(undefined4 *)(param_1 + 0x2988),&DAT_0087a0d4);
    piVar2 = &DAT_0093d7f0;
    do {
      if (*piVar2 != 0) {
        fVar4 = (float10)FUN_005b3c50(*piVar2 + 0x80,DAT_0087a908 + 0x28,0);
        if (*(float *)(DAT_0087a908 + 0x58) * *(float *)(DAT_0087a908 + 0x58) <= (float)fVar4) {
          if ((*(short *)(*piVar2 + 0x672) == 1) &&
             (fVar4 = (float10)FUN_0053f7a0(*(undefined4 *)(param_1 + 0x2988),*piVar2 + 0x670),
             fVar4 < (float10)(float)fVar3)) goto LAB_00481a3a;
        }
        else {
          bVar1 = true;
        }
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x93d7f8);
    if (bVar1) {
LAB_00481a3a:
      if ((DAT_0093b2a4 == 0) && (DAT_0087b2bc != 0)) {
        FUN_0057a580();
        return;
      }
      FUN_0057a5b0(param_1);
    }
  }
  return;
}

