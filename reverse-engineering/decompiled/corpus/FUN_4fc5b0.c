/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fc5b0; label: FUN_004fc5b0
 */

uint FUN_004fc5b0(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*(char *)(param_1 + 0x578) != '\0') {
    uVar4 = FUN_004fc390(param_1);
    return uVar4;
  }
LAB_004fc5d1:
  bVar1 = false;
  uVar4 = 0;
  *(int *)(param_1 + 0x51c) = *(int *)(param_1 + 0x51c) + 1;
  *(undefined4 *)(param_1 + 0x520) = 0;
LAB_004fc5e0:
  uVar2 = FUN_004fc2d0(param_1);
  switch(uVar2) {
  case 0:
    goto switchD_004fc5fc_caseD_0;
  case 9:
  case 0x20:
    goto switchD_004fc5fc_caseD_9;
  case 10:
    goto switchD_004fc5fc_caseD_a;
  case 0xd:
    FUN_004fc2d0(param_1);
    goto switchD_004fc5fc_caseD_a;
  case 0x22:
    goto switchD_004fc5fc_caseD_22;
  case 0x3b:
    if (iVar5 == 0) goto code_r0x004fc64c;
  }
  bVar1 = true;
  goto switchD_004fc5fc_caseD_9;
switchD_004fc5fc_caseD_22:
  iVar5 = 1 - iVar5;
  bVar1 = true;
  *(undefined1 *)((*(int *)(param_1 + 0x514) - 1U & uVar4) + *(int *)(param_1 + 0x50c)) = uVar2;
  uVar4 = uVar4 + 1;
  goto LAB_004fc5e0;
switchD_004fc5fc_caseD_a:
  if ((uVar4 != 0) && (bVar1)) {
switchD_004fc5fc_caseD_0:
    *(undefined1 *)(uVar4 + *(int *)(param_1 + 0x50c)) = 0;
    return uVar4;
  }
  *(int *)(param_1 + 0x51c) = *(int *)(param_1 + 0x51c) + 1;
  bVar1 = false;
  goto LAB_004fc5e0;
switchD_004fc5fc_caseD_9:
  *(undefined1 *)((*(int *)(param_1 + 0x514) - 1U & uVar4) + *(int *)(param_1 + 0x50c)) = uVar2;
  uVar4 = uVar4 + 1;
  goto LAB_004fc5e0;
code_r0x004fc64c:
  if ((uVar4 == 0) || (!bVar1)) {
    do {
      cVar3 = FUN_004fc2d0(param_1);
      if ((cVar3 == '\0') || (cVar3 == '\n')) goto LAB_004fc5d1;
    } while (cVar3 != '\r');
    FUN_004fc2d0(param_1);
    goto LAB_004fc5d1;
  }
  cVar3 = FUN_004fc2d0(param_1);
  if (cVar3 != '\0') {
    while (cVar3 != '\n') {
      if (cVar3 == '\r') {
        FUN_004fc2d0(param_1);
        break;
      }
      cVar3 = FUN_004fc2d0(param_1);
      if (cVar3 == '\0') {
        *(undefined1 *)(uVar4 + *(int *)(param_1 + 0x50c)) = 0;
        return uVar4;
      }
    }
  }
  *(undefined1 *)(uVar4 + *(int *)(param_1 + 0x50c)) = 0;
  return uVar4;
}

