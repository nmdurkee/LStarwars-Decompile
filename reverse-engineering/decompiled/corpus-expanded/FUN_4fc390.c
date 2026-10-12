/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fc390; label: FUN_004fc390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004fc390(int param_1)

{
  int iVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = *(int *)(param_1 + 0x50c);
  iVar6 = 0;
LAB_004fc3a5:
  bVar2 = false;
  uVar7 = 0;
  *(int *)(param_1 + 0x51c) = *(int *)(param_1 + 0x51c) + 1;
  *(undefined4 *)(param_1 + 0x520) = 0;
LAB_004fc3b6:
  bVar3 = FUN_004fc2d0(param_1);
  bVar4 = FUN_004fc2d0(param_1);
  sVar5 = (ushort)bVar4 * 0x100 + (ushort)bVar3;
  switch(sVar5) {
  case 0:
    goto switchD_004fc3f0_caseD_0;
  case 9:
  case 0x20:
    goto switchD_004fc3f0_caseD_9;
  case 10:
    goto switchD_004fc3f0_caseD_a;
  case 0xd:
    FUN_004fc2d0(param_1);
    FUN_004fc2d0(param_1);
    goto switchD_004fc3f0_caseD_a;
  case 0x22:
    goto switchD_004fc3f0_caseD_22;
  case 0x3b:
    if (iVar6 == 0) goto code_r0x004fc44a;
  }
  bVar2 = true;
  goto switchD_004fc3f0_caseD_9;
switchD_004fc3f0_caseD_22:
  iVar6 = 1 - iVar6;
  bVar2 = true;
  *(short *)(iVar1 + ((*(int *)(param_1 + 0x518) >> 1) - 1U & uVar7) * 2) = sVar5;
  uVar7 = uVar7 + 1;
  goto LAB_004fc3b6;
switchD_004fc3f0_caseD_a:
  if ((uVar7 != 0) && (bVar2)) {
switchD_004fc3f0_caseD_0:
    *(undefined2 *)(iVar1 + uVar7 * 2) = 0;
    return uVar7;
  }
  *(int *)(param_1 + 0x51c) = *(int *)(param_1 + 0x51c) + 1;
  bVar2 = false;
  goto LAB_004fc3b6;
switchD_004fc3f0_caseD_9:
  *(short *)(iVar1 + ((*(int *)(param_1 + 0x518) >> 1) - 1U & uVar7) * 2) = sVar5;
  uVar7 = uVar7 + 1;
  goto LAB_004fc3b6;
code_r0x004fc44a:
  if ((uVar7 == 0) || (!bVar2)) {
    do {
      bVar3 = FUN_004fc2d0(param_1);
      bVar4 = FUN_004fc2d0(param_1);
      sVar5 = (ushort)bVar4 * 0x100 + (ushort)bVar3;
      if ((sVar5 == 0) || (sVar5 == 10)) goto LAB_004fc3a5;
    } while (sVar5 != 0xd);
    FUN_004fc2d0(param_1);
    FUN_004fc2d0(param_1);
    goto LAB_004fc3a5;
  }
  bVar3 = FUN_004fc2d0(param_1);
  bVar4 = FUN_004fc2d0(param_1);
  sVar5 = (ushort)bVar4 * 0x100 + (ushort)bVar3;
  if (sVar5 != 0) {
    while (sVar5 != 10) {
      if (sVar5 == 0xd) {
        FUN_004fc360(param_1);
        break;
      }
      bVar3 = FUN_004fc2d0();
      bVar4 = FUN_004fc2d0(param_1);
      sVar5 = (ushort)bVar4 * 0x100 + (ushort)bVar3;
      if (sVar5 == 0) {
        *(undefined2 *)(iVar1 + uVar7 * 2) = 0;
        return uVar7;
      }
    }
  }
  *(undefined2 *)(iVar1 + uVar7 * 2) = 0;
  return uVar7;
}

