/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cb120; label: FUN_004cb120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004cb120(float param_1,int *param_2)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float local_c [3];
  
  iVar4 = (int)param_1;
  iVar3 = *param_2;
  bVar2 = *(byte *)((int)param_1 + 0x160);
  iVar7 = *(int *)(*(int *)((int)param_1 + 0x158) + 0x7c);
  iVar5 = *(int *)((int)param_1 + 0x15c);
  iVar6 = (uint)*(byte *)((bVar2 == 0) + 0x10 + iVar5) * 0x5c + iVar7;
  iVar7 = (uint)*(byte *)(bVar2 + 0x10 + iVar5) * 0x5c + iVar7;
  if ((*(uint *)(iVar5 + (uint)bVar2 * 4) & 0x800) == 0) {
    if (((*(float *)(iVar6 + 0x18) < *(float *)((int)param_1 + 0x150) ==
          (*(float *)(iVar6 + 0x18) == *(float *)((int)param_1 + 0x150))) ||
        (fVar8 = (float10)FUN_005b3cf0(param_2 + 0x17,iVar6 + 4,local_c),
        *(float *)(iVar6 + 0x14) < (float)fVar8 == (*(float *)(iVar6 + 0x14) == (float)fVar8))) ||
       (iVar5 = FUN_0043c9a0(iVar3,iVar6,0), iVar5 != 0)) {
      return 0;
    }
    *(undefined1 *)((int)param_1 + 0x139) = 0;
    FUN_0043cbb0(iVar3,iVar6,iVar7,0);
    puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 4);
    *puVar1 = *puVar1 | DAT_00802278;
    if (*(short *)(iVar3 + 0x1064) == DAT_007f18dc) {
      if ((*(char *)(iVar3 + 0xe32) == '\0') || (*(char *)(iVar3 + 0xe32) == '\x03')) {
        puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
        *puVar1 = *puVar1 | DAT_00802278;
      }
    }
    else {
      puVar1 = (uint *)(*(int *)(iVar3 + 0xca4) + 8);
      *puVar1 = *puVar1 | DAT_00802278;
    }
    iVar3 = *(int *)((int)param_1 + 0x184);
    *(undefined4 *)((int)param_1 + 0x104) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)((int)param_1 + 0x108) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)((int)param_1 + 0x10c) = *(undefined4 *)(iVar3 + 0xc);
  }
  else {
    local_c[0] = *(float *)(iVar6 + 4) - *(float *)(iVar7 + 4);
    local_c[1] = 0.0;
    local_c[2] = *(float *)(iVar6 + 0xc) - *(float *)(iVar7 + 0xc);
    param_1 = *(float *)(iVar7 + 0x10) - *(float *)((int)param_1 + 0x120);
    if (param_1 < 0.0) {
      param_1 = 0.0;
    }
    FUN_005b3830(local_c,local_c,param_1 / *(float *)(iVar5 + 0x1c));
    FUN_005b37d0(iVar4 + 0x104,(float *)(iVar7 + 4),local_c);
    *(uint *)(iVar4 + 0x1e8) = *(uint *)(iVar4 + 0x1e8) | 0x800000;
  }
  *(undefined4 *)(iVar4 + 0x110) = 0;
  *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  return 1;
}

