/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fc9c0; label: FUN_004fc9c0
 */

int FUN_004fc9c0(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  undefined2 uVar3;
  int iVar4;
  uint local_8;
  uint local_4;
  
  local_8 = 0;
LAB_004fc9d1:
  iVar4 = 0;
  do {
    bVar1 = false;
LAB_004fc9d5:
    local_4 = 0;
    FUN_004fb550(param_2,&local_4,2);
    uVar3 = (undefined2)local_4;
    switch(local_4 & 0xffff) {
    case 0:
      goto switchD_004fca00_caseD_0;
    case 9:
    case 0x20:
      if (bVar1) {
        *(undefined2 *)(param_1 + iVar4 * 2) = uVar3;
        iVar4 = iVar4 + 1;
      }
      goto LAB_004fc9d5;
    case 0xd:
      local_4 = 0;
      FUN_004fb550(param_2,&local_4,2);
    case 10:
      if ((iVar4 != 0) && (bVar1)) {
switchD_004fca00_caseD_0:
        *(undefined2 *)(param_1 + iVar4 * 2) = 0;
        return iVar4;
      }
      break;
    case 0x22:
      goto switchD_004fca00_caseD_22;
    case 0x3b:
      if (local_8 == 0) {
        if ((iVar4 == 0) || (!bVar1)) goto LAB_004fca61;
        local_8 = 0;
        FUN_004fb550(param_2,&local_8,2);
        uVar2 = local_8 & 0xffff;
        if (uVar2 != 0) goto LAB_004fcaf2;
        goto LAB_004fcb34;
      }
    default:
      bVar1 = true;
      *(undefined2 *)(param_1 + iVar4 * 2) = uVar3;
      iVar4 = iVar4 + 1;
      goto LAB_004fc9d5;
    }
  } while( true );
  while (local_4 != 0xd) {
LAB_004fca61:
    local_4 = 0;
    FUN_004fb550(param_2,&local_4,2);
    local_4 = local_4 & 0xffff;
    if ((local_4 == 0) || (local_4 == 10)) goto LAB_004fc9d1;
  }
  local_4 = 0;
  FUN_004fb550(param_2,&local_4,2);
  goto LAB_004fc9d1;
LAB_004fcaf2:
  if (uVar2 == 10) {
LAB_004fcb34:
    *(undefined2 *)(param_1 + iVar4 * 2) = 0;
    return iVar4;
  }
  if (uVar2 == 0xd) {
    FUN_004fb810(param_2);
    goto LAB_004fcb34;
  }
  local_8 = 0;
  FUN_004fb550(param_2,&local_8,2);
  uVar2 = local_8 & 0xffff;
  if (uVar2 == 0) {
    *(undefined2 *)(param_1 + iVar4 * 2) = 0;
    return iVar4;
  }
  goto LAB_004fcaf2;
switchD_004fca00_caseD_22:
  local_8 = 1 - local_8;
  bVar1 = true;
  *(undefined2 *)(param_1 + iVar4 * 2) = uVar3;
  iVar4 = iVar4 + 1;
  goto LAB_004fc9d5;
}

