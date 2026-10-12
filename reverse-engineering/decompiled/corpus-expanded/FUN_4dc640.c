/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dc640; label: FUN_004dc640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dc640(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  float10 fVar5;
  undefined4 local_4;
  
  _DAT_0087b8b8 = 0x3f800000;
  if (DAT_00951b54 == 0) {
    if (DAT_00951b50 != 0) {
      _DAT_0088249c = (float)(int)DAT_00882a58[3];
      DAT_008824a6 = (char)*DAT_00882a58;
      _DAT_008824a0 = (float)(int)DAT_00882a58[4];
      goto LAB_004dc6c5;
    }
  }
  else {
    *DAT_00882a58 = (short)DAT_008824a6;
    sVar1 = FUN_006e6b90();
    DAT_00882a58[3] = sVar1;
    sVar1 = FUN_006e6b90();
    DAT_00882a58[4] = sVar1;
LAB_004dc6c5:
    if (DAT_00951b50 != 0) goto LAB_004dc70c;
  }
  iVar2 = FUN_0057cd80(0);
  if (iVar2 != 0) {
    return;
  }
  if ((_DAT_008824aa & 0xc) != 0) {
    if ((_DAT_008824aa & 0x10) != 0) {
      return;
    }
    _DAT_008824aa = _DAT_008824aa | 0x10;
    FUN_0057a620(param_1,0,1);
    return;
  }
LAB_004dc70c:
  iVar2 = FUN_004dc150();
  if (iVar2 == 0) {
    FUN_004dbf80();
    if (DAT_00951b50 == 0) {
      FUN_004dc310(param_1);
    }
    FUN_004d8630();
  }
  iVar2 = 0;
  if (0 < DAT_0093d500) {
    puVar4 = (uint *)(DAT_0093d504 + 0x1fc);
    do {
      if ((((*puVar4 & 1) != 0) && ((*puVar4 & 0x1000) != 0)) && ((char)puVar4[0x21] == -1)) {
        local_4 = 0;
        if (((DAT_00882494 != 0) && (*(int *)(PTR_DAT_00802c54 + 0x2ae8) != 0)) &&
           (('\x01' < DAT_008824a6 &&
            (uVar3 = 1 << ((byte)(DAT_00882494 -
                                  *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x38) >> 6) & 0x1f)
            , (uVar3 & puVar4[0x2d]) != 0 || ((int)uVar3 >> 0x1f & puVar4[0x2e]) != 0)))) {
          local_4 = _DAT_007ffd90;
        }
        fVar5 = (float10)FUN_0054fb40(puVar4[0x323],local_4,_DAT_007ffd94);
        puVar4[0x323] = (uint)(float)fVar5;
      }
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 0x436;
    } while (iVar2 < DAT_0093d500);
  }
  return;
}

