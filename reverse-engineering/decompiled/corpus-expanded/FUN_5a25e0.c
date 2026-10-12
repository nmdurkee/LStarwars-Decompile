/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a25e0; label: FUN_005a25e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a25e0(int param_1)

{
  ushort uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 local_8;
  
  if (param_1 != 0) {
    iVar8 = *(int *)(param_1 + 0xc);
    iVar7 = 0;
    iVar5 = DAT_00956628;
    iVar6 = DAT_0095662c;
    if (*(short *)(param_1 + 2) != 0) {
      do {
        iVar4 = iVar8;
        if (iVar8 != 0) {
          iVar4 = *(int *)(iVar8 + 0x78);
          if (*(float *)(iVar8 + 0x6c) < *(float *)(iVar8 + 0x68)) {
            *(int *)(iVar5 + iVar6 * 4) = iVar8;
            iVar6 = iVar6 + 1;
          }
          else if (*(float *)(iVar8 + 0x70) <= 0.0) {
            uVar1 = *(ushort *)(iVar8 + 0x74);
            fVar2 = *(float *)(iVar8 + 0x68) / *(float *)(iVar8 + 0x6c);
            if ((uVar1 & 1) != 0) {
              *(float *)(iVar8 + 0x50) =
                   (*(float *)(iVar8 + 0x58) - *(float *)(iVar8 + 0x54)) * fVar2 +
                   *(float *)(iVar8 + 0x54);
            }
            iVar3 = DAT_00956628;
            if ((uVar1 & 2) != 0) {
              local_8 = (undefined1)
                        (int)ROUND((float)(int)((uint)*(byte *)(iVar8 + 0x67) -
                                               (uint)*(byte *)(iVar8 + 99)) * fVar2 +
                                   (float)*(byte *)(iVar8 + 99));
              *(undefined1 *)(iVar8 + 0x5f) = local_8;
              iVar5 = iVar3;
            }
            if ((uVar1 & 4) != 0) {
              local_8 = (undefined1)
                        (int)ROUND((float)(int)((uint)*(byte *)(iVar8 + 100) -
                                               (uint)*(byte *)(iVar8 + 0x60)) * fVar2 +
                                   (float)*(byte *)(iVar8 + 0x60));
              *(undefined1 *)(iVar8 + 0x5c) = local_8;
              local_8 = (undefined1)
                        (int)ROUND((float)(int)((uint)*(byte *)(iVar8 + 0x65) -
                                               (uint)*(byte *)(iVar8 + 0x61)) * fVar2 +
                                   (float)*(byte *)(iVar8 + 0x61));
              *(undefined1 *)(iVar8 + 0x5d) = local_8;
              iVar5 = DAT_00956628;
              local_8 = (undefined1)
                        (int)ROUND(fVar2 * (float)(int)((uint)*(byte *)(iVar8 + 0x66) -
                                                       (uint)*(byte *)(iVar8 + 0x62)) +
                                   (float)*(byte *)(iVar8 + 0x62));
              *(undefined1 *)(iVar8 + 0x5e) = local_8;
            }
            if ((uVar1 & 8) != 0) {
              *(float *)(iVar8 + 0x30) = *(float *)(iVar8 + 0x40) + *(float *)(iVar8 + 0x30);
              *(float *)(iVar8 + 0x34) = *(float *)(iVar8 + 0x44) + *(float *)(iVar8 + 0x34);
              *(float *)(iVar8 + 0x38) = *(float *)(iVar8 + 0x48) + *(float *)(iVar8 + 0x38);
            }
            *(float *)(iVar8 + 0x68) = *(float *)(iVar8 + 0x68) + _DAT_00925018;
          }
          else {
            *(float *)(iVar8 + 0x70) = *(float *)(iVar8 + 0x70) - _DAT_00925018;
            *(float *)(iVar8 + 0x68) = *(float *)(iVar8 + 0x68) + _DAT_00925018;
          }
        }
        iVar7 = iVar7 + 1;
        iVar8 = iVar4;
      } while (iVar7 < (int)(uint)*(ushort *)(param_1 + 2));
    }
    iVar8 = 0;
    if (0 < iVar6) {
      do {
        iVar7 = *(int *)(iVar5 + iVar8 * 4);
        if (iVar7 != 0) {
          if (iVar7 == *(int *)(param_1 + 0x10)) {
            *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x78);
          }
          FUN_005a2470();
        }
        *(undefined4 *)(iVar5 + iVar8 * 4) = 0;
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar6);
    }
    DAT_0095662c = 0;
  }
  return;
}

