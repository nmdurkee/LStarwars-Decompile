/* Ghidra analysis pseudocode, not original source.
 * ev_7503cf432ea6387026e6b4bb7edbc85322f44a0fb78bb064db2cebe324fceadb
 * Entry: 0x64f7e0; label: FUN_0064f7e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064f7e0(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int extraout_ECX;
  short *psVar5;
  short *psVar6;
  
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    FUN_00620ef0(param_1);
  }
  if ((*(uint *)(param_1 + 0x70) & 0x100) != 0) {
    if (DAT_02920888 == -1) {
      FUN_00644000(0xbf800000);
    }
    else {
      if ((*(byte *)(param_1 + 0x78) & 8) != 0) {
        do {
          DAT_02920888 = DAT_02920888 + 1;
          if (DAT_02920888 == 0x28) {
            DAT_02920888 = 0;
          }
        } while ((&DAT_0291f7b4)[DAT_02920888 * 0x1b] == -1);
      }
      if ((*(byte *)(param_1 + 0x78) & 2) != 0) {
        do {
          DAT_02920888 = DAT_02920888 + -1;
          if (DAT_02920888 == -1) {
            DAT_02920888 = 0x27;
          }
        } while ((&DAT_0291f7b4)[DAT_02920888 * 0x1b] == -1);
      }
    }
    if (DAT_02920888 != -1) {
      FUN_00620f10(&DAT_0291f7a8 + DAT_02920888 * 0x1b);
      iVar2 = DAT_02920888 * 0x6c;
      DAT_02920a4c = (int)*(short *)(iVar2 + 0x291f7f4);
      _DAT_02920a54 = *(float *)(iVar2 + 0x291f7f8);
      DAT_02920a50 = (int)*(short *)(iVar2 + 0x291f7f6);
      DAT_02920a40 = (int)(short)(&DAT_0291f7d4)[DAT_02920888 * 0x36];
      DAT_02920a44 = (int)(short)(&DAT_0291f7d6)[DAT_02920888 * 0x36];
      DAT_02920a48 = (int)(short)(&DAT_0291f7d8)[DAT_02920888 * 0x36];
      DAT_00810194 = (&DAT_0291f7b4)[DAT_02920888 * 0x1b];
      DAT_02920974 = (&DAT_02913b0b)[DAT_00810194 * 0x178];
    }
  }
  if (DAT_0291f73c == 0) {
    FUN_00620fa0(&DAT_0291f714,&DAT_02920894,&DAT_029208c8);
  }
  else {
    FUN_00620fe0();
  }
  iVar2 = DAT_02920888;
  if ((*(uint *)(param_1 + 0x70) & 0x100) == 0) {
    if ((*(byte *)(param_1 + 0x78) & 0x80) != 0) {
      FUN_0064cf20();
      _DAT_029209a0 = DAT_029209a4;
    }
    if ((((*(byte *)(param_1 + 0x78) & 0x40) != 0) && (DAT_0292097c == 0)) && (DAT_00810194 != -1))
    {
      FUN_0064b1c0(DAT_00810194,&DAT_0291f714);
    }
    iVar2 = DAT_02920888;
    if ((*(byte *)(param_1 + 0x70) & 0x20) != 0) {
      if (DAT_0292097c == 0) {
        if (DAT_02920888 != -1) {
          FUN_00642af0(DAT_02920888,&DAT_0291f714);
        }
      }
      else {
        FUN_00642b50();
        iVar2 = DAT_02920888;
      }
    }
    if ((((*(uint *)(param_1 + 0x70) & 0x400) != 0) && (DAT_0292097c == 0)) && (iVar2 != -1)) {
      FUN_00642af0(iVar2,&DAT_0291f714);
    }
    if ((*(byte *)(param_1 + 0x78) & 0x10) == 0) goto LAB_0064fa24;
    iVar4 = 0;
    if (DAT_0292097c != 0) {
      DAT_02920984 = 0;
      DAT_02920a64 = 0;
      goto LAB_0064fa24;
    }
    if (iVar2 != -1) {
      FUN_0064b860(iVar2);
      iVar4 = extraout_ECX;
    }
    iVar2 = -1;
    DAT_02920888 = -1;
  }
  else {
LAB_0064fa24:
    iVar4 = 0;
    if (DAT_0292097c != 0) {
      _DAT_00810198 =
           (_DAT_00810198 + (float)*(byte *)(param_1 + 0x96) / 5000.0) -
           (float)*(byte *)(param_1 + 0x97) / 5000.0;
      if (0.05 <= _DAT_00810198) {
        if (2.0 < _DAT_00810198) {
          _DAT_00810198 = 2.0;
        }
      }
      else {
        _DAT_00810198 = 0.05;
      }
      DAT_02920a64 = DAT_02920a64 + (uint)*(byte *)(param_1 + 0x94);
      DAT_02920a64 = DAT_02920a64 - (uint)*(byte *)(param_1 + 0x95);
      goto LAB_0064fca3;
    }
  }
  if (DAT_02920998 == 1) {
    if ((*(uint *)(param_1 + 0x70) & 0x200) != 0) {
      DAT_02920a4c = 0;
      DAT_02920a50 = iVar4;
    }
    DAT_02920a50 = DAT_02920a50 + (uint)*(byte *)(param_1 + 0x94);
    DAT_02920a50 = DAT_02920a50 - (uint)*(byte *)(param_1 + 0x95);
    iVar3 = DAT_02920a4c + (uint)*(byte *)(param_1 + 0x96);
    if (iVar4 < iVar3) {
      iVar3 = 0;
    }
    DAT_02920a4c = iVar3 - (uint)*(byte *)(param_1 + 0x97);
    if (DAT_02920a4c < -0x8000) {
      DAT_02920a4c = -0x8000;
    }
  }
  else if (DAT_02920998 == iVar4) {
    if ((*(uint *)(param_1 + 0x70) & 0x200) != 0) {
      DAT_02920a40 = 0;
      DAT_02920a44 = iVar4;
      DAT_02920a48 = iVar4;
    }
    if ((*(uint *)(param_1 + 0x70) & 0x400) == 0) {
      DAT_02920a44 = DAT_02920a44 + (uint)*(byte *)(param_1 + 0x94);
      DAT_02920a44 = DAT_02920a44 - (uint)*(byte *)(param_1 + 0x95);
      iVar3 = DAT_02920a40 + (uint)*(byte *)(param_1 + 0x96);
      if (0x8000 < iVar3) {
        iVar3 = 0x8000;
      }
      DAT_02920a40 = iVar3 - (uint)*(byte *)(param_1 + 0x97);
      if (DAT_02920a40 < -0x8000) {
        DAT_02920a40 = -0x8000;
      }
    }
    else {
      DAT_02920a48 = DAT_02920a48 + (uint)*(byte *)(param_1 + 0x94);
      DAT_02920a48 = DAT_02920a48 - (uint)*(byte *)(param_1 + 0x95);
    }
  }
  else if (DAT_02920998 == 3) {
    DAT_02920a5c = DAT_02920a5c + (uint)*(byte *)(param_1 + 0x94);
    DAT_02920a5c = DAT_02920a5c - (uint)*(byte *)(param_1 + 0x95);
    iVar3 = DAT_02920a58 + (uint)*(byte *)(param_1 + 0x96);
    if (iVar4 < iVar3) {
      iVar3 = 0;
    }
    DAT_02920a58 = iVar3 - (uint)*(byte *)(param_1 + 0x97);
    if (DAT_02920a58 < -0x8000) {
      DAT_02920a58 = -0x8000;
    }
  }
  else if (DAT_02920998 == 2) {
    if ((*(char *)(param_1 + 0x96) == -1) || ((*(uint *)(param_1 + 0x78) & 0x1000) != 0)) {
      _DAT_02920a54 = _DAT_02920a54 + 0.01;
    }
    if ((*(char *)(param_1 + 0x97) == -1) || ((*(uint *)(param_1 + 0x78) & 0x4000) != 0)) {
      _DAT_02920a54 = _DAT_02920a54 - 0.01;
    }
    if (_DAT_02920a54 < 0.0) {
      _DAT_02920a54 = 0.0;
    }
  }
LAB_0064fca3:
  if (iVar2 != -1) {
    DAT_0292096c = &DAT_0291f7a8 + iVar2 * 0x1b;
    if ((&DAT_0291f7b4)[iVar2 * 0x1b] != -1) {
      DAT_02920970 = &DAT_02913a58 + (&DAT_0291f7b4)[iVar2 * 0x1b] * 0x178;
    }
    psVar6 = (short *)(DAT_02920970 + 0x90);
    DAT_0291f66c = iVar4;
    DAT_0291f788 = iVar4;
    do {
      sVar1 = *psVar6;
      if ((sVar1 != -1) && (sVar1 != 9999)) {
        if (sVar1 == 0x270e) {
          DAT_0291f66c = DAT_0291f66c + 1;
        }
        else {
          iVar2 = 0;
          psVar5 = (short *)(DAT_02920970 + 0x90);
          if (0 < iVar4) {
            do {
              if (*psVar5 == sVar1) {
                DAT_0291f788 = DAT_0291f788 + 1;
                break;
              }
              iVar2 = iVar2 + 1;
              psVar5 = psVar5 + 1;
            } while (iVar2 < iVar4);
          }
        }
      }
      iVar4 = iVar4 + 1;
      psVar6 = psVar6 + 1;
    } while (iVar4 < 8);
  }
  return;
}

