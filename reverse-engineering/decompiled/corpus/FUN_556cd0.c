/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x556cd0; label: FUN_00556cd0
 */

float10 FUN_00556cd0(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,int param_5)

{
  undefined4 *puVar1;
  float fVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  undefined4 uVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float local_e8;
  undefined4 *local_e0;
  undefined4 *local_dc;
  int local_d8;
  undefined1 local_cc [8];
  float local_c4;
  undefined4 local_c0 [24];
  undefined4 local_60 [24];
  
  local_e8 = 1e+09;
  local_e0 = (undefined4 *)0x0;
  local_dc = (undefined4 *)0x0;
  bVar8 = false;
  iVar9 = FUN_00555150(param_1,local_60,local_c0);
  if (((iVar9 != 0) && (param_2 != 0)) && (local_d8 = 0, 0 < iVar9)) {
    iVar10 = 0;
    do {
      puVar1 = (undefined4 *)((int)local_60 + iVar10);
      fVar11 = (float10)FUN_005b3c50(param_2,puVar1,0);
      fVar2 = (float)fVar11;
      if (param_5 != 0) {
        bVar3 = *(byte *)(param_1 + 0x8b);
        sVar4 = *(short *)(param_1 + 0x8c);
        bVar8 = false;
        sVar5 = *(short *)(param_1 + 0x82);
        sVar6 = *(short *)(param_1 + 0x7c);
        FUN_005b3800(local_cc,param_2,param_1 + 0x5c);
        FUN_005b3620(local_cc,local_cc,
                     (((sVar4 - (short)(0x10000 / (ulonglong)(longlong)(int)(uint)bVar3) *
                                (short)local_d8) - sVar5) - sVar6) + 0x4000);
        if (!NAN(local_c4) && 0.0 < local_c4 != (local_c4 == 0.0)) {
          bVar8 = true;
        }
      }
      if (fVar2 < local_e8) {
        if (param_5 == 0) {
          local_dc = (undefined4 *)((int)local_c0 + iVar10);
          local_e8 = fVar2;
          local_e0 = puVar1;
        }
        else if (bVar8) {
          local_dc = (undefined4 *)((int)local_c0 + iVar10);
          local_e8 = fVar2;
          local_e0 = puVar1;
        }
      }
      local_d8 = local_d8 + 1;
      iVar10 = iVar10 + 0xc;
    } while (local_d8 < iVar9);
    if (local_e0 != (undefined4 *)0x0) {
      *param_3 = *local_e0;
      uVar7 = local_e0[2];
      param_3[1] = local_e0[1];
      param_3[2] = uVar7;
      *param_4 = *local_dc;
      uVar7 = local_dc[2];
      param_4[1] = local_dc[1];
      param_4[2] = uVar7;
      return (float10)local_e8;
    }
  }
  return (float10)-1.0;
}

