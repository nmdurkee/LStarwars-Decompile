/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68d6a0; label: FUN_0068d6a0
 */

void FUN_0068d6a0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int local_8;
  
  iVar6 = DAT_029231a8;
  local_8 = 0;
  if (DAT_029231a8 == -1) goto LAB_0068d970;
  if ((&DAT_02924b60)[DAT_029231a8 * 0x16] == -1) goto LAB_0068d970;
  iVar5 = (int)*(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4);
  iVar2 = *(int *)(DAT_0296209c + iVar5 * 4);
  iVar3 = *(int *)(param_2 + 0xc);
  if (*(char *)(iVar2 + 0x2e) != iVar3) {
    if (iVar3 == 2) {
      (&DAT_02924b9e)[DAT_029231a8 * 0x2c] = 40000;
    }
    else if (iVar3 == 3) {
      (&DAT_02924b9e)[DAT_029231a8 * 0x2c] = 30000;
    }
    else if (iVar3 == 0) {
      (&DAT_02924b9e)[DAT_029231a8 * 0x2c] = 20000;
    }
    else if (iVar3 == 7) {
      (&DAT_02924b9e)[DAT_029231a8 * 0x2c] = 10000;
    }
  }
  if (*(int *)(param_2 + 0xc) == 7) {
LAB_0068d75f:
    *(undefined1 *)(iVar2 + 0x2f1) = 2;
    iVar6 = DAT_029231a8;
    if (*(int *)(param_2 + 0xc) != 7) goto LAB_0068d771;
  }
  else {
    if (*(char *)(iVar2 + 0x2e) == '\a') {
      *(undefined1 *)(iVar2 + 0x2f1) = 0;
      iVar6 = DAT_029231a8;
    }
    if (*(int *)(param_2 + 0xc) == 7) goto LAB_0068d75f;
LAB_0068d771:
    if (*(char *)(*(int *)(DAT_0296209c +
                          *(short *)((&DAT_02924b60)[iVar6 * 0x16] * 0x330 + 0x182 + DAT_029620a4) *
                          4) + 0x2e) != '\a') {
      *(undefined1 *)(iVar2 + 0x2e) = *(undefined1 *)(param_2 + 0xc);
      goto LAB_0068d970;
    }
  }
  piVar7 = &DAT_02924b60;
  do {
    if (((piVar7[-1] == iVar5) && (*piVar7 != -1)) && (*piVar7 != 99999)) {
      FUN_00684400(piVar7);
      *piVar7 = 99999;
    }
    piVar7 = piVar7 + 0x16;
  } while ((int)piVar7 < 0x292fb60);
  *(undefined1 *)(iVar2 + 0x2e) = *(undefined1 *)(param_2 + 0xc);
  FUN_00600260(iVar2);
  puVar8 = &DAT_02924b54;
  do {
    if ((puVar8[2] == iVar5) && (piVar7 = puVar8 + 3, puVar8[3] == 99999)) {
      *piVar7 = -1;
      FUN_00684ee0(piVar7,puVar8[2],puVar8[-1],*puVar8,puVar8[1]);
      if (*piVar7 == -1) {
        *piVar7 = 99999;
      }
      else {
        *(undefined1 *)(*piVar7 * 0x330 + 0x2f9 + DAT_029620a4) = 0;
        FUN_00684640(*piVar7,*(undefined2 *)(puVar8 + 4),*(undefined2 *)((int)puVar8 + 0x12));
        FUN_006846a0(*piVar7,*(undefined2 *)(puVar8 + 5),*(undefined2 *)((int)puVar8 + 0x16),
                     *(undefined2 *)(puVar8 + 6));
        FUN_00655c30(*piVar7 * 0x330 + DAT_029620a4,puVar8[7]);
        uVar1 = puVar8[0xe];
        uVar4 = puVar8[0xd];
        if (*piVar7 != -1) {
          iVar6 = *piVar7 * 0x330;
          *(undefined4 *)(iVar6 + 0x2d0 + DAT_029620a4) = puVar8[0xc];
          *(undefined4 *)(iVar6 + 0x2d4 + DAT_029620a4) = uVar4;
          *(undefined4 *)(iVar6 + 0x2d8 + DAT_029620a4) = uVar1;
        }
        FUN_00655ba0(*piVar7,*(undefined2 *)(puVar8 + 0xf),*(undefined2 *)((int)puVar8 + 0x3e),
                     puVar8[0x10],puVar8[0x11]);
        FUN_00684720(*piVar7,*(undefined1 *)((int)puVar8 + 0x4f),*(undefined2 *)(puVar8 + 0x14),
                     *(undefined2 *)((int)puVar8 + 0x52));
        if (*piVar7 != -1) {
          *(undefined2 *)(*piVar7 * 0x330 + 0x2f0 + DAT_029620a4) = *(undefined2 *)(puVar8 + 0x12);
        }
        FUN_00655f30(*piVar7,*(undefined4 *)(&DAT_02947bdc + *(char *)((int)puVar8 + 0x4d) * 4));
      }
    }
    puVar8 = puVar8 + 0x16;
  } while ((int)puVar8 < 0x292fb54);
LAB_0068d970:
  iVar6 = *(int *)(param_1 + 0x40);
  if (iVar6 != 0) {
    FUN_006279f0(param_1);
    local_8 = iVar6;
  }
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))(param_1,local_8);
  }
  return;
}

