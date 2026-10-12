/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a4ff0; label: FUN_004a4ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a4ff0(undefined2 param_1)

{
  uint *puVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  float local_14;
  undefined1 local_c [12];
  
  if ((*(char *)(in_EAX + 0x28b) != '\0') || (_DAT_00950780 != 0.0)) {
    *(undefined4 *)(in_EAX + 0xd80) = 0;
    *(undefined4 *)(in_EAX + 0xd84) = 0;
    *(undefined4 *)(in_EAX + 0xd14) = 0;
    *(undefined4 *)(in_EAX + 0xd90) = 0;
    *(undefined4 *)(in_EAX + 0xd18) = 0;
    *(undefined4 *)(in_EAX + 0xd88) = 0x3e4ccccd;
    return;
  }
  if (0.0 < *(float *)(in_EAX + 0xd88)) {
    *(float *)(in_EAX + 0xd88) = *(float *)(in_EAX + 0xd88) - _DAT_00925018;
    return;
  }
  if (*(float *)(in_EAX + 0xd80) == 0.0) {
    *(undefined4 *)(in_EAX + 0xd14) = *(undefined4 *)(in_EAX + 0xd18);
    *(undefined1 *)(in_EAX + 0xe2c) = *(undefined1 *)(in_EAX + 0xe2d);
  }
  if ((*(int *)(in_EAX + 0xd14) == 0) || (*(int *)(in_EAX + 0xd14) != *(int *)(in_EAX + 0xd18))) {
    if ((_DAT_007fc074 != *(float *)(in_EAX + 0xd80)) || (*(float *)(in_EAX + 0xd90) <= 0.0)) {
LAB_004a50c0:
      local_14 = 0.0;
    }
    else {
      *(float *)(in_EAX + 0xd90) = *(float *)(in_EAX + 0xd90) - _DAT_00925018;
      local_14 = _DAT_007fc074;
    }
  }
  else {
    if ((((*(byte *)(in_EAX + 0x1fc) & 0x80) == 0) && (*(char *)(in_EAX + 0xe2c) == '\0')) &&
       (*(char *)(in_EAX + 0x7b5) != '\b')) {
      iVar5 = FUN_0062f150(in_EAX + 8,0xb,1,1);
      if ((iVar5 == 0) && (iVar5 = FUN_0062f150(in_EAX + 8,0x27,1,1), iVar5 == 0))
      goto LAB_004a50c0;
    }
    local_14 = _DAT_007fc074;
  }
  if (*(float *)(in_EAX + 0xd84) == *(float *)(in_EAX + 0xd80)) {
    *(float *)(in_EAX + 0xd84) = local_14;
  }
  else {
    fVar3 = *(float *)(in_EAX + 0xd80);
    if (*(float *)(in_EAX + 0xd80) <= *(float *)(in_EAX + 0xd84)) {
      fVar4 = *(float *)(in_EAX + 0xd80) + _DAT_00925018;
      *(float *)(in_EAX + 0xd80) = fVar4;
      if (*(float *)(in_EAX + 0xd84) < fVar4) {
        *(undefined4 *)(in_EAX + 0xd80) = *(undefined4 *)(in_EAX + 0xd84);
      }
    }
    else {
      fVar4 = *(float *)(in_EAX + 0xd80) - _DAT_00925018 * 0.5;
      *(float *)(in_EAX + 0xd80) = fVar4;
      if (fVar4 < 0.0) {
        *(undefined4 *)(in_EAX + 0xd80) = 0;
      }
    }
    if ((_DAT_007fc074 == *(float *)(in_EAX + 0xd80)) && (fVar3 != _DAT_007fc074)) {
      *(undefined4 *)(in_EAX + 0xd90) = _DAT_007fc070;
    }
  }
  if ((0.0 < *(float *)(in_EAX + 0xd80)) && (*(int *)(in_EAX + 0xd14) == 0)) {
    FUN_004a4ca0(in_EAX + 0x6c4);
  }
  if ((0.0 < *(float *)(in_EAX + 0xd80)) && (iVar5 = *(int *)(in_EAX + 0xd14), iVar5 != 0)) {
    switch(*(undefined1 *)(in_EAX + 0xe2c)) {
    case 0:
      if ((*(byte *)(iVar5 + 0xa0) & 1) != 0) {
        fVar3 = *(float *)(iVar5 + 0x68);
        *(float *)(in_EAX + 0xd8c) = fVar3;
        fVar4 = *(float *)(iVar5 + 0x70);
        *(undefined2 *)(in_EAX + 0xe1e) = param_1;
        *(float *)(in_EAX + 0xd8c) = fVar3 * fVar4;
        *(undefined4 *)(in_EAX + 0xc68) = *(undefined4 *)(iVar5 + 0x1c);
        *(undefined4 *)(in_EAX + 0xc6c) = *(undefined4 *)(iVar5 + 0x20);
        *(undefined4 *)(in_EAX + 0xc70) = *(undefined4 *)(iVar5 + 0x24);
        *(uint *)(iVar5 + 0xa0) = *(uint *)(iVar5 + 0xa0) | 0x20000;
        goto switchD_004a5247_default;
      }
      break;
    case 1:
      fVar3 = *(float *)(in_EAX + 0xd8c);
      pfVar2 = (float *)(in_EAX + 0xd8c);
      iVar7 = FUN_005cfac0(iVar5 + 4);
      if (iVar7 != 0) {
        iVar7 = in_EAX + 0xc68;
        FUN_005d0260(iVar5 + 4,iVar7,pfVar2);
        uVar6 = FUN_005d0330(iVar5 + 4);
        FUN_005c11d0(iVar7,iVar7,uVar6);
        *(undefined2 *)(in_EAX + 0xe1e) = param_1;
        *pfVar2 = *pfVar2 * fVar3;
        if (*(int *)(iVar5 + 0x24) != 0) {
          puVar1 = (uint *)(*(int *)(iVar5 + 0x24) + 4);
          *puVar1 = *puVar1 | 1;
        }
        goto switchD_004a5247_default;
      }
      break;
    case 2:
      if (((*(uint *)(iVar5 + 0x1fc) & 1) != 0) || ((*(uint *)(iVar5 + 0x1fc) & 0x1000) != 0)) {
        if (*(float *)(iVar5 + 0x1dc) <= *(float *)(iVar5 + 0x1e0)) {
          fVar3 = *(float *)(iVar5 + 0x1e0);
        }
        else {
          fVar3 = *(float *)(iVar5 + 0x1dc);
        }
        *(undefined2 *)(in_EAX + 0xe1e) = param_1;
        *(float *)(in_EAX + 0xd8c) = fVar3 * 1.75;
        *(undefined4 *)(in_EAX + 0xc68) = *(undefined4 *)(iVar5 + 0x80);
        *(float *)(in_EAX + 0xc6c) =
             (*(float *)(iVar5 + 0xff4) - *(float *)(iVar5 + 0xff0)) * 0.5 *
             *(float *)(iVar5 + 0xa8) +
             *(float *)(iVar5 + 0xa8) * *(float *)(iVar5 + 0xff0) + *(float *)(iVar5 + 0x60);
        *(undefined4 *)(in_EAX + 0xc70) = *(undefined4 *)(iVar5 + 0x88);
        goto switchD_004a5247_default;
      }
      break;
    case 3:
      if ((*(byte *)(iVar5 + 0x144) & 1) != 0) {
        iVar7 = FUN_005cfac0(iVar5 + 0x148);
        if (iVar7 == 0) {
          *(float *)(in_EAX + 0xd8c) = *(float *)(iVar5 + 0xe0) + *(float *)(iVar5 + 0xe0);
        }
        else {
          pfVar2 = (float *)(in_EAX + 0xd8c);
          FUN_005d0260(iVar5 + 0x148,local_c,pfVar2);
          *pfVar2 = *pfVar2 + *pfVar2;
        }
        *(undefined2 *)(in_EAX + 0xe1e) = param_1;
        *(undefined4 *)(in_EAX + 0xc68) = *(undefined4 *)(iVar5 + 0x30);
        *(undefined4 *)(in_EAX + 0xc6c) = *(undefined4 *)(iVar5 + 0x34);
        *(undefined4 *)(in_EAX + 0xc70) = *(undefined4 *)(iVar5 + 0x38);
        goto switchD_004a5247_default;
      }
      break;
    default:
switchD_004a5247_default:
      *(float *)(in_EAX + 0xd8c) = *(float *)(in_EAX + 0xd8c) * _DAT_007fc06c;
      return;
    }
    FUN_004a4ca0(in_EAX + 0x6c4);
  }
  return;
}

