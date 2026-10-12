/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x631e90; label: FUN_00631e90
 */

bool FUN_00631e90(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int local_70 [28];
  
  local_70[6] = 3;
  local_70[9] = 3;
  local_70[0x11] = 1;
  local_70[0x13] = 1;
  local_70[0x17] = 1;
  local_70[0x1b] = 1;
  local_70[0] = 0x16;
  local_70[1] = 0;
  local_70[2] = 4;
  local_70[3] = 0;
  local_70[4] = 0x14;
  local_70[5] = 8;
  local_70[7] = 0;
  local_70[8] = 0x17;
  local_70[10] = 2;
  local_70[0xb] = 0;
  local_70[0xc] = 0x18;
  local_70[0xd] = 2;
  local_70[0xe] = 2;
  local_70[0xf] = 0;
  local_70[0x10] = 0x15;
  local_70[0x12] = 4;
  local_70[0x14] = 0x1a;
  local_70[0x15] = 5;
  local_70[0x16] = 2;
  local_70[0x18] = 0x19;
  local_70[0x19] = 4;
  local_70[0x1a] = 2;
  uVar3 = 0;
  piVar4 = local_70;
  do {
    iVar2 = (**(code **)(*param_1 + 0x28))(param_1,0,1,param_2,0,3,*piVar4);
    if (-1 < iVar2) {
      *(int *)(param_3 + 0x10) = local_70[uVar3 * 4];
      iVar2 = local_70[uVar3 * 4 + 2];
      *(int *)(param_3 + 0x20) = local_70[uVar3 * 4 + 1];
      *(int *)(param_3 + 0x18) = iVar2;
      break;
    }
    uVar3 = uVar3 + 1;
    piVar4 = piVar4 + 4;
  } while (uVar3 < 7);
  if (uVar3 == 7) {
    return false;
  }
  uVar3 = 0;
  puVar1 = (undefined4 *)&stack0xffffff80;
  while ((puVar1[7] == 0 ||
         (iVar2 = (**(code **)(*param_1 + 0x28))(param_1,0,1,param_2,0,3,puVar1[4]), iVar2 < 0))) {
    uVar3 = uVar3 + 1;
    puVar1 = puVar1 + 4;
    if (6 < uVar3) {
      return uVar3 != 7;
    }
  }
  *(int *)(param_3 + 0xc) = local_70[uVar3 * 4];
  iVar2 = local_70[uVar3 * 4 + 1];
  *(int *)(param_3 + 0x14) = local_70[uVar3 * 4 + 2];
  *(int *)(param_3 + 0x1c) = iVar2;
  return uVar3 != 7;
}

