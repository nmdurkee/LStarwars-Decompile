/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x494180; label: FUN_00494180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494180(float param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EDI;
  float local_c;
  
  fVar2 = _DAT_0087b72c;
  fVar1 = _DAT_007facc4;
  iVar4 = 0;
  local_c = 0.0 - (_DAT_007facc4 + _DAT_007facc4) * 0.5;
  param_1 = param_1 + 0.3;
  do {
    if (iVar4 == 3) {
      local_c = 0.0 - (fVar1 + fVar1) * 0.5;
      param_1 = param_1 - 0.35;
    }
    if ((*(short *)(unaff_EDI + 10) == *(short *)(unaff_EDI + 0xe)) &&
       (*(short *)(unaff_EDI + 8) == iVar4)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    FUN_00493e60(local_c,param_1,uVar3,iVar4);
    iVar4 = iVar4 + 1;
    local_c = fVar1 + local_c;
    param_1 = fVar2 + param_1;
  } while (iVar4 < 6);
  return;
}

