/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x691a40; label: FUN_00691a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00691a40(int param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined1 local_c [12];
  
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    FUN_00620ef0(param_1);
  }
  iVar4 = DAT_02921884;
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) goto LAB_00691d05;
  if (((*(byte *)(param_1 + 0x78) & 0x20) != 0) && (DAT_02921884 != -1)) {
    uVar2 = FUN_005b9e90(0);
    *(undefined4 *)(iVar4 * 0x50 + 0x28 + DAT_02962a14) = uVar2;
    FUN_00689f70();
  }
  if (((*(byte *)(param_1 + 0x78) & 0x40) == 0) || (DAT_02921884 == -1)) {
LAB_00691b72:
    if (DAT_029629f8 != 1) goto LAB_00691ac9;
LAB_00691b7b:
    if (DAT_02920ab4 == -1) {
      FUN_0065efc0(0xbf800000);
      goto LAB_00691c00;
    }
    if (((*(byte *)(param_1 + 0x78) & 8) != 0) &&
       (DAT_02920ab4 = DAT_02920ab4 + 1,
       DAT_02920ab4 == *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14))) {
      DAT_02920ab4 = 0;
    }
    if (((*(byte *)(param_1 + 0x78) & 2) != 0) &&
       (DAT_02920ab4 = DAT_02920ab4 + -1, DAT_02920ab4 == -1)) {
      DAT_02920ab4 = *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) + -1;
    }
  }
  else {
    if (DAT_029629f8 != 1) {
      if (DAT_00810a88 != 3) goto LAB_00691b72;
      DAT_029629f8 = 1;
      goto LAB_00691b7b;
    }
    DAT_029629f8 = 0;
LAB_00691ac9:
    if (DAT_02921884 == -1) {
      FUN_00690e40(0xbf800000);
    }
    else {
      if ((*(byte *)(param_1 + 0x78) & 8) != 0) {
        do {
          DAT_02921884 = DAT_02921884 + 1;
          if (DAT_02921884 == DAT_02962a08) {
            DAT_02921884 = 0;
          }
        } while (*(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) == 0);
        FUN_00690d40(DAT_02921884);
      }
      if ((*(byte *)(param_1 + 0x78) & 2) != 0) {
        do {
          DAT_02921884 = DAT_02921884 + -1;
          if (DAT_02921884 == -1) {
            DAT_02921884 = DAT_02962a08 + -1;
          }
        } while (*(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) == 0);
        FUN_00690d40(DAT_02921884);
      }
    }
LAB_00691c00:
    if (DAT_029629f8 != 1) {
      if (DAT_02921884 != -1) {
        FUN_00620f10(DAT_02921884 * 0x50 + 8 + DAT_02962a14);
        piVar3 = (int *)(DAT_02921884 * 0x50 + DAT_02962a14);
        DAT_00810a88 = (int)*(char *)((int)piVar3 + 0x27);
        DAT_029211ec = *piVar3;
        if (DAT_00810a88 != 3) {
          _DAT_02948ee8 = (float)piVar3[5];
          DAT_0292318c = piVar3[1];
          DAT_029629ec = (int)(short)piVar3[0xd];
          DAT_029629f0 = (int)*(short *)((int)piVar3 + 0x36);
        }
      }
      goto LAB_00691d05;
    }
  }
  if ((DAT_02921884 != -1) && (DAT_02920ab4 != -1)) {
    iVar4 = (int)*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14);
    FUN_005b37d0(local_c,DAT_02921884 * 0x50 + DAT_02962a14 + 8,
                 (DAT_02962a10 * iVar4 + DAT_02920ab4) * 0x20 + DAT_02962a18);
    FUN_00620f10(local_c);
    iVar4 = (DAT_02962a10 * iVar4 + DAT_02920ab4) * 0x20;
    DAT_029629ec = (int)*(short *)(DAT_02962a18 + 0x10 + iVar4);
    DAT_029629f0 = (int)*(short *)(DAT_02962a18 + iVar4 + 0x12);
  }
