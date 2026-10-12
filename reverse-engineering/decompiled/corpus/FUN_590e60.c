/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x590e60; label: FUN_00590e60
 */

void FUN_00590e60(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  char cVar3;
  short sVar4;
  undefined2 uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined1 local_34 [16];
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_44;
  iVar8 = 0;
  local_38 = param_1;
  local_40 = 0;
  uVar2 = FUN_006218c0();
  local_44 = CONCAT31(local_44._1_3_,uVar2);
  sVar4 = FUN_00621860();
  *(short *)(param_2 + 1) = sVar4;
  if (sVar4 == 0) {
    __security_check_cookie(local_4 ^ (uint)&local_44);
    return;
  }
  iVar10 = *param_2;
  local_3c = 0;
  do {
    FUN_006216f0(iVar10,0x10);
    FUN_00621900(iVar10 + 0x1c);
    FUN_005aef10(*(undefined4 *)(iVar10 + 0x10),param_1,0,local_44,"GizBuildit",iVar10);
    fVar12 = (float10)FUN_006217a0();
    *(float *)(iVar10 + 0x4c) = (float)fVar12;
    if ((byte)local_44 < 7) {
      FUN_006217a0();
    }
    uVar5 = FUN_00621860();
    *(undefined2 *)(iVar10 + 0x56) = uVar5;
    uVar5 = FUN_00621860();
    *(undefined2 *)(iVar10 + 0x54) = uVar5;
    uVar2 = FUN_006218c0();
    *(undefined1 *)(iVar10 + 0x70) = uVar2;
    uVar2 = FUN_006218c0();
    *(undefined1 *)(iVar10 + 0x71) = uVar2;
    if (5 < (byte)local_44) {
      fVar12 = (float10)FUN_006217a0();
      *(float *)(iVar10 + 0x50) = (float)fVar12;
    }
    *(undefined2 *)(iVar10 + 0x78) = 0xffff;
    bVar7 = (byte)local_44;
    if (6 < (byte)local_44) {
      if ((byte)local_44 < 8) {
        uVar5 = FUN_00621860();
        *(undefined2 *)(iVar10 + 0x78) = uVar5;
      }
      else {
        cVar3 = FUN_006218c0();
        if (cVar3 != 0) {
          FUN_006216f0(local_24,(int)cVar3);
          sVar4 = FUN_0056a9d0(local_24);
          *(short *)(iVar10 + 0x78) = sVar4;
          if (sVar4 != -1) {
            *(ushort *)(iVar10 + 0x7a) = *(ushort *)(iVar10 + 0x7a) | 0x80;
          }
        }
      }
      uVar5 = FUN_00621860();
      *(undefined2 *)(iVar10 + 0x58) = uVar5;
      uVar5 = FUN_00621860();
      *(undefined2 *)(iVar10 + 0x5a) = uVar5;
      FUN_00621900(iVar10 + 0x5c);
      bVar7 = (byte)local_44;
    }
    if (bVar7 < 9) {
      if ((*(int *)(param_1 + 300) == 0) || ((*(byte *)(*(int *)(param_1 + 300) + 0x7a) & 1) == 0))
      {
        fVar12 = (float10)1.75;
      }
      else {
        fVar12 = (float10)12.0;
      }
    }
    else {
      fVar12 = (float10)FUN_006217a0();
      bVar7 = (byte)local_44;
    }
    *(float *)(iVar10 + 0x68) = (float)fVar12;
    if (bVar7 < 4) {
      cVar3 = FUN_006218c0();
      *(short *)(iVar10 + 0x72) = (short)cVar3;
      if (1 < (byte)local_44) {
        cVar3 = FUN_006218c0();
        if (cVar3 != '\0') {
          *(ushort *)(iVar10 + 0x72) = *(ushort *)(iVar10 + 0x72) | 0x40;
        }
        if ((2 < (byte)local_44) && (cVar3 = FUN_006218c0(), cVar3 != '\0')) {
          *(ushort *)(iVar10 + 0x72) = *(ushort *)(iVar10 + 0x72) | 0x80;
        }
      }
    }
    else {
      uVar5 = FUN_00621860();
      *(undefined2 *)(iVar10 + 0x72) = uVar5;
    }
    if (4 < (byte)local_44) {
      uVar5 = FUN_00621860();
      *(undefined2 *)(iVar10 + 0x74) = uVar5;
      cVar3 = FUN_006218c0();
      if (cVar3 != '\0') {
        FUN_006216f0(local_34,0x10);
        iVar11 = 0;
        if ((short)param_2[1] != 0) {
          iVar9 = 0;
          do {
            iVar6 = FUN_004f8b10(*param_2 + iVar9,local_34);
            iVar8 = local_40;
            if (iVar6 == 0) {
              iVar9 = *param_2;
              *(ushort *)(iVar10 + 0x7a) = *(ushort *)(iVar10 + 0x7a) | 3;
              *(int *)(iVar10 + 0x18) = iVar11 * 0x7c + iVar9;
              break;
            }
            iVar11 = iVar11 + 1;
            iVar9 = iVar9 + 0x7c;
          } while (iVar11 < (int)(uint)*(ushort *)(param_2 + 1));
        }
      }
    }
    param_1 = local_38;
    *(undefined1 *)(iVar10 + 0x6c) = 0;
    *(int *)(iVar10 + 0x14) = param_2[4] + iVar8 * 4;
    for (puVar1 = *(undefined4 **)(*(int *)(iVar10 + 0x10) + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (((puVar1[5] != 0) && (puVar1[4] != 0)) || ((*(byte *)(iVar10 + 0x72) & 0x40) != 0)) {
        *(undefined4 **)(*(int *)(iVar10 + 0x14) + (uint)*(byte *)(iVar10 + 0x6c) * 4) = puVar1;
        *(char *)(iVar10 + 0x6c) = *(char *)(iVar10 + 0x6c) + '\x01';
        iVar8 = iVar8 + 1;
      }
      local_40 = iVar8;
    }
    FUN_00590140(iVar10,local_38);
    local_3c = local_3c + 1;
    iVar10 = iVar10 + 0x7c;
    if ((int)(uint)*(ushort *)(param_2 + 1) <= local_3c) {
      __security_check_cookie(local_4 ^ (uint)&local_44);
      return;
    }
  } while( true );
}

