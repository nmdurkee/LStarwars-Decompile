/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58d340; label: FUN_0058d340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0058d340(int param_1,int param_2,float param_3)

{
  float fVar1;
  uint uVar2;
  float10 fVar3;
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  if (*(int *)(param_1 + 0x790) == 0) {
    return 0;
  }
  FUN_005b3620(local_c,&DAT_0080250c,*(undefined2 *)(param_1 + 0x27a));
  fVar3 = (float10)FUN_005b3c50(param_2 + 0x5c,param_1 + 0x5c,local_18);
  uVar2 = *(uint *)(param_1 + 0x7bc) >> 7 & 1;
  fVar1 = local_18[0] * local_c[0] + local_10 * local_4;
  if ((((uVar2 == 0) && (!NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0))) ||
      ((uVar2 != 0 && (fVar1 <= 0.0)))) &&
     (param_3 = *(float *)(param_1 + 0x1dc) + *(float *)(param_2 + 0x1dc) + param_3,
     (float)fVar3 < param_3 * param_3)) {
    return 1;
  }
  return 0;
}

