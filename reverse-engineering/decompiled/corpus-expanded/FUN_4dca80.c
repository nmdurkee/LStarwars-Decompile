/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dca80; label: FUN_004dca80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004dca80(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  undefined4 uVar10;
  float local_10;
  
  if (((param_3 == 0.0) || (piVar3 = *(int **)((int)param_3 + 0xd0), piVar3 == (int *)0x0)) ||
     (*piVar3 == 0)) {
    return 1;
  }
  fVar8 = (float10)0;
  iVar4 = *piVar3;
  if (param_6 != 0) {
    *(undefined4 *)(iVar4 + 0xed4) = *(undefined4 *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x1c)
    ;
    *(float *)(iVar4 + 0xe88) = (float)fVar8;
  }
  if (fVar8 < (float10)_DAT_0088249c) goto LAB_004dce21;
  if (DAT_008824a6 < '\x03') {
    fVar5 = _DAT_007ffdbc;
    if (DAT_008824a7 < '\x04') {
      fVar5 = *(float *)(&DAT_007ffdb0 + DAT_008824a7 * 4);
    }
    local_10 = *(float *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x1c);
    cVar2 = *(char *)(iVar4 + 0x671);
    if ((cVar2 == -1) || (cVar2 != *(char *)(DAT_0093d810 + 0x671))) {
      fVar1 = (float)fVar8;
LAB_004dcd3b:
      fVar1 = fVar1 / _DAT_007ffd9c;
      if (1.0 < fVar1) {
        fVar1 = 1.0;
      }
      param_3 = _DAT_007ffda0 * fVar1 + (1.0 - fVar1);
      uVar10 = _DAT_007ffda4;
    }
    else {
      piVar3 = *(int **)(PTR_DAT_00802c54 + 0x2988);
      iVar7 = cVar2 * 0x13c + *piVar3;
      if (DAT_0093d814 == 0) {
        fVar8 = (float10)FUN_0053f7a0(piVar3,iVar4 + 0x670);
        fVar9 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                                      DAT_0093d810 + 0x670);
        fVar9 = (float10)(double)fVar8 - fVar9;
      }
      else {
        fVar8 = (float10)FUN_0053f7a0(piVar3,DAT_0093d814 + 0x670);
        fVar9 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),
                                      DAT_0093d810 + 0x670);
        fVar1 = (float)((float10)(double)fVar8 - fVar9);
        if (fVar1 <= *(float *)(iVar7 + 0x98) * 0.5) {
          if (fVar1 < *(float *)(iVar7 + 0x98) * -0.5) {
            fVar1 = fVar1 + *(float *)(iVar7 + 0x98);
          }
        }
        else {
          fVar1 = fVar1 - *(float *)(iVar7 + 0x98);
        }
        iVar6 = DAT_0093d814;
        if (0.0 <= fVar5) {
          if (0.0 >= fVar1) goto LAB_004dcc02;
        }
        else if (0.0 < fVar1) {
LAB_004dcc02:
          iVar6 = DAT_0093d810;
        }
        fVar8 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar4 + 0x670);
        fVar9 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar6 + 0x670);
        fVar9 = (float10)(double)fVar8 - fVar9;
      }
      fVar1 = (float)fVar9;
      if (fVar1 <= *(float *)(iVar7 + 0x98) * 0.5) {
        if (fVar1 < *(float *)(iVar7 + 0x98) * -0.5) {
          fVar1 = fVar1 + *(float *)(iVar7 + 0x98);
        }
      }
      else {
        fVar1 = fVar1 - *(float *)(iVar7 + 0x98);
      }
      fVar1 = fVar1 - fVar5;
      if (fVar1 <= 0.0) goto LAB_004dcd3b;
      fVar1 = fVar1 / (_DAT_007ffda8 - fVar5);
      if (1.0 < fVar1) {
        fVar1 = 1.0;
      }
      param_3 = _DAT_00882a80 * fVar1 + (1.0 - fVar1);
      uVar10 = _DAT_007ffdac;
    }
    local_10 = param_3 * local_10;
  }
  else {
    local_10 = *(float *)(*(int *)(*(int *)(iVar4 + 0x54) + 0x24) + 0x1c);
    if (((DAT_00882484 != 0) && (DAT_00882488 != 0)) &&
       ((DAT_0088248c != 0 &&
        (local_10 = *(float *)(DAT_00882484 + 0x28) -
                    (float)(int)DAT_008824a4 * *(float *)(DAT_0088248c + 0x28),
        local_10 < *(float *)(DAT_00882488 + 0x28))))) {
      local_10 = *(float *)(DAT_00882488 + 0x28);
    }
    uVar10 = 0x40a00000;
  }
  fVar8 = (float10)FUN_0054fb40(*(undefined4 *)(iVar4 + 0xed4),local_10,uVar10);
LAB_004dce21:
  *(float *)(iVar4 + 0xed4) = (float)fVar8;
  if ((*(char *)(iVar4 + 0xe6b) != '\0') && ((_DAT_008824aa & 4) == 0)) {
    if ((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
      FUN_0046c6e0(DAT_0093d7f0,1);
    }
    if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
      FUN_0046c6e0(DAT_0093d7f4,1);
    }
    _DAT_008824aa = _DAT_008824aa | 4;
    FUN_0057a620(PTR_DAT_00802c54,"Ep1_Podsprint_OutOfTime",1);
    DAT_008824a4 = DAT_008824a4 + 1;
  }
  return 0;
}

