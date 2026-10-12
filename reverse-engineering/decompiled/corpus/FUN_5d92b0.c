/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5d92b0; label: FUN_005d92b0
 */

short FUN_005d92b0(int param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  byte extraout_CL;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  uint uVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  uint uVar11;
  bool bVar12;
  short asStack_1000c [32760];
  short local_c [6];
  
  sVar10 = 0;
  if ((param_1 == 0) || (param_2 == (float *)0x0)) {
    return -1;
  }
  sVar9 = 0;
  sVar8 = 0;
  local_c[0] = 0;
  local_c[1] = 0;
  if (0 < *(int *)(param_1 + 0x74)) {
    do {
      sVar4 = FUN_005d9220();
      if (sVar4 != 0) {
        iVar6 = *(int *)(param_1 + 0x78) + sVar9 * 0x18;
        iVar1 = *(int *)(param_1 + 0x78) + local_c[1] * 0x18;
        sVar9 = local_c[0];
        sVar4 = local_c[1];
        if (sVar10 == 2) {
          bVar12 = *(byte *)(iVar6 + 0x14) < *(byte *)(iVar1 + 0x14);
          if (*(byte *)(iVar6 + 0x14) == *(byte *)(iVar1 + 0x14)) {
            bVar3 = FUN_005c12e0();
            bVar12 = bVar3 < extraout_CL;
            iVar6 = extraout_EDX;
          }
          if (bVar12) {
            sVar9 = sVar8;
            sVar4 = local_c[1];
            if ((*(byte *)(iVar6 + 0x10) & 1) == 0) {
              FUN_005c12e0();
              iVar6 = extraout_EDX_00;
              sVar4 = local_c[1];
            }
          }
          else {
            sVar9 = local_c[0];
            sVar4 = sVar8;
            if ((*(byte *)(iVar1 + 0x10) & 1) == 0) {
              FUN_005c12e0();
              iVar6 = extraout_EDX_01;
              sVar9 = local_c[0];
            }
          }
        }
        local_c[1] = sVar4;
        local_c[0] = sVar9;
        iVar5 = (int)sVar10;
        sVar10 = sVar10 + 1;
        local_c[iVar5] = sVar8;
        sVar9 = local_c[0];
        if (((sVar10 == 2) && ((*(byte *)(iVar6 + 0x10) & 1) == 0)) &&
           ((*(byte *)(iVar1 + 0x10) & 1) == 0)) goto LAB_005d93b1;
      }
      sVar8 = sVar8 + 1;
    } while ((int)sVar8 < *(int *)(param_1 + 0x74));
    if (sVar10 == 1) {
      return sVar9;
    }
    local_c[0] = sVar9;
    if (sVar10 != 0) {
LAB_005d93b1:
      uVar11 = (uint)*(byte *)(*(int *)(param_1 + 0x78) + 0xf + local_c[0] * 0x18);
      sVar10 = 0;
      if (uVar11 != 0) {
        uVar7 = (uint)*(byte *)(*(int *)(param_1 + 0x78) + 0xf + local_c[1] * 0x18);
        iVar6 = 0;
        do {
          sVar9 = *(short *)(*(int *)(*(int *)(param_1 + 0x78) + local_c[0] * 0x18 + 8) + iVar6 * 2)
          ;
          sVar8 = 0;
          if (uVar7 != 0) {
            iVar6 = 0;
            do {
              if (sVar9 == *(short *)(*(int *)(*(int *)(param_1 + 0x78) + local_c[1] * 0x18 + 8) +
                                     iVar6 * 2)) {
                pfVar2 = (float *)(sVar9 * 0x20 + *(int *)(param_1 + 0x70));
                if (0.0 <= pfVar2[2] * param_2[2] + *pfVar2 * *param_2 + pfVar2[1] * param_2[1] +
                           pfVar2[3]) {
                  return *(short *)(pfVar2 + 6);
                }
                return *(short *)((int)pfVar2 + 0x16);
              }
              sVar8 = sVar8 + 1;
              iVar6 = (int)sVar8;
            } while (iVar6 < (int)uVar7);
          }
          sVar10 = sVar10 + 1;
          iVar6 = (int)sVar10;
        } while (iVar6 < (int)uVar11);
        return -1;
      }
    }
  }
  return -1;
}

