/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e3ea0; label: FUN_004e3ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e3ea0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_008895d0 != 0) {
    *(float *)(DAT_008895d0 + 0x28) = *(float *)(DAT_008895d0 + 0x28) + _DAT_00925018;
  }
  if (DAT_00951b50 == 0) {
    if (DAT_008895f0 != 0) {
      DAT_008895f0 = 0;
      piVar3 = &DAT_0093d7f0;
      do {
        iVar1 = *piVar3;
        if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 1) != 0)) {
          FUN_00572660(iVar1,1);
        }
        piVar3 = piVar3 + 1;
      } while ((int)piVar3 < 0x93d810);
    }
    iVar2 = DAT_0093d810;
    iVar1 = DAT_008895ec;
    if (((DAT_008895ec != 0) && (DAT_0093d810 != 0)) && (*(short *)(DAT_0093d810 + 0x27e) != -1)) {
      *(undefined4 *)(DAT_008895ec + 0x10) = *(undefined4 *)(DAT_0093d810 + 0x19c);
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x1a0);
      *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(iVar2 + 0x1a4);
    }
  }
  if (DAT_008895d8 != 0) {
    _DAT_008895d4 = _DAT_008895d4 - _DAT_00925018;
    if (DAT_008895d8 < 3) {
      piVar3 = &DAT_008895dc;
      do {
        if ((*piVar3 != 0) && (iVar1 = FUN_00467890(*piVar3), iVar1 != 0)) {
          DAT_008895da = 1;
          _DAT_008895d4 = _DAT_008000b8 + _DAT_008895d4;
          *piVar3 = 0;
        }
        piVar3 = piVar3 + 1;
      } while ((int)piVar3 < 0x8895ec);
      iVar1 = (int)DAT_008895d8;
      if (_DAT_008895d4 < *(float *)(&DAT_008000bc + iVar1 * 4)) {
        if (iVar1 == 1) {
          FUN_005ab050(DAT_0095df4c,"ceiling_collapse",0x40000000,DAT_008895cc);
        }
        else if (iVar1 == 2) {
          FUN_005ab050(DAT_0095df4c,"ceiling_collapse",0x40400000,DAT_008895cc);
          _DAT_008895d4 = 2.0;
          FUN_005d6170();
          FUN_00577880(&DAT_008000c8,&DAT_008000d4,0,0,0x40000000,0,0x3f000000,0,0,1);
        }
        DAT_008895d8 = DAT_008895d8 + 1;
      }
      if (DAT_008895da == 0) {
        if (0.0 < _DAT_008895d4) {
          iVar1 = FUN_006e6b90();
          iVar2 = FUN_006e6b90();
          if (iVar2 != iVar1) {
            FUN_00548710();
          }
        }
      }
      else {
        FUN_00548710();
      }
    }
    else if ((DAT_00951b50 == 0) && (_DAT_008895d4 <= 0.0)) {
      if ((DAT_0093d7f0 != 0) && ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) != 0)) {
        FUN_0046c6e0(DAT_0093d7f0,1);
      }
      if ((DAT_0093d7f4 != 0) && ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) != 0)) {
        FUN_0046c6e0(DAT_0093d7f4,1);
      }
      FUN_004364e0(DAT_0093d810,2,0);
    }
  }
  if ((DAT_008895f4 == '\0') &&
     ((((DAT_0093d7f0 != 0 && (*(char *)(DAT_0093d7f0 + 0x28b) != '\0')) &&
       ((*(uint *)(DAT_0093d7f0 + 0x1f8) & 0x40000) == 0)) ||
      (((DAT_0093d7f4 != 0 && (*(char *)(DAT_0093d7f4 + 0x28b) != '\0')) &&
       ((*(uint *)(DAT_0093d7f4 + 0x1f8) & 0x40000) == 0)))))) {
    DAT_008895f4 = '\x01';
    FUN_0057a620(0,0,1);
  }
  if (DAT_00951b50 != 0) {
    DAT_008895d8 = *DAT_008895bc;
    _DAT_008895d4 = (float)*(undefined4 *)(DAT_008895bc + 2);
    DAT_008895da = DAT_008895bc[1];
    return;
  }
  *DAT_008895bc = DAT_008895d8;
  *(float *)(DAT_008895bc + 2) = _DAT_008895d4;
  DAT_008895bc[1] = DAT_008895da;
  return;
}

