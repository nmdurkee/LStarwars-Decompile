/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x524cb0; label: FUN_00524cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00524cb0(int param_1,int param_2,int param_3,int param_4,uint param_5,float param_6,
                 uint param_7)

{
  byte *pbVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  float10 fVar7;
  int local_18;
  undefined1 local_c [12];
  
  _DAT_009242a0 = _DAT_009242a0 + 1;
  uVar4 = param_5 & 0x80000007;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
  }
  pbVar1 = (byte *)(((int)(param_5 + ((int)param_5 >> 0x1f & 7U)) >> 3) + param_3);
  if ((*pbVar1 & (byte)(1 << ((byte)uVar4 & 0x1f))) == 0) {
    bVar5 = '\x01' << ((byte)uVar4 & 0x1f);
    *pbVar1 = *pbVar1 | bVar5;
    iVar6 = param_5 * 0x5c + *(int *)(param_1 + 0x7c);
    fVar7 = (float10)FUN_005becc0(param_4 * 0x5c + *(int *)(param_1 + 0x7c) + 4,iVar6 + 4,local_c);
    fVar2 = (float)(fVar7 + (float10)param_6);
    if (fVar2 <= *(float *)(param_2 + param_5 * 4)) {
      *(float *)(param_2 + param_5 * 4) = fVar2;
      local_18 = 0;
      if (*(char *)(iVar6 + 0x28) != '\0') {
        do {
          iVar3 = *(int *)(*(int *)(iVar6 + 0x34) + local_18 * 4);
          uVar4 = (uint)(*(byte *)(iVar3 + 0x10) != param_5);
          if (((*(uint *)(iVar3 + uVar4 * 4) & 0x40000000) == 0) &&
             ((param_7 == 0 || ((param_7 & *(ushort *)(iVar3 + 0x14)) != 0)))) {
            FUN_00524cb0(param_1,param_2,param_3,param_5,
                         *(undefined1 *)((uVar4 == 0) + 0x10 + iVar3),fVar2,param_7);
          }
          local_18 = local_18 + 1;
        } while (local_18 < (int)(uint)*(byte *)(iVar6 + 0x28));
      }
    }
    *pbVar1 = *pbVar1 & ~bVar5;
  }
  return;
}

