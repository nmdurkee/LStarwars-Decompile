/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49ad90; label: FUN_0049ad90
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049ad90(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  char cVar1;
  float fVar2;
  bool bVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  char cVar10;
  int iVar11;
  
  iVar5 = *(int *)(PTR_DAT_00802c54 + 300);
  cVar10 = '\0';
  if (iVar5 != 0) {
    if (iVar5 == DAT_0087af84) {
      param_5 = 0;
    }
    else if (iVar5 == DAT_0087af5c) {
      return;
    }
  }
  cVar1 = *(char *)(param_1 + 0x7b5);
  if (cVar1 == ':') {
    fVar2 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar2;
    if (0.0 < fVar2) {
      return;
    }
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    return;
  }
  if (cVar1 == '6') {
    fVar2 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar2;
    if (fVar2 <= 0.0) {
      *(undefined2 *)(param_1 + 0xe1a) = 0;
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      *(undefined4 *)(param_1 + 0xd48) = 0x3e99999a;
      return;
    }
    FUN_006e6b90();
    uVar4 = FUN_006e6b90();
    *(undefined2 *)(param_1 + 0xe1a) = uVar4;
    return;
  }
  if (*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x88) <= 0.0) {
    return;
  }
  if (cVar1 != -1) {
    return;
  }
  iVar5 = FUN_0041a4d0(param_1);
  iVar11 = 0;
  bVar3 = false;
  if ((((param_5 == 0) || (*(char *)(param_1 + 0xe3c) == '\0')) || (iVar5 == 0)) ||
     (((*(char *)(iVar5 + 0xe3c) == '\0' || (*(char *)(iVar5 + 0x7b5) != '6')) ||
      ((*(float *)(iVar5 + 0x784) - 0.2 <= *(float *)(iVar5 + 0x77c) ||
       (*(float *)(iVar5 + 0x77c) <= 0.3)))))) {
LAB_0049af59:
    if (0.0 < *(float *)(param_1 + 0xd48)) goto LAB_0049b021;
    iVar6 = FUN_00499b40(*(undefined4 *)(PTR_DAT_00802c54 + 0x128));
    if (iVar6 == 0) {
      uVar9 = FUN_0054b3d0(param_1,param_4);
      uVar8 = FUN_00550040(*(undefined2 *)(param_1 + 0x27a),uVar9);
    }
    else {
      uVar8 = FUN_00550040(0,*(undefined2 *)(param_4 + 0x26));
    }
    if ((*(int *)(param_1 + 0xe64) == 0) && (0.0 < *(float *)(param_4 + 0x28))) {
      if (uVar8 + 0x5fff < 0x58e3) {
        cVar10 = '\x02';
        goto LAB_0049b021;
      }
      if (uVar8 - 0x71d < 0x58e3) {
        cVar10 = '\x01';
        goto LAB_0049b021;
      }
      if (0x3fff < (int)((uVar8 ^ (int)uVar8 >> 0x1f) - ((int)uVar8 >> 0x1f))) {
        bVar3 = true;
        goto LAB_0049b010;
      }
    }
    iVar11 = 1;
  }
  else {
    iVar6 = FUN_0040e690(iVar5);
    iVar7 = FUN_0040e690(param_1);
    if (iVar6 != iVar7) goto LAB_0049af59;
    iVar11 = 2;
    param_2 = 1;
  }
LAB_0049b010:
  cVar10 = '\0';
  if (param_5 == 0) {
    iVar11 = 0;
    bVar3 = false;
  }
LAB_0049b021:
  if (param_2 != 0) {
    if (iVar11 == 0) {
      if (cVar10 == '\0') {
        if ((bVar3) &&
           (((*(char *)(param_1 + 0xe3c) == '\0' || (iVar5 == 0)) ||
            ((cVar10 = *(char *)(iVar5 + 0x7b5), cVar10 != '*' &&
             ((cVar10 != '6' && (cVar10 != ':')))))))) {
          FUN_0049ad40(param_1);
        }
      }
      else if (((*(char *)(param_1 + 0xe3c) == '\0') || (iVar5 == 0)) ||
              ((*(char *)(iVar5 + 0x7b5) != '*' && (*(char *)(iVar5 + 0x7b5) != '6')))) {
        *(undefined4 *)(param_1 + 0x784) = 0x3f400000;
        *(undefined1 *)(param_1 + 0x7b5) = 0x3a;
        *(undefined4 *)(param_1 + 0x77c) = 0x3f400000;
        *(undefined2 *)(param_1 + 0x7aa) = 1;
        *(char *)(param_1 + 0x7b3) = cVar10 + -1;
        FUN_00681f40("XWing_LoopDeLoop",param_1 + 0x80);
        return;
      }
    }
    else if ((((iVar11 == 2) || (*(char *)(param_1 + 0xe3c) == '\0')) || (iVar5 == 0)) ||
            (((cVar10 = *(char *)(iVar5 + 0x7b5), cVar10 != '*' && (cVar10 != '6')) &&
             (cVar10 != ':')))) {
      *(undefined1 *)(param_1 + 0x7b5) = 0x36;
      *(undefined2 *)(param_1 + 0x7aa) = 1;
      *(undefined4 *)(param_1 + 0x784) = _DAT_007fc044;
      *(undefined4 *)(param_1 + 0x77c) = _DAT_007fc044;
      FUN_00681f40("XWing_LoopDeLoop",param_1 + 0x80);
      FUN_00576960(0x287);
      return;
    }
  }
  return;
}

