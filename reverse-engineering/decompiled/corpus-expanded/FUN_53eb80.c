/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53eb80; label: FUN_0053eb80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053eb80(float *param_1)

{
  int in_EAX;
  float *pfVar1;
  int in_ECX;
  int iVar2;
  float *pfVar3;
  
  if (*(int *)(in_EAX + 0x14) == 0) {
    iVar2 = *(short *)(in_ECX + 2) * 0x80 + *(int *)(in_EAX + 0x34);
    pfVar1 = (float *)(iVar2 + 0x60);
    pfVar3 = (float *)(iVar2 + 0x6c);
  }
  else {
    iVar2 = *(int *)(*(int *)(in_EAX + 0x14) + 8);
    pfVar1 = (float *)(iVar2 + *(short *)(in_ECX + 2) * 0xc);
    pfVar3 = (float *)(iVar2 + *(short *)(in_ECX + 0x28) * 0xc);
  }
  if (param_1 == (float *)0x0) {
    param_1 = (float *)&DAT_009242d0;
  }
  *param_1 = (*pfVar3 - *pfVar1) * *(float *)(in_ECX + 4) + *pfVar1;
  param_1[1] = (pfVar3[1] - pfVar1[1]) * *(float *)(in_ECX + 4) + pfVar1[1];
  param_1[2] = (pfVar3[2] - pfVar1[2]) * *(float *)(in_ECX + 4) + pfVar1[2];
  return;
}

