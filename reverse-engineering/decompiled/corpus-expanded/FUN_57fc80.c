/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57fc80; label: FUN_0057fc80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057fc80(int *param_1,float *param_2,float *param_3,int param_4)

{
  char cVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  short local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  int local_4c;
  uint local_48;
  undefined1 local_40 [64];
  
  iVar5 = *param_1;
  if ((*(uint *)(iVar5 + 0x60) & 0x100000) == 0) {
    fVar2 = param_2[2] * param_3[2] + param_2[1] * param_3[1] + *param_2 * *param_3;
    fVar2 = fVar2 + fVar2;
    local_58 = *param_2 - fVar2 * *param_3;
    local_54 = param_2[1] - param_3[1] * fVar2;
    local_50 = param_2[2] - param_3[2] * fVar2;
    FUN_005b3b30(&local_58,&local_58);
    FUN_0054ff40(&local_58,0,0);
    cVar1 = (char)param_1[0x41];
    if (((cVar1 < '\0') || ('\x1f' < cVar1)) ||
       ((*(uint *)(&DAT_008034cc + cVar1 * 0xc) & 0x800) == 0)) {
      FUN_0054fa60();
      iVar3 = FUN_006e6b90();
      DAT_0092b0bc = DAT_0092b0bc + iVar3;
      iVar3 = FUN_0054fa60();
      local_68 = (short)(int)ROUND((double)iVar3 * 1.5259021893143654e-05 * 10922.0 - 5461.0);
      DAT_0093b0c8 = DAT_0093b0c8 + local_68;
    }
    local_48 = (uint)DAT_0093b0c8;
    local_4c = DAT_0092b0bc;
    FUN_005c0820(local_40,&local_4c);
    cVar1 = *(char *)(iVar5 + 0x3d);
    if ((cVar1 < '\0') || (uVar4 = (uint)cVar1, *(int *)(PTR_PTR_008040bc + 4) <= (int)uVar4)) {
      uVar4 = (uint)*(byte *)((int)param_1 + 0x101);
    }
    fVar2 = (float)param_1[0x38] * 1.01;
    DAT_009543e8 = 1;
    local_64 = local_58 * fVar2 + (float)param_1[0x22];
    local_60 = local_54 * fVar2 + (float)param_1[0x23];
    local_5c = fVar2 * local_50 + (float)param_1[0x24];
    iVar5 = FUN_00582e70(0,&local_64,local_40,uVar4,(short)param_1[0x3e]);
    if (iVar5 != 0) {
      *(uint *)(iVar5 + 0xf0) = *(uint *)(iVar5 + 0xf0) | 0x10000000;
      if (param_4 != 0) {
        *(undefined1 *)((uint)*(byte *)(iVar5 + 0x103) + param_4) = 1;
      }
    }
  }
  return;
}

