/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4dde30; label: FUN_004dde30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dde30(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  
  switch(DAT_008894a8) {
  case 0:
    FUN_005579d0(*(&DAT_00882aa8)[DAT_008894a0]);
    puVar4 = &DAT_0088909c;
    do {
      FUN_0046f4d0(*(undefined4 *)*puVar4);
      puVar4 = puVar4 + 1;
    } while ((int)puVar4 < 0x8890a8);
    DAT_008894a8 = 1;
    break;
  case 1:
    if ((DAT_008894a0 == 0) ||
       ((*(byte *)(*(int *)(*(&DAT_00882aa8)[DAT_008894a0] + 0x34) + 10) & 1) == 0)) {
      _DAT_0088949c = (&DAT_00889490)[_DAT_00882ba8] + 3;
      DAT_008894a0 = 0;
      DAT_008894a8 = 2;
    }
    break;
  case 2:
    bVar5 = *(int *)(*(int *)(*DAT_00882aa8 + 0x34) + 0xc) == 2;
    if (bVar5) {
      DAT_00888fd8 = 0;
    }
    uVar1 = (uint)bVar5;
    if (*(int *)(*(int *)(*DAT_00882aac + 0x34) + 0xc) == 2) {
      (&DAT_00888fd8)[uVar1] = 1;
      uVar1 = uVar1 + 1;
    }
    if (*(int *)(*(int *)(*DAT_00882ab0 + 0x34) + 0xc) == 2) {
      (&DAT_00888fd8)[uVar1] = 2;
      uVar1 = uVar1 + 1;
    }
    if (uVar1 == 2) {
      DAT_008894a0 = FUN_004ddcb0();
      DAT_008894a8 = 3;
    }
    else {
      iVar3 = 0;
      do {
        iVar2 = FUN_0055a1b0(*(undefined4 *)(param_1 + 0x2ac8),
                             *(undefined4 *)((int)&DAT_0088909c + iVar3),0,0);
        if ((iVar2 != 0) &&
           (*(int *)(*(int *)(**(int **)((int)&DAT_00882aa8 + iVar3) + 0x34) + 0xc) == 0)) {
          FUN_00557960(**(int **)((int)&DAT_00882aa8 + iVar3));
        }
        iVar3 = iVar3 + 4;
      } while (iVar3 < 0xc);
    }
    break;
  case 3:
    if ((*(int *)(*(int *)(*(&DAT_00882aa8)[DAT_00888fd8] + 0x34) + 0xc) == 2) &&
       (*(int *)(*(int *)(*(&DAT_00882aa8)[DAT_00888fdc] + 0x34) + 0xc) == 2)) {
      FUN_005579d0(*(&DAT_00882aa8)[DAT_00888fd8]);
      FUN_005579d0(*(&DAT_00882aa8)[DAT_00888fdc]);
      FUN_00557960(*(&DAT_00882aa8)[DAT_008894a0]);
    }
    else if (*(int *)(*(int *)(*(&DAT_00882aa8)[DAT_008894a0] + 0x34) + 0xc) == 2) {
      if (DAT_008894a0 == _DAT_0088949c) {
        _DAT_00882ba8 = _DAT_00882ba8 + 1;
        DAT_008894a8 = (_DAT_00882ba8 != 3) - 1 & 4;
      }
      else {
        FUN_004ddcf0();
        _DAT_00882ba8 = 0;
        DAT_008894a8 = 0;
      }
    }
    break;
  case 4:
    FUN_00557960(*DAT_00882acc);
    DAT_00882b2c[2] = 1;
  }
  *DAT_00882b2c = 0;
  DAT_00882b2c[1] = DAT_00882ba8;
  DAT_00882b2c[3] = DAT_0088949c;
  if ((DAT_00882b2c[2] == '\x01') && (DAT_008894a4 == 0)) {
    iVar3 = FUN_005cfa20(*(int *)(*(int *)(*DAT_00882acc + 0x34) + 0x18) + 4);
    FUN_00681f40("Fac_BonusCylUp",iVar3 + 0x30);
    DAT_008894a4 = 1;
  }
  return;
}

