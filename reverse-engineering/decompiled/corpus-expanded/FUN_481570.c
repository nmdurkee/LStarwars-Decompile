/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x481570; label: FUN_00481570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00481570(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = param_1;
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x2ae8) != 0)) &&
      (pbVar3 = *(byte **)(*(int *)(param_1 + 0x2ae8) + 0x10), pbVar3 != (byte *)0x0)) &&
     (local_10 = 0, *pbVar3 != 0)) {
    do {
      iVar1 = *(int *)(*(int *)(pbVar3 + 4) + local_10 * 4);
      if (iVar1 != 0) {
        iVar7 = *(int *)(iVar1 + 0x80);
        param_1 = 0;
        if (*(short *)(iVar1 + 0x12) != 0) {
          do {
            iVar8 = 0;
            do {
              if ((*(byte *)(iVar7 + (short)iVar8 * 4) & 8) != 0) {
                if ((*(byte *)(iVar7 + (uint)((short)iVar8 == 0) * 4) & 8) != 0) {
                  iVar8 = 0xff;
                }
                iVar6 = (uint)*(byte *)(iVar7 + 0x11) * 0x5c;
                iVar5 = *(int *)(iVar1 + 0x7c);
                iVar4 = (uint)*(byte *)(iVar7 + 0x10) * 0x5c;
                local_c = (*(float *)(iVar6 + 4 + iVar5) + *(float *)(iVar4 + 4 + iVar5)) * 0.5;
                local_8 = (*(float *)(iVar6 + 8 + iVar5) + *(float *)(iVar4 + 8 + iVar5)) * 0.5;
                local_4 = (*(float *)(iVar6 + iVar5 + 0xc) + *(float *)(iVar4 + iVar5 + 0xc)) * 0.5;
                iVar5 = FUN_0054d760(iVar2,&local_c);
                if (iVar5 != 0) {
                  FUN_005ab140(*(undefined4 *)(iVar2 + 0x4674),iVar7,iVar8,iVar5,1);
                }
              }
              iVar8 = iVar8 + 1;
            } while ((short)iVar8 < 2);
            param_1 = param_1 + 1;
            iVar7 = iVar7 + 0x24;
          } while (param_1 < (int)(uint)*(ushort *)(iVar1 + 0x12));
        }
      }
      pbVar3 = *(byte **)(*(int *)(iVar2 + 0x2ae8) + 0x10);
      local_10 = local_10 + 1;
    } while (local_10 < (int)(uint)*pbVar3);
  }
  return;
}

