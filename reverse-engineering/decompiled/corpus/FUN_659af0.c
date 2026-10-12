/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x659af0; label: FUN_00659af0
 */

void FUN_00659af0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  char *_Source;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  size_t _Count;
  int local_2c;
  int *local_28;
  undefined1 local_24 [12];
  char local_18 [19];
  undefined1 local_5;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2c;
  iVar6 = 0;
  piVar1 = &DAT_029300ec;
  do {
    if (piVar1[-0xb5] != -1) {
      iVar6 = iVar6 + 1;
    }
    if (*piVar1 != -1) {
      iVar6 = iVar6 + 1;
    }
    if (piVar1[0xb5] != -1) {
      iVar6 = iVar6 + 1;
    }
    if (piVar1[0x16a] != -1) {
      iVar6 = iVar6 + 1;
    }
    piVar1 = piVar1 + 0x2d4;
  } while ((int)piVar1 < 0x293b5ec);
  FUN_006211c0(1);
  iVar2 = FUN_00621270(param_1,1);
  if (iVar2 != 0) {
    FUN_006211b0(1);
    FUN_00621520(6);
    FUN_00621520(iVar6);
    piVar1 = &DAT_0292fe18;
    do {
      if (*piVar1 != -1) {
        FUN_005da860(local_24,DAT_02962114,*piVar1);
        _Count = 0x14;
        _Source = (char *)FUN_005cfa50(local_24);
        _strncpy(local_18,_Source,_Count);
        local_5 = 0;
        FUN_00621440(local_18,0x14);
        FUN_00621520(piVar1[1]);
        FUN_00621520(piVar1[2]);
        FUN_00621520(piVar1[3]);
        FUN_00621520(piVar1[4]);
        FUN_006214d0(piVar1[5]);
        FUN_006214d0(piVar1[6]);
        local_2c = 0;
        if (0 < piVar1[1]) {
          local_28 = piVar1 + 0x3f;
          piVar5 = piVar1 + 0x5b;
          piVar4 = piVar1 + 0x37;
          piVar3 = piVar1 + 7;
          do {
            FUN_00621440(piVar3,0x10);
            FUN_00621520(piVar4[-8]);
            FUN_00621520(*piVar4);
            FUN_00621620(local_28);
            FUN_006215a0((short)piVar5[-4]);
            FUN_006215a0((short)*piVar5);
            local_28 = local_28 + 3;
            local_2c = local_2c + 1;
            piVar4 = piVar4 + 1;
            piVar5 = (int *)((int)piVar5 + 2);
            piVar3 = piVar3 + 4;
          } while (local_2c < piVar1[1]);
        }
        local_2c = 0;
        if (0 < piVar1[2]) {
          piVar3 = piVar1 + 0x98;
          piVar5 = piVar1 + 0x90;
          piVar4 = piVar1 + 0x60;
          do {
            FUN_00621440(piVar4,0x10);
            FUN_00621520(piVar5[-8]);
            FUN_006214d0(*piVar5);
            FUN_00621620(piVar3);
            local_2c = local_2c + 1;
            piVar5 = piVar5 + 1;
            piVar4 = piVar4 + 4;
            piVar3 = piVar3 + 3;
          } while (local_2c < piVar1[2]);
        }
        FUN_006214d0(piVar1[0xb1]);
        FUN_006214d0(piVar1[0xb2]);
        FUN_006214d0(piVar1[0xb3]);
      }
      piVar1 = piVar1 + 0xb5;
    } while ((int)piVar1 < 0x293b318);
    FUN_006213e0();
    FUN_006211b0(0);
    __security_check_cookie(local_4 ^ (uint)&local_2c);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_2c);
  return;
}

