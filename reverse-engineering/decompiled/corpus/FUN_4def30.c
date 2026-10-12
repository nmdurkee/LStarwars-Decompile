/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4def30; label: FUN_004def30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004def30(void)

{
  float fVar1;
  bool bVar2;
  short sVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  undefined4 *puVar7;
  
  sVar3 = DAT_00888ed2;
  puVar4 = (undefined4 *)(DAT_00888ed4 + -1);
  _DAT_00888ed8 = _DAT_00925018 + _DAT_00888ed8;
  switch(puVar4) {
  case (undefined4 *)0x0:
  case (undefined4 *)0x1:
  case (undefined4 *)0x2:
    *(float *)(DAT_00888f84 + 0x28) = (float)(int)DAT_00888ed2;
    fVar1 = *(float *)(DAT_00888f80 + 0x28);
    puVar4 = (undefined4 *)
             CONCAT22(sVar3 >> 0xf,
                      (ushort)(1.0 < fVar1) << 8 | (ushort)NAN(fVar1) << 10 |
                      (ushort)(fVar1 == 1.0) << 0xe);
    if (fVar1 == 1.0) {
      DAT_00888ed6 = 2;
      _DAT_00888ed8 = 0.0;
      return puVar4;
    }
    break;
  case (undefined4 *)0x3:
  case (undefined4 *)0x4:
  case (undefined4 *)0x5:
    bVar2 = true;
    iVar5 = 0;
    do {
      if ((&DAT_00888fa0)[iVar5] == '\0') {
        bVar2 = false;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 6);
    _DAT_00888fac = _DAT_00925018 + _DAT_00888fac;
    puVar4 = (undefined4 *)
             CONCAT22((short)((uint)iVar5 >> 0x10),
                      (ushort)(5.0 < _DAT_00888fac) << 8 | (ushort)NAN(_DAT_00888fac) << 10 |
                      (ushort)(_DAT_00888fac == 5.0) << 0xe);
    if (5.0 < _DAT_00888fac) {
      puVar7 = (undefined4 *)0xffffffff;
      puVar4 = (undefined4 *)0x0;
      if (0 < DAT_00888ed0) {
        puVar6 = &DAT_00882c2c;
        do {
          if ((*puVar6 & 0x10) != 0) goto LAB_004df020;
          if ((*puVar6 & 8) != 0) {
            puVar7 = puVar4;
          }
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          puVar6 = puVar6 + 0x18;
        } while ((int)puVar4 < (int)DAT_00888ed0);
        if (puVar7 != (undefined4 *)0xffffffff) {
          (&DAT_00882c2c)[(int)puVar7 * 0x18] = (&DAT_00882c2c)[(int)puVar7 * 0x18] | 0x10;
          puVar4 = &DAT_00882c2c + (int)puVar7 * 0x18;
        }
      }
LAB_004df020:
      _DAT_00888fac = 0.0;
    }
    if (bVar2) {
      DAT_00888ed6 = 2;
      _DAT_00888ed8 = 0.0;
      return puVar4;
    }
    break;
  case (undefined4 *)0x6:
    puVar4 = DAT_00888fa8;
    if ((DAT_00888fa8 != (undefined4 *)0x0) ||
       (puVar4 = (undefined4 *)FUN_0055ce20((int)DAT_007f19e0,1,1,0,0), DAT_00888fa8 = puVar4,
       puVar4 != (undefined4 *)0x0)) {
      if (*(char *)((int)puVar4 + 0x28b) != '\0') {
        DAT_00888ed6 = 2;
        _DAT_00888ed8 = 0.0;
        DAT_00888fa8 = puVar4;
        return puVar4;
      }
      DAT_00888fa8 = puVar4;
      if (*(char *)((int)puVar4 + 0x107f) == '\0') {
        DAT_00888ed6 = 2;
        _DAT_00888ed8 = 0.0;
        return puVar4;
      }
    }
  }
  return puVar4;
}