LAB_00691d05:
  FUN_00620fa0(&DAT_02961ff0,&DAT_0292fbf8,&DAT_02948e9c);
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    if ((*(byte *)(param_1 + 0x78) & 0x80) != 0) {
      FUN_00691730();
      DAT_02962988 = DAT_0296298c;
    }
    if ((*(byte *)(param_1 + 0x78) & 0x40) != 0) {
      if (DAT_029629f8 == 1) {
        FUN_0068b7f0(&DAT_02961ff0);
      }
      else if (DAT_029211ec != -1) {
        FUN_0068b3b0(&DAT_02961ff0);
      }
    }
    if ((*(byte *)(param_1 + 0x70) & 0x20) != 0) {
      if (DAT_029629f8 == 1) {
        if (DAT_02920ab4 != -1) {
          FUN_0068b220(DAT_02920ab4,&DAT_02961ff0);
        }
      }
      else if (DAT_02921884 != -1) {
        FUN_0068b170(DAT_02921884,&DAT_02961ff0);
      }
    }
    if ((*(byte *)(param_1 + 0x78) & 0x10) != 0) {
      if (DAT_029629f8 == 1) {
        if (DAT_02920ab4 != -1) {
          FUN_0068b890(DAT_02920ab4);
        }
        DAT_02920ab4 = -1;
      }
      else {
        if (DAT_02921884 != -1) {
          FUN_0068b830(DAT_02921884);
        }
        DAT_02921884 = -1;
      }
    }
  }
  if (DAT_029629f4 == 0) {
    if (DAT_00810a88 == 3) {
      if ((DAT_02921884 != -1) && (DAT_02920ab4 != -1)) {
        pfVar1 = (float *)((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 +
                           DAT_02920ab4) * 0x20 + 0xc + DAT_02962a18);
        *pfVar1 = *pfVar1 + (float)*(byte *)(param_1 + 0x96) / 5000.0;
        pfVar1 = (float *)((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 +
                           DAT_02920ab4) * 0x20 + 0xc + DAT_02962a18);
        *pfVar1 = *pfVar1 - (float)*(byte *)(param_1 + 0x97) / 5000.0;
        pfVar1 = (float *)((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 +
                           DAT_02920ab4) * 0x20 + 0xc + DAT_02962a18);
        if (1.0 < *pfVar1) {
          *pfVar1 = 1.0;
        }
        pfVar1 = (float *)((*(short *)(DAT_02921884 * 0x50 + 0x40 + DAT_02962a14) * DAT_02962a10 +
                           DAT_02920ab4) * 0x20 + 0xc + DAT_02962a18);
        if (*pfVar1 < 0.1) {
          *pfVar1 = 0.1;
        }
      }
      if ((*(char *)(param_1 + 0x96) != '\0') || (*(char *)(param_1 + 0x97) != '\0')) {
        FUN_00689f70();
        return;
      }
    }
    else {
      _DAT_02948ee8 =
           (_DAT_02948ee8 + (float)*(byte *)(param_1 + 0x96) / 5000.0) -
           (float)*(byte *)(param_1 + 0x97) / 5000.0;
      if (0.1 <= _DAT_02948ee8) {
        if (10.0 < _DAT_02948ee8) {
          _DAT_02948ee8 = 10.0;
        }
      }
      else {
        _DAT_02948ee8 = 0.1;
      }
      if ((*(char *)(param_1 + 0x95) == -1) || ((*(uint *)(param_1 + 0x78) & 0x8000) != 0)) {
        DAT_0292318c = DAT_0292318c + -1;
      }
      if ((*(char *)(param_1 + 0x94) == -1) || ((*(uint *)(param_1 + 0x78) & 0x2000) != 0)) {
        DAT_0292318c = DAT_0292318c + 1;
      }
      if (DAT_0292318c < 4) {
        DAT_0292318c = 4;
        return;
      }
      if (0x100 < DAT_0292318c) {
        DAT_0292318c = 0x100;
        return;
      }
    }
  }
  else if (DAT_029629f4 == 1) {
    DAT_029629f0 = DAT_029629f0 + (uint)*(byte *)(param_1 + 0x94);
    DAT_029629f0 = DAT_029629f0 - (uint)*(byte *)(param_1 + 0x95);
    iVar4 = DAT_029629ec + (uint)*(byte *)(param_1 + 0x96);
    if (0x8000 < iVar4) {
      iVar4 = 0x8000;
    }
    DAT_029629ec = iVar4 - (uint)*(byte *)(param_1 + 0x97);
    if (DAT_029629ec < -0x8000) {
      DAT_029629ec = -0x8000;
    }
  }
  return;
}

