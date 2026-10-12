/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x489da0; label: FUN_00489da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00489da0(void)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  float local_5c;
  int local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [12];
  float local_10;
  float local_c;
  float local_8;
  
  iVar2 = FUN_005cfac0(&DAT_0087aad8);
  if ((iVar2 != 0) && (0.0 < _DAT_0087aa50)) {
    puVar3 = &DAT_0087aef8;
    puVar5 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    if (_DAT_0092505c < 4.0) {
      iVar2 = FUN_006e6b90();
      fVar1 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff];
      local_10 = fVar1 * (_DAT_0087af28 - _DAT_0087a944) + _DAT_0087a944;
      local_c = _DAT_0087a948 + fVar1 * (_DAT_0087af2c - _DAT_0087a948);
      local_8 = _DAT_0087a94c + (_DAT_0087af30 - _DAT_0087a94c) * fVar1;
    }
    local_4c = _DAT_007fa5e8;
    local_48 = _DAT_007fa5e8;
    local_44 = _DAT_007fa5e8;
    FUN_005b4c30(local_40,&local_4c);
    iVar2 = FUN_006e6b90();
    FUN_005ff7a0(&DAT_0087aad8,local_40,
                 _DAT_0087aa58 * _DAT_0087b6d4 * (1.0 - (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff])
                );
  }
  fVar1 = _DAT_0092505c;
  if ((0.0 < DAT_0087a9cc) && (0.0 < _DAT_0087b6d4)) {
    puVar3 = &DAT_0087aef8;
    puVar5 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    local_54 = 0;
    puVar4 = &DAT_0087ab50;
    do {
      local_5c = (float)local_54 * 4.1666665 + 4.0;
      if (local_5c < fVar1) {
        if (local_5c + 1.0 <= fVar1) {
          if (local_5c + 4.1666665 <= fVar1) {
            if (local_5c + 5.1666665 <= fVar1) goto LAB_0048a036;
            local_5c = 1.0 - (fVar1 - (local_5c + 4.1666665));
            goto LAB_00489fd0;
          }
          local_5c = 1.0;
        }
        else {
          local_5c = fVar1 - local_5c;
LAB_00489fd0:
          if (local_5c <= 0.0) goto LAB_0048a036;
        }
        iVar2 = FUN_005cfac0(puVar4);
        if (iVar2 != 0) {
          local_c = _DAT_007fa5ec;
          FUN_005ff7a0(puVar4,local_40,_DAT_0087b6d4 * 0.5 * local_5c * DAT_0087a9cc);
        }
      }
LAB_0048a036:
      local_54 = local_54 + 1;
      puVar4 = puVar4 + 0xc;
    } while ((int)puVar4 < 0x87abb0);
  }
  return;
}

