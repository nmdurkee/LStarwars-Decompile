/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5ca000; label: FUN_005ca000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ca000(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  float *pfVar3;
  byte *pbVar4;
  float10 extraout_ST0;
  uint local_c;
  uint local_8;
  uint local_4;
  
  if (param_1 == 0) {
    param_1 = DAT_00973880;
  }
  if (0 < param_3) {
    pbVar4 = (byte *)(param_4 + 0x30);
    do {
      if (((int)(uint)*pbVar4 < *(int *)(param_2 + 0x178)) &&
         (uVar2 = (uint)*(byte *)(*(int *)(param_2 + 0x17c) + (uint)*pbVar4), uVar2 != 0xff)) {
        bVar1 = pbVar4[1];
        pfVar3 = (float *)(uVar2 * 0x30 + *(int *)(param_1 + 8));
        if ((bVar1 & 1) != 0) {
          pfVar3[4] = *(float *)(pbVar4 + -0x30) + pfVar3[4];
          pfVar3[5] = *(float *)(pbVar4 + -0x2c) + pfVar3[5];
          pfVar3[6] = *(float *)(pbVar4 + -0x28) + pfVar3[6];
          local_c = FUN_006e6b90();
          local_8 = FUN_006e6b90();
          local_4 = FUN_006e6b90();
          if ((bVar1 & 8) != 0) {
            local_c = local_c & 0xffff;
            if (0x7fff < local_c) {
              local_c = local_c - 0x10000;
            }
            uVar2 = (uint)*(short *)(pbVar4 + -0xc);
            if (((int)uVar2 < (int)local_c) ||
               (uVar2 = (uint)*(short *)(pbVar4 + -6), (int)local_c < (int)uVar2)) {
              local_c = uVar2;
            }
          }
          if ((bVar1 & 0x10) != 0) {
            local_8 = local_8 & 0xffff;
            if (0x7fff < local_8) {
              local_8 = local_8 - 0x10000;
            }
            uVar2 = (uint)*(short *)(pbVar4 + -10);
            if (((int)uVar2 < (int)local_8) ||
               (uVar2 = (uint)*(short *)(pbVar4 + -4), (int)local_8 < (int)uVar2)) {
              local_8 = uVar2;
            }
          }
          if ((bVar1 & 0x20) != 0) {
            local_4 = local_4 & 0xffff;
            if (0x7fff < local_4) {
              local_4 = local_4 - 0x10000;
            }
            uVar2 = (uint)*(short *)(pbVar4 + -8);
            if (((int)uVar2 < (int)local_4) ||
               (uVar2 = (uint)*(short *)(pbVar4 + -2), (int)local_4 < (int)uVar2)) {
              local_4 = uVar2;
            }
          }
          pfVar3[4] = (float)((float10)(int)local_c * extraout_ST0);
          pfVar3[5] = (float)((float10)(int)local_8 * extraout_ST0);
          pfVar3[6] = (float)((float10)(int)local_4 * extraout_ST0);
        }
        if ((bVar1 & 4) != 0) {
          pfVar3[8] = *(float *)(pbVar4 + -0x18) + pfVar3[8];
          pfVar3[9] = *(float *)(pbVar4 + -0x14) + pfVar3[9];
          pfVar3[10] = *(float *)(pbVar4 + -0x10) + pfVar3[10];
        }
        if ((bVar1 & 2) != 0) {
          *pfVar3 = *(float *)(pbVar4 + -0x24) + *pfVar3;
          pfVar3[1] = *(float *)(pbVar4 + -0x20) + pfVar3[1];
          pfVar3[2] = *(float *)(pbVar4 + -0x1c) + pfVar3[2];
        }
      }
      pbVar4 = pbVar4 + 0x34;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

