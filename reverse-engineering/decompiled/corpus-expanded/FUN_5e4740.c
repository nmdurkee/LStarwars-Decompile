/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e4740; label: FUN_005e4740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e4740(float *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  float10 fVar4;
  float local_c;
  undefined4 local_8 [2];
  
  FUN_005e4600(param_1,&local_c,local_8);
  if (local_c < 8192.0) {
    local_c = 8192.0;
  }
  fVar4 = (float10)FUN_005c0240(param_1[2] * param_1[2] +
                                *param_1 * *param_1 + param_1[1] * param_1[1]);
  *param_1 = 0.0;
  param_1[1] = 0.0;
  param_1[2] = (float)fVar4;
  FUN_005e4670(param_1,local_c,local_8[0]);
  iVar3 = 0;
  puVar2 = &DAT_009715b0;
  do {
    iVar1 = iVar3 + (iVar3 >> 0x1f & 7U);
    *puVar2 = (&DAT_029899a0)[(iVar1 >> 3) + 0x4000 >> 1 & 0x7fff];
    puVar2[1] = -(float)(&DAT_029899a0)[iVar1 >> 4 & 0x7fff];
    puVar2[2] = 0;
    FUN_005e4670(puVar2,local_c,local_8[0]);
    puVar2 = puVar2 + 3;
    iVar3 = iVar3 + 0x10000;
  } while ((int)puVar2 < 0x971610);
  return;
}

