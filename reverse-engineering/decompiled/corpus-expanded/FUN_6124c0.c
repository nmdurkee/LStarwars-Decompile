/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x6124c0; label: FUN_006124c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006124c0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5,
                 float param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int in_ECX;
  
  iVar6 = FUN_00617a00();
  fVar2 = (float)iVar6;
  if (iVar6 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  if (0 < (int)param_6) {
    param_5 = param_5 - (int)param_4;
    iVar6 = (int)param_6;
    do {
      pfVar1 = (float *)*param_4;
      fVar4 = fVar2 - *(float *)(param_3 + 0xc);
      fVar5 = fVar2 - *(float *)(param_3 + 4);
      fVar3 = fVar2 - *(float *)(param_3 + 8);
      param_6 = fVar3 * fVar5 * *(float *)(param_3 + 0x18) * pfVar1[2] +
                *(float *)(param_3 + 0x10) * fVar3 * fVar4 * *pfVar1 +
                fVar5 * fVar4 * *(float *)(param_3 + 0x14) * pfVar1[1];
      if (((*(ushort *)(in_ECX + 0xe) & 0x10) != 0) && (param_6 <= *(float *)(in_ECX + 0x20))) {
        param_6 = *(float *)(in_ECX + 0x20);
      }
      if (((*(ushort *)(in_ECX + 0xe) & 0x20) != 0) && (*(float *)(in_ECX + 0x24) <= param_6)) {
        param_6 = *(float *)(in_ECX + 0x24);
      }
      param_4 = param_4 + 1;
      iVar6 = iVar6 + -1;
      *(float *)(param_5 + -4 + (int)param_4) =
           *(float *)(param_5 + -4 + (int)param_4) * 0.8 + param_6 * 0.2;
    } while (iVar6 != 0);
  }
  return;
}

