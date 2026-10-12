/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x548c40; label: FUN_00548c40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548c40(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (DAT_00924dd8 == (code *)0x0) {
    if (DAT_0087b924 == 0) {
      iVar2 = FUN_0056e460(0xffffffff);
      if (iVar2 == 0) {
        if ((DAT_0093d7f0 == 0) ||
           ((*(int *)(DAT_0093d7f0 + 0x3ac) == 0 &&
            (((*(int *)(DAT_0093d7f0 + 0x39c) == 0 ||
              (*(char *)(*(int *)(DAT_0093d7f0 + 0x39c) + 0x28b) != '\0')) ||
             (3.0 <= *(float *)(DAT_0093d7f0 + 0x3a0))))))) {
          if (DAT_0093d7f4 != 0) {
            if (*(int *)(DAT_0093d7f4 + 0x3ac) != 0) goto LAB_00548cb6;
            if (((*(int *)(DAT_0093d7f4 + 0x39c) != 0) &&
                (*(char *)(*(int *)(DAT_0093d7f4 + 0x39c) + 0x28b) == '\0')) &&
               (*(float *)(DAT_0093d7f4 + 0x3a0) < 3.0)) {
              DAT_00924af4 = 1;
              goto LAB_00548cfd;
            }
          }
          DAT_00924af4 = 0;
        }
        else {
LAB_00548cb6:
          DAT_00924af4 = 1;
        }
      }
      else {
        DAT_00924af4 = 1;
      }
    }
    else {
      DAT_00924af4 = 1;
    }
  }
  else {
    DAT_00924af4 = (*DAT_00924dd8)();
  }
LAB_00548cfd:
  if (DAT_00924df4 == (code *)0x0) {
    DAT_00924aec = 0;
  }
  else {
    DAT_00924aec = (*DAT_00924df4)();
  }
  if ((DAT_0093b328 == 0) && (0.0 < _DAT_00924dd4)) {
    _DAT_00924dd4 = _DAT_00924dd4 - _DAT_00925018;
  }
  if ((DAT_00924dd0 != DAT_00924af4) && (_DAT_00924dd4 <= 0.0)) {
    _DAT_00924dd4 = *(float *)(&DAT_008020b4 + DAT_00924af4 * 4);
    DAT_00924dd0 = DAT_00924af4;
  }
  if (((DAT_00951be8 == 0) || (*(short *)(DAT_00951be8 + 0xec) == -1)) ||
     (iVar1 = *(short *)(DAT_00951be8 + 0xec) * 0x130, iVar2 = iVar1 + DAT_00951b78,
     (*(byte *)(iVar1 + 100 + DAT_00951b78) & 1) == 0)) {
    iVar2 = param_1;
  }
  FUN_00694240(1,*(undefined4 *)(iVar2 + 0x118 + DAT_00924aec * 4));
  FUN_00694240(2,*(undefined4 *)(iVar2 + 0x120 + DAT_00924aec * 4));
  FUN_00694240(0x20,*(undefined4 *)(iVar2 + 0x128 + DAT_00924aec * 4));
  if (*(char *)(param_2 + 6) != '\0') {
    if (DAT_00924dd0 == 0) {
      iVar2 = FUN_00694320(1,0);
      if (iVar2 != -1) {
LAB_00548e34:
        uVar3 = 1;
        goto LAB_00548e67;
      }
      iVar2 = FUN_00694320(2,0);
      if (iVar2 != -1) {
        uVar3 = 2;
        goto LAB_00548e67;
      }
    }
    else {
      iVar2 = FUN_00694320(2,0);
      if (iVar2 != -1) {
        uVar3 = 2;
        goto LAB_00548e67;
      }
      iVar2 = FUN_00694320(1,0);
      if (iVar2 != -1) goto LAB_00548e34;
    }
  }
  uVar3 = 0x20;
LAB_00548e67:
  FUN_00696a30(uVar3);
  FUN_00695950(_DAT_00925018);
  return;
}

