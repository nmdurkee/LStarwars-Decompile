/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x499300; label: FUN_00499300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00499300(float param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = param_1;
  fVar3 = 1.0;
  *(uint *)((int)param_1 + 0xef4) = *(uint *)((int)param_1 + 0xef4) | 0x10000000;
  if (_DAT_00924fdc < 1.0) {
    return;
  }
  if (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af80) {
    fVar3 = 0.5;
  }
  if (param_2 != 0) {
    iVar1 = (int)param_1 + 0x80;
    FUN_0054fd90(iVar1,&DAT_009250e8,&DAT_009250f4,0,0,&param_1);
    if (fVar3 <= param_1) {
      FUN_0054fd90(iVar1,&DAT_00925100,&DAT_0092510c,0,0,&param_1);
      if (fVar3 <= param_1) goto LAB_0049940b;
      fVar2 = -*(float *)(*(int *)(*(int *)((int)fVar4 + 0x54) + 0x24) + 0x1c);
    }
    else {
      fVar2 = *(float *)(*(int *)(*(int *)((int)fVar4 + 0x54) + 0x24) + 0x1c);
    }
    *(float *)((int)fVar4 + 0xf18) =
         (fVar2 + fVar2) * ((param_1 - fVar3) / fVar3) * -2.0 + *(float *)((int)fVar4 + 0xf18);
  }
LAB_0049940b:
  if (param_3 == 0) {
    param_1 = 1e+09;
  }
  else {
    FUN_0054fd90((int)fVar4 + 0x80,&DAT_00925118,&DAT_00925124,0,0,&param_1);
  }
  if ((param_1 != 1e+09) && (param_1 < fVar3)) {
    fVar2 = -*(float *)(*(int *)(*(int *)((int)fVar4 + 0x54) + 0x24) + 0x1c);
    *(float *)((int)fVar4 + 0xf1c) =
         (fVar2 + fVar2) * ((param_1 - fVar3) / fVar3) * -2.0 + *(float *)((int)fVar4 + 0xf1c);
    return;
  }
  if ((param_4 != 0) &&
     (FUN_0054fd90((int)fVar4 + 0x80,&DAT_00925130,&DAT_0092513c,0,0,&param_1), param_1 < fVar3)) {
    fVar2 = *(float *)(*(int *)(*(int *)((int)fVar4 + 0x54) + 0x24) + 0x1c);
    *(float *)((int)fVar4 + 0xf1c) =
         (fVar2 + fVar2) * ((param_1 - fVar3) / fVar3) * -2.0 + *(float *)((int)fVar4 + 0xf1c);
    return;
  }
  return;
}

