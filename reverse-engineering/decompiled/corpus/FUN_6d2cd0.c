/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d2cd0; label: FUN_006d2cd0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d2cd0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  if (*(int *)(in_ECX + 100) == 1) {
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(undefined4 *)(in_ECX + 0x54) = 0xc47a0000;
    *(undefined4 *)(in_ECX + 0x58) = 0;
  }
  if (*(int *)(in_ECX + 100) == 2) {
    *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x3c);
  }
  FUN_006d1950(param_1);
  FUN_006c2610(param_1);
  if (*(int *)(in_ECX + 0x4c) != 0) {
    DAT_02973c20 = 0;
    _DAT_02973c28 = 0;
    FUN_005d1740(DAT_02973a78);
    FUN_005d1750(DAT_0081f99c,DAT_0081f99c);
    FUN_0062a400(*(undefined4 *)(in_ECX + 0x4c),*(undefined4 *)(param_1 + 0x44),
                 *(undefined4 *)(param_1 + 0x40));
    if (*(int *)(in_ECX + 0x4c) != 0) {
      return;
    }
  }
  if ((*(char *)(param_1 + 0x5d) == '\0') || (*(float *)(param_1 + 0x14c) == 0.0)) {
    DAT_02973c20 = 1;
    _DAT_02973c28 = 1;
    *(undefined4 *)(in_ECX + 0x3c) = 0xff808080;
    iVar2 = FUN_006d0a40(param_1);
    for (puVar1 = DAT_0081fcfc; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[3] != 0) {
        (**(code **)(*(int *)puVar1[3] + 8))(param_1);
      }
    }
    if (iVar2 == 0) {
      if ((*(char *)(param_1 + 0x7d) != '\0') && (*(float *)(param_1 + 300) != 0.0)) {
        *(undefined4 *)(in_ECX + 0x68) = 0;
        *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081faf0;
        FUN_006c58a0(DAT_0081fb00);
      }
      if ((*(char *)(param_1 + 0x7e) != '\0') && (*(float *)(param_1 + 0x130) != 0.0)) {
        *(undefined4 *)(in_ECX + 0x68) = 3;
        *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081fb70;
        FUN_006c58a0(DAT_0081fb80);
      }
      if ((*(char *)(param_1 + 0x7f) != '\0') && (*(float *)(param_1 + 0x134) != 0.0)) {
        *(undefined4 *)(in_ECX + 0x68) = 4;
        *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081fbf0;
        FUN_006c58a0(DAT_0081fc00);
      }
      if ((*(char *)(param_1 + 0x80) != '\0') && (*(float *)(param_1 + 0x138) != 0.0)) {
        *(undefined4 *)(in_ECX + 0x68) = 5;
        *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081fc70;
        FUN_006c58a0(DAT_0081fc80);
      }
      if ((*(char *)(param_1 + 0x9d) != '\0') && (*(float *)(param_1 + 0x1ac) != 0.0)) {
        uStack_20 = 0;
        uStack_1c = 0;
        uStack_18 = 0;
        iVar2 = FUN_006c9180(param_1 + 0x20,param_1 + 0x30,&uStack_20,1);
        if (iVar2 == 0) {
          FUN_006d2590(param_1);
        }
        else {
          FUN_006c9af0();
        }
      }
      if (*(int *)(in_ECX + 0x20) == 0) {
        *(undefined ***)(in_ECX + 0x20) = &PTR_PTR_0081faf0;
      }
      iVar2 = (**(code **)**(undefined4 **)(in_ECX + 0x20))(param_1,in_ECX + 0x24);
    }
    if ((*(int **)(in_ECX + 0x1c) != (int *)0x0) && (iVar2 == 0)) {
      (**(code **)(**(int **)(in_ECX + 0x1c) + 0xc))(param_1);
    }
    if (0 < *(int *)(in_ECX + 0x2c)) {
      if ((*(char *)(param_1 + 0x81) != '\0') && (*(float *)(param_1 + 0x13c) != 0.0)) {
        FUN_006cf290();
      }
      if ((*(char *)(param_1 + 0x82) != '\0') && (*(float *)(param_1 + 0x140) != 0.0)) {
        FUN_006cf350();
      }
      for (puVar1 = *(undefined4 **)(in_ECX + 0x24); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        iVar2 = puVar1[2];
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x14) != 0)) {
          (**(code **)(**(int **)(iVar2 + 0x14) + 0x38))(puVar1[3],param_1);
        }
      }
      if ((*(char *)(param_1 + 0x9f) != '\0') && (*(float *)(param_1 + 0x1b4) != 0.0)) {
        FUN_006c8760(8,DAT_02973ab8,&uStack_20,0);
        FUN_006b9050(&uStack_20);
        FUN_006d0de0(param_1);
        if (*(int *)(in_ECX + 0x68) == 0) {
          *(undefined4 *)(in_ECX + 0x68) = 3;
        }
        FUN_006c8c20(*(undefined4 *)(in_ECX + 0x68));
        iVar2 = DAT_02973a7c;
        if (DAT_02973a7c == 0) {
          iVar2 = DAT_02973a80;
        }
        FUN_006271a0(iVar2);
      }
    }
  }
  return;
}

