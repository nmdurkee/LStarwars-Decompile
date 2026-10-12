/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x65f140; label: FUN_0065f140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065f140(undefined4 param_1)

{
  char *_Source;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  size_t _Count;
  undefined1 local_24 [12];
  char local_18 [19];
  undefined1 local_5;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  iVar4 = 0;
  iVar5 = 0;
  if (0 < DAT_02962a08) {
    piVar1 = (int *)(DAT_02962a14 + 4);
    iVar2 = DAT_02962a08;
    do {
      if (*piVar1 != 0) {
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + *piVar1;
      }
      piVar1 = piVar1 + 0x14;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_006211c0(1);
  iVar2 = FUN_00621270(param_1,1);
  if (iVar2 == 0) {
    __security_check_cookie(local_4 ^ (uint)local_24);
    return;
  }
  FUN_006211b0(1);
  FUN_00621520(9);
  FUN_006214d0(_DAT_00810a98);
  FUN_006214d0(_DAT_00810a9c);
  FUN_00621520(iVar4);
  FUN_00621520(iVar5);
  iVar4 = 0;
  if (0 < DAT_02962a08) {
    iVar2 = 0;
    iVar5 = DAT_02962a14;
    do {
      if (*(int *)(iVar2 + 4 + iVar5) != 0) {
        FUN_005da860(local_24,DAT_02962114,*(undefined4 *)(iVar2 + iVar5));
        _Count = 0x14;
        _Source = (char *)FUN_005cfa50(local_24);
        _strncpy(local_18,_Source,_Count);
        local_5 = 0;
        FUN_00621440(local_18,0x14);
        FUN_00621520(*(undefined4 *)(iVar2 + 4 + DAT_02962a14));
        FUN_00621620(iVar2 + 8 + DAT_02962a14);
        FUN_006214d0(*(undefined4 *)(iVar2 + 0x14 + DAT_02962a14));
        FUN_006214d0(*(undefined4 *)(iVar2 + 0x18 + DAT_02962a14));
        FUN_00621520(*(undefined4 *)(iVar2 + 0x1c + DAT_02962a14));
        FUN_006214d0(*(undefined4 *)(iVar2 + 0x20 + DAT_02962a14));
        FUN_00621600(*(undefined1 *)(iVar2 + 0x25 + DAT_02962a14));
        FUN_00621600(*(undefined1 *)(iVar2 + 0x26 + DAT_02962a14));
        FUN_00621600(*(undefined1 *)(iVar2 + 0x27 + DAT_02962a14));
        FUN_00621520(*(undefined4 *)(iVar2 + 0x28 + DAT_02962a14));
        FUN_006214d0(*(undefined4 *)(iVar2 + 0x2c + DAT_02962a14));
        FUN_006214d0(*(undefined4 *)(iVar2 + 0x30 + DAT_02962a14));
        FUN_006215a0(*(undefined2 *)(iVar2 + 0x34 + DAT_02962a14));
        FUN_006215a0(*(undefined2 *)(iVar2 + 0x36 + DAT_02962a14));
        FUN_006214d0(*(undefined4 *)(iVar2 + 0x38 + DAT_02962a14));
        FUN_006214d0(*(undefined4 *)(iVar2 + 0x3c + DAT_02962a14));
        FUN_00621600(*(undefined1 *)(iVar2 + 0x42 + DAT_02962a14));
        FUN_00621600(*(undefined1 *)(iVar2 + 0x43 + DAT_02962a14));
        FUN_006214d0(*(undefined4 *)(iVar2 + 0x44 + DAT_02962a14));
        if ((*(char *)(iVar2 + 0x27 + DAT_02962a14) == '\x03') &&
           (iVar5 = 0, 0 < *(int *)(iVar2 + 4 + DAT_02962a14))) {
          do {
            FUN_00621620((*(short *)(iVar2 + 0x40 + DAT_02962a14) * DAT_02962a10 + iVar5) * 0x20 +
                         DAT_02962a18);
            FUN_006214d0(*(undefined4 *)
                          ((*(short *)(iVar2 + 0x40 + DAT_02962a14) * DAT_02962a10 + iVar5) * 0x20 +
                           0xc + DAT_02962a18));
            FUN_006215a0(*(undefined2 *)
                          ((*(short *)(iVar2 + 0x40 + DAT_02962a14) * DAT_02962a10 + iVar5) * 0x20 +
                           0x10 + DAT_02962a18));
            FUN_006215a0(*(undefined2 *)
                          ((*(short *)(iVar2 + 0x40 + DAT_02962a14) * DAT_02962a10 + iVar5) * 0x20 +
                           0x12 + DAT_02962a18));
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(int *)(iVar2 + 4 + DAT_02962a14));
        }
        iVar6 = 0;
        iVar5 = DAT_02962a14;
        if (0 < *(int *)(iVar2 + 4 + DAT_02962a14)) {
          iVar3 = 0;
          do {
            FUN_00621620(*(int *)(iVar2 + 0x4c + DAT_02962a14) + iVar3);
            iVar6 = iVar6 + 1;
            iVar3 = iVar3 + 0xc;
            iVar5 = DAT_02962a14;
          } while (iVar6 < *(int *)(iVar2 + 4 + DAT_02962a14));
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x50;
    } while (iVar4 < DAT_02962a08);
  }
  FUN_006211b0(0);
  FUN_006213e0();
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

