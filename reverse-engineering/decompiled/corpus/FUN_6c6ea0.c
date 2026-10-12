/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6ea0; label: FUN_006c6ea0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c6ea0(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  void *_Dst;
  int iVar9;
  int *local_10;
  int *local_c;
  
  local_10 = (int *)0x0;
  local_c = &DAT_02973f3c;
  piVar5 = (int *)(in_ECX + 0x44);
  do {
    if (((local_10 < 10) && (*local_c != 0)) && (*piVar5 == 0)) {
      iVar2 = FUN_005da840(*local_c);
      *piVar5 = iVar2;
      uVar3 = iVar2 * 0x2c;
      _Dst = (void *)0x0;
      if (uVar3 < *DAT_0291325c - *DAT_02913258) {
        *DAT_02913258 = *DAT_02913258 + 0xf & 0xfffffff0;
        _Dst = (void *)*DAT_02913258;
        *DAT_02913258 = *DAT_02913258 + uVar3;
        _memset(_Dst,0,uVar3);
        _DAT_02913264 = _DAT_02913264 + uVar3;
        _DAT_02913268 = _DAT_02913268 + iVar2 * -0x2c;
        _DAT_02913260 = *DAT_02913258;
        if (_Dst == (void *)0x0) goto LAB_006c6f3f;
      }
      else {
LAB_006c6f3f:
        if (DAT_02913230 != 0) {
          FUN_006b7c40();
        }
      }
      piVar5[-10] = (int)_Dst;
      iVar2 = 0;
      if (0 < *piVar5) {
        iVar6 = 0;
        do {
          puVar7 = (undefined4 *)(piVar5[-10] + iVar6);
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = &PTR_FUN_0076fa04;
            *(undefined2 *)(puVar7 + 1) = 0;
            uVar1 = DAT_02973aa0;
            puVar7[2] = 0;
            *(undefined2 *)((int)puVar7 + 6) = uVar1;
            puVar7[3] = 0;
            puVar7[4] = 0;
            puVar7[5] = 0;
            *puVar7 = &PTR_FUN_0076faf4;
            FUN_005d0480(puVar7 + 6);
            *puVar7 = &PTR_FUN_0076fb64;
            *(undefined2 *)(puVar7 + 1) = (undefined2)DAT_0081fd48;
            puVar7[9] = 0;
          }
          iVar2 = iVar2 + 1;
          iVar6 = iVar6 + 0x2c;
        } while (iVar2 < *piVar5);
      }
    }
    local_10 = (int *)((int)local_10 + 1);
    local_c = local_c + 0x2a;
    piVar5 = piVar5 + 1;
    if (0x29745cb < (int)local_c) {
      uVar3 = 0;
      *(undefined4 *)(in_ECX + 0x6c) = 0;
      piVar5 = (int *)(in_ECX + 0x44);
      local_10 = &DAT_02973f3c;
      do {
        if ((uVar3 < 10) && (iVar2 = *local_10, iVar2 != 0)) {
          iVar6 = *piVar5;
          iVar9 = 0;
          if (0 < iVar6) {
            iVar8 = piVar5[-10] + 0x18;
            do {
              FUN_005da860(iVar8,iVar2,iVar9);
              *(undefined4 *)(iVar8 + -0x10) = 0x12400000;
              *(short *)(iVar8 + -0x12) = (short)uVar3;
              iVar4 = FUN_005cfa50(iVar8);
              if (iVar4 != 0) {
                FUN_004f8b10(iVar4,"reflectport");
              }
              *(int *)(in_ECX + 0x6c) = *(int *)(in_ECX + 0x6c) + 1;
              iVar9 = iVar9 + 1;
              iVar8 = iVar8 + 0x2c;
            } while (iVar9 < iVar6);
          }
        }
        local_10 = local_10 + 0x2a;
        piVar5 = piVar5 + 1;
        uVar3 = uVar3 + 1;
      } while ((int)local_10 < 0x29745cc);
      return;
    }
  } while( true );
}

